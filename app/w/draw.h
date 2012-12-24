#ifndef _DRAW_H_
#define _DRAW_H_
#define RGB(r,g,b) ( \
	(((r)&( (1<<5)-1 ))<< 11)	\
	+ (((g)&( (1<<6)-1 ))<<5)	\
	+ ((b)&( (1<<5)-1 ) ))
#define draw_color_555_to_565(color555) ( (color555>>5<<6) | (color555&31) | 32)
#include "bmp.h"
#include <libc/libc.h>
#include "wtype.h"
// from pyos, 大部分已经重写
#ifdef __cplusplus
extern "C" {
#endif 
struct s_draw_canvas
{
	u16 *video;
	int x;
	int y;
	int depth;
};

int draw_init();
int draw_set_canvas(DrawCanvas *pcanv, u16 *new_addr);

// 画点函数
void draw_set_point(DrawCanvas *pcanv, u32 x, u32 y, u16 color);

// 取得指定点色彩
u16 draw_get_point(DrawCanvas *pcanv, u32 x,u32 y);

// 矩形填充函数
void draw_fill_rect(DrawCanvas *pcanv, u32 x1, u32 y1, u32 x2, u32 y2, u16 color);

// 清屏函数
void draw_clear_screen(DrawCanvas *pcanv, u16 color);

// 拷贝函数
void draw_copy(DrawCanvas *psrc, DrawCanvas *pobj, u32 x, u32 y, u32 w, u32 h);
void draw_cursor_mask(DrawCanvas *psrc, DrawCanvas *pobj, u32 x, u32 y, u16 mask);
void draw_window(DrawCanvas *psrc, DrawCanvas *pobj, u32 x, u32 y, u32 w, u32 h);

void draw_ascii(DrawCanvas *pdc, u32 x, u32 y, u32 ascii, u16 fg, u16 bg);
int draw_string(DrawCanvas *pdc, u32 x, u32 y, char *text, u16 color);
int draw_string_bg(DrawCanvas *pdc, u32 x, u32 y, char *text, u16 fg, u16 bg);

// 画横线函数
void draw_x_line(DrawCanvas *pdc, u32 y, u32 x1, u32 x2, u16 color);

// 画竖线函数
void draw_y_line(DrawCanvas *pdc, u32 y, u32 x1, u32 x2, u16 color);

// 画矩形函数
void draw_rect(DrawCanvas *pdc, u32 x1, u32 y1, u32 x2, u32 y2, u16 color, int fill);

// 显示 pbmp 格式的图片
void draw_bmp(DrawCanvas *pdc, u32 x, u32 y, void *pbmp, u16 mask, int use_mask);
void draw_bmp16(DrawCanvas *pdc, u32 x, u32 y, void *pbmp, u16 mask, int use_mask);
void draw_bmp24(DrawCanvas *pdc, u32 x, u32 y, void *pbmp, u16 mask, int use_mask);

#ifdef __cplusplus
}
#endif 

#endif

