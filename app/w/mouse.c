/**
 * mouse.c
 * 鼠标驱动
 */
#include <libc/libc.h>
#include "draw.h"
#include "msg.h"
#include "w.h"

u16 curmem[12*20 + 40];
DrawCanvas _cursor;
DrawCanvas * const cursor = &_cursor;

void mouse_do_km_mouseact(WInfo *pwinfo, MSG *pmsg)
{
	pwinfo->mouse_lx = pwinfo->mouse_x;
	pwinfo->mouse_ly = pwinfo->mouse_y;
	pwinfo->mouse_lbtn = pwinfo->mouse_btn;
	pwinfo->mouse_x += pmsg->arg1;
	pwinfo->mouse_y += pmsg->arg2;
	pwinfo->mouse_btn = pmsg->arg3;
	if(pwinfo->mouse_x < 0) pwinfo->mouse_x = 0;
	if(pwinfo->mouse_y < 0) pwinfo->mouse_y = 0;
	if(pwinfo->mouse_x > pwinfo->virt->x) pwinfo->mouse_x = pwinfo->virt->x;
	if(pwinfo->mouse_y > pwinfo->virt->y) pwinfo->mouse_y = pwinfo->virt->y;
}

char mbmp[10*1024];
static void cursor_init()
{
	cursor->video = curmem;
	cursor->x = 12;
	cursor->y = 20;
	cursor->depth = 16;
	
	get_module("/cursor.bmp", mbmp);
	
	draw_bmp(cursor, 0, 0, mbmp, 0, 0);
}

int mouse_init(WInfo *pwinfo)
{
	MSG msg;
	
	msg.type = KM_USE_MOUSE | MSG_TYPE_BLOCK;
	send( 0, &msg);
	
	cursor_init();
	pwinfo->cursor = cursor;
	
	pwinfo->mouse_x = 400;
	pwinfo->mouse_y = 300;
	return 0;
}

int mouse_exit(WInfo *pwinfo)
{
	MSG msg;
	msg.type = KM_RESET_MOUSE;
	send( 0, &msg);
	return 0;
}


