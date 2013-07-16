#include <libc/libc.h>
extern "C"
	{
	int __cxa_atexit(void (*f)(void *), void *p, void *d);
	void __cxa_finalize(void *d);
	};

void *__dso_handle; /*only the address of this symbol is taken by gcc*/

struct object
{
	void (*f)(void*);
	void *p;
	void *d;
} object[64];
unsigned int __cxa_atexit_count = 0;

int __cxa_atexit(void (*f)(void *), void *p, void *d)
{
	if (__cxa_atexit_count >= 64) return -1;
	object[__cxa_atexit_count].f = f;
	object[__cxa_atexit_count].p = p;
	object[__cxa_atexit_count].d = d;
	++__cxa_atexit_count;
	// printf("atexit: f=%x p=%x d=%x iObject=%d\n", f, p, d, iObject);
	return 0;
}

/* This currently destroys all objects */
void __cxa_finalize(void *d)
{
	unsigned int i = __cxa_atexit_count;
	if(d)
	{
		return;
	}
	for (; i > 0; --i)
	{
		--__cxa_atexit_count;
		object[__cxa_atexit_count].f(object[__cxa_atexit_count].p);
		//printf("finalize: iObject=%d\n", iObject);
        }
}

extern "C" void __cxa_pure_virtual()
{
	// print error message
}

void * operator new(unsigned int size)
{
	void *p = malloc(size);
	return (p);
}
void operator delete(void *p)
{
	free(p);
}

void * operator new[](unsigned int size)
{
	void *p = malloc(size);
	return (p);
}
void operator delete[](void *p)
{
	free(p);
}


