#ifndef _W_H_
#define _W_H_
#include <os/type.h>
#include "draw.h"

typedef struct s_window
{
	char name[16];
	u32 attr;
	int x, y;
	int w, h;
	int pid;
	int use_timer;
	struct s_window *prev, *next;
	DrawCanvas bufcan;
	u16 *buffer;	//有未知越界
}WND;

#define WND_ATTR_EMPTY	0
#define WND_ATTR_USED	1

typedef struct s_winfo
{
	//wnd module
	WND *wtable;
	WND *hwnd;
	DrawCanvas *virt;
	
	//kb module
	int kb_ascii;
	u32 kb_aux;
	
	//mouse module
	DrawCanvas *cursor;
	int mouse_x;
	int mouse_y;
	int mouse_btn;
	int mouse_lx;
	int mouse_ly;
	int mouse_lbtn;
	int mouse_cx;
	int mouse_cy;
	WND *mouse_chwnd;
	int mouse_chwnd_x;
	int mouse_chwnd_y;
}WInfo;

#define max(x,y)	((x)>(y)?(x):(y))
#define min(x,y)	((x)<(y)?(x):(y))

void w_redraw(WInfo *pwinfo, int x1, int y1, int x2, int y2);
#endif
