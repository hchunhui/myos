#include <os/task.h>
#include <os/fork.h>
#include <os/waitexit.h>
#include <os/mm.h>
#include <os/fpu.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/sem.h>
#include <os/asm.h>
#include <os/vfs.h>

/* FIXME: fork shm support */
long do_fork(unsigned long pc, unsigned int flags)
{
	struct s_task *ptask, *ptask_run;
	ptask_run = current;
	ptask = task_struct_dup(ptask_run);
	
	fpu_fork(ptask, ptask_run);
	mm_fork(ptask, ptask_run, flags);
	vfs_fork(ptask, ptask_run);
	
	task_set_ready(ptask);
	ptask->priority = ptask_run->priority;
	ptask->counter = ptask_run->priority;
	/* return 0 for child */
	USR_RET_REG(ptask) = 0;
	ptask->stime = 0;
	ptask->utime = 0;

	ptask->thread = arch_task_mkthread(pc,
					   (unsigned long)get_user_regs(ptask));
	printk("do_fork: pid=%d\n", ptask->pid);
	sem_init(&ptask->vfork_sem, 0);
	if(flags & FORK_WAIT_EXEC_EXIT)
	{
		sem_down(&ptask->vfork_sem);
	}
	return ptask->pid;	/* return pid for father */	
}

asmlinkage long sys_fork()
{
	return do_fork((unsigned long)call_after_fork, 0);
}

asmlinkage long sys_vfork()
{
	return do_fork((unsigned long)call_after_fork, FORK_VFORK);
}
