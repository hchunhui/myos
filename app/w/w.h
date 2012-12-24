#ifndef _W_H_
#define _W_H_
#include "wtype.h"
#include <os/type.h>
struct kb_state;

struct s_winfo
{
	//wnd module
	WWnd *wtable;
	WWnd *hwnd;
	DrawCanvas *virt;
	
	//kb module
	struct kb_state *kb;
	
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
	WWnd *mouse_chwnd;
	int mouse_chwnd_x;
	int mouse_chwnd_y;

	// w module
	int rx1, rx2, ry1, ry2;
	int need_redraw;
};

#define max(x,y)	((x)>(y)?(x):(y))
#define min(x,y)	((x)<(y)?(x):(y))

void w_redraw(WInfo *pwinfo, int x1, int y1, int x2, int y2);
#endif
