/**
 * wnd.c
 * 窗口管理、重绘图
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <os/shm.h>
#include <errno.h>
#include <os/unistd.h>
#include "draw.h"
#include "w.h"
#include "wnd.h"
#include "msg.h"

static WWnd wtable[WND_MAX];	//窗口列表
static WWnd *wnd_first = NULL;	//最顶层窗口

char bmp[1024*1024];

DrawCanvas _desk;
DrawCanvas * const desk = &_desk;
__u16 deskmem[800*600];

void desktop_init()
{
	int fd;
	draw_set_canvas(desk, deskmem);
	
	draw_clear_screen(desk, RGB(31,63,31));
	draw_rect(desk, 100,100,699,499,RGB(0,50,0),1);
	
	fd = open("/share/logo.bmp", 0);
	if(fd < 0)
	{
		printf("can't find logo.bmp!\n");
		exit(1);
	}
	read(fd, bmp, 1024*1024);
	close(fd);
	draw_bmp(desk, 120,20,bmp,0xffff,1);
	draw_string(desk, 0, 0, "Hello World! Version 3", 0);
}

void wnd_list_del(WWnd **pfirst, WWnd *pwin)
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

void wnd_list_add_first(WWnd **pfirst, WWnd *pwin)
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

void __wnd_redraw(WInfo *pwinfo, int x1, int y1, int x2, int y2)		//重画以(x1,y1),(x2,y2)为顶点的矩形(左上右下)
{
	int w = x2 - x1;
	int h = y2 - y1;
	int x = x1;
	int y = y1;
	if( w<=0 || h<=0) return;
	
	draw_copy(desk, pwinfo->virt, x, y, w, h); //draw desktop
	
	if( !wnd_first ) return;
	WWnd *pwin;
	for( pwin = wnd_first->prev; pwin != wnd_first; pwin = pwin->prev)	//draw under windows
	{
		draw_window(&(pwin->bufcan), pwinfo->virt,
			pwin->x, pwin->y, pwin->w, pwin->h);
	}
	//draw top window
	pwin = wnd_first;
	draw_window(&(pwin->bufcan), pwinfo->virt,
		pwin->x, pwin->y, pwin->w, pwin->h);
}

int wnd_destroy(WInfo *pwinfo, WWnd *pwin)
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

WWnd *wnd_create(WInfo *pwinfo, int ifd, int ofd, __u32 attr, char *name, int x, int y, int w, int h)
{
	WWnd *pwin;
	for(pwin = wtable; pwin < wtable + WND_MAX; pwin++)
	{
		printf("pwin->addr %p %d\n", pwin, pwin->attr);
		if(pwin->attr == WND_ATTR_EMPTY)
		{
			strcpy(pwin->name, name);
			pwin->attr = WND_ATTR_USED | attr;
			pwin->ifd = ifd;
			pwin->ofd = ofd;
			pwin->x = x;
			pwin->y = y;
			pwin->w = w;
			pwin->h = h;

			wnd_list_add_first(&wnd_first, pwin);
			//memset(pwin->buffer, (char)x, pwinfo->virt->x * pwinfo->virt->y *2);
			w_redraw(pwinfo, pwin->x, pwin->y, pwin->x + pwin->w, pwin->y + pwin->h);
			printf("w: window created, nr = %ld wtable[1].attr = %lu\n", pwin - wtable, wtable[1].attr);
			return pwin;
		}
	}
	return NULL;
}

#define __in_area(x,y,l,t,w,h) ( (l)<=(x) && (x)<=((l)+(w)) && (t)<=(y) && (y)<=((t)+(h)) )

WWnd *wnd_in_area(int x,int y)
{
	if( !wnd_first )return NULL;
	WWnd *pwin;
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

void wnd_set_top(WInfo *pwinfo, WWnd *pwin)
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

void wnd_reset_hwnd(WInfo *pwinfo)
{
	pwinfo->hwnd = wnd_in_area(pwinfo->mouse_x, pwinfo->mouse_y);
}

int wnd_init(WInfo *pwinfo)
{
	int i;
	for(i = 0; i < WND_MAX; i++)
	{
		if(shm_get(0x1100 + i, WIN_LEN) != 0)
		{
			printf("can't shm_get\n");
			exit(1);
		}
		wtable[i].buffer = (void *)(WIN_START_ADDR + i * WIN_LEN);
		draw_set_canvas(&(wtable[i].bufcan), wtable[i].buffer);
		if(shm_at(0x1100 + i, (unsigned long)wtable[i].buffer, SHM_R) != 0)
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

static void wnd_post_exit()
{
	int i;
	for(i = 0; i < WND_MAX; i++)
	{
		if(shm_dt(0x1100 + i, (unsigned long)wtable[i].buffer) != 0)
		{
			printf("can't shm_dt\n");
		}
	}
}

static void send_um_exit(WWnd *hwnd)
{
	WMsg msg;
	msg.type = UM_EXIT;
	msg.arg1 = (WHandle)hwnd;
	w_send(hwnd->ifd, &msg, sizeof(WMsg));
}

int wnd_exit(WInfo *pwinfo)
{
	WWnd *pwin;
	int flag;
	flag = 0;
	for(pwin = wtable; pwin < wtable + WND_MAX; pwin++)
	{
		if(pwin->attr == WND_ATTR_USED)
		{
			flag = 1;
			send_um_exit(pwin);
		}
	}
	if(flag == 0)
		wnd_post_exit();
	return flag;
}
