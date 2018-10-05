#ifndef _PIC_H_
#define _PIC_H_



void pic_init();
void pic_enable_irq(int irq);
void pic_disable_irq(int irq);
void pic_send_eoi(int irq);

#endif /* _PIC_H_ */
