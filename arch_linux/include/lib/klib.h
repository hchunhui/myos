#ifndef _KLIB_H_
#define _KLIB_H_

static inline void goxy(int x,int y)
{
	printf("goxy");
}

static inline void print(char* obj)
{
	printf("%s\n", obj);
}

static inline void panic(char* text)
{
	printf("panic: %s\n", text);
	exit(1);
}

#define printk printf
#define kmalloc malloc
#define kfree free

#endif /* _KLIB_H_ */
