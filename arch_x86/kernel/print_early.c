#include <lib/string.h>
#include <os/io.h>
#define PORT 0x3f8

void video_early_print(char *buf, int n);

void print_early_init()
{
	outb_p(0x00, PORT+1);
	outb_p(0x80, PORT+3);
	outb_p(0x03, PORT+0);
	outb_p(0x00, PORT+1);
	outb_p(0x03, PORT+3);
	outb_p(0xc7, PORT+2);
	outb_p(0x0b, PORT+4);
}

void print_early(char *obj)
{
	int n;
	n = strlen(obj);
	video_early_print(obj, n);
	for(;n--;) {
		while((inb(PORT+5)&0x20) == 0);
		outb(*obj++, PORT);
	}
}

