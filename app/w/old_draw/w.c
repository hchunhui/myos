#include <type.h>
#include <unistd.h>
#include <libc/libc.h>
#include <string.h>
#include <libc/kstru.h>
#include "draw.h"
#include "w.h"
#include "msg.h"
#include "kb.h"
#include "mouse.h"
#include "timer.h"

extern u16 virtual[800*600];

static void send_um_keypress(WND *hwnd, int key, int ckey, int led)
{
	MSG msg;
	msg.type = UM_KEYPRESS;
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

static void draw_mouse(WINFO *pwinfo)
{
	draw_cursor_mask(pwinfo->mouse_x, pwinfo->mouse_y, pwinfo->cursor, info.base_addr, 12, 20, 0xffff);
}

void draw_restore(WINFO *pwinfo)
{
	draw_copy(pwinfo->mouse_x, pwinfo->mouse_y, pwinfo->virtual, info.base_addr, 12, 20);
}

void w_redraw(WINFO *pwinfo, int x1, int y1, int x2, int y2)		//重画以(x1,y1),(x2,y2)为顶点的矩形(左上右下)
{
	__wnd_redraw(pwinfo, x1, y1, x2, y2);
	draw_copy(x1, y1, pwinfo->virtual, info.base_addr, x2 - x1, y2 - y1);
	draw_mouse(pwinfo);
}

int no_handler(WINFO *pwinfo, MSG *pmsg)
{
	printf("no handler: msg.type = %d\n", pmsg->type);
	return 1;
}

int do_km_keypress(WINFO *pwinfo, MSG *pmsg)
{
	kb_do_km_keypress(pwinfo, pmsg);
	
	if(pwinfo->hwnd)
	send_um_keypress(pwinfo->hwnd,
		pmsg->arg1, pmsg->arg2, pmsg->arg3);
	else
	{
		if(pwinfo->kb_ascii == 'f')
			w_redraw(pwinfo, 0, 0, info.x, info.y);
		else if(pwinfo->kb_ascii == 'q')
			return 1;
	}
	return 0;
}

int do_km_mouseact(WINFO *pwinfo, MSG *pmsg)
{
	draw_restore(pwinfo);
	mouse_do_km_mouseact(pwinfo, pmsg);
	draw_mouse(pwinfo);
	wnd_reset_hwnd(pwinfo);
	
	//位置检测
	if(pwinfo->hwnd)
	{
		u16 *tmp = video;
		video = info.base_addr;
		draw_string(0, 560, pwinfo->hwnd->name, 0);
		video = tmp;
		send_um_mouseact(pwinfo->hwnd, 
			pwinfo->mouse_x - pwinfo->hwnd->x,
			pwinfo->mouse_y - pwinfo->hwnd->y,
			pmsg->arg3);
	}
	else
	{
		u16 *tmp = video;
		video = info.base_addr;
		draw_string(0, 560, "Desktop", 0);
		video = tmp;
	}
	
	//按键检测
	if(pwinfo->mouse_btn&1)
	{
		if(!(pwinfo->mouse_lbtn&1))	//刚按下左键
		{
			wnd_set_top(pwinfo, pwinfo->hwnd);
			pwinfo->mouse_cx = pwinfo->mouse_x;
			pwinfo->mouse_cy = pwinfo->mouse_y;
			pwinfo->mouse_chwnd = pwinfo->hwnd;
		}
	}
	else
	{
		if(pwinfo->mouse_lbtn&1)
			pwinfo->mouse_chwnd = NULL;
	}
	
	return 0;
}

int do_km_timer(WINFO *pwinfo, MSG *pmsg)
{
	WND *pwin;
	timer_do_km_timer(pwinfo, pmsg);
	
	wnd_for_each(pwinfo, pwin)
	{
		if(pwin->attr == WND_ATTR_USED && pwin->use_timer)
		{
			MSG msg;
			msg.type = UM_TIMER | MSG_TYPE_BLOCK;
			msg.arg1 = (HANDLE) pwin;
			send( pwin->pid, &msg);
		}
	}
	
	//窗口移动
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
		hwnd->y = pwinfo->mouse_y - pwinfo->mouse_cy;
		if(hwnd->x < 0) hwnd->x = 0;
		if(hwnd->y < 0) hwnd->y = 0;
		if(hwnd->x >= info.x) hwnd->x = info.x - 1;
		if(hwnd->y >= info.y) hwnd->y = info.y - 1;
		x1 = min( hwnd->x, orgi_x );
		y1 = min( hwnd->y, orgi_y );
		x2 = max( hwnd->x, orgi_x ) + hwnd->w;
		y2 = max( hwnd->y, orgi_y ) + hwnd->h;
		w_redraw(pwinfo, x1, y1, x2, y2);
	}
	
	return 0;
}

typedef int (*KM_MSG_HANDLER)(WINFO *pwinfo, MSG *pmsg);
KM_MSG_HANDLER km_msg_handler[] = {
	no_handler,				/* 0 */
	no_handler,				/* USE_KB */
	no_handler,				/* USE_MOUSE */
	no_handler,				/* RESET_KB */
	no_handler,				/* RESET_MOUSE */
	do_km_keypress,			/* KEYPRESS */
	do_km_mouseact,			/* MOUSEACT */
	no_handler,				/* SET_TIMER */
	no_handler,				/* RESET_TIMER */
	do_km_timer,				/* TIMER */
	};

void main_loop(WINFO *pwinfo)
{
	MSG msg;
	int retval;
	char wname[32];
	u32 msg_type;
	
	for(;recv( -1, &msg, 1);)
	{
		msg_type = msg.type&(~MSG_TYPE_BLOCK);
		
		if(msg_type <= KM_TIMER)
			retval = (km_msg_handler[msg_type>>1])(pwinfo, &msg);
		if(retval)
			return;
		switch( msg_type )
		{
		//下面是用户消息
			case WM_WINDOW_TIMER:
				;
				WND *hw=(WND *)msg.arg1;
				hw->use_timer = msg.arg2;
				break;
			case WM_WINDOW_REFRESH:
				;
				WND *href = (WND *)msg.arg1;
				u32 xy = (u32)msg.arg3;
				u32 wh = (u32)msg.arg4;
				int x = xy >> 16;
				int y = xy & 0xffff;
				int w = wh >> 16;
				int h = wh & 0xffff;
				if(w > href->w) w = href->w;
				if(h > href->h) h = href->h;
				w_redraw(pwinfo, href->x + x, href->y + y, href->x + x + w, href->y + y + h);
				//w_redraw(href->x, href->y, href->x + href->w, href->y + href->h);
				break;
			case WM_WINDOW_CREATE:
				send_km_copydata(
					msg.arg5,		//len
					msg.pid,		//pid
					(void *)msg.arg4,	//sptr(name)
					wname);			//dptr(wname)
				
				retval = (int) wnd_create(	//hwnd
					pwinfo,
					msg.pid,
					msg.arg1, 
					wname, 
					(msg.arg2>>16)&0xffff,
					(msg.arg2)&0xffff,
					(msg.arg3>>16)&0xffff,
					(msg.arg3)&0xffff );
				
				send_um_reply2(
					msg.pid,
					retval,
					0x1100 + (((WND *)(retval)) - pwinfo->wtable)
					);
				pwinfo->hwnd = wnd_in_area(pwinfo->mouse_x, pwinfo->mouse_y);
				break;
			case WM_WINDOW_DESTROY:
				retval = wnd_destroy(pwinfo, (void *)msg.arg1);
				send_um_reply(msg.pid, retval);
				break;
			default:
				break;
		}
	}
}

int main(int argc,char **argv)
{
	WINFO winfo;
	
	//w信息初始化
	memset(&winfo, 0, sizeof(winfo));
	
	//绘图设备启动
	draw_init(virtual);
	winfo.virtual = virtual;
	
	//输入设备启动
	kb_init(&winfo);
	mouse_init(&winfo);
	timer_init(&winfo);
	
	//窗口管理启动
	wnd_init(&winfo);
	w_redraw(&winfo, 0, 0, info.x, info.y);
	
	//主循环
	main_loop(&winfo);
	
	//窗口管理退出
	wnd_exit(&winfo);
	
	//输入设备退出
	timer_exit(&winfo);
	mouse_exit(&winfo);
	kb_exit(&winfo);
	
	//绘图设备退出，转回控制台
	tty_switch(1);
	
	return 0;
}

