#include <drv/tty.h>
#include <os/arch_config.h>
#include <os/task.h>
#include <lib/klib.h>
#include <os/mm.h>
#include <lib/string.h>
#include <libc/kstru.h>
#include <os/io.h>

//ports
#define CRT_ADDR	0x3d4
#define CRT_DATA	0x3d5

//index
#define CRT_IDX_START_ADDR_H	0xc
#define CRT_IDX_START_ADDR_L	0xd
#define CRT_IDX_CURSOR_H	0xe
#define CRT_IDX_CURSOR_L	0xf

static int cpos;
static int start_addr;
static int base_addr;
static int orgi_mode;
static int now_mode;
static u32 graph_base_addr;
static u32 graph_x,graph_y,graph_d;

static void update_cursor()
{
	outb_p(CRT_IDX_CURSOR_H, CRT_ADDR);
	outb(cpos>>8, CRT_DATA);
	outb_p(CRT_IDX_CURSOR_L, CRT_ADDR);
	outb(cpos&0xff, CRT_DATA);
}

static void update_start_addr()
{
	outb_p(CRT_IDX_START_ADDR_H, CRT_ADDR);
	outb(start_addr>>8, CRT_DATA);
	outb_p(CRT_IDX_START_ADDR_L, CRT_ADDR);
	outb(start_addr&0xff, CRT_DATA);
}

int drv_video_reset_mode()
{
	int ret=drv_video_set_mode(orgi_mode);
	return ret;
}

int drv_video_get_mode()
{
	int eax;
	int mode;
	eax=0x4f03;
	mode = 1;
	real_mode_int(0x10,&eax,&mode);
	printk("drv_video_get_mode: %x\n",mode&0xffff);
	now_mode=mode;
	return mode&0xffff;
}

int drv_video_set_mode(int mode)
{
	int eax,ebx;
	eax=0x4f02;
	ebx=mode;
	if(mode==now_mode)
	{
		return 0x4f;
	}
	real_mode_int(0x10,&eax,&ebx);
	printk("drv_video_set_mode: %x\n",mode&0xffff);
	if((eax&0xffff)!=0x4f)
		printk("drv_video_set_mode:set failed.\n");
	else	now_mode=mode;
	return eax&0xffff;
}

void drv_video_set_base_addr(u32 ba)
{
	base_addr=ba;
}

void drv_video_set_start_addr(u32 sa)
{
	start_addr=sa;
	update_start_addr();
}

void drv_video_set_cpos(int pos)
{
	cpos=pos;
	update_cursor();
}

u32 drv_video_get_start_addr()
{
	u32 sa=start_addr;
	return sa;
}

int drv_video_get_cpos()
{
	u32 pos=cpos;
	return pos;
}

void drv_video_down_screen(int delta)
{
	start_addr+=80*delta;
	if(start_addr<0)start_addr=0;
	update_start_addr();
}

/*static void backward()
{
	int base = 0x000A0000, size = (128<<10); // 128K

	// prologue
	outw( 0x0100, 0x3C4 );	// enter synchronous reset
	outw( 0x0402, 0x3C4 );	// write only to map 2
	outw( 0x0704, 0x3C4 );	// use sequential addressing
	outw( 0x0300, 0x3C4 );	// leave synchronous reset
	outw( 0x0204, 0x3CE );	// select map 2 for reads
	outw( 0x0005, 0x3CE );	// disable odd-even addressing
	outw( 0x0006, 0x3CE );	// map starts at 0xA000:0000
	
	// modify the contents of character generator ram
	unsigned char *vram = (unsigned char*)base;
	int i,j;
	for (i = 0; i < 32*256; i++)
		{
			unsigned char orig = vram[ i ],revs=0;
			for (j = 0; j < 8; j++)
				if ( orig & (1<<j) ) revs |= 1<<(7-j);
			vram[i] = revs;
		}

	// epilogue
	outw( 0x0100, 0x3C4 );	// enter synchronous reset
	outw( 0x0302, 0x3C4 );	// write to maps 0 and 1
	outw( 0x0304, 0x3C4 );	// use odd-even addressing
	outw( 0x0300, 0x3C4 );	// leave synchronous reset
	outw( 0x0004, 0x3CE );	// select map 0 for reads
	outw( 0x1005, 0x3CE );	// enable odd-even addressing
	outw( 0x0E06, 0x3CE );	// map starts at 0xB800:0000
}*/

void drv_video_clear()
{
	u16 *video_base=(u16*)video_text_base_addr;
	int len=video_text_len/2;
	for(;len;len--)*video_base++=(CHAR_ATTR<<8);
}

void drv_video_graph_clear()
{
	memset((void *)graph_base_addr,0xff,graph_x*graph_y*graph_d/8);
}

void drv_video_get_graph_info(struct myos_graph_info *info)
{
	info->x=graph_x;
	info->y=graph_y;
	info->depth=graph_d;
	info->base_addr=(void *)graph_base_addr;
}

void drv_video_init()
{
	update_cursor();
	
	orgi_mode=drv_video_get_mode();
	//backward();
	
	//graph mode init
	struct vbe_mode_info *mf=(void *)0x1000;	//请与realmode.S同步
	int eax=0x4f01,ecx=video_graph_mode&0xfff;
	real_mode_int(0x10,&eax,&ecx);
	int pg=(mf->PhysBasePtr)/PAGE_SIZE;
	int i;
	graph_base_addr=mf->PhysBasePtr;
	graph_x=mf->XResolution;
	graph_y=mf->YResolution;
	graph_d=mf->BitsPerPixel;
	printk("video init:\n\t"
		"Base Addr: 0x%x\n\t"
		"X Resolution: %d\n\t"
		"Y Resolution: %d\n\t"
		"Bits Per Pixel: %d\n",
		graph_base_addr,
		graph_x,
		graph_y,
		graph_d);
	
	printk("video init: self map ok.\n");
}

void drv_video_goxy(int x,int y)
{
	cpos=base_addr+(80*(x-1)+y-1);
	update_cursor();
}

void drv_video_putchar(unsigned char x,int attr)
{
	u16 *video_base=(u16*)video_text_base_addr;
	if(x=='\n')
	{
		cpos+=80-( (cpos-base_addr)%80 );
		goto quit;
	}
	if(x=='\b')
	{
		cpos--;
		*(video_base+cpos)=(attr<<8)|' ';
		goto quit;
	}
	*(video_base+cpos)=(attr<<8)|x;
	cpos++;
quit:	
	if(cpos>=( base_addr +80*25*2))
	{
		int i;
		u32 sa=(u32)video_base+start_addr*2;
		u32 da=(u32)video_base+base_addr*2;
		memcpy(da, sa, 80*25*2);
		for(i = 0; i < 80*25; i++)
		{
			((u16 *)sa)[i] = (CHAR_ATTR<<8);
		}
		
		/* asm volatile ( */
		/* "cld;rep movsl" */
		/* ::"S"(sa),"D"(da),"c"(80*25*2/4):"memory"); */
		/* asm volatile ( */
		/* "cld;rep stosl" */
		/* ::"a"((CHAR_ATTR<<8)|(CHAR_ATTR<<24)),"D"(sa),"c"(80*25*2/4):"memory"); */
		cpos=base_addr+80*25;
		update_cursor();
		start_addr=base_addr;
		update_start_addr();
	}
	if(cpos>=(start_addr+80*25))drv_video_down_screen(1);
	update_cursor();
}

