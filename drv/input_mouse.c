/*
 *  mouse driver
 */
#include <os/asm.h>
#include <os/arch_config.h>
#include <os/type.h>
#include <lib/klib.h>
#include <lib/string.h>
#include <os/isr.h>
#include <os/io.h>
#include <drv/i8042.h>
#include <os/sem.h>
#include <drv/input.h>
#include <os/vfs.h>
#include <os/task.h>
#include <os/timer.h>
#define xstr(s) str(s)
#define str(x) #x

extern struct input_dev_desc mouse_desc;

void mouse_thread()
{
	int fd;
	struct s_event event;
	fd = vfs_open("/dev/input/"xstr(INPUT_MINOR_MOUSE), 0);
	assert(fd != -1);
	printk("mousefd = %d\n", fd);

	enable_irq();
	for(;;)
	{
		vfs_read(fd, &event, sizeof(event));
		printk("tick=%d type=%d code=%x value=(%d,%d)\n",
		       event.ticks,
		       event.type,
		       event.code,
		       (short)(event.value>>16),
		       (short)(event.value&0xffff));
	}
}

struct mouse_int_state {
	int last_tick;
	int xdiff;
	int ydiff;
	int count;
	int xsgn;
	int ysgn;
	int lrb;
};

static int mouse_int(struct s_regs *pregs, void *state)
{
	struct mouse_int_state *s = state;
	unsigned char data = inb(0x60);
	struct s_event event;
	int ticks = timer_get_ticks();

	//trick:在真机上数据对不上号，用ticks计时，把过早数据丢弃
	if(ticks - s->last_tick > 5)
		s->count = 0;
	switch (++s->count)
	{
		case 1:
			s->lrb = data & 0x7;
			s->xsgn = (data & 0x10) ? (~0xff) : 0;
			s->ysgn = (data & 0x20) ? (~0xff) : 0;
			break;
		case 2:
			s->xdiff = (s->xsgn | data);
			break;
		case 3:
			s->ydiff = -(s->ysgn | data);
			s->count = 0;
			/* printk("xdiff=%d, ydiff=%d\n", */
			/*        xdiff, */
			/*        ydiff); */
			event.ticks = ticks;
			event.type = 2;
			event.code = s->lrb;
			event.value = (s->xdiff<<16) | (s->ydiff&0xffff);
			input_dev_event(&mouse_desc, &event);
			break;
	}
	s->last_tick = ticks;
	return 0;
}

static int mouse_init()
{
	struct mouse_int_state *s;
	printk("mouse: up\n");
	s = kmalloc(sizeof(struct mouse_int_state));
	memset(s, 0, sizeof(struct mouse_int_state));
	s->last_tick = timer_get_ticks();
	irq_register(IRQ_MOUSE, mouse_int, s);
	pic_enable_irq(IRQ_MOUSE);
	return 0;
}

static int mouse_exit()
{
	printk("mouse: down\n");
	// TODO: free mouse_int_state
	return 0;
}

struct input_dev_desc mouse_desc = {
	.name = "mouse",
	.init = mouse_init,
	.exit = mouse_exit,
};
