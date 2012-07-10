#ifndef _KLIB_H_
#define _KLIB_H_
//screen
extern void (*print)(char* obj);
void panic(char* text);
int printk(const char* fmt,...);
//kmalloc
void* kmalloc(int size);
void kmalloc_init();
void kfree(void* ptr);
#endif
