#include <os/type.h>
#include <os/arch_config.h>
#include <os/hz.h>
#include <os/task.h>
#include <os/fork.h>
#include <lib/klib.h>
#include <os/mm.h>
#include <lib/string.h>
#include <os/unistd.h>
#include <os/asm.h>
#include <os/fpu.h>
#include <os/isr.h>
#include <os/vfs.h>
#include <os/errno.h>

struct s_task *current_task;
static struct s_task *idle_task;
struct list_head tasks;
struct list_head ready_queue;

static int pid_count = 0;

void task_set_ready(struct s_task *p)
{
	if(p->state != TASK_STAT_READY)
	{
		p->state = TASK_STAT_READY;
		list_add(&p->ready, &ready_queue);
	}
}

void task_set_block(struct s_task *p)
{
	if(p->state == TASK_STAT_READY)
		list_del(&p->ready);
	p->state = TASK_STAT_BLOCK;
}

void task_set_die(struct s_task *p)
{
	if(p->state == TASK_STAT_READY)
		list_del(&p->ready);
	p->state = TASK_STAT_DIE;
}

#define for_each_ready_task(p) list_for_each_entry(p, &ready_queue, ready)
static struct s_task *choose_next(struct s_task *prev)
{
	struct s_task *next, *p;
	int prio;
	int ready_count;
redo:
	prio = 0;
	next = NULL;
	ready_count = 0;
	for_each_ready_task(p)
	{
		if(p == idle_task) continue;
		ready_count++;
		if(prio < p->counter)
		{
			next = p;
			prio = p->counter;
		}
	}
	if(ready_count == 0)
		return idle_task;
	if(next == NULL) {
		/* 时间片用光 */
		for_each_task(p)
		{
			p->counter =
				(p->counter + p->priority) >> 1;
		}
		idle_task->priority = 1;
		goto redo;
	}
	/* 有就绪任务，有时间片 */
	assert(next);
	return next;
}

void task_sched()
{
	struct s_task *prev, *next, *last;
	prev = current;
	next = choose_next(prev);

	if(prev != next) {
		current_task = next;
		switch_to(prev, next, last);
	}
}

void task_clock()
{
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

struct s_task *task_struct_find(int pid)
{
	struct s_task *ptask;
	for_each_task(ptask)
	{
		if(ptask->pid == pid)
			return ptask;
	}
	return NULL;
}

void task_struct_free(struct s_task *ptask)
{
	assert(ptask->state == TASK_STAT_DIE);
	list_del(&ptask->tasks);
	kfree(ptask);
}

struct s_task *task_struct_alloc()
{
	int pid = pid_count++;
	struct s_task *ptask = kmalloc(sizeof(struct s_task));
	ptask->state = TASK_STAT_EMPTY;
	ptask->pid = pid;
	init_regs(get_user_regs(ptask));
	ptask->mm = NULL;
	list_add(&ptask->tasks, &tasks);
	INIT_LIST_HEAD(&ptask->ready);
	return ptask;
}

struct s_task *task_struct_dup(struct s_task *task_old)
{
	int pid;
	struct s_task *task_new;
	struct list_head tmp;
	task_new = task_struct_alloc();
	pid = task_new->pid;
	tmp = task_new->tasks;
	memcpy(task_new, task_old, sizeof(struct s_task));
	task_new->state = TASK_STAT_EMPTY;
	task_new->tasks = tmp;
	task_new->pid = pid;
	task_new->father = task_old;
	task_new->mm = NULL;
	INIT_LIST_HEAD(&task_new->ready);
	return task_new;
}

void task_init()
{
	INIT_LIST_HEAD(&tasks);
	INIT_LIST_HEAD(&ready_queue);
	/* 手工创建0号进程 */
	idle_task = task_struct_alloc();
	idle_task->priority = 2;
	idle_task->counter = 2;
	idle_task->father = NULL;
	idle_task->brk = kernel_brk;
	idle_task->stack_size = normal_stack_size;
	idle_task->level = 1;

	task_set_ready(idle_task);
	current_task = idle_task;
	arch_task_init(idle_task);
	mm_fork(idle_task, NULL, 0);
	fpu_init(current);
	vfs_init(current);
}

asmlinkage long sys_get_utime()
{
	return (current->utime) / (HZ/USR_HZ);
}

asmlinkage long sys_get_stime()
{
	return (current->stime) / (HZ/USR_HZ);
}

asmlinkage long sys_pause()
{
	task_sched();
	return 0;
}

asmlinkage long sys_getpid()
{
	return current->pid;
}

asmlinkage long sys_getppid()
{
	return current->father->pid;
}

asmlinkage long sys_nice(int nice)
{
	if(current->priority - nice > 0)
	{
		current->priority -= nice;
		return 0;
	}
	return 1;
}

asmlinkage unsigned long sys_sbrk(int delta)
{
	unsigned long xbrk, obrk;
	obrk = current->brk;
	xbrk = obrk + delta;
	if(xbrk < kernel_brk || xbrk >= usr_stack_top)
		return -ENOMEM;
	current->brk = xbrk;
	return obrk;
}
