#ifndef _DRAW_H_
#define _DRAW_H_
#define RGB(r,g,b) ( \
	(((r)&( (1<<5)-1 ))<< 11)	\
	+ (((g)&( (1<<6)-1 ))<<5)	\
	+ ((b)&( (1<<5)-1 ) ))
#define draw_color_555_to_565(color555) ( (color555>>5<<6) | (color555&31) | 32)
#include "draw.h"
#include "bmp.h"
#include <type.h>
#include <unistd.h>
#include <libc/libc.h>
#include <string.h>
// from pyos, 大部分已经重写
extern u16 *video;
extern struct myos_graph_info info;

int draw_init();

// 画点函数
void draw_set_point(u32 x, u32 y, u16 color);

// 取得指定点色彩
u16 draw_get_point(u32 x,u32 y);

// 矩形填充函数
void draw_fill_rect(u32 x1, u32 y1, u32 x2, u32 y2, u16 color);

// 清屏函数
void draw_clear_screen(u16 color);

// 拷贝函数
void draw_copy(u32 x, u32 y, u16 *src, u16 *obj, u32 w, u32 h);
void draw_copy_screen(u16 *src, u16 *obj);
void draw_cursor_mask(u32 x, u32 y,u16 *src, u16 *obj, u32 w, u32 h, u16 mask);
void draw_window(u32 x, u32 y, u16 *src, u16 *obj, u32 w, u32 h);

void draw_ascii(u32 x, u32 y, u32 ascii, u16 color);
int draw_string(u32 x, u32 y, char *text, u16 color);

// 画横线函数
void draw_x_line(u32 y, u32 x1, u32 x2, u16 color);

// 画竖线函数
void draw_y_line(u32 x, u32 y1, u32  y2, u16 color);

// 画矩形函数
void draw_rect(u32 x1, u32 y1, u32 x2, u32 y2, u16 color, int fill);
// 显示 pbmp 格式的图片
void draw_bmp(u32 x, u32 y, void *pbmp, u16 mask, int use_mask);
void draw_bmp16(u32 x, u32 y, void *pbmp, u16 mask, int use_mask);
void draw_bmp24(u32 x, u32 y, void *pbmp, u16 mask, int use_mask);

#endif
