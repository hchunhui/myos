#ifndef _IO_H_
#define _IO_H_
#include <type.h>

static inline void outb(u8 v, u16 port)
{
}

static inline void outw(u16 v, u16 port)
{
}

static inline void outl(u32 v, u16 port)
{
}

static inline u8 inb(u16 port)
{
	return 0;
}

static inline u16 inw(u16 port)
{
	return 0;
}

static inline u32 inl(u16 port)
{
	return 0;
}

static inline void io_delay(void)
{
	return 0;
}

static inline void outb_p(u8 v, u16 port)
{
	io_delay();
}

static inline void outw_p(u16 v, u16 port)
{
	io_delay();
}

static inline void outl_p(u32 v, u16 port)
{
	io_delay();
}

static inline u8 inb_p(u16 port)
{
	io_delay();
	return 0;
}

static inline u16 inw_p(u16 port)
{
	io_delay();
	return 0;
}

static inline u32 inl_p(u16 port)
{
	io_delay();
	return 0;
}

#endif /* _IO_H_ */
