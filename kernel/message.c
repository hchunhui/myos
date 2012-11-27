#include <os/task.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/unistd.h>
#include <libc/kstru.h>
#include <os/asm.h>
#include <os/message.h>
#include <os/arch_config.h>
#include <os/mm.h>

static int use_kb_pid;
static int use_mouse_pid;
static int use_timer_pid;

int timer;
int timer_long;

static void do_copydata(MSG *m)
{
/*
	arg1: 长度
	arg2: 原进程pid
	arg4: 原进程指针
	arg5: current进程指针
*/
	int len;
	int src_pid, des_pid;
	void *src_ptr, *des_ptr;
	
	void *buffer = (void *) message_buffer;
	len = m->arg1;
	src_pid = m->arg2;
	src_ptr = (void *)m->arg4;
	des_ptr = (void *)m->arg5;
	des_pid = current->pid;
	
	if(len > message_buffer_len)
		panic("do_copydata: data too long!");
	
	mm_change_page( src_pid );
	memcpy(buffer, src_ptr, len);
	mm_change_page( des_pid );
	memcpy(des_ptr, buffer, len);
}

static int do_send_to_kernel(MSG *m)
{
	switch(m->type&(~MSG_TYPE_BLOCK))
	{
		case KM_USE_KB:
			use_kb_pid = current->pid;		
			break;
		case KM_USE_MOUSE:
			use_mouse_pid = current->pid;
			break;
		case KM_RESET_KB:
			use_kb_pid = 0;
			break;
		case KM_RESET_MOUSE:
			use_mouse_pid = 0;
			break;
		case KM_SET_TIMER:
			use_timer_pid = current->pid;
			timer_long = m->arg1;
			timer = timer_long;
			break;
		case KM_RESET_TIMER:
			use_timer_pid = 0;
			break;
		case KM_COPYDATA:
			do_copydata(m);
			break;
		default:
			panic("do_send_to_kernel");
			break;
	}
	return 0;
}

int do_send_to_user(MSG *m)
{
	int pid_to = 0;
	switch(m->type)
	{
		case KM_KEYPRESS:
			pid_to = use_kb_pid;
			//printk("do_send_to_user: will send to pid %d\n",pid_to);
			break;
		case KM_MOUSEACT:
			pid_to = use_mouse_pid;
			break;
		case KM_TIMER:
			pid_to = use_timer_pid;
			break;
		default:
			panic("do_send_to_user");
	}
	if(pid_to == 0) return -1;
	return do_send(pid_to, m, 1);
}

int do_send(int pid_to, MSG *m,int is_kernel)	//是否阻塞由msg决定
{
	int nr;
	MSG *msg;
	struct s_task *task_to;
	
	if(pid_to == 0)
		return do_send_to_kernel(m);
	nr = task_pid_hash( pid_to );
	task_to = task + nr;
	
	msg = kmalloc(sizeof(MSG));
	
	memcpy(msg, m, sizeof(MSG));
	if(is_kernel)
		msg->pid = 0;
	else
		msg->pid = current->pid;
	msg->next = NULL;
	
	if( !task_to->msg_count)
	{
		if( task_to->msg_list || task_to->msg_last )
			panic("sys_send error 1");
		task_to->msg_list = msg;
		task_to->msg_last = msg;
		task_to->msg_count++;
	}
	else
	{
		if( task_to->msg_count == MSG_MAX )
		{
			//丢弃消息不是一个好主意
			//丢弃最早的消息
			MSG *firstm;
			firstm = task_to->msg_list;
			
			task_to->msg_list = firstm->next;
			kfree(firstm);
			task_to->msg_count--;
			printk("do_send: message lost(%d to %d, type %d)\n",
			       msg->pid,
			       pid_to,
			       msg->type);
		}
		
		task_to->msg_last->next = msg;
		task_to->msg_last = msg;
		task_to->msg_count++;
	}
	
	task_set_signal(task_to, SIGSEND);	//tell recv
	
	if(msg->type&MSG_TYPE_BLOCK && (!is_kernel) )
	{
		while(!(current->signal&SIGRECV))
		{
			current->state = TASK_STAT_BLOCK;
			task_sched();	//让出CPU
		}
		task_remove_signal(current, SIGRECV);
	}
	
	return 0;
}

int do_recv(int pid_from, MSG *m, int block)
{
	if( pid_from == -1)	//接收任意进程消息
	{
		rep_recv:
		if(current->msg_count)
		{
			memcpy(m, current->msg_list, sizeof(MSG));
			
			kfree(current->msg_list);
			current->msg_list = m->next;
			current->msg_count--;
			if( current->msg_count == 0)
				current->msg_last = NULL;
			m->next = NULL;
			
			if(m->type&MSG_TYPE_BLOCK)
			{
				int nr;
				struct s_task *task_from;
				nr = task_pid_hash(m->pid);
				task_from = task + nr;
				task_set_signal(task_from , SIGRECV);	//tell send
			}
			if( current->msg_count == 0)
				task_remove_signal(current, SIGSEND);
			return 1;
		}
		//此时msg_count == 0
		if(block)
		{
			while(!(current->signal&SIGSEND))
			{
				current->state = TASK_STAT_BLOCK;
				task_sched();			//让出CPU
			}
			goto rep_recv;
		}
	}
	else
	{
		return -1;
	}
	return 0;
}

void message_init(struct s_task *ptask)
{
	ptask->msg_list = NULL;
	ptask->msg_last = NULL;
	ptask->msg_count = 0;
}

void message_exit(struct s_task *ptask)
{
	MSG *p;
	while(ptask->msg_count)
	{
		if(!ptask->msg_list)
			panic("message_exit: some bug.");
		p = ptask->msg_list;
		ptask->msg_list = p->next;
		kfree(p);
		ptask->msg_count--;
	}
	if(ptask->msg_list)
		panic("message_exit: some bug2.");
	ptask->msg_last = NULL;
}

asmlinkage long sys_send(int pid_to, MSG *m)	//是否阻塞由msg决定
{
	return do_send(pid_to, m, 0);
}

asmlinkage long sys_recv(int pid_from, MSG *m, int block)
{
	return do_recv(pid_from, m, block);
}
