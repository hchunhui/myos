/*
 *  i8042
 */
#include <os/arch_config.h>
#include <os/type.h>
#include <lib/klib.h>
#include <os/isr.h>
#include <os/io.h>
#include <drv/i8042.h>
#include <os/sem.h>
#include <os/fork.h>
#include <drv/input.h>

#define TIME_OUT 1000

static void empty_8042()
{
	u8 ret;
	int i = TIME_OUT;
	do {
		ret = inb(0x64);
		i--;
	}while((ret&0x2) && i);
	assert(i);
}

static void wait_8042()
{
	u8 ret;
	int i = TIME_OUT;
	do {
		ret = inb(0x64);
		i--;
	}while( (!(ret&0x1)) && i );
	assert(i);
}

static void out_8042(u8 val, u16 port)
{
	empty_8042();
	outb(val, port);
}

static u8 in_8042(u16 port)
{
	wait_8042();
	return inb(port);
}

static int i8042_ctl(int minor, void *data, int cmd, void *arg)
{
	unsigned long ularg = (unsigned long)arg;
	unsigned char *carg = arg;
	switch(cmd)
	{
	case I8042_CMD_SETCMD:
		out_8042(ularg&0xff, 0x64);
		break;
	case I8042_CMD_SETCNTL:
		out_8042(0x60, 0x64);
		out_8042(ularg&0xff, 0x60);
		empty_8042();
		break;
	case I8042_CMD_GETCNTL:
		out_8042(0x20, 0x64);
		*carg = in_8042(0x60);
		break;
	case I8042_CMD_GETSTAT:
		*carg = in_8042(0x64);
		break;
	case I8042_CMD_GETOBUF:
		*carg = in_8042(0x60);
		break;
	case I8042_CMD_SETIBUF:
		out_8042(ularg&0xff, 0x60);
		break;
	default:
		printk("i8042_ctl: invaild cmd\n");
	}
	return 0;
}

extern struct input_dev_desc kbd_desc;
extern struct input_dev_desc mouse_desc;
static int i8042_init()
{
	u8 ret;
	unsigned long lret;

	/* disable keyboard */
	i8042_ctl(0, 0, I8042_CMD_SETCMD, (void *)0xad);

	i8042_ctl(0, 0, I8042_CMD_GETCNTL, &ret);
	/* use scancode 2 */
	ret &= ~(1<<6);
	/* enable mouse&keyboard int */
	ret |= (1<<1) | 1;
	lret = ret;
	i8042_ctl(0, 0, I8042_CMD_SETCNTL, (void *)lret);
	printk("i8042: set command byte ok\n");

	/* enable keyboard */
	i8042_ctl(0, 0, I8042_CMD_SETCMD, (void *)0xae);
	/* enable mouse */
	i8042_ctl(0, 0, I8042_CMD_SETCMD, (void *)0xa8);
	i8042_ctl(0, 0, I8042_CMD_SETCMD, (void *)0xd4);
	i8042_ctl(0, 0, I8042_CMD_SETIBUF, (void *)0xf4);

	input_dev_register(INPUT_MINOR_KBD, &kbd_desc);
	input_dev_register(INPUT_MINOR_MOUSE, &mouse_desc);

	printk("i8042: up\n");
	return 0;
}

static int i8042_exit()
{
	printk("i8042: down\n");
	return 0;
}

struct dev_desc i8042_dev_desc = {
	.name = "i8042",
	.init = i8042_init,
	.exit = i8042_exit,
	.ctl = i8042_ctl,
};
