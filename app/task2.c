#include <libc/libc.h>
#include "w/draw.h"

int w_pid;

int get_utime()
{
	return usr_sys_call0(__NR_get_utime);
}

void pause()
{
	usr_sys_call0(__NR_pause);
}

double sin(double x)
{
	double ret;
	asm (
	"fldl %1\n\t"
	"fsin\n\t"
	"fstpl %0"
	:"=m"(ret)
	:"m"(x)
	);
	return ret;
}

double cos(double x)
{
	double ret;
	asm (
	"fldl %1\n\t"
	"fcos\n\t"
	"fstpl %0"
	:"=m"(ret)
	:"m"(x)
	);
	return ret;
}

u16 *buff = (void *)(1024*1024*1024);
DrawCanvas _canv;
DrawCanvas * const canv = &_canv;

int shm_key;

HANDLE w_create(int attr, int x, int y, int w, int h, char *name)
{
	MSG msg;
	msg.type = WM_WINDOW_CREATE;
	msg.arg1 = attr;
	msg.arg2 = (x << 16) | y;
	msg.arg3 = (w << 16) | h;
	msg.arg4 = (HANDLE) name;
	msg.arg5 = strlen(name) + 1;
	send( w_pid, &msg);
	do {
		recv( -1, &msg, 1);
	} while(msg.type != UM_REPLY);
	shm_key = msg.arg2;
	shm_at(shm_key, buff, SHM_RW);
	return msg.arg1;
}

void w_refresh(HANDLE hwnd, int x, int y ,int w, int h)
{
	MSG msg;
	msg.type = WM_WINDOW_REFRESH;
	msg.arg1 = hwnd;
	msg.arg2 = 0;
	msg.arg3 = (x << 16) | y;
	msg.arg4 = (w << 16) | h;
	send( w_pid, &msg);
}

int w_destroy(HANDLE hwnd)
{
	MSG msg;
	msg.type = WM_WINDOW_DESTROY;
	msg.arg1 = hwnd;
	send( w_pid, &msg);
	do {
		recv( -1, &msg, 1);
		printf("msg.type = %d\n",msg.type);
	} while(msg.type != UM_REPLY);
	
	shm_dt(shm_key, buff);
	return msg.arg1;
}

void main_loop()
{
	MSG msg;
	HANDLE hwnd;
	int x = 0;
	int y = 0;
	int btn = 0;
	int wcount = 1;
	for(;recv( -1, &msg, 1);)
	{
		hwnd = msg.arg1;
		
		switch( msg.type&(~MSG_TYPE_BLOCK) )
		{
			case UM_KEYPRESS:
				if(msg.arg2 == 'c')
				{
					if(w_create(0, x, y, 200, 250, "new"))
						wcount++;
				}
				if(msg.arg2 == 'q')
				{
					if(w_destroy(hwnd))
						return;
				}
				break;
			case UM_MOUSEACT:
				x = msg.arg2;
				y = msg.arg3;
				btn = msg.arg4;
				char buf[100];
				sprintf(buf, "Press Ctrl to move window. (%4d,%4d) %s %s %s", x, y, 
					btn&1?"L":" ", btn&2?"R":" ", btn&4?"M":" ");
				draw_string(canv, 0, 0, buf, 0);
				w_refresh(hwnd, 0, 0, 600, 15);
				break;
			case UM_EXIT:
				if(w_destroy(hwnd))
					wcount--;
				printf("now wcount = %d\n", wcount);
				if(wcount == 0)
					return;
				break;
			default:
				break;
		}
		//pause();
		
		/*int i=0;
		int x,y;
		u16 color;
		for(i=0;i<10;i++)
		{
			x = rand()%130;
			y = rand()%160;
			color =rand();
			buff[y*800 + x] = color;
		}
		w_refresh(mhwnd, buff);*/
	}
}

int main()
{
	int x,y;
	double z;
	HANDLE hwnd;
	
	printf("enter window manager 's pid:\n");
	scanf("%d", &w_pid);
	
	draw_init();	
	draw_set_canvas(canv, buff);
	
	hwnd = w_create(0, 0, 0, canv->y, canv->y, "abcdef");
	
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
	
	w_refresh(hwnd, 0 ,0 , canv->y, canv->y);
	
	main_loop();
	
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
