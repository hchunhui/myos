#ifndef _W_H_
#define _W_H_
#include <type.h>

typedef struct s_window
{
	char name[16];
	u32 attr;
	int x, y;
	int w, h;
	int pid;
	int use_timer;
	struct s_window *prev, *next;
	u16 *buffer;	//有未知越界
}WND;

#define WND_ATTR_EMPTY	0
#define WND_ATTR_USED	1

typedef struct s_winfo
{
	//wnd module
	WND *wtable;
	WND *hwnd;
	u16 *virtual;
	
	//kb module
	int kb_ascii;
	u32 kb_aux;
	
	//mouse module
	u16 *cursor;
	int mouse_x;
	int mouse_y;
	int mouse_btn;
	int mouse_lx;
	int mouse_ly;
	int mouse_lbtn;
	int mouse_cx;
	int mouse_cy;
	WND *mouse_chwnd;
}WINFO;

#define max(x,y)	((x)>(y)?(x):(y))
#define min(x,y)	((x)<(y)?(x):(y))

void w_redraw(WINFO *pwinfo, int x1, int y1, int x2, int y2);
#endif
