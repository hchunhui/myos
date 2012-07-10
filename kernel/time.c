#include <os/arch_config.h>
#include <os/hz.h>
#include <lib/klib.h>
#include <os/devfs.h>

static long startup_time;

static struct d_devfs den_rtc = {
	.major = DEV_MAJOR_RTC,
	.minor = 0,
};

long time_get_startup_time()
{
	return startup_time;
}

void time_init()
{
	dev_register(DEV_MAJOR_RTC, &rtc_dev_desc);
	fsys_devfs.open(&den_rtc, 0);
	fsys_devfs.ioctl(&den_rtc, RTC_CMD_READ, &startup_time);
	fsys_devfs.close(&den_rtc);
	printk("  startup_time: %ld\n",startup_time);
}

long sys_gettime()
{
	long time = time_get_startup_time();
	long ticks = task_get_ticks();
	return time + ticks/HZ;
}
