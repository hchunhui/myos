#include <os/type.h>
#include <lib/klib.h>
#include <os/devfs.h>
#include <drv/cmos.h>
#include <lib/user.h>

static long read_rtc()
{
	return user_read_rtc();
}

static int cmos_init()
{
	printk("cmos up\n");
	return 0;
}

static int cmos_exit()
{
	printk("cmos down\n");
	return 0;
}

static int cmos_ctl(int minor, void *data, int cmd, void *arg)
{
	switch(cmd)
	{
	case CMOS_CMD_READ_RTC:
		*(long *)arg = read_rtc();
		break;
	default:
		printk("cmos_ctl: invaild cmd\n");
		return -1;
	}
	return 0;
}

struct dev_desc cmos_dev_desc = {
	.name = "cmos",
	.init = cmos_init,
	.exit = cmos_exit,
	.ctl = cmos_ctl,
};
