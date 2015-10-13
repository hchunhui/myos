#ifndef _ASM_H_
#define _ASM_H_
#define asmlinkage __attribute__((regparm(0)))
#define disable_irq() asm volatile("cli":::"memory")
#define enable_irq() asm volatile("sti":::"memory")

#endif
