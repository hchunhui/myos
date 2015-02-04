#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <os/unistd.h>
#include <drv/pipe.h>
#include <drv/poll.h>
#include <os/shm.h>
#include <string.h>
#include "w/draw.h"
#include "w/msg.h"
#include "kb_state.h"

int get_utime()
{
	return usr_sys_call0(__NR_get_utime);
}

static void poll_set_event(int pollfd, int fd, int type)
{
	struct s_poll_event event;
	event.fd = fd;
	event.type = type;
	if(ioctl(pollfd, POLL_CMD_SET, &event))
		printf ("ioctl error\n");
}

static void poll_unset_event(int pollfd, int fd)
{
	struct s_poll_event event;
	event.fd = fd;
	event.type = 0;
	if(ioctl(pollfd, POLL_CMD_UNSET, &event))
		printf ("ioctl error\n");
}

unsigned long buff = (1024*1024*1024);
DrawCanvas _canv;
DrawCanvas * const canv = &_canv;

long shm_key;
int priv_fd, ifd, ofd;
WHandle hwnd;

int x = 0;
int y = 0;
int btn = 0;
int time;
int score;

#define N 20
#define M 20
#define LEFT 1
#define UP 2
#define RIGHT 3
#define DOWN 4
#define APPLE 6
int data[N][M];
int headx, heady;
int tailx, taily;

int over;

void do_timer();
void game_init();

void do_paint()
{
	int i,j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			if(data[i][j] == 0)
				draw_fill_rect(canv, 15 * i , 15 + 15 * j, 15 * i + 15, 30 + 15 * j, RGB(31, 63, 31));
			else if(data[i][j] == APPLE)
				draw_fill_rect(canv, 15 * i , 15 + 15 * j, 15 * i + 15, 30 + 15 * j, RGB(31, 0, 0));
			else
				draw_fill_rect(canv, 15 * i , 15 + 15 * j, 15 * i + 15, 30 + 15 * j, RGB(0, 0, 31));
		}
	}
	//draw_fill_rect(0, 15, 15, 15, RGB(31,63,31));
	w_send_wrefresh(ofd, hwnd, 0 ,0 , 300, 315);
}

void new_apple()
{
	int x=rand()%N;
	int y=rand()%M;
	while(data[x][y] != 0)
	{
		x=rand()%N;
		y=rand()%M;
	}
	data[x][y] = APPLE;
}

void game_over()
{
	over = 1;
	char buf[100];
	sprintf(buf, "Snake time:%d score:%d Game Over     ", time, score);
	draw_string(canv, 0, 0, buf, 0);
	w_send_wrefresh(ofd, hwnd, 0, 0, 300, 15);
}

void show_title()
{
	char buf[100];
	if(over)
	{
		game_over();
		return;
	}
	sprintf(buf, "Snake time:%d score:%d (%4d,%4d) %s %s %s", time, score, x, y, 
	btn&1?"L":" ", btn&2?"R":" ", btn&4?"M":" ");
	draw_string(canv, 0, 0, buf, 0);
	w_send_wrefresh(ofd, hwnd, 0, 0, 300, 15);
}

void do_keypress(int key)
{
	int stat;
	int pstat;
	if(over && key == 'r')
	{
		game_init();
		return;
	}
	pstat = data[headx][heady];
	stat = pstat;
	switch(key)
	{
		case 'w':
			if(pstat != DOWN)
				stat = UP;
			break;
		case 'a':
			if(pstat != RIGHT)
				stat = LEFT;
			break;
		case 's':
			if(pstat != UP)
				stat = DOWN;
			break;
		case 'd':
			if(pstat != LEFT)
				stat = RIGHT;
			break;
		default:
			return;
	}
	data[headx][heady] = stat;
}

void print_data()
{
	int i;
	int j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			printf("%d",data[i][j]);
		if(i &1)printf("\n");
	}
	
}

void run()
{
	int hx, hy;
	int tx, ty;
	tx = tailx;
	ty = taily;
	switch(data[tailx][taily])
	{
		case LEFT:
			tx = (tailx + N - 1) % N;
			break;
		case UP:
			ty = (taily + M - 1) % M;
			break;
		case RIGHT:
			tx = (tailx + 1) % N;
			break;
		case DOWN:
			ty = (taily + 1) % M;
			break;
		default:
			exit(1);
	}

	hx = headx;
	hy = heady;
	switch(data[headx][heady])
	{
		case LEFT:
			hx = (headx + N - 1) % N;
			break;
		case UP:
			hy = (heady + M - 1) % M;
			break;
		case RIGHT:
			hx = (headx + 1) % N;
			break;
		case DOWN:
			hy = (heady + 1) % M;
			break;
		default:
			exit(1);
	}

	switch(data[hx][hy])
	{
		case APPLE:
			data[hx][hy] = data[headx][heady];
			headx = hx;
			heady = hy;
			score++;
			new_apple();
			break;
		case 0:
			data[hx][hy] = data[headx][heady];
			data[tailx][taily] = 0;
			headx = hx;
			heady = hy;
			tailx = tx;
			taily = ty;
			break;
		default:
			game_over();
			break;
	}
}

void do_timer()
{
	run();
	do_paint();
	show_title();
}

int destroy_window()
{
	long ret;
	w_send_wdestroy(ofd, hwnd);
	w_wait_reply(ifd, &ret, NULL);
	return ret;
}

void main_loop()
{
	WMsg msg;
	struct s_poll_event ev;
	int poll_fd;
	int tm_fd;
	int tick, t;

	poll_fd = open("/dev/poll/0", 0);
	tm_fd = open("/dev/timer/0", 0);
	tick = 10;
	write(tm_fd, &tick, sizeof(tick));
	poll_set_event(poll_fd, tm_fd, POLL_TYPE_READ);
	poll_set_event(poll_fd, ifd, POLL_TYPE_READ);

	for(;;)
	{
		if(read(poll_fd, &ev, sizeof(ev)) == -1)
			break;
		if(ev.fd == tm_fd)
		{
			write(tm_fd, &tick, sizeof(tick));
			read(tm_fd, &t, sizeof(t));
			if(!over)
			{
				time++;
				do_timer();
			}
		}
		else
		{
			w_recv(ifd, &msg, sizeof(msg));
			switch(msg.type)
			{
			case UM_KEY:
				if(!(msg.arg4 & KBS_BRK))
				{
					if(msg.arg2 == 'q')
						if(destroy_window())
							return;
					do_keypress(msg.arg2);
				}
				break;
			case UM_MOUSE:
				x = msg.arg2;
				y = msg.arg3;
				btn = msg.arg4;
				show_title();
				break;
			case UM_EXIT:
				if(destroy_window())
					return;
				break;
			}
		}
	}
}

void game_init()
{
	over = 0;
	score = 0;
	time = 0;
	memset(data, 0, sizeof(data));
	data[9][9] = LEFT;
	data[10][9] = LEFT;
	headx = 9;
	heady = 9;
	tailx = 10;
	taily = 9;
	new_apple();
}

int main()
{
	srand(get_utime());
	
	draw_init();
	draw_set_canvas(canv, (void *)buff);
	if(w_connect(&priv_fd, &ifd, &ofd))
		return -1;
	w_send_wcreate(ofd, 0, 250, 150, 300, 315, "Snake2");
	w_wait_reply(ifd, &hwnd, &shm_key);
	shm_at(shm_key, buff, SHM_RW);
	
	printf("hwnd: %x\n",hwnd);
	
	game_init();
	w_send_wrefresh(ofd, hwnd, 0 ,0 , 300, 315);
	
	main_loop();
	
	w_disconnect(priv_fd, ifd, ofd);
	shm_dt(shm_key, buff);
	printf("exit with exit code 0\n");
	return 0;
}
