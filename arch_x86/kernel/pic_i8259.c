#include <os/type.h>
#include <os/arch_config.h>
#include <os/io.h>
#define I8259M           0x20
#define I8259MMask       0x21
#define I8259S           0xA0
#define I8259SMask       0xA1

void i8259_init()
{
	/* ICW1 00010001b */
	outb_p(0x11, I8259M);
	outb_p(0x11, I8259S);
	/* ICW2 IRQ0->0x20 */
	outb_p(IRQ_0, I8259MMask);
	/* ICW2 IRQ8->0x28 */
	outb_p(IRQ_8, I8259SMask);
	/* ICW3 主IR2接从100b */
	outb_p(0x4, I8259MMask);
	/* ICW3 从接主IR2 */
	outb_p(0x2, I8259SMask);
	/* ICW4 */
	outb_p(0x1, I8259MMask);
	outb_p(0x1, I8259SMask);

	/* OCW1 */
	outb_p(0xff, I8259MMask);
	outb_p(0xff, I8259SMask);
}

static u8 i8259_s1, i8259_s2;
void i8259_irqsave()
{
	i8259_s1 = inb(I8259MMask);
	i8259_s2 = inb(I8259SMask);
}

void i8259_irqrestore()
{
	outb(i8259_s1, I8259MMask);
	outb(i8259_s2, I8259SMask);
}

void i8259_enable_irq(int irq)
{
	if(irq<8)
	{
		outb(inb(I8259MMask)&(~(1<<irq)), I8259MMask);
	}
	else
	{
		outb(inb(I8259MMask)&(~(1<<2)), I8259MMask);
		outb(inb(I8259SMask)&(~(1<<(irq-8))), I8259SMask);
	}
}
