#include <os/task.h>
#include <os/mm.h>
#include <os/fpu.h>
#include <os/waitexit.h>
#include <os/message.h>
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
	struct s_task* ptask_run;
	int retpid;

	if (pid < -1 || pid == 0)
		return -EINVAL;

	ptask_run = current;
	if(pid > 0)
	{
		ptask = &(task[0]);
		for(i = 0; i < NR_TASK; i++, ptask++)
			if(ptask->pid == pid)
			{
				if(ptask_run != ptask->father)
					return -ECHILD;
				if(options&WNOHANG &&
				   ptask->state != TASK_STAT_DIE)
					return 0;
				while(ptask->state != TASK_STAT_DIE)
				{
					ptask_run->state = TASK_STAT_BLOCK;
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
			if(ptask_run != ptask->father)
				continue;
			if(ptask->state == TASK_STAT_DIE)
				goto recycle;
		}
		if(options&WNOHANG)
			return 0;
		else
		{
			ptask_run->state = TASK_STAT_BLOCK;
			task_sched();
			goto redo;
		}
	}
	return -EINVAL;
recycle:
	if(status)
		*status = ptask->exit_code;
	task_pid_hash_remove( ptask->pid );
	ptask->state = TASK_STAT_EMPTY;
	retpid = ptask->pid;
	printk("do_waitpid: pid:%d\n",retpid);
	return retpid;
}

int do_exit(int exit_code)
{
	int i;
	struct s_task *ptask_run, *ptask;
	
	ptask_run = current;
	
	mm_exit(ptask_run);

	ptask_run->state = TASK_STAT_DIE;
	ptask_run->exit_code = exit_code;
	message_exit(current);
	fpu_exit(current);
	vfs_exit(current);

	sem_up(&ptask_run->vfork_sem);
	/* wakeup father */
	ptask = ptask_run->father;
	if(ptask->state == TASK_STAT_BLOCK)
		ptask->state = TASK_STAT_READY;

	ptask = task;
	for(i = 0; i < NR_TASK; i++, ptask++)
		if(ptask->father == ptask_run)
			ptask->father = task + task_pid_hash(1);
	printk("do_exit: a task die(pid=%d) exit code:%d\n", 
		ptask_run->pid, ptask_run->exit_code);
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
