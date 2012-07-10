#include "draw.h"
#include "bmp.h"
#include <type.h>
#include <unistd.h>
#include <libc/libc.h>
#include <string.h>
// from pyos, 大部分已经重写

struct myos_graph_info info;
u16 *video;
static char asctab[16 * 256];

int draw_init(u16 *tmp)
{
	get_graph_info(&info);
	if(info.depth != 16)
	{
		printf("depth!=16\n");
		return 0;
	}
	video = tmp;
	get_module("/asc16", asctab);
	tty_switch(4);
	return 1;
}

// 画点函数
void draw_set_point(u32 x, u32 y, u16 color)
{
	if(x >= info.x)return;
	if(y >= info.y)return;
	video[y*(info.x)+x]=color;
}

// 取得指定点色彩
u16 draw_get_point(u32 x,u32 y)
{
	if(x >= info.x)return 0;
	if(y >= info.y)return 0;
	return video[y*(info.x)+x];
}

// 矩形填充函数
void draw_fill_rect(u32 x1, u32 y1, u32 x2, u32 y2, u16 color)
{
	u32 y;
	u16 *pos;
	u32 w;
	if(x1 >= info.x) return;
	if(y1 >= info.y) return;
	if(x2 >= info.x) return;
	if(y2 >= info.y) return;
	if(x1 > x2 || y1 > y2) return;
	
	pos = video + (y1 * info.x) + x1;
	w = x2 - x1;
	
	asm ("cld");
	for(y = y1; y <= y2; y++)
	{
		asm (
		"rep;stosw"
		::"c"(w),"a"(color),"D"(pos)
		:"memory"
		);
		pos += info.x;
	}
}

// 清屏函数
void draw_clear_screen(u16 color)
{
	asm (
	"rep;stosl"
	::"c"((info.x * info.y) >> 1),"a"((color << 16) | color),"D"(video)
	:"memory"
	);
}

// 拷贝函数
void draw_copy(u32 x, u32 y, u16 *src, u16 *obj, u32 w, u32 h)
{
	int j;
	u32 offset;
	
	if(x >= info.x) return;
	if(y >= info.y) return;
	if(x+w >= info.x)
		w = info.x - x;
	if(y+h >= info.y)
		h = info.y - y;
	offset = y*info.x + x;
	asm ("cld");
	for(j = 0; j < h; j++)
	{
		asm (
		"rep;movsw"
		::"c"(w), "S"(src + offset), "D"(obj + offset)
		:"memory"
		);
		offset += info.x;
	}
}

void draw_window(u32 x, u32 y, u16 *src, u16 *obj, u32 w, u32 h)
{
	int j;
	u32 offset;
	
	if(x >= info.x) return;
	if(y >= info.y) return;
	if(x+w >= info.x)
		w = info.x - x;
	if(y+h >= info.y)
		h = info.y - y;
	offset = 0;
	asm ("cld");
	for(j = 0; j < h; j++)
	{
		asm (
		"rep;movsw"
		::"c"(w), "S"(src + offset), "D"(obj + y*info.x + x + offset)	//注意与draw_copy的不同之处
		:"memory"
		);
		offset += info.x;
	}
}

void draw_cursor_mask(u32 x, u32 y,u16 *src, u16 *obj, u32 w, u32 h, u16 mask)
{	
	int j;
	int i;
	
	if(x >= info.x) return;
	if(y >= info.y) return;
	if(x+w >= info.x)
		w = info.x - x;
	if(y+h >= info.y)
		h = info.y - y;
		
	obj += y*info.x + x;
	
	for(j = 0; j < h; j++)
	{
		for(i = 0; i < w; i++)
		{
			if(src[i] == mask) continue;
			obj[i] = src[i];
		}
		src += info.x;
		obj += info.x;
	}
}

void draw_copy_screen(u16 *src, u16 *obj)
{
	asm("cld;rep;movsl"::"c"(info.x*info.y/2),"S"(src),"D"(obj):"memory");
}

// 画横线函数
void draw_x_line(u32 y, u32 x1, u32 x2, u16 color)
{
	if(x1 > x2)return;
	asm("cld\n\t"
	"rep;stosw"
	::"c"(x2 - x1), "D"(video + y*info.x + x1), "a"(color)
	:"memory"
	);
}

// 画竖线函数
void draw_y_line(u32 x, u32 y1, u32  y2, u16 color)
{
	int y;
	for(y = y1; y <= y2; y++)
		draw_set_point(x, y, color);
}

// 画矩形函数
void draw_rect(u32 x1, u32 y1, u32 x2, u32 y2, u16 color, int fill)
{
	draw_x_line(y1, x1, x2, color);
	draw_x_line(y2, x1, x2, color);
	draw_y_line(x1, y1, y2, color);
	draw_y_line(x2, y1, y2, color);
	if(fill)
		draw_fill_rect(x1, y1, x2, y2, color);
}

int draw_string(u32 x, u32 y, char *text, u16 color)
{
	while(*text)
	{
		draw_ascii(x, y, *text, color);
		x += 8;
		text++;
	}
	return x;
}

void draw_ascii(u32 x, u32 y, u32 ascii, u16 color)
{
	char *c, ch;
	int i,j;
	c = asctab + (ascii * 16);
	for( j = 0; j < 16; j++)
	{
		ch = *c++;
		
		for( i = 0; i < 8; i++)
		{
			if(ch & 1)
				video[(y + j) * info.x + x + (8 - i)] = color;
			else
				video[(y + j) * info.x + x + (8 - i)] = 0xffff;
			ch >>= 1;
		}
	}
}


// 显示汉字
/*void vesa_print_chinese( unsigned int x , unsigned int y , unsigned int pos_in_font , unsigned short color )
{
  unsigned char *chinese_font_addr = ( unsigned char * )0x30000 + pos_in_font * 32 ; // 一个汉字 32 字节

  union{
    unsigned char ch ;
    struct{
      unsigned char ch0 : 1 ;
      unsigned char ch1 : 1 ;
      unsigned char ch2 : 1 ;
      unsigned char ch3 : 1 ;
      unsigned char ch4 : 1 ;
      unsigned char ch5 : 1 ;
      unsigned char ch6 : 1 ;
      unsigned char ch7 : 1 ;
    } ;
  } u ;

  for( int j = 0 ; j < 16 ; ++j ){ // 一个汉字 16 行
    for( int i = 0 ; i < 2 ; ++i ){ // 每行 2 个字节 ( 16 位 )
      u.ch = chinese_font_addr[ j * 2 + i ] ;
      int offset = x + i * 8 ; // 一个字节 8 个像素
      if( u.ch7 ){
        vesa_draw_point( offset , y , color ) ;
      }
      if( u.ch6 ){
        vesa_draw_point( offset + 1  , y , color ) ;
      }
      if( u.ch5 ){
        vesa_draw_point( offset + 2 , y , color ) ;
      }
      if( u.ch4 ){
        vesa_draw_point( offset + 3 , y , color ) ;
      }
      if( u.ch3 ){
        vesa_draw_point( offset + 4 , y , color ) ;
      }
      if( u.ch2 ){
        vesa_draw_point( offset + 5 , y , color ) ;
      }
      if( u.ch1 ){
        vesa_draw_point( offset + 6 , y , color ) ;
      }
      if( u.ch0 ){
        vesa_draw_point( offset + 7 , y , color ) ;
      }    
    }
    y++ ; // 显示下一行
  }
}*/

// 显示 pbmp 16 bit 格式的图片
void draw_bmp16(u32 x, u32 y, void *pbmp, u16 mask, int use_mask)
{
	// 这里只支持 windows 标准 16 位 bmp 格式图片，（1:5:5:5）
	struct bmp_bmp_head_struct *bmp_head = pbmp;
	int w = bmp_head->info_head.width;
	int h = bmp_head->info_head.height;
	int i, j;
	u16 c565;
	
	// 下面记算存储每个点的色彩的信息所在的位置
	u16 *color = (u16 *)( (u32)pbmp + bmp_head->offset );
	
	// 由于一行的字节数比须是 4 的倍数，因此，这里先计算每行需要的填充数，除 2 是因为每个像素两个字节
	int fill_length = w * 2 % 4 / 2 ; 
	
	// bmp 的存放顺序是从下到上，从左到右
	for(i = h - 1; i >= 0; --i)
	{
		for(j = 0; j < w; j++)
		{
			c565 = draw_color_555_to_565(*color);
			
			if( !use_mask || c565 != mask)
				draw_set_point( x + j, y + i, c565);
			color++;
		}
		color += fill_length;
	}
}

void draw_bmp(u32 x, u32 y, void *pbmp, u16 mask, int use_mask)
{
	struct bmp_bmp_head_struct *bmp_head = pbmp;
	if(bmp_head->info_head.biBitCount==24)
	{
		//printf("use24\n");
		draw_bmp24(x,y,pbmp,mask,use_mask);
	}
	else
		draw_bmp16(x,y,pbmp,mask,use_mask);
}

// 显示 pbmp 24 bit 格式的图片
void draw_bmp24(u32 x, u32 y, void *pbmp, u16 mask, int use_mask)
{
	// 这里只支持 windows 标准 24 位 bmp 格式图片，（8:8:8）
	struct bmp_bmp_head_struct *bmp_head = pbmp;
	int w = bmp_head->info_head.width;
	int h = bmp_head->info_head.height;
	int i, j;
	struct color24
	{
		u8 b, g, r;
	} *color;
	u16 c565;
	
	// 下面记算存储每个点的色彩的信息所在的位置
	color = (void *)( (u32)pbmp + bmp_head->offset );
	
	// 由于一行的字节数比须是 4 的倍数，因此，这里先计算每行需要的填充数(char)
	int fill_length = w * 3 % 4 ; 
	
	// bmp 的存放顺序是从下到上，从左到右
	for(i = h - 1; i >= 0; --i)
	{
		for(j = 0; j < w; j++)
		{
			c565 = RGB(color->r>>3,color->g>>2,color->b>>3);
			
			if( !use_mask || c565 != mask)
				draw_set_point( x + j, y + i, c565);
			color++;
		}
		color = (void *)((u32)color + fill_length);
	}
}
