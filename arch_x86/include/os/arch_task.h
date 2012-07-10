#ifndef _ARCH_TASK_H_
#define _ARCH_TASK_H_
#include <os/regs.h>

struct s_task;
void arch_task_init();
void idle_task_func();
void init_task_exec();
void init_regs(struct s_regs *regs);

__attribute__((regparm(2)))
struct s_task *__switch_to(struct s_task *prev, struct s_task *next);

void call_after_fork();

/* from linux-2.6.26 */
#define switch_to(prev, next, last)					\
do {									\
	/*								\
	 * Context-switching clobbers all registers, so we clobber	\
	 * them explicitly, via unused output variables.		\
	 * (EAX and EBP is not listed because EBP is saved/restored	\
	 * explicitly for wchan access and EAX is the return value of	\
	 * __switch_to())						\
	 */								\
	unsigned long ebx, ecx, edx, esi, edi;				\
									\
	asm volatile("pushfl\n\t"		/* save    flags */	\
		     "pushl %%ebp\n\t"		/* save    EBP   */	\
		     "movl %%esp,%[prev_sp]\n\t"	/* save    ESP   */ \
		     "movl %[next_sp],%%esp\n\t"	/* restore ESP   */ \
		     "movl $1f,%[prev_ip]\n\t"	/* save    EIP   */     \
		     "pushl %[next_ip]\n\t"	/* restore EIP   */     \
		     "jmp __switch_to\n"	/* regparm call  */     \
	             "1:\t"                                             \
                     "popl %%ebp\n\t"		/* restore EBP   */	\
		     "popfl\n"			/* restore flags */	\
									\
		     /* output parameters */				\
		     : [prev_sp] "=m" (prev->thread.sp),		\
		       [prev_ip] "=m" (prev->thread.ip),		\
		       "=a" (last),					\
									\
		       /* clobbered output registers: */		\
		       "=b" (ebx), "=c" (ecx), "=d" (edx),		\
		       "=S" (esi), "=D" (edi)				\
		       							\
		       /* input parameters: */				\
		     : [next_sp]  "m" (next->thread.sp),		\
		       [next_ip]  "m" (next->thread.ip),		\
		       							\
		       /* parameters for __switch_to(): */	\
		       [_prev]     "a" (prev),				\
		       [_next]     "d" (next));				\
} while (0)

static inline struct s_regs *get_user_regs(struct s_task *p)
{
	return (struct s_regs *)
		(((char *)p) + 4096 - sizeof(struct s_regs));
}

#define USR_RET_REG(p) (get_user_regs(p)->ax)
#define USR_PC_REG(p) (get_user_regs(p)->ip)
#define USR_SP_REG(p) (get_user_regs(p)->sp)

struct s_thread
{
	unsigned long ip;
	unsigned long sp;
};

static inline struct s_thread arch_task_mkthread(unsigned long pc,
						 unsigned long sp)
{
	struct s_thread thr = {
		.ip = pc,
		.sp = sp};
	return thr;
}

#endif /* _ARCH_TASK_H_ */
