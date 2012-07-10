#include <os/protect.h>
#include <os/hz.h>
#include <os/task.h>
#include <os/mm.h>
#include <os/devfs.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/unistd.h>
#include <os/asm.h>
#include <drv/speaker.h>
#include <drv/video.h>
#include <drv/kdev.h>

long sys_sbrk(int delta)
{
	return 0;
}

long sys_get_ticks()
{
	return task_get_ticks() / (HZ/USR_HZ);
}

long sys_get_utime()
{
	return task_get_utime() / (HZ/USR_HZ);
}

long sys_get_stime()
{
	return task_get_stime() / (HZ/USR_HZ);
}

long sys_get_graph_info(struct myos_graph_info *info)
{
	return fsys_devfs.ioctl(&den_video,
		       VIDEO_CMD_GET_INFO,
		       info);
}

long sys_pause()
{
	task_sched();
	return 0;
}

long sys_getpid()
{
	return current->pid;
}

long sys_getppid()
{
	return current->father->pid;
}

long sys_nice(int nice)
{
	if(current->priority - nice > 0)
	{
		current->priority -= nice;
		return 0;
	}
	return 1;
}
