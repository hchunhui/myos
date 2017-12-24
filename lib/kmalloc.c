#include <os/type.h>
#include <os/arch_config.h>
#include <lib/klib.h>
#include <lib/string.h>
#define MAP_MAX	4096
static const int limit[]={
		4096	,	/* 1byte 1p*/
		2048	,	/* 2byte 1p*/
		2048	,	/* 4byte 2p*/
		2048	,	/* 8byte 4p*/
		2048	,	/* 16byte 8p*/
		2048	,	/* 32byte 16p*/
		2048	,	/* 64byte 32p*/
		2048	,	/* 128byte 64p*/
		1024	,	/* 256byte 64p*/
		512	,	/* 512byte 64p*/
		256	,	/* 1024byte 64p*/
		128	,	/* 2048byte 64p*/
		256	,	/* 4096byte 256p*/
		64	,	/* 8192byte 128p*/
		-1	,	/* end */
	};

static char heap[4096*(1+1+2+4+8+16+32+64+64+64+64+64+256+128)]
__attribute__((aligned(4096)));

static struct s_mem
{
	unsigned long start_addr;
	char map[MAP_MAX];
}mem_map[20];

void kmalloc_init()
{
	int i;
	unsigned long addr = (unsigned long) heap;

	memset(mem_map,0,sizeof(mem_map));
	for(i=0;limit[i]!=-1;i++)
	{
		mem_map[i].start_addr=addr;
		addr+=(1<<i)*limit[i];
	}
}

void* kmalloc(int size)
{
	int i,n,t=size;
	assert(size > 0 && size <= 8192);
	for(n=-1;t>0;n++)t/=2;
	if(size-(1<<n))n++;

	for(i=0;i<limit[n];i++)
	{
		if(mem_map[n].map[i]==0)
		{
			unsigned long ret=mem_map[n].start_addr+(1<<n)*i;
			mem_map[n].map[i]=1;
			return (void*)ret;
		}
	}
	panic("kmalloc: no memory\n");
}

void kfree(void* ptr)
{
	unsigned long nr = (unsigned long) ptr;
	unsigned long start = (unsigned long) heap;
	int i;
	if(ptr == NULL)
		return;
	if(nr < start)
		panic("addr error! nr=%x\n", nr);
	nr -= start;
	for(i=0;limit[i]!=-1;i++)
	{
		if(nr<limit[i]*(1<<i))break;
		nr-=limit[i]*(1<<i);
	}
	if(limit[i]!=-1)
	{
		if(nr%(1<<i))
			panic("addr error2!\n");
		nr/=(1<<i);
		if(!mem_map[i].map[nr])
			panic("free a free addr!\n");
		mem_map[i].map[nr]=0;
		return;
	}
	panic("ptr=%x not found.", ptr);
}

