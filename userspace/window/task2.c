#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <os/shm.h>
#include <os/unistd.h>
#include <drv/pipe.h>
#include "w/draw.h"
#include "w/msg.h"
#include "kb_state.h"

int priv_fd;
int ifd, ofd;

int get_utime()
{
	return usr_sys_call0(__NR_get_utime);
}

__u16 *buff = (void *)(1024*1024*1024);
DrawCanvas _canv;
DrawCanvas * const canv = &_canv;

long shm_key;
int destroy_window(WHandle hwnd)
{
	long ret;
	w_send_wdestroy(ofd, hwnd);
	w_wait_reply(ifd, &ret, NULL);
	return ret;
}

void main_loop()
{
	WMsg msg;
	WHandle hwnd;
	int x = 0;
	int y = 0;
	int btn = 0;
	for(;;)
	{
		w_recv(ifd, &msg, sizeof(WMsg));
		hwnd = msg.arg1;
		switch( msg.type )
		{
			case UM_KEY:
				if(!(msg.arg4 & KBS_BRK))
					if(msg.arg2 == 'q')
						if(destroy_window(hwnd))
							return;
				break;
			case UM_MOUSE:
				x = msg.arg2;
				y = msg.arg3;
				btn = msg.arg4;
				char buf[100];
				sprintf(buf,
					"Press Ctrl to move window. "
					"(%4d,%4d) %s %s %s",
					x, y, 
					btn&1?"L":" ",
					btn&2?"R":" ",
					btn&4?"M":" ");
				draw_string(canv, 0, 0, buf, 0);
				w_send_wrefresh(ofd, hwnd, 0, 0, 600, 15);
				break;
			case UM_EXIT:
				if(destroy_window(hwnd))
					return;
				break;
			default:
				break;
		}
	}
}

int main()
{
	int x,y;
	double z;
	WHandle hwnd;

	draw_init();
	draw_set_canvas(canv, buff);
	if(w_connect(&priv_fd, &ifd, &ofd))
		return -1;

	w_send_wcreate(ofd, 0, 0, 0, canv->y, canv->y, "abcdef");
	w_wait_reply(ifd, &hwnd, &shm_key);
	shm_at(shm_key, (unsigned long)buff, SHM_RW);
	
	printf("hwnd: %x\n",hwnd);
	for(x = 0; x < canv->y; x++)
	{
		for(y = 0; y < canv->y; y++)
		{
			double xx,yy;
			xx = ((double)x) * 3 * 3.14159 / canv->y;
			yy = ((double)y) * 3 * 3.14159 / canv->y;
			z=sin(xx+xx+yy+yy)*sin(2*xx*yy);
			buff[y*canv->x + x] = RGB(0,(int)(62 * (z + 1.01)), 0);
		}
	}
	
	w_send_wrefresh(ofd, hwnd, 0 ,0 , canv->y, canv->y);
	
	main_loop();

	w_disconnect(priv_fd, ifd, ofd);
	shm_dt(shm_key, (unsigned long)buff);
	printf("exit with exit code 0\n");
	return 0;
}

/*int main()
{
	int cpid;
	if((cpid=fork()) == 0)
	{
		int i;
		int ppid = getppid();
		int pid = getpid();
		MSG m;
		for(i=0;i<1000;i++)printf("a");
		m.type = 0;
		m.arg1 = ppid;
		m.arg2 = 0; //pid;
		for(i=0;i<10000;i++)
		{
			send(ppid, &m);
			m.arg2++;
		}
		for( i=0; i<10; i++)
			printf("child no block\n");
		return 0;
	}
	MSG m;
	int i;
	//for(i=0;i<1000;i++);
	//for(;recv( -1, &m, 0)==0;)
	//	printf("no block\n");
	
	for(;;)
	{
		i = recv( -1, &m, 1);
		//if(i==0)continue;
		//printf("cpid = %d\n",cpid);
		//printf("pid = %d\n",getpid());
		//printf("arg1 = %d\n",m.arg1);
		printf("arg2 = %d\n",m.arg2);
	}
	return 0;
}*/
/*int main()
{
	set_tty_attr(0x2);
	int clock;
	int y;
	int x;
	int i,count;
	srand(gettime());
	for(;;)
	{
		x=rand()%24+1;
		y=(rand()%80+1)/2*2;
		count=rand()%24+1;
		for(i=0;i<count && x+i<=24;i++)
		{
			tty_goxy(x,y);
			printf("%c",rand()%(127-32)+32);
			for(clock=get_utime();get_utime()-clock<3;);
			x++;
		}
	}
	return 0;
}*/
/*int main(int argc,char** argv)
{
	set_file_mode(STDOUT,0x2);
	printf("Hello World!\n");
	set_file_mode(STDOUT,0x3);
	printf("Now time:%d\n",gettime());
	int x=ttyctl(STDOUT,0,(7<<16)+56);
	printf("hehehe!");
	return 0;
}*/
