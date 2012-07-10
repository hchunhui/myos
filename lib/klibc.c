#include <lib/klib.h>
#include <os/devfs.h>
#include <lib/string.h>
#include <drv/kdev.h>

void panic(char* text)
{
	asm volatile ("cli");	//机器停转
	//drv_tty_switch(0);
	printk("\nkernel panic: %s\n", text);
	for(;;)
		asm volatile ("hlt");
}

void print_early(char *obj)
{
	fsys_devfs.write(&den_video, 0, obj, strlen(obj));
}
