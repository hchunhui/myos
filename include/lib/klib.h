#ifndef _KLIB_H_
#define _KLIB_H_
#include <lib/stdarg.h>
//screen
extern void (*print)(char *obj);

void print_early(char *obj);

void __panic(const char *file, int line, const char *func, const char *fmt,...)
__attribute__((noreturn));

int vsprintf(char *buf, const char *fmt, va_list args);
int printk(const char *fmt,...);
#define panic(...) __panic(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define assert(exp) do { if(!(exp)) panic("assert failure: "#exp); } while(0)

//kmalloc
void* kmalloc(int size);
void kmalloc_init();
void kfree(void* ptr);
#endif
