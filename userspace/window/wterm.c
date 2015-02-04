#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <drv/pipe.h>
#include <drv/poll.h>
#include <os/shm.h>
#include <os/waitexit.h>
#include "w/draw.h"
#include "w/msg.h"
#include "kb_state.h"
#define R 25
#define C 81
#define FH 16
#define FW 8
#define NBUF 4
int priv_fd;
int ifd, ofd;

__u16 *buff = (void *)(1024*1024*1024);
DrawCanvas _canv;
DrawCanvas * const canv = &_canv;

long shm_key;
WHandle hwnd;

unsigned char scr[R*C*NBUF];
unsigned short fg[R*C*NBUF];
unsigned short bg[R*C*NBUF];
int cur_top;
int scr_pos;
int scr_pos_hide;
unsigned short cur_fg, cur_bg;
char kb_pend[R*C];
int kb_pi;
int pipe_in;
int pipe_out;
int poll_fd;

int p_x1, p_y1, p_x2, p_y2;
int pend;

/*
颜色表
黑色  #000000
深棕  #800000
绿色  #008000
橄榄  #808000
深蓝  #000080
紫色  #800080
深青  #008080
银色  #c0c0c0

灰色  #808080
红色  #ff0000
亮绿  #00ff00
黄色  #ffff00
蓝色  #0000ff
紫红  #ff00ff
青色  #00ffff
白色  #ffffff
*/
short color_table[16] = {
	RGB(0,0,0),
	RGB(16,0,0),
	RGB(0,32,0),
	RGB(16,32,0),
	RGB(0,0,16),
	RGB(16,0,16),
	RGB(0,32,16),
	RGB(24,48,24),

	RGB(16,32,16),
	RGB(31,0,0),
	RGB(0,63,0),
	RGB(31,63,0),
	RGB(0,0,31),
	RGB(31,0,31),
	RGB(0,63,31),
	RGB(31,63,31),
};

static int add_mod(int a, int b)
{
	return (a + b + R*C*NBUF)%(R*C*NBUF);
}

static int min(int a, int b) {return a>b?b:a;}
static int max(int a, int b) {return a<b?b:a;}
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

void draw_title()
{
	char buf[C+1];
	memset(buf, ' ', C);
	buf[C] = 0;
	memcpy(buf, "WTerm", 5);
	draw_string_bg(canv, 0, 0, buf, RGB(25,50,25), RGB(8,16,31));
	w_send_wrefresh(ofd, hwnd, 0, 0, C*FW, FH);
}

void refresh_scr(int x1, int y1, int x2, int y2)
{
	w_send_wrefresh(ofd, hwnd,
			x1*FW, (y1+1)*FH,
			(x2 - x1 + 1)*FW,
			(y2 - y1 + 1)*FH);
}

void draw_scr(int top, int x1, int y1, int x2, int y2)
{
	int i, j, p;
	for(i = y1; i <= y2; i++)
		for(j = x1; j <= x2; j++)
		{
			p = add_mod(i*C+j, top);
			draw_ascii(canv, j*FW, (i+1)*FH, 
				   scr[p], fg[p], bg[p]);
		}
}

void scroll_down()
{
	int j;
	int p;
	cur_top = add_mod(cur_top, C);
	for(j = 0; j < C; j++)
	{
		p = add_mod((R-1)*C+j, cur_top);
		scr[p] = ' ';
	}
	p_x1 = 0;
	p_y1 = 0;
	p_x2 = C-1;
	p_y2 = R-1;
	pend = 1;
}

void update_scr(int i)
{
	int r, c;
	r = add_mod(i, -cur_top)/C;
	c = add_mod(i, -cur_top)%C;
	while(r >= R)
	{
		scroll_down();
		r--;
	}
	if(pend) {
		p_x1 = min(c, p_x1);
		p_y1 = min(r, p_y1);
		p_x2 = max(c, p_x2);
		p_y2 = max(r, p_y2);
	} else {
		p_x1 = p_x2 = c;
		p_y1 = p_y2 = r;
		pend = 1;
	}
}

void draw_cur()
{
	int r, c;
	if(!scr_pos_hide) {
		r = add_mod(scr_pos, -cur_top)/C;
		c = add_mod(scr_pos, -cur_top)%C;
		update_scr(scr_pos);
		draw_ascii(canv, c*FW, (r+1)*FH, scr[scr_pos], bg[scr_pos], fg[scr_pos]);
		refresh_scr(p_x1, p_y1, p_x2, p_y2);
	}
}

void write_tty_normal(char buf)
{
	if(buf == '\n') {
		update_scr(scr_pos);
		scr_pos = add_mod(scr_pos, C-(scr_pos%C));
		update_scr(scr_pos);
	} else if(buf == '\t') {
		update_scr(scr_pos);
		scr_pos = add_mod(scr_pos, 8-(scr_pos%C%8));
		update_scr(scr_pos);
	} else if(buf == '\b') {
		update_scr(scr_pos);
		scr_pos = add_mod(scr_pos, -1);
		scr[scr_pos] = ' ';
		fg[scr_pos] = cur_fg;
		bg[scr_pos] = cur_bg;
		update_scr(scr_pos);
	} else {
		scr[scr_pos] = buf;
		fg[scr_pos] = cur_fg;
		bg[scr_pos] = cur_bg;
		update_scr(scr_pos);
		scr_pos = add_mod(scr_pos, 1);
	}
}

void write_tty(char *buf, int n)
{
	static int estate;
	static int num, num2;
	static int light, hide;
	static int saved_r, saved_c;
	int i;
	int tmp, tr, tc;
	while(n--) {
		switch(estate) {
		case 0: //normal state
			if(*buf == '\033') {
				estate = 1;
			} else {
				write_tty_normal(*buf);
				estate = estate;
			}
			break;
		case 1: //esc begin
			if(*buf == '[')
				estate = 2;
			else estate = 0;
			break;
		case 2: //meet '['
			if(*buf == 'K') {
				//清除从光标到行尾内容
				estate = 0;
			} else if(*buf == 's') {
				//保存光标位置
				saved_r = add_mod(scr_pos, -cur_top)/C;
				saved_c = add_mod(scr_pos, -cur_top)%C;
				estate = 0;
			} else if(*buf == 'u') {
				//恢复光标位置
				scr_pos = add_mod(cur_top, saved_c+C*saved_r);
				estate = 0;
			} else if(*buf == '?') {
				//隐藏/显示光标
				estate = 6;
			} else if(*buf >= 0 && *buf <= '9') {
				num = *buf - '0';
				estate = 3;
			} else {
				printf("unkown esc seq 1\n");
				estate = 0;
			}
			break;
		case 3: //first arg
			if(*buf == 'm') {
				switch(num) {
				case 0: //关闭所有属性
					light = 0;
					hide = 0;
					cur_fg = color_table[7];
					cur_bg = color_table[0];
					break;
				case 1: //设置高亮
					light = 1;
					break;
				case 4: //下划线
					break;
				case 5: //闪烁
					break;
				case 7: //反显
					tmp = cur_fg;
					cur_fg = cur_bg;
					cur_bg = tmp;
					break;
				case 8: //消隐
					hide = 1;
					break;
				default:
					if(num >= 30 && num <= 37) {
						//前景色
						cur_fg = hide ? cur_bg :
							color_table[num-30+light*8];
					}else if(num >= 40 && num <= 47) {
						//背景色
						cur_bg = color_table[num-40+light*8];
					} else {
						printf("unkown esc seq 2\n");
					}
					break;
				}
				estate = 0;
			} else if(*buf == 'J') {
				if(num == 2) {
					//清屏
					for(i = 0; i < R*C; i++)
					{
						int p = add_mod(i, cur_top);
						scr[p] = ' ';
						fg[p] = color_table[7];
						bg[p] = color_table[0];
					}
					p_x1 = 0; p_y1 = 0;
					p_x2 = C-1; p_y2 = R-1;
					pend = 1;
					estate = 0;
				} else {
					printf("unkown esc seq 3\n");
					estate = 0;
				}
			} else if(*buf == 'A') {
				//上移动
				tr = add_mod(scr_pos, -cur_top)/C;
				tc = add_mod(scr_pos, -cur_top)%C;
				tr -= num;
				if(tr < 0) tr = 0;
				scr_pos = add_mod(cur_top, tc+C*tr);
				estate = 0;
			} else if(*buf == 'B') {
				//下移动
				tr = add_mod(scr_pos, -cur_top)/C;
				tc = add_mod(scr_pos, -cur_top)%C;
				tr += num;
				if(tr >= R) tr = R-1;
				scr_pos = add_mod(cur_top, tc+C*tr);
				estate = 0;
			} else if(*buf == 'C') {
				//左移动
				tr = add_mod(scr_pos, -cur_top)/C;
				tc = add_mod(scr_pos, -cur_top)%C;
				tc -= num;
				if(tc < 0) tc = 0;
				scr_pos = add_mod(cur_top, tc+C*tr);
				estate = 0;
			} else if(*buf == 'D') {
				//右移动
				tr = add_mod(scr_pos, -cur_top)/C;
				tc = add_mod(scr_pos, -cur_top)%C;
				tc += num;
				if(tc >= C) tc = C-1;
				scr_pos = add_mod(cur_top, tc+C*tr);
				estate = 0;
			} else if(*buf == ';') {
				estate = 4;
			} else if(*buf >= '0' && *buf <= '9') {
				num = num*10 + *buf - '0';
				estate = estate;
			}
			break;
		case 4: //meet ;
			if(*buf >= '0' && *buf <= '9') {
				num2 = *buf - '0';
				estate = 5;
			} else {
				printf("unkown esc seq 4\n");
				estate = 0;
			}
			break;
		case 5: //second arg
			if(*buf == 'H') {
				//设置光标
				tr = num;
				tc = num2;
				if(tc >= C) tc = C-1;
				if(tr >= R) tr = R-1;
				scr_pos = add_mod(cur_top, tc+C*tr);
				estate = 0;
			} else if(*buf >= '0' && *buf <= '9') {
				num2 = num2*10 + *buf - '0';
				estate = estate;
			} else {
				printf("unkown esc seq 5\n");
				estate = 0;
			}
			break;
		case 6: //meet ?
			if(*buf >= '0' && *buf <= '9') {
				num2 = *buf - '0';
				estate = 7;
			} else {
				printf("unkown esc seq 6\n");
				estate = 0;
			}
			break;
		case 7:
			if(*buf == 'h') {
				//显示光标
				if(num2 == 25) {
					scr_pos_hide = 0;
				} else printf("unkown esc seq 7\n");
				estate = 0;
			} else if(*buf == 'l') {
				//隐藏光标
				if(num2 == 25) {
					scr_pos_hide = 1;
					printf("cursor hide\n");
				} else printf("unkown esc seq 8\n");
				estate = 0;
			} else if(*buf >= '0' && *buf <= '9') {
				num2 = num2*10 + *buf - '0';
				estate = estate;
			} else {
				printf("unkown esc seq 9\n");
				estate = 0;
			}
			break;
		default:
			printf("esc bug\n");
			exit(1);
			break;
		}
		buf++;
	}
	draw_scr(cur_top, p_x1, p_y1, p_x2, p_y2);
	refresh_scr(p_x1, p_y1, p_x2, p_y2);
	pend = 0;
	draw_cur();
}

void read_tty(char ch)
{
	int n;
	if(kb_pi >= R*C)
		printf("input buffer full\n");
	if(ch == '\b') {
		if(kb_pi) {
			kb_pi--;
			goto echo;
		}
		else goto no_echo;
	}
	kb_pend[kb_pi] = ch;
	kb_pi++;
	if(ch == '\n') {
		n = write(pipe_in, kb_pend, kb_pi);
		if(n < kb_pi)
			printf("truncation\n");
		kb_pi = 0;
	}
echo:	write_tty_normal(ch);
	draw_scr(cur_top, p_x1, p_y1, p_x2, p_y2);
	refresh_scr(p_x1, p_y1, p_x2, p_y2);
	pend = 0;
	draw_cur();
no_echo:;
}

void term_init()
{
	int i;
	printf("in\n");
	for(i = 0; i < R*C*NBUF; i++)
	{
		fg[i] = color_table[7];
		bg[i] = color_table[0];
		scr[i] = ' ';
	}
	cur_fg = color_table[7];
	cur_bg = color_table[0];
	draw_scr(0, 0, 0, C-1, R-1);
	refresh_scr(0, 0, C-1, R-1);
}

int destroy_window()
{
	long ret;
	w_send_wdestroy(ofd, hwnd);
	w_wait_reply(ifd, &ret, NULL);
	return ret;
}

int do_window()
{
	WMsg msg;
	static int scroll_off;
	w_recv(ifd, &msg, sizeof(WMsg));
	switch( msg.type )
	{
	case UM_KEY:
		if(!(msg.arg4 & KBS_BRK))
		{
			if((msg.arg4 & KBS_LSH || msg.arg4 & KBS_RSH)) {
				if(msg.arg3 & KB_PGDN) {
					scroll_off += R*C;
					draw_scr(add_mod(cur_top, scroll_off),
						 0, 0, C-1, R-1);
					refresh_scr(0, 0, C-1, R-1);
				} else if(msg.arg3 & KB_PGUP) {
					scroll_off -= R*C;
					draw_scr(add_mod(cur_top, scroll_off),
						 0, 0, C-1, R-1);
					refresh_scr(0, 0, C-1, R-1);
				}
			}
			if(msg.arg2 != 0) {
				if(scroll_off) {
					scroll_off = 0;
					draw_scr(cur_top, 0, 0, C-1, R-1);
					refresh_scr(0, 0, C-1, R-1);
				}
				read_tty(msg.arg2);
			}
		}
		break;
	case UM_EXIT:
		if(destroy_window(hwnd))
			return 1;
		break;
	default:
		break;
	}
	return 0;
}

int do_pipe()
{
	int n;
	char buf[1024];
	n = read(pipe_out, buf, 1024);
	write_tty(buf, n);
	return 0;
}

void main_loop()
{
	int i, num_evs;
	struct s_poll_event poll_event;
	int status;
	for(;;)
	{
		num_evs = ioctl(poll_fd, POLL_CMD_PEEK, 0);
		if(num_evs == 0)
		{
			if(waitpid(-1, &status, WNOHANG) > 0)
				write(pipe_out, "shell die\n", 10);
			num_evs = 1;
		}
		for(i = 0; i < num_evs; i++)
		{
			if(read(poll_fd,
				&poll_event,
				sizeof(struct s_poll_event)) == -1)
				return;
			if(poll_event.fd == ifd)
			{
				if(do_window())
					return;
			}
			else
				do_pipe();
		}
	}
}

int main()
{
	draw_init();
	draw_set_canvas(canv, buff);
	if(w_connect(&priv_fd, &ifd, &ofd))
		return -1;

	poll_fd = open("/dev/poll/0", 0);
	pipe_in = open("/dev/pipe/0", 0);
	pipe_out = open("/dev/pipe/0", 0);
	poll_set_event(poll_fd, pipe_out, POLL_TYPE_READ);
	if(fork() == 0)
	{
		dup2(pipe_in, 0);
		dup2(pipe_out, 1);
		dup2(pipe_out, 2);
		_exit(execl("/bin/sh", "*sh*", NULL));
	}

	w_send_wcreate(ofd, 0, 0, 0, C*FW, (R+1)*FH, "WTerm");
	w_wait_reply(ifd, &hwnd, &shm_key);
	shm_at(shm_key, buff, SHM_RW);
	printf("hwnd: %x\n",hwnd);
	poll_set_event(poll_fd, ifd, POLL_TYPE_READ);

	draw_title();
	term_init();
	main_loop();

	w_disconnect(priv_fd, ifd, ofd);
	shm_dt(shm_key, buff);
	printf("exit with exit code 0\n");
	return 0;
}
