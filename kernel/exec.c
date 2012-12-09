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
#include <os/errno.h>
#define ARGS_MAX 512

const char sign_bin[] = {0xeb, 0x4, 'X', 'B', 'I', 'N'};
const char sign_elf[] = {0x7f, 'E', 'L', 'F'};

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
	char *xhdr;
	int fd;
	char type;
	unsigned long entry;
	unsigned long brk_addr;
	
	ppath = kmalloc(strlen(path)+1);
	pargs = kmalloc(4096);
	pargv = kmalloc(ARGS_MAX*sizeof(int));
	penvp = kmalloc(ARGS_MAX*sizeof(int));
	strcpy(ppath, path);
	xhdr = kmalloc(4096);

	fd = vfs_open(path, 0);
	if(fd < 0) {
		retval = fd;
		goto out;
	}

	cc = vfs_read(fd, xhdr, 4096);
	if(cc < 0)
	{
		retval = cc;
		goto out;
	}
	/* 检测格式 */
	if(memcmp(xhdr, sign_bin, sizeof(sign_bin)) == 0) {
		type = 'B';
	} else if(memcmp(xhdr, sign_elf, sizeof(sign_elf)) == 0) {
		Elf32_Ehdr *elf_hdr;
		elf_hdr = (Elf32_Ehdr *)xhdr;
		if(elf_hdr->e_type != ET_EXEC)
		{
			retval = -ENOEXEC;
			goto out;
		}
		type = 'E';
	} else {
		retval = -ENOEXEC;
		goto out;
	}

	/* 排列参数 */
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

	/* vfork时叫醒父亲 */
	sem_up(&ptask->vfork_sem);

	/* 加载文件 */
	ptask->brk = usr_stack_top;
	if(type == 'B') {
		brk_addr = kernel_brk + 256*1024*1024;
		entry = kernel_brk;

		memcpy((char *)kernel_brk, xhdr, cc);
		while((chunk = vfs_read(fd, (char *)(kernel_brk + cc), 4096)) > 0)
			cc += chunk;
	}
	else if(type == 'E') {
		Elf32_Ehdr *elf_hdr;
		int i;
		brk_addr = 0;
		elf_hdr = (Elf32_Ehdr *)xhdr;
		entry = elf_hdr->e_entry;
		printk("exec: elf e_phnum=%d\n", elf_hdr->e_phnum);
		for(i = 0; i < elf_hdr->e_phnum; i++) {
			long poff = elf_hdr->e_phoff + (i*elf_hdr->e_phentsize);
			Elf32_Phdr *prog_hdr = (Elf32_Phdr *)(xhdr + poff);
			unsigned long pend;
			assert(poff < 4096);
			if(prog_hdr->p_type == PT_LOAD) {
				vfs_lseek(fd, prog_hdr->p_offset, 0);
				vfs_read(fd,
					 (void *)prog_hdr->p_vaddr,
					 prog_hdr->p_filesz);
				pend = prog_hdr->p_vaddr + prog_hdr->p_memsz;
				if(brk_addr < pend)
					brk_addr = pend;
			}

		}
	}
	else
		panic("wrong type");
	vfs_close(fd);
	
	/* 设置堆栈 */
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
	
	/* 设置寄存器 */
	memset(get_user_regs(ptask), 0, sizeof(struct s_regs));
	init_regs(get_user_regs(ptask));
	USR_PC_REG(ptask) = entry;
	USR_SP_REG(ptask) = stack_top;

	ptask->brk = brk_addr;
	vfs_exec(ptask);
	/* 成功变身 */
out:	kfree(ppath);
	kfree(pargv);
	kfree(penvp);
	kfree(pargs);
	kfree(xhdr);
	return retval;
}

asmlinkage long sys_execve(char *path, char *argv[], char *envp[])
{
	return do_execve(path, argv, envp);
}
