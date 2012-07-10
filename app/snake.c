#include <libc/libc.h>
#include "w/draw.h"

int w_pid;

void do_timer(HANDLE hwnd);

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

void w_timer(HANDLE hwnd,int val)
{
	MSG msg;
	msg.type = WM_WINDOW_TIMER;
	msg.arg1 = hwnd;
	msg.arg2 = val;
	send( w_pid, &msg);
}

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

void do_paint(HANDLE hwnd)
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
	w_refresh(hwnd, 0 ,0 , 300, 315);
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

void game_over(HANDLE hwnd)
{
	over = 1;
	char buf[100];
	sprintf(buf, "Snake time:%d score:%d Game Over     ", time, score);
	draw_string(canv, 0, 0, buf, 0);
	w_refresh(hwnd, 0, 0, 300, 15);
}

void show_title(HANDLE hwnd)
{
	char buf[100];
	if(over)
	{
		game_over(hwnd);
		return;
	}
	sprintf(buf, "Snake time:%d score:%d (%4d,%4d) %s %s %s", time, score, x, y, 
	btn&1?"L":" ", btn&2?"R":" ", btn&4?"M":" ");
	draw_string(canv, 0, 0, buf, 0);
	w_refresh(hwnd, 0, 0, 300, 15);
}

void do_kepress(HANDLE hwnd, int key)
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
	do_timer(hwnd);
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
				game_over(hwnd);
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
				game_over(hwnd);
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
				game_over(hwnd);
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
				game_over(hwnd);
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

void run(HANDLE hwnd)
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
				game_over(hwnd);
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
				game_over(hwnd);
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
				game_over(hwnd);
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
				game_over(hwnd);
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

void do_timer(HANDLE hwnd)
{
	run(hwnd);
	do_paint(hwnd);
	show_title(hwnd);
}


void main_loop()
{
	MSG msg;
	HANDLE hwnd;
	
	for(;recv( -1, &msg, 1);)
	{
		hwnd = msg.arg1;
		
		switch( msg.type&(~MSG_TYPE_BLOCK) )
		{
			case UM_KEYPRESS:
				if(msg.arg2 == 'q')
					if(w_destroy(hwnd))
						return;
				do_kepress(hwnd, msg.arg2);
				break;
			case UM_MOUSEACT:
				x = msg.arg2;
				y = msg.arg3;
				btn = msg.arg4;
				show_title(hwnd);
				break;
			case UM_EXIT:
				if(w_destroy(hwnd))
					return;
				break;
			case UM_TIMER:
				if((!over))
				{
					time++;
					do_timer(hwnd);
				}
			default:
				break;
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
	HANDLE hwnd;
	
	printf("enter window manager 's pid:\n");
	scanf("%d", &w_pid);
	srand(get_utime());
	
	draw_init();
	draw_set_canvas(canv, buff);
	
	hwnd = w_create(0, 250, 150, 300, 315, "Snake");
	
	printf("hwnd: %x\n",hwnd);
	
	game_init();
	w_refresh(hwnd, 0 ,0 , 300, 315);
	w_timer(hwnd, 1);
	
	main_loop();
	
	printf("exit with exit code 0\n");
	return 0;
}

