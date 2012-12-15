#include <libc/libc.h>
#include <drv/pipe.h>
#include <drv/poll.h>
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

u16 *buff = (void *)(1024*1024*1024);
DrawCanvas _canv;
DrawCanvas * const canv = &_canv;

long shm_key;
int priv_fd, ifd, ofd;
WHandle hwnd;

int x = 0;
int y = 0;
int btn = 0;
int time = 0;
int score = 0;

#define N 20
#define M 20
#define LEFT 1
#define UP 2
#define RIGHT 3
#define DOWN 4
#define TAIL 5
#define APPLE 6
int data[N][M];
int headx, heady;
int over = 0;
int skip = 0;

void do_timer();

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

void do_kepress(int key)
{
	int stat;
	int stat1;
	int dir;
	int nx;
	int ny;
	if(over)return;
	switch(key)
	{
		case 'w':
			stat = UP;
			stat1 = DOWN;
			break;
		case 'a':
			stat = LEFT;
			stat1 = RIGHT;
			break;
		case 's':
			stat = DOWN;
			stat1 = UP;
			break;
		case 'd':
			stat = RIGHT;
			stat1 = LEFT;
			break;
		default:
			return;
	}
	if( data[headx][heady] == stat || data[headx][heady] == stat1) 
		return;
	do_timer();
	nx = headx;
	ny = heady;
	skip = 1; //skip next move
	if( data[headx][heady] == LEFT || data[headx][heady] == UP) dir =1 ; //right or down
	else dir = -1;
	
	switch(stat)
	{
		case LEFT:
			if( data[(nx - 1 + N) % N][(ny - dir + M) % M] == APPLE)
			{
				score++;
				new_apple();
			}
			else if( data[(nx - 1 + N) % N][(ny - dir + M) % M] != 0)
			{
				game_over();
				return;
			}
			data[nx][ny] = 0;
			data[(nx - 1 + N) % N][(ny - dir + M) % M] = RIGHT;
			headx = (nx - 1 + N) % N;
			heady = (ny - dir + M) % M;
			break;
		case UP:
			if( data[(nx - dir + N) % N][(ny - 1 + M) % M] == APPLE)
			{
				score++;
				new_apple();
			}
			else if( data[(nx - dir + N) % N][(ny - 1 + M) % M] != 0)
			{
				game_over();
				return;
			}
			data[nx][ny] = 0;
			data[(nx - dir + N) % N][(ny - 1 + M) % M] = DOWN;
			headx = (nx - dir + N) % N;
			heady = (ny - 1 + M) % M;
			break;
		case RIGHT:
			if( data[(nx + 1 + N) % N][(ny - dir + M) % M] == APPLE)
			{
				score++;
				new_apple();
			}
			else if( data[(nx + 1 + N) % N][(ny - dir + M) % M] != 0)
			{
				game_over();
				return;
			}
			data[nx][ny] = 0;
			data[(nx + 1 + N) % N][(ny - dir + M) % M] = LEFT;
			headx = (nx + 1 + N) % N;
			heady = (ny - dir + M) % M;
			break;
		case DOWN:
			if( data[(nx - dir + N) % N][(ny + 1) % M] == APPLE)
			{
				score++;
				new_apple();
			}
			else if( data[(nx - dir + N) % N][(ny + 1) % M] != 0)
			{
				game_over();
				return;
			}
			data[nx][ny] = 0;
			data[(nx - dir + N) % N][(ny + 1) % M] = UP;
			headx = (nx - dir + N) % N;
			heady = (ny + 1) % M;
			break;
	}
	
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
	int nx, ny, lastx, lasty;
	nx = headx;
	ny = heady;
	int eat=0;
	//print_data();
	if(skip)
	{
		skip = 0;
		return;
	}
	switch(data[nx][ny])
	{
		case LEFT:
			if( data[(nx + 1) % N][ny] == APPLE)
			{
				score++;
				new_apple();
				eat = 1;
			}
			else if( data[(nx + 1) % N][ny] != 0)
			{
				game_over();
				return;
			}
			data[(nx + 1) % N][ny] = LEFT;
			headx = (nx + 1) % N;
			heady = ny;
			break;
		case UP:
			if( data[nx][(ny + 1) % M]  == APPLE)
			{
				score++;
				new_apple();
				eat = 1;
			}
			else if( data[nx][(ny + 1) % M] != 0)
			{
				game_over();
				return;
			}
			data[nx][(ny + 1) % M] = UP;
			headx = nx;
			heady = (ny + 1) % M;
			break;
		case RIGHT:
			if( data[(nx - 1 + N) % N][ny]  == APPLE)
			{
				score++;
				new_apple();
				eat = 1;
			}
			else if( data[(nx - 1 + N) % N][ny] != 0)
			{
				game_over();
				return;
			}
			data[(nx - 1 + N) % N][ny] = RIGHT;
			headx = (nx - 1 + N) % N;
			heady = ny;
			break;
		case DOWN:
			if( data[nx][(ny - 1 + M) % M]  == APPLE)
			{
				score++;
				new_apple();
				eat = 1;
			}
			else if( data[nx][(ny - 1 + M) % M] != 0)
			{
				game_over();
				return;
			}
			data[nx][(ny - 1 + M) % M] = DOWN;
			headx = nx;
			heady = (ny - 1 + M) % M;
			break;
	}
	//print_data();
	if(eat)return;
	while(data[nx][ny] != TAIL)
	{
		lastx=nx;
		lasty=ny;
		printf("x %d %d %d %d\n",time, nx, ny, data[nx][ny]);
		switch(data[nx][ny])
		{
			case LEFT:
				nx= nx - 1 + N;
				nx %= N;
				break;
			case UP:
				ny= ny - 1 + M;
				ny %= M;
				break;
			case RIGHT:
				nx++;
				nx %= N;
				break;
			case DOWN:
				ny++;
				ny %= M;
				break;
			default:
				printf("panic1\n");
				for(;;);
				break;
		}
	}
	data[nx][ny] = 0;
	data[lastx][lasty] = TAIL;
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
					do_kepress(msg.arg2);
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
	memset(data, 0, sizeof(data));
	data[9][9] = TAIL;
	data[10][9] = LEFT;
	headx = 10;
	heady = 9;
	new_apple();
}

int main()
{
	srand(get_utime());
	
	draw_init();
	draw_set_canvas(canv, buff);
	if(w_connect(&priv_fd, &ifd, &ofd))
		return -1;
	w_send_wcreate(ofd, 0, 250, 150, 300, 315, "Snake");
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
