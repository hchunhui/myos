/**
 * timer.c
 * 时钟驱动
 */
#include <libc/libc.h>
#include "draw.h"
#include "msg.h"
#include "w.h"

void timer_do_km_timer(WInfo *pwinfo, MSG *pmsg)
{
	
}

int timer_init(WInfo *pwinfo)
{
	MSG msg;
	msg.type = KM_SET_TIMER | MSG_TYPE_BLOCK;
	msg.arg1 = 10;
	send( 0, &msg);
	return 0;
}

int timer_exit(WInfo *pwinfo)
{
	MSG msg;
	msg.type = KM_RESET_TIMER;
	send( 0, &msg);
	return 0;
}

