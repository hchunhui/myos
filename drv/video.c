#include <os/arch_config.h>
#include <os/task.h>
#include <lib/klib.h>
#include <os/mm.h>
#include <lib/string.h>
#include <os/io.h>
#include <drv/video.h>

struct vbe_mode_info         /* VESA information for a specific mode */
{
   u16 ModeAttributes;
   u8  WinAAttributes;
   u8  WinBAttributes;
   u16 WinGranularity;
   u16 WinSize;
   u16 WinASegment;
   u16 WinBSegment;
   u32  WinFuncPtr;
   u16 BytesPerScanLine;
   u16 XResolution;
   u16 YResolution;
   u8  XCharSize;
   u8  YCharSize;
   u8  NumberOfPlanes;
   u8  BitsPerPixel;
   u8  NumberOfBanks;
   u8  MemoryModel;
   u8  BankSize;      
   u8  NumberOfImagePages;
   u8  Reserved_page;   
   u8  RedMaskSize; 
   u8  RedMaskPos;      
   u8  GreenMaskSize;      
   u8  GreenMaskPos;      
   u8  BlueMaskSize;      
   u8  BlueMaskPos;        
   u8  ReservedMaskSize;  
   u8  ReservedMaskPos;    
   u8  DirectColorModeInfo; 
   /* VBE 2.0 extensions */
   u32  PhysBasePtr;      
   u32  Reserved2;
   u16  Reserved1; 
   /* VBE 3.0 extensions */
   u16 LinBytesPerScanLine;
   u8  BnkNumberOfPages;   
   u8  LinGreenMaskSize;  
   u8  LinGreenFieldPos;   
   u8  LinBlueMaskSize;   
   u8  LinBlueFieldPos;    
   u8  LinRsvdMaskSize;   
   u8  LinRsvdFieldPos;   
   u32  MaxPixelClock;    
   u8  Reserved[190];    
}__attribute__((packed));

//mem
#define video_text_base_addr	0xb8000
#define video_text_len		(32<<10)
#define video_text_mode		0x3
#define video_graph_mode	0x4114

//ports
#define CRT_ADDR	0x3d4
#define CRT_DATA	0x3d5

//index
#define CRT_IDX_START_ADDR_H	0xc
#define CRT_IDX_START_ADDR_L	0xd
#define CRT_IDX_CURSOR_H	0xe
#define CRT_IDX_CURSOR_L	0xf

#define CHAR_ATTR 0x07

static int cpos;
static int start_addr;
static int orig_mode;
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

static int video_get_mode()
{
	int eax;
	int mode;
	eax = 0x4f03;
	mode = 1;
	real_mode_int(0x10, &eax, &mode);
	printk("video_get_mode: %x\n", mode&0xffff);
	now_mode = mode;
	return mode&0xffff;
}

static int video_set_mode(int mode)
{
	int eax, ebx;
	eax = 0x4f02;
	ebx = mode;
	if(mode == now_mode)
		return 0x4f;
	real_mode_int(0x10, &eax, &ebx);
	printk("video_set_mode: %x\n", mode&0xffff);
	if((eax&0xffff) != 0x4f)
		printk("video_set_mode: set failed.\n");
	else
		now_mode = mode;
	return eax&0xffff;
}

static int video_reset_mode()
{
	return video_set_mode(orig_mode);
}

static void video_set_start_addr(u32 sa)
{
	start_addr = sa;
	update_start_addr();
}

static void video_down_screen(int delta)
{
	start_addr += 80*delta;
	if(start_addr < 0)
		start_addr = 0;
	update_start_addr();
}

static void video_get_graph_info(struct myos_graph_info *info)
{
	info->x = graph_x;
	info->y = graph_y;
	info->depth = graph_d;
	info->base_addr = (void *)graph_base_addr;
}

static void video_putchar(unsigned char x,int attr)
{
	int step;
	u16 *video_base = (u16*)video_text_base_addr;
	switch(x)
	{
	case '\n':
		cpos += 80 - cpos%80;
		break;
	case '\b':
		do {
			cpos--;
			*(video_base + cpos) = (attr<<8) | ' ';
		}while(*(video_base+cpos-1) == 65535 && cpos%8);
		break;
	case '\t':
		step = 8 - cpos%8;
		for(;step;step--)
			*(video_base + (cpos++)) = -1;
		break;
	case 0:
		break;
	default:
		*(video_base + cpos) = (attr<<8) | x;
		cpos++;
		break;
	}
	if(cpos >= 80*25*2)
	{
		int i;
		u32 sa = (u32)video_base + start_addr*2;
		u32 da = (u32)video_base;
		memcpy((void *)da, (void *)sa, 80*25*2);
		for(i = 0; i < 80*25; i++)
		{
			((u16 *)sa)[i] = (CHAR_ATTR<<8);
		}
		cpos = 80*25;
		update_cursor();
		start_addr = 0;
		update_start_addr();
	}
	if(cpos >= (start_addr + 80*25))
		video_down_screen(1);
	update_cursor();
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

static int video_init()
{
	struct vbe_mode_info *mf = (void *)0x1000;
	u16 *base = (u16 *)video_text_base_addr;
	int len = video_text_len/2;
	int eax, ecx;
	for(; len; len--)
		*base++ = (CHAR_ATTR<<8);
	cpos = 0;
	update_cursor();

	orig_mode = video_get_mode();
	eax = 0x4f01;
	ecx = video_graph_mode&0xfff;
	real_mode_int(0x10, &eax, &ecx);
	graph_base_addr = mf->PhysBasePtr;
	graph_x = mf->XResolution;
	graph_y = mf->YResolution;
	graph_d = mf->BitsPerPixel;
	printk("video init:\n"
	       "Base Addr: 0x%x\n"
	       "X Resolution: %d\n"
	       "Y Resolution: %d\n"
	       "Bits Per Pixel: %d\n",
	       graph_base_addr,
	       graph_x,
	       graph_y,
	       graph_d);
	printk("video up\n");
	return 0;
}

static int video_ctl(int minor, void *data, int cmd, void *arg)
{
	switch(cmd)
	{
	case VIDEO_CMD_GET_MODE:
		*(int *)arg = video_get_mode();
		break;
	case VIDEO_CMD_SET_MODE:
		video_set_mode(*(int *)arg);
		break;
	case VIDEO_CMD_RESET_MODE:
		video_reset_mode();
		break;
	case VIDEO_CMD_SET_POS:
		cpos = (*(int *)arg)*2 + start_addr;
		update_cursor();
		break;
	case VIDEO_CMD_GET_POS:
		*(int *)arg = (cpos - start_addr)/2;
		break;
	case VIDEO_CMD_DOWN_SCREEN:
		video_down_screen(*(int *)arg);
		break;
	case VIDEO_CMD_GET_INFO:
		video_get_graph_info(arg);
		break;
	}
	return 0;
}

static long video_read(int minor, void *data, void *buf, long n, long off)
{
	return n;
}

static long video_write(int minor, void *data, void *buf, long n, long off)
{
	char *cbuf = buf;
	for(; n; n--, cbuf++)
		video_putchar(*cbuf, CHAR_ATTR);
	return 0;
}

struct dev_desc video_dev_desc = {
	.name = "video",
	.init = video_init,
	.ctl = video_ctl,
	.read = video_read,
	.write = video_write,
};
