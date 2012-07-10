#include <os/arch_config.h>
#include <drv/tty.h>
#include <lib/klib.h>
#include <os/task.h>
#include <os/asm.h>
#include <os/message.h>
#include <libc/kstru.h>
#include <os/isr.h>
#include <os/io.h>

#define TIME_OUT 1000

//scan code 2 define
#define CODE_BRK	0xf0
#define CODE_EX0	0xe0
#define CODE_EX1	0xe1

#define CODE_LSHIFT		0x12
#define CODE_RSHIFT		0x59
#define CODE_LCTRL		0x14
#define CODE_RCTRL		0xe014
#define CODE_LALT		0x11
#define CODE_RALT		0xe011
#define CODE_BACK		0x66
#define CODE_ENTER		0x5a
#define CODE_NUMLOCK		0x77
#define CODE_CAPSLOCK		0x58
#define CODE_SCROLOCK		0x7e
#define CODE_UP			0xe075
#define CODE_DOWN		0xe072
#define CODE_LEFT		0xe06b
#define CODE_RIGHT		0xe074
#define CODE_DELETE		0xe071
#define CODE_PAD_DEL		0x71
#define CODE_ESC		0x76
#define LED_NUM			1
#define LED_CAPS		2
#define LED_SCRO		4

int drv_kb_int();

/* tools begin */
static void empty_8042()
{
	u32 ret;
	int i=TIME_OUT;
	do {
		ret=inb(0x64);
		i--;
	}while((ret&0x2) && i);
	if(i==0)panic("keyboard error");
}

static void wait_8042()
{
	u32 ret;
	int i=TIME_OUT;
	do {
		ret=inb(0x64);
		i--;
	}while( (!(ret&0x1)) && i );
	if(i==0)panic("keyboard error");
}

static void kb_out(u32 port,u8 val)
{
	empty_8042();
	outb(val, port);
}

static u8 kb_in(u32 port)
{
	wait_8042();
	return inb(port);
}
/* tools end */
static struct s_kbbuf kbbuf;
static int is_brk;
static int is_lshift,is_rshift,is_lctrl,is_rctrl,is_lalt,is_ralt;
static int is_ex;
static int gcode;
static u32 led;
static int key_lock=0;		//不为零时，控制按键被忽略。
void drv_kb_lock()
{
	key_lock++;
}
void drv_kb_unlock()
{
	key_lock--;
}
const char kb_table[2][256]=
{
	{
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,'`',0,0,
	0,0,0,0,'q','1',0,0,0,'z','s','a','w','2',0,0,
	'c','x','d','e','4','3',0,0,' ','v','f','t','r','5',0,0,
	'n','b','h','g','y','6',0,0,0,'m','j','u','7','8',0,0,
	',','k','i','o','0','9',0,0,'.','/','l',';','p','-',0,0,
	0,'\'',0,'[','=',0,0,0,0,'\n',']',0,'\\',0,0,0,
	0,0,0,0,0,'\b',0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0x1b,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},
	{
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,'~',0,0,
	0,0,0,0,'Q','!',0,0,0,'Z','S','A','W','@',0,0,
	'C','X','D','E','$','#',0,0,' ','V','F','T','R','%',0,0,
	'N','B','H','G','Y','^',0,0,0,'M','J','U','&','*',0,0,
	'<','K','I','O',')','(',0,0,'>','?','L',':','P','_',0,0,
	0,'"',0,'{','+',0,0,0,0,'\n','}',0,'|',0,0,0,
	0,0,0,0,0,'\b',0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0x1b,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},
};

void drv_kb_init()
{
	u32 ret;
	
	/* 8042 编程 */
	kb_out(0x64,0xad);	//禁止键盘
	
	//使用第二套扫描码（禁止将第二套扫描码翻译为第一套）
	kb_out(0x64,0x20);
	ret=kb_in(0x60);
	ret&=~(1<<6);
	kb_out(0x64,0x60);
	kb_out(0x60,ret);
	empty_8042();
	print("switch to scan code 2\n");
	
	kb_out(0x64,0xae);	//开启键盘
	
	//变量初始化
	is_brk=0;
	is_ex=0;
	is_lshift=0;
	is_rshift=0;
	is_lctrl=0;
	is_rctrl=0;
	is_lalt=0;
	is_ralt=0;
	gcode=0;
	led=0;
	
	kbbuf.p=&(kbbuf.buf[0]);
	kbbuf.q=kbbuf.p;
	kbbuf.count=0;
	
	//开启键盘中断
	irq_register(IRQ_KB, drv_kb_int);
	pic_enable_irq(IRQ_KB);
}

static void drv_kb_sendkey(char key)
{
	MSG msg;
	if(drv_tty_now() < NR_TTY)
		return;
	msg.type = KM_KEYPRESS;
	msg.arg1 = key;
	msg.arg2 = (is_lshift<<0) | (is_rshift<<1) | (is_lctrl<<2)  | 
			(is_rctrl<<3) | (is_lalt<<4) | (is_ralt<<5);
	msg.arg3 = led;
	msg.arg4 = is_brk;
	do_send_to_user(&msg);
}

int drv_kb_emptybuf()
{
	return kbbuf.count<=0;
}

static int drv_kb_fullbuf()
{
	return kbbuf.count>=KBBUF_LEN;
}

static void drv_kb_putbuf(char key)
{
	if(drv_tty_now()<NR_TTY)
	{
		*(kbbuf.q++)=key;
		kbbuf.count++;
		if(kbbuf.q>&(kbbuf.buf[KBBUF_LEN-1]))
			kbbuf.q=&(kbbuf.buf[0]);
		drv_tty_wakeup();
		return;
	}
}

char drv_kb_getbuf()
{
	char key;
	key=*(kbbuf.p++);
	kbbuf.count--;
	if(kbbuf.p>&(kbbuf.buf[KBBUF_LEN-1]))
		kbbuf.p=&(kbbuf.buf[0]);
	return key;
}

static void kb_reboot()
{
	int d1,d2;
	u16* magic_addr=(u16*)0x472;
	empty_8042();
	cli();
	drv_tty_switch(0);
	print("\nNow reboot");
	for(d1=0;d1<50000;d1++)
	{
		for(d2=0;d2<1000;d2++);
		if(d1%1000==0)print(".");
	}
	*magic_addr=0x1234;		/* don't do memory check */
	kb_out(0x64,0xfe);
	for(;;);
}

static void kb_halt()
{
	const char bochs_shutdown[] = "Shutdown";
	const char *p=bochs_shutdown;
	cli();
	for(;p;p++)
		outb(*p,0x8900);
}

static void translate()
{
	char ch;
	switch(gcode)
	{
		case CODE_LSHIFT:	is_lshift=!is_brk;drv_kb_sendkey(0);break;
		case CODE_RSHIFT:	is_rshift=!is_brk;drv_kb_sendkey(0);break;
		case CODE_LCTRL:	is_lctrl=!is_brk;drv_kb_sendkey(0);break;
		case CODE_RCTRL:	is_rctrl=!is_brk;drv_kb_sendkey(0);break;
		case CODE_LALT:		is_lalt=!is_brk;drv_kb_sendkey(0);break;
		case CODE_RALT:		is_ralt=!is_brk;drv_kb_sendkey(0);break;
		case CODE_NUMLOCK:	if(!is_brk)led=(led|LED_NUM)&(~(led&LED_NUM));break;
		case CODE_CAPSLOCK:	if(!is_brk)led=(led|LED_CAPS)&(~(led&LED_CAPS));break;
		case CODE_SCROLOCK:	if(!is_brk)led=(led|LED_SCRO)&(~(led&LED_SCRO));break;
		case CODE_ENTER:
		case CODE_BACK:
		default:
			if(is_lshift || is_rshift)
			{
				ch=kb_table[!(led&LED_CAPS)][gcode&0xff];
			}
			else
			{
				ch=kb_table[!!(led&LED_CAPS)][gcode&0xff];
			}
			drv_kb_sendkey(ch);
			if(!is_brk)
			{	
				/* 处理控制键 */
				if( key_lock!=0 )goto next;
				if( (is_lalt || is_ralt) && (is_lctrl || is_rctrl) && (ch=='h'))
				{
					kb_halt();
				}
				if( (is_lalt || is_ralt)  && (is_lctrl || is_rctrl) && (ch=='\b'))	//reboot
				{
					kb_reboot();
				}
				if( (is_lalt || is_ralt)  && (is_lctrl || is_rctrl) && (gcode==CODE_DELETE || gcode==CODE_PAD_DEL))	//reboot
				{
					kb_reboot();
				}
				if( (is_lalt || is_ralt) )
				{
					switch(ch)
					{
						case '1':
						case '2':
						case '3':
						case '4':
						case '5':
							drv_tty_switch(ch-'0'-1);
							return;
							break;
					}
					switch(gcode)
					{
						case CODE_UP:
							drv_video_down_screen(-1);
							break;
						case CODE_DOWN:
							drv_video_down_screen(1);
							break;
					}
					return;
				}
				if(ch==0)return;	//其他未处理字符不放入缓冲区
				/* */
				
			next:	if(!drv_kb_fullbuf())
				{
					drv_kb_putbuf(ch);
					//putchar(ch);
				}
			}
	}
}

//键盘中断处理程序
int drv_kb_int()
{
	u8 code=inb(0x60);

	if(code==CODE_BRK)
	{
		is_brk=1;
		return 0;
	}
	if(code==CODE_EX0)
	{
		is_ex=1;
		gcode=CODE_EX0;
		//print("--enter e0--");
		return 0;
	}
	if(code==CODE_EX1)
	{
		is_ex=2;
		gcode=0;
		return 0;
	}
	if(is_ex)
	{
		is_ex--;
		gcode<<=8;
		gcode|=code;
		if(is_ex)return 0;
		translate();
		is_brk=0;
		return 0;
	}
	gcode=code;
	translate();
	is_brk=0;
	return 0;
}


/*
i8042 键盘控制器

    键盘驱动直接读写 i8042 芯片，通过 i8042 间接的向键盘中的 i8048 发命令。所以对于驱动来说，直接发生联系的只有 i8042 ，因此我们只介绍 i8042 ，不介绍 i8048。

    象 i8042，i8048 这样的芯片，本身就是一个小的处理器，它的内部有自己的处理器，有自己的 Ram，有自己的寄存器，等等。

    i8042 有 4 个 8 bits 的寄存器，他们是 Status Register（状态寄存器），Output Buffer（输出缓冲器），Input Buffer（输入缓冲器），Control Register（控制寄存器）。使用两个 IO 端口，60h 和 64h。

Status Register（状态寄存器）

状态寄存器是一个8位只读寄存器，任何时刻均可被cpu读取。其各位定义如下

Bit7: PARITY-EVEN(P_E): 从键盘获得的数据奇偶校验错误

Bit6: RCV-TMOUT(R_T): 接收超时，置1

Bit5: TRANS_TMOUT(T_T): 发送超时，置1

Bit4: KYBD_INH(K_I): 为1，键盘没有被禁止。为0，键盘被禁止。

Bit3: CMD_DATA(C_D): 为1，输入缓冲器中的内容为命令，为0，输入缓冲器中的内容为数据。

Bit2: SYS_FLAG(S_F): 系统标志，加电启动置0，自检通过后置1

Bit1: INPUT_BUF_FULL(I_B_F): 输入缓冲器满置1，i8042 取走后置0

BitO: OUT_BUF_FULL(O_B_F): 输出缓冲器满置1，CPU读取后置0

Output Buffer（输出缓冲器）

输出缓冲器是一个8位只读寄存器。驱动从这个寄存器中读取数据。这些数据包括，扫描码，发往 i8042 命令的响应，间接的发往 i8048 命令的响应。

Input Buffer（输入缓冲器）

输入缓冲器是一个8位只写寄存器。缓冲驱动发来的内容。这些内容包括，发往 i8042 的命令，通过 i8042 间接发往 i8048 的命令，以及作为命令参数的数据。

Control Register（控制寄存器）

也被称作 Controller Command Byte （控制器命令字节）。其各位定义如下

Bit7: 保留，应该为0

Bit6: 将第二套扫描码翻译为第一套

Bit5: 置1，禁止鼠标

Bit4: 置1，禁止键盘

Bit3: 置1，忽略状态寄存器中的 Bit4

Bit2: 设置状态寄存器中的 Bit2

Bit1: 置1，enable 鼠标中断

BitO: 置1，enable 键盘中断

2个端口 0x60,0x64

驱动中把 0x60 叫数据端口

驱动中把 0x64 叫命令端口

1.5 命令

驱动可以直接给 i8042 发命令，可以通过 i8042 间接给 i8048 发命令。命令这部分内容直接来自 < 参考资料 [1] >。

1.5.1 发给i8042的命令

驱动对键盘控制器发送命令是通过写端口64h实现的，共有12条命令，分别为

20h

准备读取8042芯片的Command Byte；其行为是将当前8042 Command Byte的内容放置于Output Register中，下一个从60H端口的读操作将会将其读取出来。

60h

准备写入8042芯片的Command Byte；下一个通过60h写入的字节将会被放入Command Byte。

A4h

测试一下键盘密码是否被设置；测试结果放置在Output Register，然后可以通过60h读取出来。测试结果可以有两种值：FAh=密码被设置；F1h=没有密码。

A5h

设置键盘密码。其结果被按照顺序通过60h端口一个一个被放置在Input Register中。密码的最后是一个空字节（内容为0）。

A6h

让密码生效。在发布这个命令之前，必须首先使用A5h命令设置密码。

AAh

自检。诊断结果放置在Output Register中，可以通过60h读取。55h=OK。

ADh

禁止键盘接口。Command Byte的bit-4被设置。当此命令被发布后，Keyboard将被禁止发送数据到Output Register。

AEh

打开键盘接口。Command Byte的bit-4被清除。当此命令被发布后，Keyboard将被允许发送数据到Output Register。

C0h

准备读取Input Port。Input Port的内容被放置于Output Register中，随后可以通过60h端口读取。

D0h

准备读取Outport端口。结果被放在Output Register中，随后通过60h端口读取出来。

D1h

准备写Output端口。随后通过60h端口写入的字节，会被放置在Output Port中。

D2h

准备写数据到Output Register中。随后通过60h写入到Input Register的字节会被放入到Output Register中，此功能被用来模拟来自于Keyboard发送的数据。如果中断被允许，则会触发一个中断。

1.5.2 发给8048的命令

共有10条命令，分别为

EDh

设置LED。Keyboard收到此命令后，一个LED设置会话开始。Keyboard首先回复一个ACK（FAh），然后等待从60h端口写入的LED设置字节，如果等到一个，则再次回复一个ACK，然后根据此字节设置LED。然后接着等待。。。直到等到一个非LED设置字节(高位被设置)，此时LED设置会话结束。

EEh

诊断Echo。此命令纯粹为了检测Keyboard是否正常，如果正常，当Keyboard收到此命令后，将会回复一个EEh字节。

F0h

选择Scan code set。Keyboard系统共可能有3个Scan code set。当Keyboard收到此命令后，将回复一个ACK，然后等待一个来自于60h端口的Scan code set代码。系统必须在此命令之后发送给Keyboard一个Scan code set代码。当Keyboard收到此代码后，将再次回复一个ACK，然后将Scan code set设置为收到的Scan code set代码所要求的。

F2h

读取Keyboard ID。由于8042芯片后不仅仅能够接Keyboard。此命令是为了读取8042后所接的设备ID。设备ID为2个字节，Keyboard ID为83ABh。当键盘收到此命令后，会首先回复一个ACK，然后，将2字节的Keyboard ID一个一个回复回去。

F3h

设置Typematic Rate/Delay。当Keyboard收到此命令后，将回复一个ACK。然后等待来自于60h的设置字节。一旦收到，将回复一个ACK，然后将Keyboard Rate/Delay设置为相应的值。

F4h

清理键盘的Output Buffer。一旦Keyboard收到此命令，将会将Output buffer清空，然后回复一个ACK。然后继续接受Keyboard的击键。

F5h

设置默认状态(w/Disable)。一旦Keyboard收到此命令，将会将 Keyboard完全初始化成默认状态。之前所有对它的设置都将失效——Output buffer被清空，Typematic Rate/Delay被设置成默认值。然后回复一个ACK，接着等待下一个命令。需要注意的是，这个命令被执行后，键盘的击键接受是禁止的。如果想让键盘接受击键输入，必须Enable Keyboard。

F6h

设置默认状态。和F5命令唯一不同的是，当此命令被执行之后，键盘的击键接收是允许的。

FEh

Resend。如果Keyboard收到此命令，则必须将刚才发送到8042 Output Register中的数据重新发送一遍。当系统检测到一个来自于Keyboard的错误之后，可以使用自命令让Keyboard重新发送刚才发送的字节。

FFh

Reset Keyboard。如果Keyboard收到此命令，则首先回复一个ACK，然后启动自身的Reset程序，并进行自身基本正确性检测（BAT- Basic Assurance Test）。等这一切结束之后，将返回给系统一个单字节的结束码（AAh=Success, FCh=Failed），并将键盘的Scan code set设置为2。

1.5.3 读到的数据

00h/FFh

当击键或释放键时检测到错误时，则在Output Bufer后放入此字节，如果Output Buffer已满，则会将Output Buffer的最后一个字节替代为此字节。使用Scan code set 1时使用00h，Scan code 2和Scan Code 3使用FFh。

AAh

BAT完成代码。如果键盘检测成功，则会将此字节发送到8042 Output Register中。

EEh

Echo响应。Keyboard使用EEh响应从60h发来的Echo请求。

F0h

在Scan code set 2和Scan code set 3中，被用作Break Code的前缀。

FAh

ACK。当Keyboard任何时候收到一个来自于60h端口的合法命令或合法数据之后，都回复一个FAh。

FCh

BAT失败代码。如果键盘检测失败，则会将此字节发送到8042 Output Register中。

FEh

Resend。当Keyboard任何时候收到一个来自于60h端口的非法命令或非法数据之后，或者数据的奇偶交验错误，都回复一个FEh，要求系统重新发送相关命令或数据。

83ABh

当键盘收到一个来自于60h的F2h命令之后，会依次回复83h，ABh。83AB是键盘的ID。

Scan code

除了上述那些特殊字节以外，剩下的都是Scan code。

*/
