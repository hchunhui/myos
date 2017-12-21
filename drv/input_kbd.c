/*
 *  keyboard driver
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
#include <os/task.h>
#include <os/vfs.h>
#include <os/timer.h>
#define xstr(s) str(s)
#define str(x) #x
#define CODE_BRK	0xf0
#define CODE_EX0	0xe0
#define CODE_EX1	0xe1
extern struct input_dev_desc kbd_desc;

void kbd_thread()
{
	struct s_event event;
	int fd;
	fd = vfs_open("/dev/input/"xstr(INPUT_MINOR_KBD), 0);
	assert(fd != -1);
	printk("kbdfd = %d\n", fd);

	enable_irq();
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

struct kb_int_state {
	int is_brk;
	int is_ex;
	int follow;
	int gcode;
};

static int kbd_int(struct s_regs *pregs, void *data)
{
	struct s_event event;
	struct kb_int_state *s = data;
	unsigned char code = inb(0x60);

	switch(code)
	{
	case CODE_BRK:
		s->is_brk = 1;
		if(!s->is_ex)
			s->gcode = 0;
		break;
	case CODE_EX0:
		s->is_ex = 1;
		s->follow = 1;
		s->gcode = 0xe0;
		break;
	case CODE_EX1:
		s->is_ex = 2;
		s->follow = 2;
		s->gcode = 0;
		break;
	default:
		if(!s->is_ex)
			s->follow = 1;
		s->gcode <<= 8;
		s->gcode |= code;
		s->follow--;
		if(s->follow == 0)
		{
			event.ticks = timer_get_ticks();
			event.type = 1;
			event.code = s->gcode;
			event.value = s->is_brk;
			input_dev_event(&kbd_desc, &event);
			/*printk("ex=%d, brk=%d, gcode=%x\n",
			       is_ex,
			       is_brk,
			       gcode);*/
			s->is_ex = 0;
			s->is_brk = 0;
			s->gcode = 0;
		}
		break;
	}
	return 0;
}

static int kbd_init()
{
	struct kb_int_state *s;
	printk("kbd: up\n");
	s = kmalloc(sizeof(struct kb_int_state));
	memset(s, 0, sizeof(struct kb_int_state));
	irq_register(IRQ_KB, kbd_int, s);
	pic_enable_irq(IRQ_KB);
	return 0;
}

static int kbd_exit()
{
	printk("kbd: down\n");
	// TODO: free kb_int_state
	return 0;
}

struct input_dev_desc kbd_desc = {
	.name = "keyboard",
	.init = kbd_init,
	.exit = kbd_exit,
};
