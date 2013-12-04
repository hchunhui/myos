#include <os/type.h>
#include <os/asm.h>
#include <os/arch_config.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/task.h>
#include <os/protect.h>
#include <os/devfs.h>
#include <os/sem.h>
#include <os/hz.h>
#include <lib/klib.h>
#include <os/isr.h>
#include <os/errno.h>

struct timer_data {
	struct list_head list;
	void *pipe;
	int inter;
	int tick;
};

static struct list_head timer_list;

static void insert(struct timer_data *data)
{
	struct timer_data *p;
	list_for_each_entry(p, &timer_list, list)
		if(data->tick > p->tick)
			break;
	list_add(&(data->list), &(p->list));
}

static void remove(struct timer_data *data)
{
	list_del(&(data)->list);
	INIT_LIST_HEAD(&(data->list));
}

static int ticks;

int timer_get_ticks()
{
	return ticks;
}

int do_timer_int()
{
	int inter;
	struct timer_data *td;
	ticks++;
	for(;!list_empty(&timer_list);)
	{
		td = list_entry(timer_list.next,
				struct timer_data, list);
		if(td->tick <= ticks)
		{
			inter = ticks - td->tick + td->inter;
			dev_simp_write(DEV_MAJOR_PIPE, 0,
				       td->pipe, 0,
				       &inter, sizeof(int));
			remove(td);
		}
		else
			break;
	}

	task_clock();
	return 0;
}

extern struct dev_desc gtimer_dev_desc;
void timer_init()
{
	void *data;
	ticks = 0;
	INIT_LIST_HEAD(&timer_list);
	dev_register(DEV_MAJOR_PIT, &timer_dev_desc);
	dev_register(DEV_MAJOR_TIMER, &gtimer_dev_desc);
	dev_simp_open(DEV_MAJOR_PIT, 0, 0, &data);
	dev_simp_ioctl(DEV_MAJOR_PIT, 0, data,
		       TIMER_CMD_SETFREQ, (void *)HZ);
	irq_register(IRQ_TIMER, do_timer_int);
	pic_enable_irq(IRQ_TIMER);
}


static int timer_open(int minor, int mode, void **data)
{
	struct timer_data *td;
	td = kmalloc(sizeof(struct timer_data));
	INIT_LIST_HEAD(&(td->list));
	*data = td;
	dev_simp_open(DEV_MAJOR_PIPE, 0, 0, &(td->pipe));
	return 0;
}

static int timer_close(int minor, void *data)
{
	struct timer_data *td = data;
	disable_irq();
	remove(td);
	enable_irq();
	kfree(td);
	dev_simp_close(DEV_MAJOR_PIPE, 0, td->pipe);
	return 0;
}

static long timer_read(int minor, void *data, void *buf, long n, long off)
{
	struct timer_data *td = data;
	return dev_simp_read(DEV_MAJOR_PIPE, 0, td->pipe, off, buf, n);
}

static long timer_write(int minor, void *data, void *buf, long n, long off)
{
	struct timer_data *td = data;
	int inter;
	if(n != sizeof(int))
		return -EINVAL;
	inter = *((int *)buf);
	inter = inter * HZ / USR_HZ;
	if(inter < 0)
		return -EINVAL;
	disable_irq();
	remove(td);
	td->tick = ticks + inter;
	td->inter = inter;
	insert(td);
	enable_irq();
	return n;
}

static int timer_poll(int minor, void *data, int func, struct list_head *lsem)
{
	struct timer_data *td = data;
	return dev_simp_poll(DEV_MAJOR_PIPE, 0, td->pipe, func, lsem);
}

struct dev_desc gtimer_dev_desc = {
	.name = "timer",
	.open = timer_open,
	.close = timer_close,
	.read = timer_read,
	.write = timer_write,
	.poll = timer_poll,
};
