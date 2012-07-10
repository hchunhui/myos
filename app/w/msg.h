#ifndef _MSG_H_
#define _MSG_H_
#include "w.h"
#include "wnd.h"

void send_km_copydata(int len, int pid, void *sptr, void *dptr);
void send_um_reply(int pid, int retval);
void send_um_reply2(int pid, int retval1, int retval2);
void send_um_exit(WND *hwnd);

#endif
