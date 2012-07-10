#include <os/type.h>
#include <lib/klib.h>
#include <os/devfs.h>
#include <drv/cmos.h>
#include <time.h>

static long read_rtc()
{
	time_t res = time(NULL);
	struct tm *tmm = localtime(&res);
	printk("  date: %d - %d - %d\n",
	       tmm->tm_year + 1900,
	       tmm->tm_mon + 1,
	       tmm->tm_mday);
	printk("  time: %d : %d : %d\n",
	       tmm->tm_hour,
	       tmm->tm_min,
	       tmm->tm_sec);
	return res;
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

static int cmos_open(int minor, int mode)
{
	return 0;
}

static int cmos_close(int minor)
{
	return 0;
}

static int cmos_ctl(int minor, int cmd, void *arg)
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
	.open = cmos_open,
	.close = cmos_close,
	.ctl = cmos_ctl,
};
