#ifndef _STDARG_H
#define _STDARG_H
#include <os/type.h>
typedef __size_t size_t;
typedef __ssize_t ssize_t;
typedef __s8 s8;
typedef __s16 s16;
typedef __s32 s32;
typedef __u8 u8;
typedef __u16 u16;
typedef __u32 u32;
typedef char *va_list;
#define NULL ((void *)0)
#include <os/unistd.h>
#include <lib/string.h>
#include <drv/video.h>

/* Amount of space required in an argument list for an arg of type TYPE.
   TYPE may alternatively be an expression whose type is used.  */

#define __va_rounded_size(TYPE)  \
  (((sizeof (TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))

#ifndef __sparc__
#define va_start(AP, LASTARG) 						\
 (AP = ((char *) &(LASTARG) + __va_rounded_size (LASTARG)))
#else
#define va_start(AP, LASTARG) 						\
 (__builtin_saveregs (),						\
  AP = ((char *) &(LASTARG) + __va_rounded_size (LASTARG)))
#endif

void va_end (va_list);		/* Defined in gnulib */
#define va_end(AP)

#define va_arg(AP, TYPE)						\
 (AP += __va_rounded_size (TYPE),					\
  *((TYPE *) (AP - __va_rounded_size (TYPE))))

#endif /* _STDARG_H */

#ifndef _LIBC_H
#define _LIBC_H

extern int errno;

#ifdef __cplusplus
extern "C" {
#endif 

void uprint(char* obj);
int printf(const char* fmt,...);
int vsprintf(char *buf, const char *fmt, va_list args);
int sprintf(char * buf, const char *fmt, ...);
#define vfork() usr_sys_call0(__NR_vfork)
int fork();
void exit(int err_code);
int waitpid(int pid,int* status,int options);
	int execve(char *path, char *argv[], char *envp[]);
	int execv(char *path, char *argv[]);
	int execl(char *path, char *arg, ...);
	int execle(char *path, char *arg, ...);

void getline(char* buf);
long gettime();

int rand(void);
void srand(unsigned seed);

typedef int clock_t;
clock_t clock();
long mystrtol(const char *nptr, /*char **endptr,*/ int base);
int scanf(const char* fmt,...);

int getpid();
int getppid();

int shm_at(int key, void *base_addr, unsigned int flag);
#define SHM_R  1
#define SHM_W  2
#define SHM_RW (SHM_R | SHM_W)
int shm_dt(int key, void *base_addr);
int shm_get(int key, unsigned long size);
int shm_free(int key);

int isdigit(int x);
int isxdigit(int x);
int islower(int x);
int isspace(int x);
int isalpha(int x);
int isupper(int x);
int toupper(int x);

void *malloc(int size);
void free(void* ptr);

#include <os/dirent.h>
#include <os/stat.h>

int read(int fd, void *buf, ssize_t count);
int write(int fd, void *buf, ssize_t count);
int open(char *name, int flags);
int close(int fd);
int nice(int nice);
int ioctl(int fd, int cmd, void *arg);
int dup2(int oldfd, int newfd);
int mknod(char *name, int type);
int readdir(int fd, struct dirent *dirp, int count);
int fstat(int fd, struct stat *stat);


#ifdef __cplusplus
}
#endif

#endif /* _LIBC_H */

