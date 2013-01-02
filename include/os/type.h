#ifndef _TYPE_H_
#define _TYPE_H_
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef signed char __s8;
typedef signed short __s16;
typedef signed int __s32;

#undef __size_t
#undef __ssize_t
#undef __off_t
typedef unsigned long __size_t;
typedef signed long __ssize_t;
typedef signed long __off_t;

typedef unsigned long __clock_t;
typedef signed long __time_t;
typedef unsigned long __clockid_t;
typedef unsigned long __timer_t;

typedef int __pid_t;

typedef int __dev_t;
typedef int __uid_t;
typedef int __gid_t;


struct timeval {
  __time_t tv_sec;
  long tv_usec;
};

typedef	unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;

#define PATH_MAX 256
#ifdef __KERNEL__
typedef __u8 u8;
typedef __u16 u16;
typedef __u32 u32;
typedef __s8 s8;
typedef __s16 s16;
typedef __s32 s32;

typedef __size_t size_t;
typedef __ssize_t ssize_t;

#define NULL ((void *)0)

#endif

#endif

