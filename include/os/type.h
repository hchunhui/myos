#ifndef _TYPE_H_
#define _TYPE_H_
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned char	u8;
typedef unsigned short	u16;
typedef unsigned int	u32;
typedef signed char	s8;
typedef signed short	s16;
typedef signed int	s32;

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

#ifndef _SSIZE_T
#define _SSIZE_T
typedef int ssize_t;
#endif
#define NULL ((void *)0)
#endif

