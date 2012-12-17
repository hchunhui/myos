#include <lib/klib.h>
#include <os/devfs.h>
#include <lib/string.h>
#include <lib/stdarg.h>

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
