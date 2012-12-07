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
#include <signal.h>
#include <ucontext.h>
#include <unistd.h>

extern sigset_t old_set;

long do_execve(char *path, char **argv, char **envp);

void arch_task_init(struct s_task *idle_task)
{
	printk("sizeof(s_task)=%d\n", sizeof(struct s_task));
}

void idle_task_func()
{
	sigprocmask(SIG_SETMASK, &old_set, NULL);
	do_fork((unsigned long)init_task_exec, 0);
	for(;;)
	{
		pause();
	}
}


void task2()
{
	int a=0;
	sigprocmask(SIG_SETMASK, &old_set, NULL);
	for(;;)
	{
		printk("2 %d\n", a++);
		pause();
	}
}

void init_task_exec()
{
	int a=0;
	printk("do_exec /app1.bin\n");
	do_fork((unsigned long)task2, 0);
	do_execve("/app1.bin", NULL, NULL);
	
	sigprocmask(SIG_SETMASK, &old_set, NULL);
	for(;;)
	{
		printk("1 %d\n", a++);
		pause();
	}
}

void init_regs(struct s_regs *regs)
{

}
