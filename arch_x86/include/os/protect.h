#ifndef _PROTECT_H_
#define _PROTECT_H_     //防止多次定义

#define PRIVILEGE_KNL 0
#define PRIVILEGE_USER 3
#define	CS			0x8
#define	DS			0x10
#define	CS_USR			(0x18+3)	//RPL=3
#define	DS_USR			(0x20+3)	//RPL=3
#define	TSS			0x28
#define TSS_SIZE 		104

#define	SYSCALL 		0x80
#endif
