/**
 * kb.c
 * 键盘驱动
 */
#include <libc/libc.h>
#include "msg.h"
#include "kb.h"

void kb_do_km_keypress(WInfo *pwinfo, MSG *pmsg)
{
	pwinfo->kb_ascii = pmsg->arg1;
	pwinfo->kb_aux = pmsg->arg2;
}

int kb_init(WInfo *pwinfo)
{
	MSG msg;
	pwinfo->kb_aux = 0;
	msg.type = KM_USE_KB | MSG_TYPE_BLOCK;
	send( 0, &msg);
	return 0;
}

int kb_exit(WInfo *pwinfo)
{
	MSG msg;
	msg.type = KM_RESET_KB | MSG_TYPE_BLOCK;
	send( 0, &msg);
	return 0;
}


