#include <os/arch_config.h>
#include <drv/tty.h>
#include <lib/klib.h>
#include <os/task.h>
#include <os/asm.h>
#include <os/message.h>
#include <libc/kstru.h>
#include <os/isr.h>
#include <os/io.h>

#define TIME_OUT 1000
int drv_mouse_int();

/* tools begin */
static void empty_8042()
{
	u32 ret;
	int i=TIME_OUT;
	do {
		ret=inb(0x64);
		i--;
	}while((ret&0x2) && i);
	if(i==0)panic("mouse error");
}

static void wait_8042()
{
	u32 ret;
	int i=TIME_OUT;
	do {
		ret=inb(0x64);
		i--;
	}while( (!(ret&0x1)) && i );
	if(i==0)panic("mouse error");
}

static void mouse_out(u32 port,u8 val)
{
	empty_8042();
	outb(val, port);
}

static u8 mouse_in(u32 port)
{
	wait_8042();
	return inb(port);
}
/* tools end */

static int xdiff = 0;
static int ydiff = 0;
static int count = 0;
static int xsgn = 0;
static int ysgn = 0;
static int lrb;

void drv_mouse_init()
{
	u32 ret;
	
	/* 8042 编程 */
	printk("init mouse\n");
	// 允许 鼠标 接口
	mouse_out( 0x64 , 0xa8 ) ;

	// 许可 鼠标 接口
	mouse_out(0x64,0x20);
	ret=mouse_in(0x60);
	ret|=1<<1;
	mouse_out( 0x64 , 0x60 ) ;
	mouse_out( 0x60 , ret ) ;
	
	// 允许 鼠标 发数据
	mouse_out( 0x64 , 0xd4 ) ;
	mouse_out( 0x60 , 0xf4 ) ;

	//开启鼠标中断
	irq_register(IRQ_MOUSE, drv_mouse_int);
	pic_enable_irq(IRQ_MOUSE);
}

static void drv_mouse_send()
{
	MSG msg;
	msg.type = KM_MOUSEACT;
	msg.arg1 = xdiff;
	msg.arg2 = ydiff;
	msg.arg3 = lrb;
	do_send_to_user(&msg);
}

extern int ticks;		//task.c
//鼠标中断处理程序
int drv_mouse_int()
{
	u8 data = inb(0x60);
	static int last_tick;
	//trick:在真机上数据对不上号，用ticks计时，把过早数据丢弃
	
	if(!last_tick) last_tick = ticks;
	if( ticks - last_tick > 5)
		count = 0;
	switch (++count)
	{
		case 1:

			lrb = data & 0x7;
			xsgn = (data & 0x10) ? 0xffffff00 : 0;
			ysgn = (data & 0x20) ? 0xffffff00 : 0;
			break;
		case 2:
			xdiff = (xsgn | data);
			break;
		case 3:
			ydiff = -(ysgn | data);
			count = 0;
			drv_mouse_send();
			break;
	}
	last_tick = ticks;
	return 0;
}

