#ifndef _ARCH_TASK_H_
#define _ARCH_TASK_H_
#include <lib/klib.h>
#include <os/regs.h>
#include <lib/user.h>

struct s_thread
{
	struct s_context *p;
};

struct s_task;
void arch_task_init();
void idle_task_func();
void init_task_exec();
void init_regs(struct s_regs *regs);

void call_after_fork();

#define switch_to(prev, next, last) \
do { \
	context_switch(prev->thread.p, next->thread.p); \
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
	thr.p = kmalloc(context_len());
	context_make(thr.p, pc, sp);
	return thr;
}

#endif /* _ARCH_TASK_H_ */
