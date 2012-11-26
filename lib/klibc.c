#include <lib/klib.h>
#include <os/devfs.h>
#include <lib/string.h>
#include <drv/kdev.h>

void print_early(char *obj)
{
	dev_simp_write(DEV_MAJOR_VIDEO, 0, video_data, 0, obj, strlen(obj));
}

void panic(char *text)
{
	print = print_early;
	printk("\nkernel panic: %s\n", text);
	for(;;);
}
