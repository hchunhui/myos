#ifndef _PYOS_BMP_H_
#define _PYOS_BMP_H_
#include <os/type.h>
/******************************************************
* bmp 格式处理文件                                    *
* 现只支持 16位色(5:6:5) 非压缩 Windows 标准 bmp 格式 *
******************************************************/

/******************************************************
* 下面是说明部分                                      *
******************************************************/

struct bmp_bmp_info_head_struct{
	u32 the_struct_size ;
	u32 width ;
	u32 height ;
	u16 biPlanes;
	u16 biBitCount;
	u32 biCompression;
	u32 biSizeImage;
	u32 biXPelsPerMeter;
	u32 biYPelsPerMeter;
	u32 biClrUsed;
	u32 biClrImportant;
}__attribute__((packed)) ;

struct bmp_bmp_head_struct{
  u16 type ; // 类型
  u32 size_file ; // 大小
  u16 reserved_0 ;
  u16 reserved_1 ;
  u32 offset ; // 位图阵列的起始位置
  struct bmp_bmp_info_head_struct info_head ;
}__attribute__((packed)) ;

#endif
