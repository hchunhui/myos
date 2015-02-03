#ifndef _ASM_H_
#define _ASM_H_
#define asmlinkage __attribute__((regparm(0)))

void enable_irq();
void disable_irq();
#endif


