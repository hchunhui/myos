#include <os/type.h>
#include <os/arch_config.h>
#include <os/task.h>
#include <os/protect.h>
#include <lib/klib.h>
#include <os/mm.h>
#include <os/fpu.h>
#include <lib/string.h>
#include <os/asm.h>

struct s_tss {
	u32	backlink;
	u32	esp0;		/* stack pointer to use during interrupt */
	u32	ss0;		/*   "   segment  "  "    "        "     */
	u32	esp1;
	u32	ss1;
	u32	esp2;
	u32	ss2;
	u32	cr3;
	u32	eip;
	u32	flags;
	u32	eax;
	u32	ecx;
	u32	edx;
	u32	ebx;
	u32	esp;
	u32	ebp;
	u32	esi;
	u32	edi;
	u32	es;
	u32	cs;
	u32	ss;
	u32	ds;
	u32	fs;
	u32	gs;
	u32	ldt;
	u16	trap;
	u16	iobase;	/* I/O位图基址大于或等于TSS段界限，就表示没有I/O许可位图 */
}__attribute__((packed));

/* 整个内核只用这一个tss */
struct s_tss tss;
extern struct s_task *task;

void arch_task_init(struct s_task *idle_task)
{
	printk("sizeof(s_task)=%d\n", sizeof(struct s_task));
	assert(sizeof(struct s_task) == 4096);
	memset(&tss,0,sizeof(struct s_tss));
	tss.esp0 = ((unsigned long)get_user_regs(idle_task)) +
		sizeof(struct s_regs);
	tss.ss0=DS;
	tss.iobase=sizeof(struct s_tss);
	asm volatile( "ltr %%cx"::"c"(TSS) );
}

__attribute__((regparm(2)))
struct s_task *__switch_to(struct s_task *prev, struct s_task *next)
{
	/* 切换fpu */
	fpu_switch(prev, next);
	/* 切换TSS */
	tss.esp0 = ((unsigned long)get_user_regs(next)) + sizeof(struct s_regs);
	/* 切换页表 */
	mm_switch(prev, next);
	return prev;
}

void kbd_thread();
void mouse_thread();
void init_task_exec();
void idle_task_func()
{
	/* adjust stack */
	asm ("movl %0, %%esp\n\t"
	     "movl %%esp, %%ebp\n\t"
	     ::"g"(get_user_regs(current)));
	
	/* fork init */
	do_fork((unsigned long)init_task_exec, FORK_SHARE_MM);
//	do_fork((unsigned long)kbd_thread, FORK_SHARE_MM);
//	do_fork((unsigned long)mouse_thread, FORK_SHARE_MM);

	/* idle loop */
	current->level = 0;
	asm("sti");
	for(;;)
		asm("hlt");
}

char *init_argv[] = {"init", 0};
char *init_envp[] = {"OS=myos", 0};
long do_execve(char *path, char **argv, char **envp);
void init_task_exec()
{
	printk("do_execve /bin/init\n");
	do_execve("/bin/init", init_argv, init_envp);
	asm (
		"movl %0, %%esp\n\t"
		"jmp call_after_fork\n"
		::"g"(get_user_regs(current)));
}

void init_regs(struct s_regs *regs)
{
	regs->cs=CS_USR;
	regs->ds=DS_USR;
	regs->es=DS_USR;
	regs->ss=DS_USR;
	regs->flags=0x200;	//IF
	regs->ip = 0;
	regs->sp = usr_stack_top;
}
