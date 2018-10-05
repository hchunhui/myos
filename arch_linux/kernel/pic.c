#include <stddef.h>
#include <signal.h>

void irq0();

sigset_t irqon_set, irqoff_set;

void enable_irq()
{
	sigprocmask(SIG_SETMASK, &irqon_set, NULL);
}

void disable_irq()
{
	sigprocmask(SIG_SETMASK, &irqoff_set, NULL);
}

void pic_enable_irq(int irq)
{
}

void pic_disable_irq(int irq)
{
}

void pic_send_eoi(int irq)
{
}

void pic_init()
{
	struct sigaction act;

	sigprocmask(0, NULL, &irqon_set);

	irqoff_set = irqon_set;
	sigaddset(&irqoff_set, SIGALRM);

	disable_irq();

	sigaction(SIGALRM, NULL, &act);
	act.sa_handler = irq0;
	sigaction(SIGALRM, &act, NULL);
}
