#include "comm.h"
.text
.globl start
.code16
start:
	movb %dl,BOOTDRIVER		//得到启动的驱动器号
	movw %cs,%ax
	movw %ax,%ds
	movw %ax,%es
	movw $BASE,%sp
	movw $msg,%si
	call print
load_setup:
	movw $SETUPSEG,%ax
	movw %ax,%es
	movw $SETUPOFF,%bx			//copy to SETUPSEG:SETUPOFF
	movb $2,%ah			
	movb $0x0,%dl		//driver num
	movb $0,%ch			//track
	movb $2,%cl			//sector
	movb $SETUPSIZE,%al		//读入扇区数
	int $0x13
	jc load_setup
load_kernel:
	movw $KERNELSEG,%ax
	movw %ax,%es
	movw $KERNELOFF,%bx
	movb $2,%ah			
	movb $0x0,%dl		//driver num
	movb $0,%ch			//track
	movb $(2+SETUPSIZE),%cl			//sector
	movb $KERNELSIZE,%al		//读入扇区数( 2个共1KB )
	int $0x13
	jc load_kernel
	movw $msg2,%si
	call print
	jmp $SETUPSEG,$SETUPOFF
this:	jmp this

print:
//--ds:si :要显示字符串的地址,串以0结束
	movb $0x0e,%ah
	cld
	lodsb
1:	cmpb $0,%al
	je 2f
	int $0x10
	lodsb
	jmp 1b
2:
	ret
msg:
	.string "Loading...\x0"
msg2:
	.string "Done.\0"
.org 0x1fe,0x90
.word 0xaa55
