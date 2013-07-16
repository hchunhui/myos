#ifndef _DRAW_H_
#define _DRAW_H_
#include <sys/types.h>

#define RGB(r,g,b) ( \
	(((r)&( (1<<5)-1 ))<< 11)	\
	+ (((g)&( (1<<6)-1 ))<<5)	\
	+ ((b)&( (1<<5)-1 ) ))
#define draw_color_555_to_565(color555) ( (color555>>5<<6) | (color555&31) | 32)
#include "bmp.h"
#include "wtype.h"
// from pyos, 大部分已经重写
#ifdef __cplusplus
extern "C" {
#endif 
struct s_draw_canvas
{
	__u16 *video;
	int x;
	int y;
	int depth;
};

int draw_init();
int draw_set_canvas(DrawCanvas *pcanv, __u16 *new_addr);

// 画点函数
void draw_set_point(DrawCanvas *pcanv, __u32 x, __u32 y, __u16 color);

// 取得指定点色彩
__u16 draw_get_point(DrawCanvas *pcanv, __u32 x,__u32 y);

// 矩形填充函数
void draw_fill_rect(DrawCanvas *pcanv, __u32 x1, __u32 y1, __u32 x2, __u32 y2, __u16 color);

// 清屏函数
void draw_clear_screen(DrawCanvas *pcanv, __u16 color);

// 拷贝函数
void draw_copy(DrawCanvas *psrc, DrawCanvas *pobj, __u32 x, __u32 y, __u32 w, __u32 h);
void draw_cursor_mask(DrawCanvas *psrc, DrawCanvas *pobj, __u32 x, __u32 y, __u16 mask);
void draw_window(DrawCanvas *psrc, DrawCanvas *pobj, __u32 x, __u32 y, __u32 w, __u32 h);

void draw_ascii(DrawCanvas *pdc, __u32 x, __u32 y, __u32 ascii, __u16 fg, __u16 bg);
int draw_string(DrawCanvas *pdc, __u32 x, __u32 y, char *text, __u16 color);
int draw_string_bg(DrawCanvas *pdc, __u32 x, __u32 y, char *text, __u16 fg, __u16 bg);

// 画横线函数
void draw_x_line(DrawCanvas *pdc, __u32 y, __u32 x1, __u32 x2, __u16 color);

// 画竖线函数
void draw_y_line(DrawCanvas *pdc, __u32 y, __u32 x1, __u32 x2, __u16 color);

// 画矩形函数
void draw_rect(DrawCanvas *pdc, __u32 x1, __u32 y1, __u32 x2, __u32 y2, __u16 color, int fill);

// 显示 pbmp 格式的图片
void draw_bmp(DrawCanvas *pdc, __u32 x, __u32 y, void *pbmp, __u16 mask, int use_mask);
void draw_bmp16(DrawCanvas *pdc, __u32 x, __u32 y, void *pbmp, __u16 mask, int use_mask);
void draw_bmp24(DrawCanvas *pdc, __u32 x, __u32 y, void *pbmp, __u16 mask, int use_mask);

#ifdef __cplusplus
}
#endif 

#endif

