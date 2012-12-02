#include <os/type.h>
#include <os/arch_config.h>
#include <os/task.h>
#include <os/fork.h>
#include <lib/klib.h>
#include <os/mm.h>
#include <lib/string.h>
#include <os/unistd.h>
#include <os/asm.h>
#include <os/message.h>
#include <os/fpu.h>
#include <os/isr.h>
#include <os/vfs.h>

struct s_task *task;

int task_running;
static int pid_count = 0;

static struct s_task *idle_task;

int ticks;

int task_get_ticks()
{
	return ticks;
}

int task_get_utime()
{
	return current->utime;
}

int task_get_stime()
{
	return current->stime;
}

void task_set_signal(struct s_task *ptask, unsigned int signal_mask)
{
	ptask->signal |= signal_mask;
	if(ptask->state == TASK_STAT_BLOCK)
	{
		ptask->state = TASK_STAT_READY;
		//printk("wake up pid:%d\n", ptask->pid);
	}
}

void task_remove_signal(struct s_task *ptask, unsigned int signal_mask)
{
	ptask->signal &= ~signal_mask;
}

static struct s_task *choose_next(struct s_task *prev)
{
	int i;
	int next_running;
	int prio;
	int ready_count;

redo:
	prio = 0;
	next_running = -1;
	ready_count = 0;
	for(i = 0; i < NR_TASK; i++)
	{
		if(&task[i] != idle_task &&
		   task[i].state == TASK_STAT_READY)
		{
			ready_count++;
			if(prio < task[i].counter)
			{				
				next_running = i;
				prio = task[i].counter;
			}
		}
	}

	if(ready_count == 0) {
		/* 当前无非idle就绪任务 */
		return idle_task;
	}
	else if(prio == 0) {
		/* 有就绪任务，但时间片用光 */
		for(i = 0; i < NR_TASK; i++)
		{
			if(task[i].state != TASK_STAT_EMPTY)
				task[i].counter =
					(task[i].counter +
					 task[i].priority) >> 1;
		}
		idle_task->priority = 1;
		goto redo;
	}
	/* 有就绪任务，有时间片 */
	if(next_running == -1)
		panic("next_running == -1!");
	//printk("ne:%d  ", next_running);
	return &task[next_running];
}



void task_sched()
{
	struct s_task *prev, *next, *last;
	prev = current;
	next = choose_next(prev);

	if(prev != next) {
		task_running = next - task;
		switch_to(prev, next, last);
	}
}

void task_clock()
{
	ticks++;
	if(current->level > 1)
		current->stime++;
	else
		current->utime++;
	current->counter--;
	if(current->counter <= 0)
	{
		current->resched = 1;
		current->counter = 0;
	}
}

#define HASH_MAGIC	NR_TASK
int hash_table[HASH_MAGIC];

int task_pid_hash(int pid)
{
	int hash=pid % HASH_MAGIC;
	int i,j;
	if(hash_table[hash] == pid)
		return hash;
	for(i = 1; i < HASH_MAGIC; i++)
	{
		j = (i+hash) % HASH_MAGIC;
		if( hash_table[j] == pid )
			return j;
	}
	panic("can't find task (pid = %d)", pid);
}

int task_pid_hash_create(int pid)
{
	int hash=pid % HASH_MAGIC;
	int i,j;
	if(hash_table[hash] == 0)
	{
		hash_table[hash] = pid;
		return hash;
	}
	for(i = 1; i < HASH_MAGIC; i++)
	{
		j = (i+hash) % HASH_MAGIC;
		if( hash_table[j] == 0 )
		{
			hash_table[j] = pid;
			return j;
		}
	}
	panic("hash table is too short");
}

void task_pid_hash_remove(int pid)
{
	hash_table[task_pid_hash(pid)] = 0;
}

struct s_task *task_struct_alloc()
{
	int pid = pid_count++;
	int nr = task_pid_hash_create(pid);

	if(task[nr].state != TASK_STAT_EMPTY)
	{
		panic("bug, nr == %d, task[nr].state == %d\n",
		      nr,
		      task[nr].state);
	}

	task[nr].pid = pid;
	init_regs(get_user_regs(&task[nr]));
	task[nr].mm = NULL;
	
	return &task[nr];
}

struct s_task *task_struct_dup(struct s_task *task_old)
{
	int pid;
	struct s_task *task_new;
	task_new = task_struct_alloc();
	pid = task_new->pid;
	memcpy(task_new, task_old, sizeof(struct s_task));
	task_new->pid = pid;
	task_new->father = task_old;
	task_new->mm = NULL;
	return task_new;
}

void task_init()
{
	task = (void *)task_addr;
	ticks = 0;
	memset(task, 0, sizeof(struct s_task)*NR_TASK);

	/* 手工创建0号进程 */
	idle_task = task_struct_alloc();
	idle_task->state = TASK_STAT_READY;
	idle_task->priority = 2;
	idle_task->counter = 2;
	idle_task->father = NULL;
	idle_task->brk = kernel_brk;
	idle_task->stack_size = normal_stack_size;
	idle_task->level = 1;

	task_running = 0;
	arch_task_init(idle_task);
	mm_fork(idle_task, NULL, 0);
	message_init(current);
	fpu_init(current);
	vfs_init(current);
}
