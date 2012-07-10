#include <lib/klib.h>

void drv_tty_put_rqueue()
{
}

void drv_video_get_graph_info()
{
}

void drv_video_clear()
{
	printk("clear\n");
}

void drv_video_goxy(int x,int y)
{
	printk("goxy(%d, %d)\n", x, y);
}

void drv_video_putchar(unsigned char x,int attr)
{
	putchar(x);
}

