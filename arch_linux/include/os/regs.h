#ifndef _REGS_H_
#define _REGS_H_
struct s_regs
{
	long syscall_retval;
	unsigned long pc;
	unsigned long sp;
};

#endif /* _REGS_H_ */
