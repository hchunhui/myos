#ifndef _STDARG_H
#define _STDARG_H
#include <os/type.h>
#include <libc/kstru.h>
#include <os/unistd.h>
#include <lib/string.h>

typedef char *va_list;

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

int get_module_size(char* filename);
int get_module(char* filename,char* buf);

int get_graph_info(struct myos_graph_info *info);
int tty_switch(int nr);

int rand(void);
void srand(unsigned seed);

typedef int clock_t;
clock_t clock();
long mystrtol(const char *nptr, /*char **endptr,*/ int base);
int scanf(const char* fmt,...);

int send(int pid_to, MSG *m);
int recv(int pid_from, MSG *m, int block);
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

int read(int fd, void *buf, s32 count);
int write(int fd, void *buf, s32 count);
int open(char *name, int flags);
int close(int fd);
	int nice(int nice);
	int ioctl(int fd, int cmd, void *arg);
	int dup2(int oldfd, int newfd);
#ifdef __cplusplus
}
#endif

#endif /* _LIBC_H */

