#include <os/type.h>
#include <os/arch_config.h>
#include <lib/klib.h>
#include <stddef.h>
#include <signal.h>

void irq0();

sigset_t old_set;

void pic_init()
{
	sigset_t set_noalarm;
	struct sigaction act;
	/* 屏蔽SIGALRM */
	sigprocmask(0, NULL, &old_set);
	set_noalarm = old_set;
	sigaddset(&set_noalarm, SIGALRM);
	sigprocmask(SIG_SETMASK, &set_noalarm, NULL);
	/* 设置SIGALRM处理函数 */
	sigaction(SIGALRM, NULL, &act);
	act.sa_handler = irq0;
	sigaction(SIGALRM, &act, NULL);


	/* 	getcontext(&p->context); */
	/* p->context.uc_stack.ss_sp = p->stack; */
	/* p->context.uc_stack.ss_size = STACK_SIZE; */
	/* p->context.uc_link = NULL; */
	/* p->context.uc_sigmask = *sigmask; */
	/* makecontext(&p->context, */
	/* 	    proc, 2, p->pid, p->ltime); */

}

void pic_enable_irq(int irq)
{

}
