/**
 * w.c
 * w管理器主逻辑
 */
 
#include <libc/libc.h>
#include "draw.h"
#include "w.h"
#include "msg.h"
#include "kb.h"
#include "mouse.h"
#include "timer.h"

u16 virtmem[800*600];

DrawCanvas _real;
DrawCanvas _virt;
DrawCanvas * const real = &_real;
DrawCanvas * const virt = &_virt;

static void send_um_keypress(WND *hwnd, int key, int ckey, int led, int isbrk)
{
	MSG msg;
	msg.type = isbrk ? UM_KEYUP : UM_KEYPRESS;
	msg.arg1 = (HANDLE) hwnd;
	msg.arg2 = key;
	msg.arg3 = ckey;
	msg.arg4 = led;
	send( hwnd->pid, &msg);
}

static void send_um_mouseact(WND *hwnd, int x, int y, int lrb)
{
	MSG msg;
	msg.type = UM_MOUSEACT;
	msg.arg1 = (HANDLE) hwnd;
	msg.arg2 = x;
	msg.arg3 = y;
	msg.arg4 = lrb;
	send( hwnd->pid, &msg);
}

static void draw_mouse(WInfo *pwinfo)
{
	draw_cursor_mask(pwinfo->cursor, real,
		pwinfo->mouse_x, pwinfo->mouse_y,
		0xffff);
}

void draw_restore(WInfo *pwinfo)
{
	draw_copy(pwinfo->virt, real,
		pwinfo->mouse_x, pwinfo->mouse_y,
		12, 20);
}

/* 重画以(x1,y1),(x2,y2)为顶点的矩形(左上右下) */
void w_redraw(WInfo *pwinfo, int x1, int y1, int x2, int y2)
{
	__wnd_redraw(pwinfo, x1, y1, x2, y2);
	draw_copy(pwinfo->virt, real,
		x1, y1, x2 - x1, y2 - y1);
	draw_mouse(pwinfo);
}

int no_handler(WInfo *pwinfo, MSG *pmsg)
{
	printf("no handler: msg.type = %d\n", pmsg->type);
	return 1;
}

int do_km_keypress(WInfo *pwinfo, MSG *pmsg)
{
	kb_do_km_keypress(pwinfo, pmsg);
	
	if(pwinfo->hwnd)
	send_um_keypress(pwinfo->hwnd,
		pmsg->arg1, pmsg->arg2, pmsg->arg3, pmsg->arg4);
	else
	{
		if(pmsg->arg4) goto next;
		if(pwinfo->kb_ascii == 'f')
			w_redraw(pwinfo, 0, 0,
				pwinfo->virt->x, pwinfo->virt->y);
		else if(pwinfo->kb_ascii == 'q')
			return 1;
	next:	;
	}
	return 0;
}

int do_km_mouseact(WInfo *pwinfo, MSG *pmsg)
{
	draw_restore(pwinfo);
	mouse_do_km_mouseact(pwinfo, pmsg);
	draw_mouse(pwinfo);
	
	/* 位置检测 */
	wnd_reset_hwnd(pwinfo);
	
	w_redraw(pwinfo, 0, 560, 799, 576);
	if(pwinfo->hwnd)
	{
		draw_string(real, 0, 560, pwinfo->hwnd->name, 0);
		send_um_mouseact(pwinfo->hwnd,
			pwinfo->mouse_x - pwinfo->hwnd->x,
			pwinfo->mouse_y - pwinfo->hwnd->y,
			pmsg->arg3);
	}
	else
	{
		draw_string(real, 0, 560, "Desktop", 0);
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
	
	return 0;
}

int do_km_timer(WInfo *pwinfo, MSG *pmsg)
{
	WND *pwin;
	static int timer;
	
	timer_do_km_timer(pwinfo, pmsg);
	
	timer++;
	wnd_for_each(pwinfo, pwin)
	{
		if(pwin->attr == WND_ATTR_USED &&
		   pwin->use_timer &&
		   timer%(pwin->use_timer) == 0)
		{
			MSG msg;
			msg.type = UM_TIMER | MSG_TYPE_BLOCK;
			msg.arg1 = (HANDLE) pwin;
			send( pwin->pid, &msg);
		}
	}
	
	/* 下面处理窗口移动 */
	if(
		pwinfo->mouse_chwnd &&
		pwinfo->mouse_btn&1 &&
		(pwinfo->kb_aux & (1<<2)) )
	{
		int orgi_x, orgi_y;
		int x1, x2, y1, y2;
		WND *hwnd = pwinfo->mouse_chwnd;
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

typedef int (*KmMsgHandler)(WInfo *pwinfo, MSG *pmsg);
KmMsgHandler km_handler[] = {
	no_handler,				/* 0 */
	no_handler,				/* USE_KB */
	no_handler,				/* USE_MOUSE */
	no_handler,				/* RESET_KB */
	no_handler,				/* RESET_MOUSE */
	do_km_keypress,				/* KEYPRESS */
	do_km_mouseact,				/* MOUSEACT */
	no_handler,				/* SET_TIMER */
	no_handler,				/* RESET_TIMER */
	do_km_timer,				/* TIMER */
	};

int do_wm_window_create(WInfo *pwinfo, MSG *pmsg)
{
	int retval;
	char wname[32];
	
	send_km_copydata(
		pmsg->arg5,				/* len */
		pmsg->pid,				/* pid */
		(void *)pmsg->arg4,			/* sptr(name) */
		wname);					/* dptr(wname) */
	
	retval = (int) wnd_create(			/* HWND */
				pwinfo,
				pmsg->pid,
				pmsg->arg1, 
				wname, 
				(pmsg->arg2>>16)&0xffff,
				(pmsg->arg2)&0xffff,
				(pmsg->arg3>>16)&0xffff,
				(pmsg->arg3)&0xffff );
	
	send_um_reply2(
			pmsg->pid,
			retval,
			0x1100 + (((WND *)(retval)) - pwinfo->wtable)
			);
	pwinfo->hwnd = wnd_in_area(pwinfo->mouse_x, pwinfo->mouse_y);
	
	return 0;
}

int do_wm_window_destroy(WInfo *pwinfo, MSG *pmsg)
{
	int retval;
	retval = wnd_destroy(pwinfo, (void *)pmsg->arg1);
	send_um_reply(pmsg->pid, retval);
	
	return 0;
}

int do_wm_window_refresh(WInfo *pwinfo, MSG *pmsg)
{
	WND *href = (WND *)pmsg->arg1;
	u32 xy = (u32)pmsg->arg3;
	u32 wh = (u32)pmsg->arg4;
	int x = xy >> 16;
	int y = xy & 0xffff;
	int w = wh >> 16;
	int h = wh & 0xffff;

	if(w > href->w) w = href->w;
	if(h > href->h) h = href->h;
	
	w_redraw(pwinfo, href->x + x, href->y + y,
		href->x + x + w, href->y + y + h);	
	return 0;
}

int do_wm_window_timer(WInfo *pwinfo, MSG *pmsg)
{
	WND *hw=(WND *)pmsg->arg1;
	hw->use_timer = pmsg->arg2;
	
	return 0;
}

typedef int (*WmMsgHandler)(WInfo *pwinfo, MSG *pmsg);
WmMsgHandler wm_handler[] = {
	no_handler,				/* 1000 */
	do_wm_window_create,			/* WINDOW_CREATE */
	do_wm_window_refresh,			/* WINDOW_REFRESH */
	do_wm_window_destroy,			/* WINDOW_DESTROY */
	do_wm_window_timer,			/* WINDOW_TIMER	 */
	};

void main_loop(WInfo *pwinfo)
{
	MSG msg;
	int retval;
	u32 msg_type;
	
	for(;recv( -1, &msg, 1);)
	{
		msg_type = msg.type&(~MSG_TYPE_BLOCK);
		
		if(msg_type <= KM_TIMER)
		{
			//printf("k%d ",msg_type>>1);
			retval = (km_handler[msg_type>>1])(pwinfo, &msg);
			if(retval)
				return;
		}
		
		if(msg_type >= WM_WINDOW_CREATE && msg_type <= WM_WINDOW_TIMER)
		{
			msg_type -= 1000 << 1;
			//printf("w%d ", msg_type >>1);
			retval = (wm_handler[msg_type>>1])(pwinfo, &msg);
			if(retval)
				return;
		}
	}
}

int main(int argc,char **argv)
{
	WInfo winfo;

	nice(-10);
	
	/* w信息初始化 */
	memset(&winfo, 0, sizeof(winfo));
	
	/* 绘图设备启动 */
	draw_init();
	draw_set_canvas(real, NULL);
	draw_set_canvas(virt, virtmem);
	winfo.virt = virt;
	
	/* 输入设备启动 */
	kb_init(&winfo);
	mouse_init(&winfo);
	timer_init(&winfo);
	
	/* 窗口管理启动 */
	wnd_init(&winfo);
	w_redraw(&winfo, 0, 0, virt->x, virt->y);
	
	/* 主循环 */
	main_loop(&winfo);
	
	/* 窗口管理退出 */
	wnd_exit(&winfo);
	
	/* 输入设备退出 */
	timer_exit(&winfo);
	mouse_exit(&winfo);
	kb_exit(&winfo);
	
	/* 绘图设备退出，转回控制台 */
	tty_switch(1);
	return 0;
}

