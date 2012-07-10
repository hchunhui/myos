#ifndef _ISR_H_
#define _ISR_H_
#include <os/regs.h>
typedef int (*isr_func)(struct s_regs *pregs);
int isr_register(int no, isr_func fn);
int irq_register(int irq_no, isr_func fn);

#endif /* _ISR_H_ */
