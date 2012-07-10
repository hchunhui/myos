#ifndef _PYOS_BMP_H_
#define _PYOS_BMP_H_
#include <os/type.h>
/******************************************************
* bmp ��ʽ�����ļ�                                    *
* ��ֻ֧�� 16λɫ(5:6:5) ��ѹ�� Windows ��׼ bmp ��ʽ *
******************************************************/

/******************************************************
* ������˵������                                      *
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
  u16 type ; // ����
  u32 size_file ; // ��С
  u16 reserved_0 ;
  u16 reserved_1 ;
  u32 offset ; // λͼ���е���ʼλ��
  struct bmp_bmp_info_head_struct info_head ;
}__attribute__((packed)) ;

#endif
