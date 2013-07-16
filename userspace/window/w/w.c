/**
 * w.c
 * w管理器主逻辑
 */
 
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <drv/input.h>
#include <drv/poll.h>
#include <drv/video.h>
#include <drv/pipe.h>
#include "draw.h"
#include "cursor.h"
#include "w.h"
#include "wnd.h"
#include "msg.h"
#include "kb_state.h"

int poll_fd;
int video_fd;
int my_turn;

int ms_fd;

__u16 virtmem[800*600];

DrawCanvas _real;
DrawCanvas _virt;
DrawCanvas * const real = &_real;
DrawCanvas * const virt = &_virt;

typedef struct s_client
{
	int priv_fd;
	int ifd, ofd;
} WClient;
#define WCLIENT_MAX 8
WClient wc[WCLIENT_MAX];

int timer_diff = 10;

extern char **environ;

static void draw_mouse(WInfo *pwinfo)
{
	draw_cursor_mask(pwinfo->cursor, real,
		pwinfo->mouse_x, pwinfo->mouse_y,
		0xffff);
}

static void draw_restore(WInfo *pwinfo)
{
	draw_copy(pwinfo->virt, real,
		pwinfo->mouse_x, pwinfo->mouse_y,
		12, 20);
}

static void send_um_key(WWnd *hwnd, struct kb_state *kbs)
{
	WMsg msg;
	msg.type = UM_KEY;
	msg.arg1 = (WHandle) hwnd;
	msg.arg2 = kbs->ch;
	msg.arg3 = kbs->func;
	msg.arg4 = kbs->state;
	msg.arg5 = kbs->leds;
	w_send(hwnd->ifd, &msg, sizeof(WMsg));
}

static void send_um_mouse(WWnd *hwnd, int x, int y, int lrb)
{
	WMsg msg;
	msg.type = UM_MOUSE;
	msg.arg1 = (WHandle) hwnd;
	msg.arg2 = x;
	msg.arg3 = y;
	msg.arg4 = lrb;
	w_send(hwnd->ifd, &msg, sizeof(WMsg));
}

static void send_um_reply(int fd, int retval1, int retval2)
{
	WMsg msg;
	msg.type = UM_REPLY;
	msg.arg1 = retval1;
	msg.arg2 = retval2;
	w_send(fd, &msg, sizeof(WMsg));
}

static void poll_set_event(int pollfd, int fd, int type)
{
	struct s_poll_event event;
	event.fd = fd;
	event.type = type;
	if(ioctl(pollfd, POLL_CMD_SET, &event))
		printf ("ioctl error\n");
}

static void poll_unset_event(int pollfd, int fd)
{
	struct s_poll_event event;
	event.fd = fd;
	event.type = 0;
	if(ioctl(pollfd, POLL_CMD_UNSET, &event))
		printf ("ioctl error\n");
}

typedef int (*act_func_t)(WInfo *pwinfo,int fd);
act_func_t act_func[64];

int act_noop(WInfo *pwinfo, int fd)
{
	return 0;
}

int act_kbfd(WInfo *pwinfo, int fd)
{
	int mode = 0x4114;
	struct s_event event;
	struct kb_state *kbs;
	read(fd, &event, sizeof(struct s_event));
	kbs = kb_trans(event.code, event.value);
	if(kbs->state & KBS_LAL ||
	   kbs->state & KBS_RAL)
	{
		if(kbs->state & KBS_BRK)
			goto next1;
		if(kbs->func == KB_F5)
		{
			ioctl(video_fd, VIDEO_CMD_SET_MODE, &mode);
			my_turn = 1;
			w_redraw(pwinfo, 0, 0, virt->x, virt->y);
		}
		else if(kbs->func >= KB_F1 && kbs->func <= KB_F12)
		{
			ioctl(video_fd, VIDEO_CMD_RESET_MODE, 0);
			my_turn = 0;
		}
	}
next1:	if(kbs->leds & KBL_SCR)
	{
		struct s_event ms_ev = {
			.ticks = event.ticks,
			.type = 2,
		};
		int xdiff = 0;
		int ydiff = 0;
		static int lrb = 0;
		if(!(kbs->state & KBS_BRK)) {
			switch(kbs->func)
			{
			case KB_ARU: ydiff -= 5; break;
			case KB_ARD: ydiff += 5; break;
			case KB_ARL: xdiff -= 5; break;
			case KB_ARR: xdiff += 5; break;
			case KB_END: lrb |= 1; break;
			case KB_PGDN: lrb |= 2; break;
			default: goto next;
			}
		} else {
			switch(kbs->func)
			{
			case KB_END: lrb &= ~1; break;
			case KB_PGDN: lrb &= ~2; break;
			default: goto next;
			}
		}
		ms_ev.code = lrb;
		ms_ev.value = (xdiff << 16) | (ydiff & 0xffff);
		write(ms_fd, &ms_ev, sizeof(struct s_event));
	}
next:
	if(my_turn)
	{
		pwinfo->kb = kbs;
		if(pwinfo->hwnd)
		{
			send_um_key(pwinfo->hwnd, kbs);
		}
		else
		{
			if(kbs->state & KBS_BRK) return 0;
			if(kbs->ch == 'f')
				w_redraw(pwinfo, 0, 0,
					 pwinfo->virt->x, pwinfo->virt->y);
			else if(kbs->ch == 'q')
				return 1;
		}
	}
	return 0;
}

int act_msfd(WInfo *pwinfo, int fd)
{
	struct s_event event;
	read(fd, &event, sizeof(struct s_event));
	if(my_turn)
	{
		draw_restore(pwinfo);
		pwinfo->mouse_lx = pwinfo->mouse_x;
		pwinfo->mouse_ly = pwinfo->mouse_y;
		pwinfo->mouse_lbtn = pwinfo->mouse_btn;
		pwinfo->mouse_x += (short)(event.value>>16);
		pwinfo->mouse_y += (short)(event.value&0xffff);
		pwinfo->mouse_btn = event.code;
		if(pwinfo->mouse_x < 0) pwinfo->mouse_x = 0;
		if(pwinfo->mouse_y < 0) pwinfo->mouse_y = 0;
		if(pwinfo->mouse_x > pwinfo->virt->x)
			pwinfo->mouse_x = pwinfo->virt->x;
		if(pwinfo->mouse_y > pwinfo->virt->y)
			pwinfo->mouse_y = pwinfo->virt->y;
		draw_mouse(pwinfo);

		/* 位置检测 */
		wnd_reset_hwnd(pwinfo);
		if(pwinfo->hwnd)
		{
			send_um_mouse(pwinfo->hwnd,
					      pwinfo->mouse_x - pwinfo->hwnd->x,
					      pwinfo->mouse_y - pwinfo->hwnd->y,
					      pwinfo->mouse_btn);
}

		/* 按键检测 */
		if(pwinfo->mouse_btn&1)
		{
			if(!(pwinfo->mouse_lbtn&1))
			{
				/* 刚按下左键 */
				wnd_set_top(pwinfo, pwinfo->hwnd);
				pwinfo->mouse_cx = pwinfo->mouse_x;
				pwinfo->mouse_cy = pwinfo->mouse_y;
				pwinfo->mouse_chwnd = pwinfo->hwnd;
				if(pwinfo->hwnd)
				{
					pwinfo->mouse_chwnd_x = pwinfo->hwnd->x;
					pwinfo->mouse_chwnd_y = pwinfo->hwnd->y;
				}
			}
		}
		else
		{
			if(pwinfo->mouse_lbtn&1)
				pwinfo->mouse_chwnd = NULL;
		}
	}
	return 0;
}

int act_clifd(WInfo *pwinfo, int fd)
{
	WMsg msg;
	int i;
	char wname[32];
	WWnd *hwnd;
	int ret;
	w_recv(fd, &msg, sizeof(WMsg));
	if(msg.type == WM_WCREATE)
	{
		printf("w create\n");
		w_recv(fd, wname, msg.arg5);
		printf("w name %s\n", wname);
		for(i = 0; i < WCLIENT_MAX; i++)
		{
			if(wc[i].ofd == fd)
				break;
		}
		if(i == WCLIENT_MAX)
		{
			printf("bad!\n");
			exit(1);
		}
		printf("ifd=%d\n", wc[i].ifd);
		hwnd = wnd_create(pwinfo,
				  wc[i].ifd,
				  wc[i].ofd,
				  msg.arg1,
				  wname,
				  (msg.arg2>>16)&0xffff,
				  (msg.arg2)&0xffff,
				  (msg.arg3>>16)&0xffff,
				  (msg.arg3)&0xffff);
		printf("w create ok\n");
		send_um_reply(wc[i].ifd,
			      (WHandle)hwnd,
			      0x1100 + (hwnd - pwinfo->wtable));
		printf("reply ok\n");
		pwinfo->hwnd = wnd_in_area(pwinfo->mouse_x, pwinfo->mouse_y);
	}
	else if(msg.type == WM_WREFRESH)
	{
		WWnd *href = (WWnd *)msg.arg1;
		__u32 xy = (__u32)msg.arg3;
		__u32 wh = (__u32)msg.arg4;
		int x = xy >> 16;
		int y = xy & 0xffff;
		int w = wh >> 16;
		int h = wh & 0xffff;
		if(w > href->w) w = href->w;
		if(h > href->h) h = href->h;
		if(pwinfo->need_redraw)
		{
			pwinfo->rx1 = min(pwinfo->rx1, x + href->x);
			pwinfo->ry1 = min(pwinfo->ry1, y + href->y);
			pwinfo->rx2 = max(pwinfo->rx2, href->x + x + w);
			pwinfo->ry2 = max(pwinfo->ry2, href->y + y + h);
		}
		else
		{
			pwinfo->rx1 = x + href->x;
			pwinfo->ry1 = y + href->y;
			pwinfo->rx2 = href->x + x + w;
			pwinfo->ry2 = href->y + y + h;
			pwinfo->need_redraw = 1;
		}
	}
	else if(msg.type == WM_WDESTROY)
	{
		hwnd = (WWnd *)msg.arg1;
		ret = wnd_destroy(pwinfo, hwnd);
		send_um_reply(hwnd->ifd, ret, 0);
		return 0;
	}
	return 0;
}

int act_sendfd(WInfo *pwinfo, int fd)
{
	int i;
	char buf[2];
	buf[1] = 0;
	read(fd, buf, 1);
	if(buf[0] == 'a') {
		for(i = 0; i < WCLIENT_MAX; i++)
		{
			if(wc[i].priv_fd == -1 &&
			   wc[i].ifd == -1 &&
			   wc[i].ofd == -1)
				break;
		}
		if(i == WCLIENT_MAX)
		{
			printf("Too many client !!\n");
			exit(1);
		}
		wc[i].priv_fd = fd;
		wc[i].ifd = open("/dev/pipe/0", 0);
		wc[i].ofd = open("/dev/pipe/0", 0);
		//request ifd
		ioctl(fd, PIPE_CMD_SENDFD, (void *)(wc[i].ifd));
	} else if(buf[0] == 'A') {
		//request stdout
		for(i = 0; i < WCLIENT_MAX; i++)
		{
			if(wc[i].priv_fd == fd)
				break;
		}
		if(i == WCLIENT_MAX)
		{
			printf("bad protocol\n");
		}
		ioctl(fd, PIPE_CMD_SENDFD, (void *)(wc[i].ofd));
		poll_set_event(poll_fd, wc[i].ofd, POLL_TYPE_READ);
		act_func[wc[i].ofd] = act_clifd;
	} else {
		for(i = 0; i < WCLIENT_MAX; i++)
		{
			if(wc[i].priv_fd == fd)
			{
				poll_unset_event(poll_fd, fd);
				act_func[fd] = act_noop;
				close(fd);
				if(wc[i].ifd != -1)
				{
					close(wc[i].ifd);
					wc[i].ifd = -1;
				}
				if(wc[i].ofd != -1)
				{
					poll_unset_event(poll_fd,
							 wc[i].ofd);
					close(wc[i].ofd);
					wc[i].ofd = -1;
				}
				wc[i].priv_fd = -1;
				break;
			}
		}
	}
	return 0;
}

int act_lisfd(WInfo *pwinfo, int fd)
{
	char buf[1];
	int xfd;
	read(fd, buf, 1);
	xfd = -1;
	if(ioctl(fd, PIPE_CMD_TESTFD, 0))
	{
		ioctl(fd, PIPE_CMD_RECVFD, &xfd);
		if(xfd < 0)
			printf("listen fd recv error!\n");
		poll_set_event(poll_fd, xfd, POLL_TYPE_READ);
		act_func[xfd] = act_sendfd;
	}
	else
		printf("bad protocol\n");
	return 0;
}

int idle_func(WInfo *pwinfo)
{
	if(pwinfo->need_redraw)
	{
		pwinfo->need_redraw = 1;
		w_redraw(pwinfo,
			 pwinfo->rx1, pwinfo->ry1,
			 pwinfo->rx2, pwinfo->ry2);
	}

	/* status bar */
	w_redraw(pwinfo, 0, 560, 799, 576);
	if(pwinfo->hwnd)
	{
		draw_string(real, 0, 560, pwinfo->hwnd->name, 0);
	}
	else
	{
		char buf[128];
		sprintf(buf, "(%d, %d)", pwinfo->mouse_x, pwinfo->mouse_y);

		draw_string(real, 0, 560, buf, 0);
	}

	/* 下面处理窗口移动 */
	if(
		pwinfo->mouse_chwnd &&
		pwinfo->mouse_btn&1 &&
		(pwinfo->kb->state & KBS_LCT) )
	{
		int orgi_x, orgi_y;
		int x1, x2, y1, y2;
		WWnd *hwnd = pwinfo->mouse_chwnd;
		orgi_x = hwnd->x;
		orgi_y = hwnd->y;
		hwnd->x = pwinfo->mouse_x - pwinfo->mouse_cx;
		hwnd->x += pwinfo->mouse_chwnd_x;
		hwnd->y = pwinfo->mouse_y - pwinfo->mouse_cy;
		hwnd->y += pwinfo->mouse_chwnd_y;
		if(hwnd->x < 0) hwnd->x = 0;
		if(hwnd->y < 0) hwnd->y = 0;
		if(hwnd->x >= pwinfo->virt->x) hwnd->x = pwinfo->virt->x - 1;
		if(hwnd->y >= pwinfo->virt->y) hwnd->y = pwinfo->virt->y - 1;
		x1 = min( hwnd->x, orgi_x );
		y1 = min( hwnd->y, orgi_y );
		x2 = max( hwnd->x, orgi_x ) + hwnd->w;
		y2 = max( hwnd->y, orgi_y ) + hwnd->h;
		w_redraw(pwinfo, x1, y1, x2, y2);
	}
	return 0;
}

/* 重画以(x1,y1),(x2,y2)为顶点的矩形(左上右下) */
void w_redraw(WInfo *pwinfo, int x1, int y1, int x2, int y2)
{
	__wnd_redraw(pwinfo, x1, y1, x2, y2);
	if(my_turn)
	{
		draw_copy(pwinfo->virt, real,
			  x1, y1, x2 - x1, y2 - y1);
		draw_mouse(pwinfo);
	}
}

int main(int argc, char **argv)
{
	WInfo winfo;
	int i, num_evs;
	int xfd;
	struct s_poll_event poll_event;
	/* global init */
	memset(&winfo, 0, sizeof(WInfo));
	draw_init();
	draw_set_canvas(real, NULL);
	draw_set_canvas(virt, virtmem);
	cursor_init(&winfo);
	winfo.virt = virt;
	winfo.need_redraw = 0;
	winfo.mouse_x = 400;
	winfo.mouse_y = 300;
	
	/* 窗口管理启动 */
	wnd_init(&winfo);
	w_redraw(&winfo, 0, 0, virt->x, virt->y);

	for(i = 0; i < 64; i++)
		act_func[i] = act_noop;
	for(i = 0; i < WCLIENT_MAX; i++)
	{
		wc[i].priv_fd = -1;
		wc[i].ifd = -1;
		wc[i].ofd = -1;
	}
	/* setup fd */
	poll_fd = open("/dev/poll/0", 0);
	video_fd = open("/dev/video/0", 0);

	xfd = open("/dev/input/1", 0);
	poll_set_event(poll_fd, xfd, POLL_TYPE_READ);
	act_func[xfd] = act_kbfd;

	xfd = open("/dev/input/2", 0);
	poll_set_event(poll_fd, xfd, POLL_TYPE_READ);
	act_func[xfd] = act_msfd;
	ms_fd = xfd;

	xfd = open("/dev/pipe/2", 0);
	poll_set_event(poll_fd, xfd, POLL_TYPE_READ);
	act_func[xfd] = act_lisfd;

	/* main loop */
	for(;;)
	{
		num_evs = ioctl(poll_fd, POLL_CMD_PEEK, 0);
		if(num_evs == 0)
		{
			idle_func(&winfo);
			num_evs = 1;
		}
		for(i = 0; i < num_evs; i++)
		{
			if(read(poll_fd,
				&poll_event,
				sizeof(struct s_poll_event)) == -1)
				return -1;
			xfd = poll_event.fd;
			if(act_func[xfd](&winfo, xfd))
				if(wnd_exit(&winfo) == 0)
				{
					ioctl(video_fd, VIDEO_CMD_RESET_MODE, 0);
					return 0;
				}
		}
	}
	return 0;
}
