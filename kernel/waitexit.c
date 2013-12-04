#include <os/task.h>
#include <os/mm.h>
#include <os/fpu.h>
#include <os/waitexit.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/sem.h>
#include <os/asm.h>
#include <os/vfs.h>
#include <os/errno.h>

int do_waitpid(int pid, int *status, int options)
{
	int i;
	struct s_task* ptask;
	int retpid;

	if (pid < -1 || pid == 0)
		return -EINVAL;

	if(pid > 0)
	{
		ptask = task_struct_find(pid);
		if(ptask)
		{
			if(current != ptask->father)
				return -ECHILD;
			if(options&WNOHANG &&
			   ptask->state != TASK_STAT_DIE)
				return 0;
			while(ptask->state != TASK_STAT_DIE)
			{
				current->state = TASK_STAT_BLOCK;
				task_sched();
			}
			goto recycle;
		}
	}
	if(pid == -1)
	{
	redo:
		ptask = &task[0];
		for(i = 0; i < NR_TASK; i++, ptask++)
		{
			if(current != ptask->father)
				continue;
			if(ptask->state == TASK_STAT_DIE)
				goto recycle;
		}
		if(options&WNOHANG)
			return 0;
		else
		{
			current->state = TASK_STAT_BLOCK;
			task_sched();
			goto redo;
		}
	}
	return -EINVAL;
recycle:
	if(status)
		*status = ptask->exit_code;
	retpid = ptask->pid;
	task_struct_free(ptask);
	printk("do_waitpid: pid:%d\n",retpid);
	return retpid;
}

int do_exit(int exit_code)
{
	int i;
	struct s_task *ptask, *ptask1;

	mm_exit(current);
	current->state = TASK_STAT_DIE;
	current->exit_code = exit_code;
	fpu_exit(current);
	vfs_exit(current);

	sem_up(&current->vfork_sem);
	/* wakeup father */
	ptask = current->father;
	if(ptask->state == TASK_STAT_BLOCK)
		ptask->state = TASK_STAT_READY;

	ptask = task;
	ptask1 = task_struct_find(1);
	assert(ptask1);
	for(i = 0; i < NR_TASK; i++, ptask++)
		if(ptask->father == current)
			ptask->father = ptask1;
	printk("do_exit: a task die(pid=%d) exit code:%d\n", 
	       current->pid, current->exit_code);
	return 0;
}

asmlinkage long sys_exit(int exit_code)
{
	int ret;
	ret = do_exit(exit_code);
	if(ret)
		return ret;
	/* 调度新的任务执行 */
	task_sched();
	panic("sched a dead process!");
	return 0;
}

asmlinkage long sys_waitpid(int pid,int *status,int options)
{
	return do_waitpid(pid, status, options);
}
