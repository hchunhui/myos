#ifndef _UNISTD_H_
#define _UNISTD_H_
#define usr_sys_call0(nr)	\
		({long res;	\
		asm volatile (	\
		"int $0x80":"=a"(res):"a"(nr):"memory");	\
		(res<0)?((errno=-res),-1):(res);})
#define usr_sys_call1(nr,x)	\
		({long res;	\
		asm volatile (	\
		"int $0x80":"=a"(res):"a"(nr),"b"(x):"memory");	\
		(res<0)?((errno=-res),-1):(res);})
#define usr_sys_call2(nr,x,y)	\
		({long res;	\
		asm volatile (	\
		"int $0x80":"=a"(res):"a"(nr),"b"(x),"c"(y):"memory");	\
		(res<0)?((errno=-res),-1):(res);})
#define usr_sys_call3(nr,x,y,z)	\
		({long res;	\
		asm volatile (	\
		"int $0x80":"=a"(res):"a"(nr),"b"(x),"c"(y),"d"(z):"memory");	\
		(res<0)?((errno=-res),-1):(res);})

#define __NR_sbrk		7
#define __NR_fork		8
#define __NR_exit		9
#define __NR_get_ticks		10
#define __NR_get_utime		11
#define __NR_get_stime		12
#define __NR_waitpid		13
#define __NR_execve		14
#define __NR_get_module		15
#define __NR_get_module_size 	16
#define __NR_gettime		17
#define __NR_get_graph_info	18
#define __NR_pause		19
#define __NR_send		20
#define __NR_recv		21
#define __NR_getpid		22
#define __NR_getppid		23
#define __NR_shm_get		24
#define __NR_shm_at		25
#define __NR_shm_dt		26
#define __NR_shm_free		27
#define __NR_open		28
#define __NR_read		29
#define __NR_write		30
#define __NR_close		31
#define __NR_nice               32
#define __NR_vfork              33
#define __NR_ioctl              34
#define __NR_dup2               35
#define __NR_mknod              36
#define __NR_readdir		37
#define __NR_fstat		38
#endif
