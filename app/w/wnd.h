#ifndef _WND_H_
#define _WND_H_
#include "w.h"
#include "draw.h"
#define WIN_START_ADDR	(512*1024*1024)
#define WIN_LEN		(1024*1024)

typedef struct s_window
{
	char name[16];
	u32 attr;
	int x, y;
	int w, h;
	int ofd, ifd;
	struct s_window *prev, *next;
	DrawCanvas bufcan;
	u16 *buffer;	//有未知越界
}WWnd;
#define WND_MAX	8

#define WND_ATTR_EMPTY	0
#define WND_ATTR_USED	1

void wnd_list_del(WWnd **pfirst, WWnd *pwin);
void wnd_list_add_first(WWnd **pfirst, WWnd *pwin);
void __wnd_redraw(WInfo *pwinfo, int x1, int y1, int x2, int y2);
int wnd_destroy(WInfo *pwinfo, WWnd *pwin);
WWnd *wnd_create(WInfo *pwinfo, int ifd, int ofd, u32 attr, char *name, int x, int y, int w, int h);
WWnd *wnd_in_area(int x,int y);
void wnd_set_top(WInfo *pwinfo, WWnd *pwin);
void wnd_reset_hwnd(WInfo *pwinfo);
int wnd_init(WInfo *pwinfo);
int wnd_exit(WInfo *pwinfo);

#define wnd_for_each(pwinfo, it)	for(it = pwinfo->wtable; it < pwinfo->wtable + WND_MAX; it++)
#endif
