#include <os/type.h>
#include <os/asm.h>
#include <os/arch_config.h>
#include <os/task.h>
#include <os/protect.h>
#include <os/devfs.h>
#include <os/hz.h>
#include <lib/klib.h>
#include <os/message.h>
#include <os/isr.h>

extern int timer;	//in HZ
extern int timer_long;	//in USR_HZ

static struct d_devfs den_pit = {
	.major = DEV_MAJOR_PIT,
	.minor = 0,
};

int do_timer_int()
{
	if(--timer < 0)
	{
		MSG msg;
		msg.type = KM_TIMER;
		timer = timer_long * (HZ/USR_HZ);
		do_send_to_user(&msg);
	}

	task_clock();
	return 0;
}

void timer_init()
{
	dev_register(DEV_MAJOR_PIT, &timer_dev_desc);
	fsys_devfs.open(&den_pit, 0);
	fsys_devfs.ioctl(&den_pit, TIMER_CMD_SETFREQ, (void *)HZ);
	irq_register(IRQ_TIMER, do_timer_int);
	pic_enable_irq(IRQ_TIMER);
}
