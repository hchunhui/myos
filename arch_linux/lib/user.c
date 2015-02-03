#include <unistd.h>
#include <ucontext.h>
#include <time.h>
#include <lib/user.h>

struct s_context
{
	ucontext_t ctx;
};

int context_len()
{
	return sizeof(struct s_context);
}

void context_switch(struct s_context *p,
		    struct s_context *q)
{
	swapcontext(&(p->ctx), &(q->ctx));
}

void context_make(struct s_context *p,
		  unsigned long pc,
		  unsigned long sp)
{
	getcontext(&(p->ctx));
	if(pc) {
		p->ctx.uc_stack.ss_sp = (void *)(sp);
		p->ctx.uc_stack.ss_size = 0;
		makecontext(&(p->ctx), (void *)pc, 0);
	}
}

void user_pause()
{
	pause();
}

long user_read_rtc()
{
	time_t res = time(NULL);
	return res;
}

void user_ualarm(long t)
{
	ualarm(t, t);
}
