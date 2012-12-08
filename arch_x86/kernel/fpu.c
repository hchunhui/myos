/*
 * fpu switch
 * 2010.2
 * 2011.6.20 fix lazy method bug.
 */
#include <os/type.h>
#include <os/task.h>
#include <lib/klib.h>
#include <os/mm.h>
#include <lib/string.h>
#include <os/asm.h>
#include <os/isr.h>

#define LAZY

#define stts()			asm volatile ("movl %cr0, %eax; orl $8, %eax; movl %eax, %cr0")
#define clts()			asm volatile ("clts")
#define fsave(mem)		asm volatile ("fnsave %0; fwait":: "m"(*(mem)))
#define frstor(mem)		asm volatile ("frstor %0":: "m"(*(mem)))
#define fninit()		asm volatile ("fninit")

struct s_fpu
{
	u32 cwd;
	u32 twd;
	u32 fip;
	u32 fcs;
	u32 foo;
	u32 fos;
	u32 st[20];
};

static struct s_task *last_use = NULL;

void fpu_fork(struct s_task *child, struct s_task *father)
{
	//child->used_fpu = 0;
	if(father->fpu_info)
	{
		printk("fpu_fork: copy\n");
		child->fpu_info = kmalloc(sizeof(struct s_fpu));
		printk("fpu_fork: cpid=%d fpu_info=%x\n",child->pid,child->fpu_info);
		//memcpy(child->fpu_info, father->fpu_info, sizeof(struct s_fpu));
		fsave(child->fpu_info);
		fsave(father->fpu_info);
	}
	else
	{
		printk("fpu_fork: no copy\n");
		child->fpu_info = NULL;
	}
}

void fpu_exit(struct s_task *ptask)
{
	if(ptask->fpu_info)
	{
		printk("exit ptask->pid=%d ptask->fpu_info=%x\n",ptask->pid,ptask->fpu_info);
		kfree(ptask->fpu_info);
		ptask->fpu_info = NULL;
	}
	printk("fpu_exit: last use: %x   patsk:%x\n",last_use,ptask);
	if(ptask == last_use)
	{
		printk("aa\n");
		last_use = NULL;
		ptask->used_fpu = 0;
	}
	printk("fpu_exit: last use: %x   patsk:%x\n",last_use,ptask);

}

void fpu_init(struct s_task *ptask)
{
	ptask->used_fpu = 0;
	ptask->fpu_info = NULL;
	stts();
}

void fpu_switch(struct s_task *prev, struct s_task *next)
{
#ifndef LAZY
	if(prev->used_fpu)
	{
		printk("prev fpu_info=%x pid=%d\n",prev->fpu_info,prev->pid);
		if(prev->fpu_info)
			fsave(prev->fpu_info);
		prev->used_fpu = 0;
	}
	stts();
#else
	if(prev->used_fpu)
	{
		last_use = prev;
		prev->used_fpu = 0;
	}
	stts();
#endif
}

int do_fpu_fault(struct s_regs *pregs)
{
#ifndef LAZY
	clts();
	if( current->fpu_info )
	{
		frstor(current->fpu_info);
	}
	else
	{
		fninit();
		printk("pid=%d fninit\n", current->pid);
		current->fpu_info = kmalloc(sizeof(struct s_fpu));
		current->used_fpu = 1;
	}
	clts();
#else
	clts();
//	printk("fpu_fault\n");
//	printk("  last use %x current %x\n", last_use, current);
	if(current != last_use)
	{
		if(last_use && last_use->fpu_info)
		{
//			printk("  fsave fpu_info=%x\n",last_use->fpu_info);
			fsave(last_use->fpu_info);
		}
		if(last_use && !last_use->fpu_info)
			panic("  last_use must have fpu_info");
		
		if(current->fpu_info)
		{
//			printk("  frstor fpu_info=%x\n",current->fpu_info);
			frstor(current->fpu_info);
		}
		else
		{
//			printk("  fninit\n");
			current->fpu_info = kmalloc(sizeof(struct s_fpu));
			fninit();
		}
		last_use = current;
		current->used_fpu = 1;
	}
	else
		current->used_fpu = 1;
#endif
	return 0;
}

void fpu_fault_init()
{
	isr_register(7, do_fpu_fault);
}
