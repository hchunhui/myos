#include <os/arch_config.h>
#include <os/hz.h>
#include <lib/klib.h>
#include <os/devfs.h>

static long startup_time;

long time_get_startup_time()
{
	return startup_time;
}

void time_init()
{
	void *data;
	dev_register(DEV_MAJOR_RTC, &rtc_dev_desc);
	dev_simp_open(DEV_MAJOR_RTC, 0, 0, &data);
	dev_simp_ioctl(DEV_MAJOR_RTC, 0, data, RTC_CMD_READ, &startup_time);
	dev_simp_close(DEV_MAJOR_RTC, 0, data);
	printk("  startup_time: %ld\n",startup_time);
}

long sys_gettime()
{
	long time = time_get_startup_time();
	long ticks = task_get_ticks();
	return time + ticks/HZ;
}
