#include <stdio.h>
#include <stdlib.h>
#include <lib/klib.h>

void print_early(char *obj)
{
	printf(obj);
}

void __panic(const char *file, int line, const char *func, const char *fmt,...)
{
	va_list args;
	char buf[256];
	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);
	print = print_early;
	printk("\nkernel panic:\n"
	       "FILE: %s\n"
	       "LINE: %d\n"
	       "FUNC: %s\n"
	       "%s\n",
	       file, line, func, buf);
	for(;;);
}

void* kmalloc(int size)
{
	return malloc(size);
}

void kmalloc_init()
{
}

void kfree(void* ptr)
{
	free(ptr);
}

int printk(const char* fmt,...)
{
	va_list args;
	int i;
	char buf[256];
	va_start(args,fmt);
	i=vsprintf(buf,fmt,args);
	va_end(args);
	print(buf);
	return i;
}
