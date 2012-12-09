#include <os/protect.h>
#include <os/hz.h>
#include <os/task.h>
#include <os/mm.h>
#include <os/devfs.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/unistd.h>
#include <os/asm.h>
#include <os/arch_config.h>
#include <os/errno.h>

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

asmlinkage long sys_get_ticks()
{
	return task_get_ticks() / (HZ/USR_HZ);
}

asmlinkage long sys_get_utime()
{
	return task_get_utime() / (HZ/USR_HZ);
}

asmlinkage long sys_get_stime()
{
	return task_get_stime() / (HZ/USR_HZ);
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
