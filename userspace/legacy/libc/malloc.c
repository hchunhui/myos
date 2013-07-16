#include <os/type.h>
#include <libc/libc.h>
#include <lib/string.h>

#define MAP_MAX	8192
#define malloc_mem_start 100*1024*1024
const static int limit[]={
		8192	,	/* 1byte 2p*/
		8192	,	/* 2byte 4p*/
		8192	,	/* 4byte 8p*/
		8192	,	/* 8byte 16p*/
		8192	,	/* 16byte 32p*/
		8192	,	/* 32byte 64p*/
		8192	,	/* 64byte 128p*/
		8192	,	/* 128byte 256p*/
		8192	,	/* 256byte 512p*/
		4096	,	/* 512byte 512p*/
		2048	,	/* 1024byte 512p*/
		1024	,	/* 2048byte 512p*/
		512	,	/* 4096byte 512p*/
		256	,	/* 8192byte 512p*/
		-1	,	/* end */
	};

static struct s_mem
{
	unsigned long start_addr;
	char map[MAP_MAX];
}mem_map[20];

void malloc_init()
{
	int i;
	unsigned long addr=malloc_mem_start;
	memset(mem_map,0,sizeof(mem_map));
	for(i=0;limit[i]!=-1;i++)
	{
		mem_map[i].start_addr=addr;
		//printk("%p\n",addr);
		addr+=(1<<i)*limit[i];
	}
	//for(;;);
}

void *malloc(int size)
{
	int i,n,t=size;
	if(size<=0)
	{
		//panic("kmalloc size<=0\n");
		return NULL;
	}
	if(size>8192)
	{
		//panic("kmalloc: size>8192\n");
		return NULL;
	}
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
	//panic("kmalloc: no memory\n");
	return NULL;
}

void free(void* ptr)
{
	unsigned long nr=(unsigned long)ptr;
	int i;
	if(nr<malloc_mem_start)
	{
		//printk("nr=%x\n",nr);
		//panic("kfree: addr error!\n");
		return;
	}
	nr-=malloc_mem_start;
	for(i=0;limit[i]!=-1;i++)
	{
		if(nr<limit[i]*(1<<i))break;
		nr-=limit[i]*(1<<i);
	}
	if(limit[i]!=-1)
	{
		if(nr%(1<<i))
		{
			//panic("kfree: addr error2!\n");
			return;
		}
		nr/=(1<<i);
		//printk("kfree: real size=%d,nr=%d\n",(1<<i),nr);
		if(!mem_map[i].map[nr])
		{
			//panic("kfree: free a free addr!\n");
			return;
		}
		mem_map[i].map[nr]=0;
		//printk("kfree: ok.\n");
		return;
	}
	//printk("kfree: ptr=%x\n",ptr);
	//panic("kfree: not found.");
}

