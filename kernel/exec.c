#include <os/protect.h>
#include <os/arch_config.h>
#include <os/asm.h>
#include <os/task.h>
#include <os/mm.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/i386-elf.h>
#include <os/sem.h>
#include <os/vfs.h>
#define ARGS_MAX 512

const char sign_bin[] = {0xeb, 0x4, 'X', 'B', 'I', 'N'};

int do_execve(char *path, char *argv[], char *envp[])
{
	int retval = 0;
	char *pargs;
	int *pargv;
	int *penvp;
	char *ppath;
	int argsc;
	int envpc;
	int argvc;
	int len;
	int i;
	unsigned long stack_top, prev_stack_top;
	long chunk, cc;
	struct s_task *ptask = current;

	int fd;
	char sign[sizeof(sign_bin)];
	
	ppath = kmalloc(strlen(path)+1);
	pargs = kmalloc(4096);
	pargv = kmalloc(ARGS_MAX*sizeof(int));
	penvp = kmalloc(ARGS_MAX*sizeof(int));
	strcpy(ppath, path);

	fd = vfs_open(path, 0);
	if(fd < 0)
	{
		retval = -1;
		goto out;
	}

	if(vfs_read(fd, sign, sizeof(sign)) != sizeof(sign))
	{
		retval = -2;
		goto out;
	}

	if(memcmp(sign, sign_bin, sizeof(sign)))
	{
		retval = -2;
		goto out;
	}

	argsc = 0;
	if(argv) {
		for(argvc = 0; argvc < ARGS_MAX - 1; argvc++)
		{
			if(!argv[argvc])
				break;
			len = strlen(argv[argvc])+1;
			if(argsc + len <= 4096)
			{
				strcpy(pargs + argsc, argv[argvc]);
				pargv[argvc] = argsc;
				argsc += len;
			}
			else
				break;
		}
	} else {
		argvc = 0;
	}
	
	if(envp) {
		for(envpc = 0; envpc < ARGS_MAX - 1; envpc++)
		{
			if(!envp[envpc])
				break;
			len = strlen(envp[envpc])+1;
			if(argsc + len <= 4096)
			{
				strcpy(pargs + argsc, envp[envpc]);
				penvp[envpc] = argsc;
				argsc += len;
			}
			else
				break;
		}
	} else {
		envpc = 0;
	}
	
	/* 回收当前用户空间 */
	mm_exit(ptask);
	mm_fork(ptask, NULL, 0);

	sem_up(&ptask->vfork_sem);
	ptask->brk = kernel_brk + 256*1024*1024;

	memcpy((char *)kernel_brk, sign, sizeof(sign));
	cc = sizeof(sign);
	chunk = vfs_read(fd, (char *)(kernel_brk + cc), 4096 - cc);
	cc += chunk;
	while((chunk = vfs_read(fd, (char *)(kernel_brk + cc), 4096)) > 0)
		cc += chunk;
	vfs_close(fd);
	
	stack_top = usr_stack_top - 4096;
	memcpy((void *)stack_top,
	       pargs,
	       4096);
	prev_stack_top = stack_top;
	stack_top -= ARGS_MAX*sizeof(unsigned long);
	for(i = 0; i < envpc; i++)
		((unsigned long *)stack_top)[i] = prev_stack_top + penvp[i];
	((unsigned long *)stack_top)[i] = 0;

	stack_top -= ARGS_MAX*sizeof(unsigned long);
	for(i = 0; i < argvc; i++)
		((unsigned long *)stack_top)[i] = prev_stack_top + pargv[i];
	((unsigned long *)stack_top)[i] = 0;

	prev_stack_top = stack_top;
	stack_top -= 3*sizeof(unsigned long);
	((unsigned long *)stack_top)[0] = argvc;
	((unsigned long *)stack_top)[1] = prev_stack_top;
	((unsigned long *)stack_top)[2] =
		prev_stack_top + ARGS_MAX*sizeof(unsigned long);
	
	memset(get_user_regs(ptask), 0, sizeof(struct s_regs));
	init_regs(get_user_regs(ptask));
	USR_PC_REG(ptask) = kernel_brk;
	USR_SP_REG(ptask) = stack_top;

	vfs_exec(ptask);
	/* 成功变身 */
out:	kfree(ppath);
	kfree(pargv);
	kfree(penvp);
	kfree(pargs);
	return retval;
}

long sys_execve(char *path, char *argv[], char *envp[])
{
	return do_execve(path, argv, envp);
}
