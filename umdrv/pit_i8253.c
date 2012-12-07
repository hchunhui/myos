#include <lib/klib.h>
#include <drv/pit_i8253.h>
#include <unistd.h>

#define I8253_TIMER_FREQ 1193182UL

int freq[3];

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
		freq[minor] = ularg;
		break;
	default:
		printk("i8253_ctl: invaild cmd\n");
	}
	ualarm(1000000/freq[0], 1000000/freq[0]);
	return 0;
}

struct dev_desc i8253_dev_desc = {
	.name = "timer_i8253",
	.init = i8253_init,
	.exit = i8253_exit,
	.ctl = i8253_ctl,
};
