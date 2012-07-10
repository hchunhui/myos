#include <os/type.h>
#include <os/task.h>
#include <lib/klib.h>

struct s_fpu
{

};

void fpu_fork(struct s_task *child, struct s_task *father)
{
	printk("fpu_fork\n");
}

void fpu_exit(struct s_task *ptask)
{
	printk("fpu_exit\n");
}

void fpu_init(struct s_task *ptask)
{
	printk("fpu_init\n");
}

void fpu_switch(struct s_task *prev, struct s_task *next)
{
}


void fpu_fault_init()
{
}
