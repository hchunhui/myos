#include <os/arch_config.h>
#include <os/asm.h>
#include <lib/klib.h>
#include <os/regs.h>
#include <lib/string.h>
#include <os/isr.h>

struct isr_desc
{
	isr_func fn;
	struct isr_desc *next;
};

int isr_dummy();

static struct isr_desc dummy_desc = {
	.fn = isr_dummy,
	.next = NULL
};

static struct isr_desc *isr_table[64];

int isr_register(int no, isr_func fn)
{
	struct isr_desc *desc;
	assert(no >= 0 && no < 64);

	desc = kmalloc(sizeof(struct isr_desc));

	desc->next = isr_table[no];
	desc->fn = fn;
	isr_table[no] = desc;
	return 0;
}

int irq_register(int irq_no, isr_func fn)
{
	return isr_register(IRQ_0 + irq_no, fn);
}

void isr_init()
{
	int i;

	for(i = 0; i < 64; i++)
		isr_table[i] = &dummy_desc;
}

int isr_dummy(void)
{
	panic("unhandled int/exception.");
	/* printk("vec_no: %d\n" */
	/*        "eflags: %x\n" */
	/*        "cs: %x\n" */
	/*        "eip: %x\n", */
	/*        vec_no, */
	/*        pregs->flags, */
	/*        pregs->cs, */
	/*        pregs->ip); */
	/* if(pregs->err_code != 0xffffffff) */
	/* 	printk("err_code: %x\n", pregs->err_code); */
	return 0;
}

asmlinkage void do_isr(int vec_no, struct s_regs *pregs)
{
	struct isr_desc *desc;
	desc = isr_table[vec_no];
	/*for(;desc;)
	{
		if(desc->fn(vec_no, pregs) == 0)
			break;
		desc = desc->next;
		}*/
	desc->fn(pregs);
}
