#include <os/type.h>
#include <os/arch_config.h>
#include <lib/klib.h>
#include <lib/string.h>
#define MAP_MAX	4096
const static int limit[]={
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

static struct s_mem
{
	unsigned long start_addr;
	char map[MAP_MAX];
}mem_map[20];

void kmalloc_init()
{
	int i;
	unsigned long addr=kmalloc_mem_start;
	memset(mem_map,0,sizeof(mem_map));
	for(i=0;limit[i]!=-1;i++)
	{
		mem_map[i].start_addr=addr;
		//printk("%p\n",addr);
		addr+=(1<<i)*limit[i];
	}
	//for(;;);
}

void* kmalloc(int size)
{
	int i,n,t=size;
	assert(size > 0 && size <= 8192);
	for(n=-1;t>0;n++)t/=2;
	if(size-(1<<n))n++;
	//printk("kmalloc: ask size=%d , real size=%d   ",size, 1<<n);
	for(i=0;i<limit[n];i++)
	{
		if(mem_map[n].map[i]==0)
		{
			unsigned long ret=mem_map[n].start_addr+(1<<n)*i;
			mem_map[n].map[i]=1;
			//printk("kmalloc: get %d, addr=%p\n",i,ret);
			return (void*)ret;
		}
	}
	panic("kmalloc: no memory\n");
}

void kfree(void* ptr)
{
	unsigned long nr=(unsigned long)ptr;
	int i;
	if(nr<kmalloc_mem_start)
		panic("addr error! nr=%x\n", nr);
	nr-=kmalloc_mem_start;
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
		//printk("kfree: real size=%d,nr=%d\n",(1<<i),nr);
		if(!mem_map[i].map[nr])
			panic("free a free addr!\n");
		mem_map[i].map[nr]=0;
		//printk("kfree: ok.\n");
		return;
	}
	panic("ptr=%x not found.", ptr);
}

