#ifndef _ISR_H_
#define _ISR_H_
#include <os/regs.h>
typedef int (*isr_func)(struct s_regs *pregs, void *data);
int isr_register(int no, isr_func fn, void *data);
int irq_register(int irq_no, isr_func fn, void *data);

#endif /* _ISR_H_ */
