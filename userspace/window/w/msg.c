/**
 * msg.c
 * 消息发送
 */
#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <drv/pipe.h>
#include "msg.h"

int w_send(int fd, const void *q, int n)
{
	int m;
	const char *p = q;
	while(n)
	{
		m = write(fd, p, n);
		if(m < 0)
			return m;
		n -= m;
		p += m;
	}
	return 0;
}

int w_recv(int fd, void *q, int n)
{
	int m;
	char *p = q;
	while(n)
	{
		m = read(fd, p, n);
		if(m < 0)
			return m;
		n -= m;
		p += m;
	}
	return 0;
}

// for client

void w_wait_reply(int fd, long *retval1, long *retval2)
{
	WMsg msg;
	do {
		w_recv(fd, &msg, sizeof(WMsg));
	} while(msg.type != UM_REPLY);
	if(retval1)
		*retval1 = msg.arg1;
	if(retval2)
		*retval2 = msg.arg2;
}

void w_send_wcreate(int ofd,
		    int attr,
		    int x, int y, int w, int h,
		    const char *name)
{
	WMsg msg;
	msg.type = WM_WCREATE;
	msg.arg1 = attr;
	msg.arg2 = (x << 16) | y;
	msg.arg3 = (w << 16) | h;
	msg.arg4 = 0;
	msg.arg5 = strlen(name) + 1;
	w_send(ofd, &msg, sizeof(WMsg));
	w_send(ofd, name, strlen(name)+1);
	printf("w_send_wcreate ok.\n");
}

void w_send_wrefresh(int ofd, WHandle hwnd, int x, int y ,int w, int h)
{
	WMsg msg;
	msg.type = WM_WREFRESH;
	msg.arg1 = hwnd;
	msg.arg2 = 0;
	msg.arg3 = (x << 16) | y;
	msg.arg4 = (w << 16) | h;
	w_send(ofd, &msg, sizeof(WMsg));
}

void w_send_wdestroy(int ofd, WHandle hwnd)
{
	WMsg msg;
	msg.type = WM_WDESTROY;
	msg.arg1 = hwnd;
	w_send(ofd, &msg, sizeof(WMsg));
}

//about connect
int w_connect(int *ppriv_fd, int *pifd, int *pofd)
{
	int pub_fd;
	int priv_fd, ifd = -1, ofd = -1;
	pub_fd = open("/dev/pipe/2", 0);
	if(pub_fd < 0)
		return pub_fd;
	priv_fd = open("/dev/pipe/0", 0);
	if(priv_fd < 0)
	{
		close(pub_fd);
		return priv_fd;
	}
	while(ioctl(pub_fd, PIPE_CMD_SENDFD, priv_fd) < 0)
		;
	while(write(pub_fd, " ", 1) == 0)
		;
	write(priv_fd, "a", 1);
	ioctl(priv_fd, PIPE_CMD_RECVFD, &ifd);
	write(priv_fd, "A", 1);
	ioctl(priv_fd, PIPE_CMD_RECVFD, &ofd);
	close(pub_fd);
	*ppriv_fd = priv_fd;
	*pifd = ifd;
	*pofd = ofd;
	printf("connection establish\n");
	return 0;
}


int w_disconnect(int priv_fd, int ifd, int ofd)
{
	write(priv_fd, "X", 1);
	close(priv_fd);
	close(ifd);
	close(ofd);
	return 0;
}
