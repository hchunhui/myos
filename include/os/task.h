#ifndef _TASK_H_
#define _TASK_H_
#ifndef __ASSEMBLY__
#include <os/arch_task.h>
#include <os/sem.h>
#include <lib/list.h>
struct s_fpu;
struct s_vfs;
struct s_mm;

struct s_task
{
	/**/
	volatile int resched;
	volatile int level;
	/* list */
	struct list_head tasks;
	struct list_head ready;
	/* 状态 */
	unsigned int state;
	/* 时间片 */
	int counter;
	/* 优先级 */
	int priority;
	/* 退出码 */
	unsigned long exit_code;
	/* 进程号 */
	int pid;
	/* 父进程 */
	struct s_task *father;
	/* 终止位 */
	unsigned long brk;
	/* 堆栈大小 */
	unsigned long stack_size;
	long stime;
	long utime;
	
	/* FPU */
	struct s_fpu *fpu_info;

	/* VFS */
	struct s_vfs *vfs;
	struct s_mm *mm;

	sem_t vfork_sem;
	struct s_thread thread;
	/* 为进程内核态堆栈保留空间 */
	unsigned long kernel_stack[1024-24];
};

extern struct list_head tasks;
extern struct s_task *current_task;

#define current	(current_task)

void task_clock();
void task_sched();

struct s_task *task_struct_find(int pid);
void task_struct_free(struct s_task *ptask);
struct s_task *task_struct_dup(struct s_task *task_old);
struct s_task *task_struct_alloc();

void task_set_ready(struct s_task *);
void task_set_block(struct s_task *);
void task_set_die(struct s_task *);

#define for_each_task(p) list_for_each_entry(p, &tasks, tasks)
#endif  /* __ASSEMBLY__ */

#define TASK_STAT_EMPTY	0
#define TASK_STAT_READY	2
#define TASK_STAT_DIE	3
#define TASK_STAT_BLOCK	4

#define TASK_RESCHED  0
#define TASK_LEVEL    4
#endif
