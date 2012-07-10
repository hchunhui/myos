#ifndef _ARCH_TASK_H_
#define _ARCH_TASK_H_
#include <os/regs.h>
#include <ucontext.h>

struct s_thread_link
{
	ucontext_t ctx;
	struct s_thread_link *back;
};

struct s_thread
{
	struct s_thread_link *p;
};

struct s_task;
void arch_task_init();
void idle_task_func();
void init_task_exec();
void init_regs(struct s_regs *regs);

void call_after_fork();

#define switch_to(prev, next, last) \
do { \
	struct s_thread_link *q; \
	q = malloc(sizeof(struct s_thread_link)); \
	q->back = prev->thread.p; \
	prev->thread.p = q; \
	swapcontext(&prev->thread.p->ctx, &next->thread.p->ctx); \
	prev->thread.p = q->back; \
	free(q); \
}while(0)


static inline struct s_regs *get_user_regs(struct s_task *p)
{
	return (struct s_regs *)
		(((char *)p) + 4092 - sizeof(struct s_regs));
}

#define USR_RET_REG(p) (get_user_regs(p)->syscall_retval)
#define USR_PC_REG(p) (get_user_regs(p)->pc)
#define USR_SP_REG(p) (get_user_regs(p)->sp)

static inline struct s_thread arch_task_mkthread(unsigned long pc,
						 unsigned long sp)
{
	struct s_thread thr;
	struct s_thread_link *link;

	link = malloc(sizeof(struct s_thread_link));
	getcontext(&link->ctx);
	link->ctx.uc_stack.ss_sp = (void *)(sp);
	link->ctx.uc_stack.ss_size = 0;
	makecontext(&link->ctx, (void *)pc, 0);
	
	thr.p = link;
	return thr;
}

#endif /* _ARCH_TASK_H_ */
