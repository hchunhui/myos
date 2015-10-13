#include <os/type.h>
#include <os/task.h>
#include <os/asm.h>
#include <os/isr.h>
#include <lib/klib.h>
#include <lib/string.h>

#define stts()			asm volatile ("movl %%cr0, %%eax; orl $8, %%eax; movl %%eax, %%cr0":::"eax")
#define clts()			asm volatile ("clts")
#define fsave(mem)		asm volatile ("fnsave %0; fwait":: "m"(*(mem)))
#define frstor(mem)		asm volatile ("frstor %0": "=m"(*(mem)))
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

static struct s_task *last_use;

void fpu_fork(struct s_task *child, struct s_task *father)
{
	if(last_use == father) {
		child->fpu_info = kmalloc(sizeof(struct s_fpu));
		fsave(child->fpu_info);
	} else if(father->fpu_info) {
		child->fpu_info = kmalloc(sizeof(struct s_fpu));
		memcpy(child->fpu_info,
		       father->fpu_info,
		       sizeof(struct s_fpu));
	} else {
		child->fpu_info = NULL;
	}
}

void fpu_exit(struct s_task *ptask)
{
	if(ptask->fpu_info) {
		kfree(ptask->fpu_info);
		ptask->fpu_info = NULL;
	}

	if(ptask == last_use)
		last_use = NULL;
}

void fpu_init(struct s_task *ptask)
{
	last_use = NULL;
	ptask->fpu_info = NULL;
	stts();
}

void fpu_switch(struct s_task *prev, struct s_task *next)
{
	if(last_use == next)
		clts();
	else
		stts();
}

int do_fpu_fault(struct s_regs *pregs)
{
	clts();

	if(current != last_use) {
		if(last_use) {
			if(last_use->fpu_info == NULL)
				last_use->fpu_info = kmalloc(sizeof(struct s_fpu));
			fsave(last_use->fpu_info);
		}

		if(current->fpu_info)
			frstor(current->fpu_info);
		else
			fninit();
		last_use = current;
	}
	return 0;
}

void fpu_fault_init()
{
	isr_register(7, do_fpu_fault);
}
