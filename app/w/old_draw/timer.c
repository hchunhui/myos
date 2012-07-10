#include <type.h>
#include <unistd.h>
#include <libc/libc.h>
#include <string.h>
#include <libc/kstru.h>
#include "draw.h"
#include "msg.h"
#include "w.h"

extern WND *hwnd;
extern WND wtable[8];

void timer_do_km_timer(WINFO *pwinfo, MSG *pmsg)
{
	
}

int timer_init(WINFO *pwinfo)
{
	MSG msg;
	msg.type = KM_SET_TIMER | MSG_TYPE_BLOCK;
	msg.arg1 = 20;
	send( 0, &msg);
	return 0;
}

int timer_exit(WINFO *pwinfo)
{
	MSG msg;
	msg.type = KM_RESET_TIMER;
	send( 0, &msg);
	return 0;
}

