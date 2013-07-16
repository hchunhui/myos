/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Graph.h"
#include "GraphMan.h"
#include "Sound.h"
#include "SoundMan.h"
#include "Game.h"
#include "Control.h"

CGraph gGraph;
CGraphMan gGraphMan;
CSound gSound;
CSoundMan gSoundMan;
CControl gControl;
CGame gGame;

#ifndef MYOS
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	int KeyState;
	switch(uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_PAINT://刷新显示
		BeginPaint(hWnd,&ps);
		BitBlt(ps.hdc,0,0,288,256,gGraph.GetMemDC(),0,0,SRCCOPY);
		EndPaint(hWnd,&ps);
		break;
	case WM_TIMER:
		gControl.Clock();//向游戏控制器发送时钟信号
		break;
	case WM_KEYDOWN:
	case WM_KEYUP:
		//检查各个按键的状态
		KeyState=0;
		if(GetKeyState('W')&0x80000000)KeyState|=1<<0;
		if(GetKeyState('S')&0x80000000)KeyState|=1<<1;
		if(GetKeyState('A')&0x80000000)KeyState|=1<<2;
		if(GetKeyState('D')&0x80000000)KeyState|=1<<3;
		if(GetKeyState('J')&0x80000000)KeyState|=1<<4;
		if(GetKeyState('K')&0x80000000)KeyState|=1<<5;
		if(GetKeyState(VK_RETURN)&0x80000000)KeyState|=1<<6;
		gControl.KeyChanged(KeyState);
		break;
	default:
		return DefWindowProc(hWnd,uMsg,wParam,lParam);
	}
	return 0;
}

int main()
{
	//从资源文件中加载声音数据
	HMODULE hModule=GetModuleHandle(NULL);
	HRSRC hrSrc;
	hrSrc=FindResource(hModule,"BackMusic1","WAVE");
	BackMusic_Len[0]=SizeofResource(hModule,hrSrc);
	BackMusic_Sound[0]=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"BackMusic2","WAVE");
	BackMusic_Len[1]=SizeofResource(hModule,hrSrc);
	BackMusic_Sound[1]=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"AttackDemon","WAVE");
	AttackDemon_Len=SizeofResource(hModule,hrSrc);
	AttackDemon_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"AttackMario","WAVE");
	AttackMario_Len=SizeofResource(hModule,hrSrc);
	AttackMario_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"Block","WAVE");
	Block_Len=SizeofResource(hModule,hrSrc);
	Block_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"Bullet","WAVE");
	Bullet_Len=SizeofResource(hModule,hrSrc);
	Bullet_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"Coin","WAVE");
	Coin_Len=SizeofResource(hModule,hrSrc);
	Coin_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"Death","WAVE");
	Death_Len=SizeofResource(hModule,hrSrc);
	Death_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"EatFlower","WAVE");
	EatFlower_Len=SizeofResource(hModule,hrSrc);
	EatFlower_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"FlowerRise","WAVE");
	FlowerRise_Len=SizeofResource(hModule,hrSrc);
	FlowerRise_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"Jump","WAVE");
	Jump_Len=SizeofResource(hModule,hrSrc);
	Jump_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"KillDemon","WAVE");
	KillDemon_Len=SizeofResource(hModule,hrSrc);
	KillDemon_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));
	hrSrc=FindResource(hModule,"BrickBroken","WAVE");
	BrickBroken_Len=SizeofResource(hModule,hrSrc);
	BrickBroken_Sound=(char*)LockResource(LoadResource(hModule,hrSrc));

	//注册一个窗口类
	WNDCLASS wc;
	wc.cbClsExtra=0;
	wc.cbWndExtra=0;
	wc.hbrBackground=(HBRUSH)GetStockObject(NULL_BRUSH);
	wc.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc.hInstance=GetModuleHandle(NULL);
	wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wc.lpfnWndProc=WndProc;
	wc.lpszClassName="MarioWnd";
	wc.lpszMenuName=NULL;
	wc.style=0;
	RegisterClass(&wc);

	//创建主窗口
	HWND hMainWnd=CreateWindow("MarioWnd","采磨菇",WS_OVERLAPPED|WS_SYSMENU,CW_USEDEFAULT,CW_USEDEFAULT,288,256,NULL,NULL,wc.hInstance,NULL);
	//调整主窗口客户区的大小为288*256
	RECT rect;
	GetClientRect(hMainWnd,&rect);
	rect.right=288+(288-rect.right);
	rect.bottom=256+(256-rect.bottom);
	SetWindowPos(hMainWnd,NULL,0,0,rect.right,rect.bottom,SWP_NOZORDER|SWP_NOMOVE);
	//显示主窗口
	ShowWindow(hMainWnd,SW_SHOW);
	
	//将各个类连接起来
	gGraph.Init(hMainWnd);
	gGraphMan.SetGraph(&gGraph);
	gGraphMan.SetGame(&gGame);
	gSound.Init();
	gSoundMan.SetSound(&gSound);
	gControl.SetGraph(&gGraphMan);
	gControl.SetGame(&gGame);
	gGame.SetSound(&gSoundMan);

	//启动定时器
	SetTimer(hMainWnd,1,50,NULL);

	//进入消息循环
	MSG msg;
	while(GetMessage(&msg,NULL,NULL,NULL))
	{
		DispatchMessage(&msg);
	}

	gGraph.UnInit();

	return 0;
}
#else
__u16 *buff = (__u16 *)(1024*1024*1024);
DrawCanvas _canv;
DrawCanvas * const canv = &_canv;

long shm_key;
int priv_fd, ifd, ofd;
WHandle hwnd;

static void poll_set_event(int pollfd, int fd, int type)
{
	struct s_poll_event event;
	event.fd = fd;
	event.type = type;
	if(ioctl(pollfd, POLL_CMD_SET, &event))
		printf ("ioctl error\n");
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
	char buf[100];
	WMsg msg;
	struct s_poll_event ev;
	int poll_fd;
	int tm_fd;
	int tick, t;

	int x = 0;
	int y = 0;
	int btn = 0;
	int KeyState;

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
			gControl.Clock();
			w_send_wrefresh(ofd, hwnd, 0 ,0 , 288, 256);
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
				}
				KeyState = 0;
				if(msg.arg2 == 'w')KeyState|=1<<0;
				if(msg.arg2 == 's')KeyState|=1<<1;
				if(msg.arg2 == 'a')KeyState|=1<<2;
				if(msg.arg2 == 'd')KeyState|=1<<3;
				if(msg.arg2 == 'j')KeyState|=1<<4;
				if(msg.arg2 == 'k')KeyState|=1<<5;
				if(msg.arg2 == '\n')KeyState|=1<<6;
				if(msg.arg4 & KBS_BRK)
					gControl.KeyUp(KeyState);
				else
					gControl.KeyDown(KeyState);
				break;
			case UM_MOUSE:
				x = msg.arg2;
				y = msg.arg3;
				btn = msg.arg4;
				sprintf(buf,
					"Press Ctrl to move window."
					"(%4d,%4d) %s %s %s",
					x, y,
					btn&1?"L":" ",
					btn&2?"R":" ",
					btn&4?"M":" ");
				draw_string(canv, 0, 0, buf, 0);
				w_send_wrefresh(ofd, hwnd, 0, 0, 600, 15);
				break;
			case UM_EXIT:
				if(destroy_window())
					return;
				break;
			}
		}
	}
}

int main(int argc, char **argv)
{
	draw_init();
	draw_set_canvas(canv, buff);
	if(w_connect(&priv_fd, &ifd, &ofd))
		return -1;
	w_send_wcreate(ofd, 0, 0, 0, 288, 256, "Super Mario");
	w_wait_reply(ifd, &hwnd, &shm_key);
	shm_at(shm_key, (unsigned long)buff, SHM_RW);
	
	printf("hwnd: %lx\n", hwnd);
	
	w_send_wrefresh(ofd, hwnd, 0 ,0 , 288, 256);
	
	//将各个类连接起来
	gGraph.Init(hwnd);
	gGraphMan.SetGraph(&gGraph);
	gGraphMan.SetGame(&gGame);
	gSound.Init();
	gSoundMan.SetSound(&gSound);
	gControl.SetGraph(&gGraphMan);
	gControl.SetGame(&gGame);
	gGame.SetSound(&gSoundMan);

	main_loop();

	w_disconnect(priv_fd, ifd, ofd);
	shm_dt(shm_key, (unsigned long)buff);	
	printf("exit with exit code 0\n");
	return 0;
}
#endif
