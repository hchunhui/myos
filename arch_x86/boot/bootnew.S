#include "comm.h"
.text
.globl start
.code16
start:
/*
int $0x13 扩展调用规范
ds:si==>磁盘地址数据包(diskaddresspacket)
dl==>驱动器号
ah==>功能代码/返回码
AH:
检查扩展In13H是否存在(41h)
扩展读(42h)
扩展写(43h)
校验扇区(44h)
扩展定位(47h)
取得驱动器参数(48h)。　
锁定/解锁驱动器(45h)
弹出驱动器(46h)
取得扩展驱动器改变状态(49h)　
struct DiskAddressPacket
{
	BYTE PacketSize;　　//数据包尺寸(16字节)
	BYTE Reserved;　　　//==0
	WORDB lockCount;　　//要传输的数据块个数(以扇区为单位)
	DWORD BufferAddr;　//传输缓冲地址(segment:offset)
	QWORD BlockNum;　　//磁盘起始绝对块地址
};
http://www.bianceng.cn/Programming/hb/zl/200804/9576_3.htm
*/
	movb %dl,BOOTDRIVER		//得到启动的驱动器号
	movw %cs,%ax
	movw %ax,%ds
	movw %ax,%es
	movw $BASE,%sp
	movw $msg,%si
	call print
load_setup:
	movw $SETUPSEG,%ax
	movw %ax,dap_buf_seg
	movw $dap1,%si
	movw $SETUPOFF,dap_buf_off
	movb $0x42,%ah
	movb $0x0,%dl		//driver num
	movl $2,dap_start			//高位已经为零
	movw $SETUPSIZE,dap_count		//读入扇区数
	int $0x13
	jc load_setup
load_kernel:
	movw $KERNELSEG,%ax
	movw %ax,dap_buf_seg
	movw $dap1,%si
	movw $KERNELOFF,dap_buf_off
	movb $0x42,%ah
	movb $0x0,%dl		//driver num
	movl $(2+SETUPSIZE),dap_start			//高位已经为零
	movw $KERNELSIZE,dap_count		//读入扇区数
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
dap1:
	.byte 16
	.byte 0
dap_count:
	.word 0
dap_buf_off:
	.word 0
dap_buf_seg:
	.word 0
dap_start:
	.long 0
	.long 0
msg:
	.string "Loading...\x0"
msg2:
	.string "Done.\0"
.org 0x1fe,0x90
.word 0xaa55
