#ifndef _PYOS_BMP_H_
#define _PYOS_BMP_H_
#include <sys/types.h>
/******************************************************
* bmp 格式处理文件                                    *
* 现只支持 16位色(5:6:5) 非压缩 Windows 标准 bmp 格式 *
******************************************************/

/******************************************************
* 下面是说明部分                                      *
******************************************************/

struct bmp_bmp_info_head_struct{
	__u32 the_struct_size ;
	__u32 width ;
	__u32 height ;
	__u16 biPlanes;
	__u16 biBitCount;
	__u32 biCompression;
	__u32 biSizeImage;
	__u32 biXPelsPerMeter;
	__u32 biYPelsPerMeter;
	__u32 biClrUsed;
	__u32 biClrImportant;
}__attribute__((packed)) ;

struct bmp_bmp_head_struct{
  __u16 type ; // 类型
  __u32 size_file ; // 大小
  __u16 reserved_0 ;
  __u16 reserved_1 ;
  __u32 offset ; // 位图阵列的起始位置
  struct bmp_bmp_info_head_struct info_head ;
}__attribute__((packed)) ;

#endif
