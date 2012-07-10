/**
 * mouse.c
 * 鼠标驱动
 */
#include <type.h>
#include <unistd.h>
#include <libc/libc.h>
#include <string.h>
#include <libc/kstru.h>
#include "draw.h"
#include "msg.h"
#include "w.h"

u16 cursor[800*600];

void mouse_do_km_mouseact(WINFO *pwinfo, MSG *pmsg)
{
	pwinfo->mouse_lx = pwinfo->mouse_x;
	pwinfo->mouse_ly = pwinfo->mouse_y;
	pwinfo->mouse_lbtn = pwinfo->mouse_btn;
	pwinfo->mouse_x += pmsg->arg1;
	pwinfo->mouse_y += pmsg->arg2;
	pwinfo->mouse_btn = pmsg->arg3;
	if(pwinfo->mouse_x < 0) pwinfo->mouse_x = 0;
	if(pwinfo->mouse_y < 0) pwinfo->mouse_y = 0;
	if(pwinfo->mouse_x > info.x) pwinfo->mouse_x = info.x;
	if(pwinfo->mouse_y > info.y) pwinfo->mouse_y = info.y;
}

char mbmp[1024*1024];
static void cursor_init()
{	
	u16 *tmp = video;
	video = cursor;
	
	get_module("/cursor.bmp", mbmp);
	draw_bmp(0, 0, mbmp, 0, 0);
	
	video = tmp;
}

int mouse_init(WINFO *pwinfo)
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

int mouse_exit(WINFO *pwinfo)
{
	MSG msg;
	msg.type = KM_RESET_MOUSE;
	send( 0, &msg);
	return 0;
}


