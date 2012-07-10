/**
 * wnd.c
 * 窗口管理、重绘图
 */

#include <type.h>
#include <unistd.h>
#include <libc/libc.h>
#include <string.h>
#include <libc/kstru.h>
#include "draw.h"
#include "w.h"
#include "wnd.h"
#include "msg.h"

static WND wtable[WND_MAX];	//窗口列表
static WND *wnd_first = NULL;	//最顶层窗口

char bmp[1024*1024];
u16 virtual[800*600];
u16 desktop[800*600];

void desktop_init()
{
	u16 *tmp = video;
	video = desktop;
	
	draw_clear_screen(RGB(31,63,31));
	draw_rect(100,100,699,499,RGB(0,50,0),1);
	get_module("/logo.bmp", bmp);
	draw_bmp(120,20,bmp,0xffff,1);
	draw_string(0, 0, "Hello World!", 0);
	
	video = tmp;
}

void wnd_list_del(WND **pfirst, WND *pwin)
{
	if( pwin->next == pwin )
	{
		(*pfirst) = NULL;
	}
	else
	{
		if(pwin == (*pfirst) )
			(*pfirst) = pwin->next;
		pwin->prev->next = pwin->next;
		pwin->next->prev = pwin->prev;
	}
}

void wnd_list_add_first(WND **pfirst, WND *pwin)
{
	if( !(*pfirst) )
	{
		(*pfirst) = pwin;
		pwin->next = pwin;
		pwin->prev = pwin;
	}
	else
	{
		(*pfirst)->prev->next = pwin;
		pwin->prev = (*pfirst)->prev;
		pwin->next = (*pfirst);
		(*pfirst)->prev = pwin;
		
		(*pfirst) = pwin;	//set top!
	}
}

void __wnd_redraw(WINFO *pwinfo, int x1, int y1, int x2, int y2)		//重画以(x1,y1),(x2,y2)为顶点的矩形(左上右下)
{
	int w = x2 - x1;
	int h = y2 - y1;
	int x = x1;
	int y = y1;
	if( w<=0 || h<=0) return;
	draw_copy(x, y, desktop, virtual, w, h); //draw desktop
	if( !wnd_first ) return;
	WND *pwin;
	for( pwin = wnd_first->prev; pwin != wnd_first; pwin = pwin->prev)	//draw under windows
	{
		draw_window(pwin->x, pwin->y, pwin->buffer, virtual, pwin->w, pwin->h);
	}
	//draw top window
	pwin = wnd_first;
	draw_window(pwin->x, pwin->y, pwin->buffer, virtual, pwin->w, pwin->h);
}

int wnd_destroy(WINFO *pwinfo, WND *pwin)
{
	if(pwin->attr == WND_ATTR_EMPTY)
		return 0;
	wnd_list_del(&wnd_first, pwin);
	pwin->attr = WND_ATTR_EMPTY;
	w_redraw(pwinfo, pwin->x, pwin->y, pwin->x + pwin->w, pwin->y + pwin->h);
	if(pwin == pwinfo->hwnd)
		pwinfo->hwnd = NULL;
	return 1;
}

WND *wnd_create(WINFO *pwinfo, int pid, u32 attr, char *name, int x, int y, int w, int h)
{
	WND *pwin;
	for(pwin = wtable; pwin < wtable + 8; pwin++)
	{
		if(pwin->attr == WND_ATTR_EMPTY)
		{
			strcpy(pwin->name, name);
			pwin->attr = WND_ATTR_USED | attr;
			pwin->pid = pid;
			pwin->x = x;
			pwin->y = y;
			pwin->w = w;
			pwin->h = h;

			wnd_list_add_first(&wnd_first, pwin);
			memset(pwin->buffer, (char)x, info.x * info.y *2);
			w_redraw(pwinfo, pwin->x, pwin->y, pwin->x + pwin->w, pwin->y + pwin->h);
			printf("w: window created, nr = %d wtable[1].attr = %d\n", pwin - wtable, wtable[1].attr);
			return pwin;
		}
	}
	return NULL;
}

#define __in_area(x,y,l,t,w,h) ( (l)<=(x) && (x)<=((l)+(w)) && (t)<=(y) && (y)<=((t)+(h)) )

WND *wnd_in_area(int x,int y)
{
	if( !wnd_first )return NULL;
	WND *pwin;
	//check top window
	pwin = wnd_first;
	if( __in_area(x, y, pwin->x, pwin->y, pwin->w, pwin->h) )
		return pwin;
	
	//check under windows
	for( pwin = wnd_first->next; pwin != wnd_first; pwin = pwin->next)
	{
		if( __in_area(x, y, pwin->x, pwin->y, pwin->w, pwin->h) )
			return pwin;
	}
	return NULL;
}

void wnd_set_top(WINFO *pwinfo, WND *pwin)
{
	if(!pwin)
		return;
	if(wnd_first == pwin)
		return;
	//脱链
	wnd_list_del(&wnd_first, pwin);
	//插入第一个
	wnd_list_add_first(&wnd_first, pwin);
	w_redraw(pwinfo, pwin->x, pwin->y, pwin->x + pwin->w, pwin->y + pwin->h);
}

void wnd_reset_hwnd(WINFO *pwinfo)
{
	pwinfo->hwnd = wnd_in_area(pwinfo->mouse_x, pwinfo->mouse_y);
}

int wnd_init(WINFO *pwinfo)
{
	int i;
	for(i = 0; i < 8; i++)
	{
		if(shm_get(0x1100 + i, WIN_LEN) != 0)
		{
			printf("can't shm_get\n");
			exit(1);
		}
		wtable[i].buffer = (void *)(WIN_START_ADDR + i * WIN_LEN);
		if(shm_at(0x1100 + i, wtable[i].buffer, SHM_RW) != 0)
		{
			printf("can't shm_at\n");
			exit(1);
		}
	}
	
	pwinfo->wtable = wtable;
	pwinfo->hwnd = NULL;
	desktop_init();
	return 0;
}

int wnd_exit(WINFO *pwinfo)
{
	int i;
	WND *pwin;
	MSG msg;
	
	for(pwin = wtable; pwin < wtable + 8; pwin++)
	{
		if(pwin->attr == WND_ATTR_USED)
		{
			send_um_exit(pwin);
			recv( -1, &msg ,1);
			if( (msg.type&(~MSG_TYPE_BLOCK)) == WM_WINDOW_DESTROY )
			{
				int retval = wnd_destroy(pwinfo, (void *)msg.arg1);
				send_um_reply(msg.pid, retval);
			}
		}
	}
	
	for(i = 0; i < 8; i++)
	{
		if(shm_dt(0x1100 + i, wtable[i].buffer) != 0)
		{
			printf("can't shm_dt\n");
		}
	}
	return 0;
}

