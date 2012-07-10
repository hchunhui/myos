#include <libc/libc.h>
#include <drv/input.h>
#include <drv/poll.h>

class A
{
public:
	int u;
	A()
	{
		printf("A start.\n");
		u = 1;
		printf("u=%d\n", u);
	}
	virtual void test()
	{
		printf("A\n");
	}
	~A()
	{
		printf("A end.\n");
	}
};

class D
{
public:
	D()
	{
		printf("D start.\n");
	}
	~D()
	{
		printf("D end.\n");
	}
};

class B:public A
{
public:
	B()
	{
		printf("B start.\n");
	}
	virtual void test()
	{
		printf("B\n");
	}
	~B()
	{
		printf("B end.\n");
	}
};

int get_utime()
{
	return usr_sys_call0(__NR_get_utime);
}

void matrix()
{
	// set_tty_attr(0x2);
	// int clock;
	// int y;
	// int x;
	// int i,count;
	// int rep;
	// srand(gettime());
	// for(rep = 0; rep < 100; rep++)
	// {
	// 	x=rand()%24+1;
	// 	y=(rand()%80+1)/2*2;
	// 	count=rand()%24+1;
	// 	for(i=0;i<count && x+i<=24;i++)
	// 	{
	// 		tty_goxy(x,y);
	// 		printf("%c",rand()%(127-32)+32);
	// 		for(clock=get_utime();get_utime()-clock<20;);
	// 		x++;
	// 	}
	// }
}

void test_pipe()
{
	printf("test pipe\n");
	int fd;
	char buf[32];
	int n, i;
	int stat;
	struct s_poll_event event;
	int fdp;
	fd = open("/dev/pipe/0", 0);
	if(fork() == 0)
	{
		printf("i am child\n");
		fdp = open("/dev/poll/0", 0);
		if(fdp == -1)
		{
			printf("error\n");
			exit(1);
		}
		event.fd = fd;
		event.type = POLL_TYPE_READ;
		printf("before ioctl\n");
		ioctl(fdp, POLL_CMD_SET, &event);
		fd = open("/dev/input/1", 0);
		event.fd = fd;
		ioctl(fdp, POLL_CMD_SET, &event);
		printf("after ioctl\n");
		for(;;)
		{
			n = read(fdp, &event, sizeof(struct s_poll_event));
			printf("after read fd=%d\n", event.fd);
			n = read(event.fd, buf, 32);
			printf("ch: read %d bytes\n", n);
			for(i = 0; i < n; i++)
				printf("%d %d\n", i, buf[i]);
		}
		printf("\n");
		exit(0);
	}
	else
	{
		printf("i am father\n");
		n = write(fd, "hahaha", 6);
		waitpid(-1, &stat, 0);
		printf("child die\n");
	}
}

D d;
int main()
{
	A a;
	B b;
	A *c;
	A *aa;
	//short freq;
	struct s_event event;
	int fd;
	a.test();
	b.test();
	c = &b;
	c->test();
	printf("-------------\n");
	aa = new A;
	printf("-------------\n");

	// printf("\ntestspk\n");
	// fd = open("/dev/speaker", 0);
	// freq = 300;
	// for(;;)
	// {
	// 	scanf("%d", &freq);
	// 	if(freq == 0)
	// 		break;
	// 	write(fd, &freq, 3);
	// }
	// close(fd);
	test_pipe();
	printf("out test_pipe()\n");
	fd = open("/dev/input/1", 0);
	if(fd == -1)
	{
		printf("die\n");
		for(;;);
	}
	printf("fd ok\n");
	for(;;)
	{
		read(fd, &event, sizeof(struct s_event));
		printf("tick=%d type=%d code=%x value=%d jj\n",
		       event.ticks,
		       event.type,
		       event.code,
		       event.value);
	}
	//printf("matrix\n");
	//matrix();
	return 0;
}
