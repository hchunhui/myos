#ifndef _ARCH_CONFIG_H_
#define _ARCH_CONFIG_H_

/* about timer */
#include <drv/pit_i8253.h>
#define timer_dev_desc (i8253_dev_desc)
#define TIMER_CMD_SETFREQ I8253_CMD_SETFREQ

/* about rtc */
#include <drv/cmos.h>
#define rtc_dev_desc (cmos_dev_desc)
#define RTC_CMD_READ (CMOS_CMD_READ_RTC)

/* about PIC */
#include <os/pic_i8259.h>
#define pic_init i8259_init
#define pic_enable_irq i8259_enable_irq
#define pic_disable_irq i8259_disable_irq
#define pic_send_eoi i8259_send_eoi

#define IRQ_0           0x20
#define IRQ_8           0x28

#define IRQ_TIMER		0
#define IRQ_KB			1
#define IRQ_MOUSE		12
#define IRQ_SERIAL1		4
#define IRQ_SERIAL2		3


/* about memory */
#define PAGE_SHIFT 12
#define PAGE_SIZE  (1 << PAGE_SHIFT)
#define PAGE_MASK  (~(PAGE_SIZE - 1))
#define PTE_COUNT  1024

#define kernel_brk		0x1000000
#define usr_stack_top		0x80000000
#define	max_usr_pde		(usr_stack_top/PAGE_SIZE/PTE_COUNT)
#define normal_stack_size	0x1000000	//16M

/* realmode */
void real_mode_int(int vec,int *eax,int *ebx);

/* barriers */
#define barrier() asm volatile("":::"memory")
#define mb() asm volatile("mfence":::"memory")

#endif /* _ARCH_CONFIG_H_ */
