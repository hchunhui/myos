#ifndef _MSG_H_
#define _MSG_H_
#include "wtype.h"
struct s_wmsg
{
	int type;
	long arg1;
	long arg2;
	long arg3;
	long arg4;
	long arg5;
};
typedef long WHandle;

#define WM_WCREATE		(1001)
#define WM_WREFRESH		(1002)
#define WM_WDESTROY		(1003)

#define UM_REPLY		(2001)
#define UM_KEY			(2002)
#define UM_MOUSE		(2003)
#define UM_EXIT			(2004)

#ifdef __cplusplus
extern "C" {
#endif 
int w_send(int fd, void *q, int n);
int w_recv(int fd, void *q, int n);

void w_wait_reply(int fd, long *retval1, long *retval2);
void w_send_wcreate(int ofd,
		    int attr,
		    int x, int y, int w, int h,
		    char *name);
void w_send_wrefresh(int ofd, WHandle hwnd, int x, int y ,int w, int h);
int w_send_wdestroy(int ofd, WHandle hwnd);

int w_connect(int *ppriv_fd, int *pifd, int *pofd);
int w_disconnect(int priv_fd, int ifd, int ofd);
#ifdef __cplusplus
}
#endif 

#endif
