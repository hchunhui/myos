#ifndef _PIC_I8259_H_
#define _PIC_I8259_H_



void i8259_init();
void i8259_enable_irq(int irq);
void i8259_disable_irq(int irq);
void i8259_send_eoi(int irq);

#endif /* _PIC_I8259_H_ */
