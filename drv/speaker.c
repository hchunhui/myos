#include <drv/speaker.h>
#include <lib/klib.h>
#include <os/asm.h>
#include <os/io.h>

static int open_pid;

void drv_speaker_init()
{
	open_pid = -1;
	printk("drv_speaker_init: ok.\n");
}

static void shutdown()
{
	u8 tmp = (inb(0x61) & 0xFC); 
	outb(tmp, 0x61);
}

static void setfreq(int freq)
{
	u32 div;
	u8 tmp;
	
	div = 1193180 / freq;
	outb(0xb6, 0x43);
	outb((u8)div, 0x42);
	outb((u8)(div>>8), 0x42);
	
	tmp = inb(0x61);
	if(tmp != (tmp | 3))
	{
		outb(tmp | 3, 0x61);
	}
}

int drv_speaker_open(int pid)
{
	printk("drv_speaker_open: pid = %d open_pid=%d\n", pid, open_pid);
	if(open_pid != -1)
		return -1;
	open_pid = pid;
	shutdown();
	return 0;
}

int drv_speaker_read(int pid, int fd, void *buf, int count)
{
	return -1;
}

int drv_speaker_write(int pid, int fd, void *buf, int count)
{
	u16 freq;
	//printk("drv_speaker_write: count=%d openpid=%d ", count, open_pid);
	if(pid != open_pid)
		return -1;
	if(count < sizeof(u16))
	{
		return -1;
	}
	freq = *(u16 *)buf;
	if(freq)
		setfreq(freq);
	else
		shutdown();
	return count - sizeof(u16);
}

int drv_speaker_close(int pid)
{
	if(pid != open_pid)
		return -1;
	open_pid = -1;
	shutdown();
	return 0;
}

