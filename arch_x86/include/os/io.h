#ifndef _IO_H_
#define _IO_H_
#include <os/type.h>

static inline void outb(u8 v, u16 port)
{
	asm volatile("outb %0,%1" : : "a" (v), "dN" (port));
}

static inline void outw(u16 v, u16 port)
{
	asm volatile("outw %0,%1" : : "a" (v), "dN" (port));
}

static inline void outl(u32 v, u16 port)
{
	asm volatile("outl %0,%1" : : "a" (v), "dN" (port));
}

static inline u8 inb(u16 port)
{
        u8 v;
	asm volatile("inb %1,%0" : "=a" (v) : "dN" (port));
	return v;
}

static inline u16 inw(u16 port)
{
        u16 v;
	asm volatile("inw %1,%0" : "=a" (v) : "dN" (port));
	return v;
}

static inline u32 inl(u16 port)
{
        u32 v;
	asm volatile("inl %1,%0" : "=a" (v) : "dN" (port));
	return v;
}

static inline void io_delay(void)
{
        const u16 DELAY_PORT = 0x80;
	asm volatile("outb %%al,%0" : : "dN" (DELAY_PORT));
}

static inline void outb_p(u8 v, u16 port)
{
	outb(v, port);
	io_delay();
}

static inline void outw_p(u16 v, u16 port)
{
	outw(v, port);
	io_delay();
}

static inline void outl_p(u32 v, u16 port)
{
	outl(v, port);
	io_delay();
}

static inline u8 inb_p(u16 port)
{
        u8 v;
	v = inb(port);
	io_delay();
	return v;
}

static inline u16 inw_p(u16 port)
{
        u16 v;
	v = inw(port);
	io_delay();
	return v;
}

static inline u32 inl_p(u16 port)
{
        u32 v;
	v = inl(port);
	io_delay();
	return v;
}

#endif /* _IO_H_ */
