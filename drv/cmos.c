#include <os/type.h>
#include <lib/klib.h>
#include <os/devfs.h>
#include <os/io.h>
#include <drv/cmos.h>

/*
 * from linux kernel 0.12, modified
 *  (C) 1991  Linus Torvalds
*/
#define __isleap(year)  \
((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 1000 == 0))

/*
 * PS. I hate whoever though up the year 1970 - couldn't they have gotten
 * a leap-year instead? I also hate Gregorius, pope or no. I'm grumpy.
 */
#define MINUTE 60
#define HOUR (60*MINUTE)
#define DAY (24*HOUR)
#define YEAR (365*DAY)
/* interestingly, we assume leap-years */
static int month[12] = {
	0,
	DAY*(31),
	DAY*(31+29),
	DAY*(31+29+31),
	DAY*(31+29+31+30),
	DAY*(31+29+31+30+31),
	DAY*(31+29+31+30+31+30),
	DAY*(31+29+31+30+31+30+31),
	DAY*(31+29+31+30+31+30+31+31),
	DAY*(31+29+31+30+31+30+31+31+30),
	DAY*(31+29+31+30+31+30+31+31+30+31),
	DAY*(31+29+31+30+31+30+31+31+30+31+30)
};

/*
* Yeah, yeah, it's ugly, but I cannot find how to do this correctly
* and this seems to work. I anybody has more info on the real-time
* clock I'd be interested. Most of this was trial and error, and some
* bios-listing reading. Urghh.
*/

#define CMOS_READ(addr) ({ \
outb_p(0x80|addr,0x70); \
inb(0x71); \
})

#define BCD_TO_BIN(val) ((val)=((val)&15) + ((val)>>4)*10)

static long read_rtc()
{
	int sec, min, hour, day, mon, year;
	long res = 0;
	do {
		sec = CMOS_READ(0);
		min = CMOS_READ(2);
		hour = CMOS_READ(4);
		day = CMOS_READ(7);
		mon = CMOS_READ(8);
		year = CMOS_READ(9);
	} while (sec != CMOS_READ(0));
	BCD_TO_BIN(sec);
	BCD_TO_BIN(min);
	BCD_TO_BIN(hour);
	BCD_TO_BIN(day);
	BCD_TO_BIN(mon);
	BCD_TO_BIN(year);

	mon--;
	year -= 70;
	if(year < 0) year += 100;
	/* magic offsets (y+1) needed to get leapyears right.*/
	res = YEAR*year + DAY*((year+1)/4);
	res += month[mon];
	/* and (y+2) here. If it wasn't a leap-year, we have to adjust */
	if (mon>1 && ((year+2)%4))
		res -= DAY;
	res += DAY*(day-1);
	res += HOUR*hour;
	res += MINUTE*min;
	res += sec;

	printk("cmos: %02d-%02d-%02d %02d:%02d:%02d (%d secs elapsed)\n",
	       year + 1970, mon + 1, day,
	       hour, min, sec,
	       res);
	return res;
}

static int cmos_init()
{
	printk("cmos: up\n");
	return 0;
}

static int cmos_exit()
{
	printk("cmos: down\n");
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
