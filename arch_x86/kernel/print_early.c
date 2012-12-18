#include <lib/string.h>
#include <os/io.h>
#define PORT 0x3f8

void video_early_init();
void video_early_print(char *buf, int n);

void serial_early_init();
void serial_early_print(char *buf, int n);

void print_early_init()
{
	video_early_init();
	serial_early_init();
}

void print_early(char *obj)
{
	int n;
	n = strlen(obj);
//	video_early_print(obj, n);
	for(;n--;) {
		while((inb(PORT+5)&0x20) == 0);
		outb(*obj++, PORT);
	}
}

