#include <os/asm.h>
#include <os/regs.h>
#include <os/task.h>
#include <lib/klib.h>

asmlinkage void do_isr(int vec_no, struct s_regs *pregs);
#define MAKEIRQ(i) \
void irq##i() \
{ \
	do_isr(i, (void *)0);			\
	if(current->resched)			\
	{					\
		current->resched = 0;		\
		task_sched();			\
	}					\
}

MAKEIRQ(0)
MAKEIRQ(1)
MAKEIRQ(2)
MAKEIRQ(3)
MAKEIRQ(4)
MAKEIRQ(5)
MAKEIRQ(6)
MAKEIRQ(7)
MAKEIRQ(8)
MAKEIRQ(9)
MAKEIRQ(10)
MAKEIRQ(11)
MAKEIRQ(12)
MAKEIRQ(13)
MAKEIRQ(14)
MAKEIRQ(15)

void syscall()
{
}

void call_after_fork()
{
	printk("haha!\n");
	for(;;);
}
