#include <type.h>
#include <unistd.h>
#include <libc/libc.h>
#include <string.h>
#include <libc/kstru.h>
#include "draw.h"
#include "w.h"

void send_km_copydata(int len, int pid, void *sptr, void *dptr)
{
	MSG msg;
	msg.type = KM_COPYDATA| MSG_TYPE_BLOCK;
	msg.arg1 = len;
	msg.arg2 = pid;
	msg.arg4 = (int) sptr;
	msg.arg5 = (int) dptr;
	send( 0, &msg);
}

void send_um_reply(int pid, int retval)
{
	MSG msg;
	msg.type = UM_REPLY;
	msg.arg1 = retval;
	send(pid, &msg);
}

void send_um_reply2(int pid, int retval1, int retval2)
{
	MSG msg;
	msg.type = UM_REPLY;
	msg.arg1 = retval1;
	msg.arg2 = retval2;
	send(pid, &msg);
}

void send_um_exit(WND *hwnd)
{
	MSG msg;
	msg.type = UM_EXIT;
	msg.arg1 = (HANDLE) hwnd;
	send( hwnd->pid, &msg);
}

