#ifndef _TTY_H_
#define _TTY_H_
#include <os/type.h>
#include <os/task.h>
#include <libc/kstru.h>

#define video_text_base_addr	0xb8000
#define video_text_len		(32<<10)
#define video_text_mode		0x3
#define video_graph_mode	0x4114

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


#define KBBUF_LEN 64
#define KBSCAN_LEN 128
struct s_kbbuf
{
	char *p,*q;
	char buf[KBBUF_LEN];
	int count;
};

struct s_queue
{
	struct s_task *ptask[NR_TASK];
	struct s_task **p,**q;
};

void drv_kb_lock();
void drv_kb_unlock();
int drv_kb_emptybuf();
char drv_kb_getbuf();
//video.c
void drv_video_goxy(int x,int y);
void drv_video_putchar(unsigned char x,int attr);
void drv_video_down_screen(int delta);
void drv_video_set_start_addr(u32 sa);
void drv_video_set_cpos(int pos);
void drv_video_set_base_addr(u32 ba);
u32 drv_video_get_start_addr();
int drv_video_get_cpos();
void drv_video_clear();

int drv_video_reset_mode();
int drv_video_get_mode();
int drv_video_set_mode(int mode);
void drv_video_graph_clear();
void drv_video_get_graph_info(struct myos_graph_info *info);

//tty.c
int drv_tty_now();
int drv_tty_write(int tty_nr,void* buf,s32 count,int mode);
int drv_tty_read(int tty_nr,void* buf,s32 count);
void drv_tty_switch(int nr);
void drv_tty_goxy(int tty_nr,int x,int y);
int drv_tty_is_setup();
void drv_tty_put_rqueue(struct s_task *ptask);
void drv_tty_wakeup();
#define CHAR_ATTR 0x07
#define NR_TTY 4
#endif
