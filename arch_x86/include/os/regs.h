#ifndef _REGS_H_
#define _REGS_H_
#include <os/type.h>
#if 0
struct s_regs
{
	u32 es;
	u32 ds;
	u32 di;
	u32 si;
	u32 bp;
	u32 bx;
	u32 dx;
	u32 cx;
	u32 ax;
	u32 err_code;
	u32 ip;
	u32 cs;
	u32 flags;
	u32 sp;
	u32 ss;
}__attribute__((packed));
#else
struct s_regs
{
	unsigned long bx;
	unsigned long cx;
	unsigned long dx;
	unsigned long si;
	unsigned long di;
	unsigned long bp;
	unsigned long ax;
	unsigned long ds;
	unsigned long es;
	unsigned long err_code;
	unsigned long ip;
	unsigned long cs;
	unsigned long flags;
	unsigned long sp;
	unsigned long ss;
};
#endif
#endif /* _REGS_H_ */
