#ifndef _KSTRU_H
#define _KSTRU_H
#include <os/type.h>
struct myos_graph_info
{
	int x;
	int y;
	int depth;
	void *base_addr;
};

typedef struct s_msg
{
	int type;
	int pid;
	int arg1;
	int arg2;
	int arg3;
	int arg4;
	int arg5;
	struct s_msg *next;
} MSG;
typedef u32	HANDLE;
#define MSG_MAX 32
#define MSG_TYPE_BLOCK (1<<0)

//kernel message
#define KM_USE_KB		(1 <<1)
#define KM_USE_MOUSE		(2 <<1)
#define KM_RESET_KB		(3 <<1)
#define KM_RESET_MOUSE		(4 <<1)

#define KM_KEYPRESS		(5 <<1)
#define KM_MOUSEACT		(6 <<1)

#define KM_SET_TIMER		(7 <<1)
#define KM_RESET_TIMER		(8 <<1)
#define KM_TIMER		(9 <<1)

#define KM_COPYDATA		(10 <<1)

//user message

//to w
#define WM_WINDOW_CREATE	(1001<<1)
#define WM_WINDOW_REFRESH	(1002<<1)
#define WM_WINDOW_DESTROY	(1003<<1)
#define WM_WINDOW_TIMER		(1004<<1)

//to u
#define UM_REPLY		(2001<<1)
#define UM_KEYPRESS		(2002<<1)
#define UM_MOUSEACT		(2003<<1)
#define UM_EXIT			(2004<<1)
#define UM_TIMER		(2005<<1)
#define UM_KEYUP		(2006<<1)
#endif
