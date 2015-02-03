#include <os/type.h>
#include <os/arch_config.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/devfs.h>
#include <drv/serial.h>
#include <os/isr.h>
#include <os/io.h>
#include <os/errno.h>

#define N 2
struct s_serial {
	void *pin_data;
	int port;
};

static struct s_serial sdata[N];
static int early_init;

static char sbuf[512];
static void do_serial_int(int i)
{
	int port = sdata[i].port;
	int ax;
	int n;
	for(n = 0; ((ax = inb(port+2)) & 1) == 0;)
	{
		ax &= 0xe;
		switch(ax)
		{
		case 0: /* modem_status */
			inb(port+6);
			break;
		case 2: /* write char */
			panic("unexpect intr: write char");
			break;
		case 4: /* read char */
		case 12:
			sbuf[n++] = inb(port);
			break;
		case 6: /* line_status */
			inb(port+5);
			break;
		default:
			panic("unexpect intr %d", ax);
			break;
		}
	}
	if(dev_simp_write(DEV_MAJOR_PIPE, 0, sdata[i].pin_data, 0, sbuf, n) != n)
		panic("lost data");
}

int do_serial1_int()
{
	do_serial_int(0);
	return 0;
}

int do_serial2_int()
{
	do_serial_int(1);
	return 0;
}

void serial_early_init()
{
	int i;
	early_init = 1;
	sdata[0].port = 0x3f8;
	sdata[1].port = 0x2f8;
	for(i = 0; i < N; i++) {
		outb_p(0x00, sdata[i].port+1);
		outb_p(0x80, sdata[i].port+3);
		outb_p(0x03, sdata[i].port+0);
		outb_p(0x00, sdata[i].port+1);
		outb_p(0x03, sdata[i].port+3);
		outb_p(0xc7, sdata[i].port+2);
		outb_p(0x0b, sdata[i].port+4);
		outb_p(0x0d, sdata[i].port+1);
	}
}

static int serial_init()
{
	int i;
	if(!early_init)
		serial_early_init();
	for(i = 0; i < N; i++)
		dev_simp_open(DEV_MAJOR_PIPE, 0, 0, &sdata[i].pin_data);
	irq_register(IRQ_SERIAL1, do_serial1_int);
	irq_register(IRQ_SERIAL2, do_serial1_int);
	pic_enable_irq(IRQ_SERIAL1);
	pic_enable_irq(IRQ_SERIAL2);
	printk("serial: up\n");
	return 0;
}

static int serial_open(int minor, int mode, void **data)
{
	if(minor < 0 || minor >= N)
		return -EINVAL;
	return 0;
}

static int serial_ctl(int minor, void *data, int cmd, void *arg)
{
	return -1;
}

static long serial_read(int minor, void *data, void *buf, long n, long off)
{
	void *pdata = sdata[minor].pin_data;
	return dev_simp_read(DEV_MAJOR_PIPE, 0, pdata, off, buf, n);
}

static long serial_write(int minor, void *data, void *buf, long n, long off)
{
	char *xbuf = buf;
	int port = sdata[minor].port;
	int m = n;
	for(;m--;) {
		while((inb(port+5)&0x20) == 0);
		outb(*xbuf++, port);
	}
	return n;
}

static int serial_poll(int minor, void *data, int func, struct list_head *lsem)
{
	void *pdata = sdata[minor].pin_data;
	return dev_simp_poll(DEV_MAJOR_PIPE, 0, pdata, func, lsem);
}

void serial_early_print(char *buf, int n)
{
	serial_write(0, NULL, buf, n, 0);
}

struct dev_desc serial_dev_desc = {
	.name = "serial",
	.init = serial_init,
	.open = serial_open,
	.ctl = serial_ctl,
	.read = serial_read,
	.write = serial_write,
	.poll = serial_poll,
};
