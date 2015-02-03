#include <os/type.h>
#include <os/arch_config.h>
#include <os/task.h>
#include <os/protect.h>
#include <lib/klib.h>
#include <os/mm.h>
#include <lib/string.h>
#include <os/unistd.h>
#include <os/asm.h>
#include <os/fork.h>

long do_execve(char *path, char **argv, char **envp);

void arch_task_init(struct s_task *idle_task)
{
	printk("sizeof(s_task)=%d\n", sizeof(struct s_task));
}

void idle_task_func()
{
	enable_irq();
	do_fork((unsigned long)init_task_exec, 0);
	current->thread = arch_task_mkthread(0, 0);
	for(;;)
	{
		user_pause();
	}
}

void task2()
{
	int a=0;
	enable_irq(0);
	for(;;)
	{
		printk("2 %d\n", a++);
		user_pause();
	}
}

void init_task_exec()
{
	int a=0;
	printk("do_exec /app1.bin\n");
	do_fork((unsigned long)task2, 0);
	do_execve("/app1.bin", NULL, NULL);

	enable_irq();
	for(;;)
	{
		printk("1 %d\n", a++);
		user_pause();
	}
}

void init_regs(struct s_regs *regs)
{

}
