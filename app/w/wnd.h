#ifndef _WND_H_
#define _WND_H_
#include "w.h"
#define WIN_START_ADDR	(512*1024*1024)
#define WIN_LEN		(1024*1024)

#define WND_MAX	8

void wnd_list_del(WND **pfirst, WND *pwin);
void wnd_list_add_first(WND **pfirst, WND *pwin);
void __wnd_redraw(WInfo *pwinfo, int x1, int y1, int x2, int y2);
int wnd_destroy(WInfo *pwinfo, WND *pwin);
WND *wnd_create(WInfo *pwinfo, int pid, u32 attr, char *name, int x, int y, int w, int h);
WND *wnd_in_area(int x,int y);
void wnd_set_top(WInfo *pwinfo, WND *pwin);
void wnd_reset_hwnd(WInfo *pwinfo);
int wnd_init(WInfo *pwinfo);
int wnd_exit(WInfo *pwinfo);

#define wnd_for_each(pwinfo, it)	for(it = pwinfo->wtable; it < pwinfo->wtable + WND_MAX; it++)
#endif
