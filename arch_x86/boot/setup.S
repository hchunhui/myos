#include "comm.h"
.text
.globl start
.align 4
.code16
start:
	movw %cs,%ax
	movw %ax,%ds
	movw %ax,%es
	movw %ax,%ss
	movw $stack_top,%sp
	movw $0,%ax				//fs=0x0
	movw %ax,%fs
	movw $msg,%si
	call print
save_xy:
	movb $0x3,%ah
	xorb %bh,%bh
	int $0x10
	movw %dx,%fs:(CXY)
	
get_mem_size:
/*	;**************int 15h:******************
	;input:
	;		eax=0000e820h
	;		ebx=0(only the first)
	;		es:di=a buffer addr.
	;		ecx=20
	;		edx=0534d4150h
	;output:
	;		cf=0(no error,else there's a error)
	;		eax=0534d4150h
	;		es:di=a buffer addr.(the same as input)
	;		ecx
	;		if ebx=0 and cf=0 then it's the last.
	;*****************************************
	;注意es取值!*/
	xorl %ebx,%ebx
	movw $membuf,%di
1:
	movl $0xe820,%eax
	movl $20,%ecx
	movl $0x534d4150,%edx
	int $0x15
	jc mem_fail				//if cf=1 then goto L_MEM_FAIL
	addw $20,%di
	incl mem_count
	cmpl $0,%ebx					//if ebx!=0 goto .loop(not the last)
	jne 1b
	jmp mem_ok
mem_fail:
	movl $0,mem_count
	jmp 2f
mem_ok:
	xorl %ebx,%ebx					//ebx=0(counter)
	movw $membuf,%si
	movw mem_count,%cx
1:
	addw $8,%si				//goto MemBuf.LengthLow
	addl (%si),%ebx				//ebx+=MemBuf.LengthLow
	addw $12,%si				//goto next record
	loop 1b
	mov %ebx,%fs:(MEM_SIZE)		//注意段寄存器的取值!
2:
get_video_setting:
move_kernel:
	movw $KERNELSEG,%ax
	movw %ax,%ds
	movw $KERNEL,%ax
	movw %ax,%es
	movw $KERNELOFF,%si
	movw $0,%di
	movw $8960,%cx
	cld
	rep movsd

go_to_protect_mode:
	cli
	movw $SETUPSEG,%ax
	movw %ax,%ds
	movw %ax,%es
	
	lgdt gdt_48
	
	open_A20:
	call empty_8042
	movb $0xd1,%al
	outb %al,$0x64
	
	call empty_8042
	movb $0xdf,%al
	outb %al,$0x60
	call empty_8042		//A20 open!
	
	/*set_8259:			//已经移动至内核
	//ICW1
	movb $0x11,%al
	outb %al,$0x20
	.word 0x00eb,0x00eb		//delay
	outb %al,$0xa0
	.word 0x00eb,0x00eb
	
	//ICW2
	movb $0x20,%al
	outb %al,$0x21
	.word 0x00eb,0x00eb
	outb %al,$0xa1
	.word 0x00eb,0x00eb
	
	//ICW3
	movb $0x4,%al
	outb %al,$0x21
	.word 0x00eb,0x00eb
	movb $0x2,%al
	outb %al,$0xa1
	.word 0x00eb,0x00eb
	
	//ICW4
	movb $0x1,%al
	outb %al,$0x21
	.word 0x00eb,0x00eb
	outb %al,$0xa1
	.word 0x00eb,0x00eb
	
	//mask off all interrupts for now
	movb $0xff,%al
	outb %al,$0x21
	.word 0x00eb,0x00eb
	outb %al,$0xa1
	.word 0x00eb,0x00eb*/
	
	do_go:
	movl %cr0,%eax	//set PE
	orl $1,%eax
	movl %eax,%cr0
	ljmpl $8,$KERNEL	//8 is selector*/
this:	jmp this

empty_8042:
	.word 0x00eb,0x00eb
	inb $0x64,%al
	testb $2,%al
	jnz empty_8042
	ret
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
	.string "\n\rI am setup!\n\r\x0"
mem_count:
	.long 0
gdt:
	.word 0,0,0,0 				//dummy
	.word 0x7ff,0x0,0x9a00,0xcf	//code seg
	.word 0x7ff,0x0,0x9200,0xcf	//data seg

gdt_48:
	.word 0x800,0x9000+gdt,0

.org 0xe00,0x90
membuf:nop
.org 0xfff,0x90
stack_top:nop
