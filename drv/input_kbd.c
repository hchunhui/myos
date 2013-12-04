/*
 *  keyboard driver
 */
#include <os/arch_config.h>
#include <os/type.h>
#include <lib/klib.h>
#include <os/isr.h>
#include <os/io.h>
#include <drv/i8042.h>
#include <os/sem.h>
#include <drv/input.h>
#include <os/task.h>
#include <os/vfs.h>
#define xstr(s) str(s)
#define str(x) #x
#define CODE_BRK	0xf0
#define CODE_EX0	0xe0
#define CODE_EX1	0xe1
int is_brk;
int is_ex;
int follow;
int gcode;
extern struct input_dev_desc kbd_desc;

void kbd_thread()
{
	struct s_event event;
	int fd;
	fd = vfs_open("/dev/input/"xstr(INPUT_MINOR_KBD), 0);
	assert(fd != -1);
	printk("kbdfd = %d\n", fd);
	asm("sti");
	for(;;)
	{
		vfs_read(fd, &event, sizeof(event));
		printk("tick=%d type=%d code=%x value=%d level=%d resched=%d\n",
		       event.ticks,
		       event.type,
		       event.code,
		       event.value,
		       current->level,
		       current->resched);
	}
}

static int kbd_int()
{
	struct s_event event;
	unsigned char code = inb(0x60);
	
	switch(code)
	{
	case CODE_BRK:
		is_brk = 1;
		if(!is_ex)
			gcode = 0;
		break;
	case CODE_EX0:
		is_ex = 1;
		follow = 1;
		gcode = 0xe0;
		break;
	case CODE_EX1:
		is_ex = 2;
		follow = 2;
		gcode = 0;
		break;
	default:
		if(!is_ex)
			follow = 1;
		gcode <<= 8;
		gcode |= code;
		follow--;
		if(follow == 0)
		{
			event.ticks = timer_get_ticks();
			event.type = 1;
			event.code = gcode;
			event.value = is_brk;
			input_dev_event(&kbd_desc, &event);
			/*printk("ex=%d, brk=%d, gcode=%x\n",
			       is_ex,
			       is_brk,
			       gcode);*/
			is_ex = 0;
			is_brk = 0;
			gcode = 0;
		}
		break;
	}
	return 0;
}

static int kbd_init()
{
	printk("kbd up\n");
	irq_register(IRQ_KB, kbd_int);
	pic_enable_irq(IRQ_KB);
	return 0;
}

static int kbd_exit()
{
	printk("kbd down\n");
	return 0;
}

struct input_dev_desc kbd_desc = {
	.name = "keyboard",
	.init = kbd_init,
	.exit = kbd_exit,
};
