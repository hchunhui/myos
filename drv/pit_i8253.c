/*
 *  i8253
 */
#include <os/type.h>
#include <lib/klib.h>
#include <os/io.h>
#include <drv/pit_i8253.h>

#define I8253_TIMER0_PORT 0x40
#define I8253_CTRL_PORT 0x43
#define I8253_CTRL_CMD(minor)  ((0x36|((minor)<<6))&0xff)

#define I8253_TIMER_FREQ 1193182UL

static int i8253_init()
{
	printk("i8253 init\n");
	return 0;
}

static int i8253_exit()
{
	printk("i8253 down\n");
	return 0;
}


static int i8253_ctl(int minor, void *data, int cmd, void *arg)
{
	unsigned long ularg = (unsigned long)arg;
	if(minor != 0 && minor != 2)
		return -1;
	switch(cmd)
	{
	case I8253_CMD_SETFREQ:
		outb_p(I8253_CTRL_CMD(minor),
		       I8253_CTRL_PORT);
		outb_p((u8)(I8253_TIMER_FREQ/ularg),
		       I8253_TIMER0_PORT + minor);
		outb_p((u8)((I8253_TIMER_FREQ/ularg)>>8),
		       I8253_TIMER0_PORT + minor);
		break;
	default:
		printk("i8253_ctl: invaild cmd\n");
	}
	return 0;
}

struct dev_desc i8253_dev_desc = {
	.name = "timer_i8253",
	.init = i8253_init,
	.exit = i8253_exit,
	.ctl = i8253_ctl,
};
