#include <os/type.h>
#include <os/arch_config.h>
#include <os/protect.h>

/* 描述符类型值说明 */
#define	DA_32			0x4000	/* 32 位段 */
#define	DA_LIMIT_4K		0x8000	/* 段界限粒度为 4K 字节 */
#define	DA_DPL0			0x00	/* DPL = 0 */
#define	DA_DPL1			0x20	/* DPL = 1 */
#define	DA_DPL2			0x40	/* DPL = 2 */
#define	DA_DPL3			0x60	/* DPL = 3 */
/* 存储段描述符类型值说明 */
#define	DA_DR			0x90	/* 存在的只读数据段类型值 */
#define	DA_DRW			0x92	/* 存在的可读写数据段属性值 */
#define	DA_DRWA			0x93	/* 存在的已访问可读写数据段类型值 */
#define	DA_C			0x98	/* 存在的只执行代码段属性值 */
#define	DA_CR			0x9A	/* 存在的可执行可读代码段属性值 */
#define	DA_CCO			0x9C	/* 存在的只执行一致代码段属性值 */
#define	DA_CCOR			0x9E	/* 存在的可执行可读一致代码段属性值 */
/* 系统段描述符类型值说明 */
#define	DA_LDT			0x82	/* 局部描述符表段类型值 */
#define	DA_TaskGate		0x85	/* 任务门类型值 */
#define	DA_386TSS		0x89	/* 可用 386 任务状态段类型值 */
#define	DA_386CGate		0x8C	/* 386 调用门类型值 */
#define	DA_386IGate		0x8E	/* 386 中断门类型值 */
#define	DA_386TGate		0x8F	/* 386 陷阱门类型值 */

struct s_desc
{
        u16    limitL;          //limitLow(16)
        u16    baseL;           //baseLow(16)
        u8     baseHL;          //baseHigh->Low(4)
        u8     attr1;           //P(1) DPL(2) DT(1) TYPE(4)
        u8     limitH_attr2;    //G(1) D(1) O(1) AVL(1) LimitHigh(4)
        u8     baseHH;          //baseHigh->high(4)
}__attribute__((packed));

struct s_gate
{
        u16    offsetL;
        u16    selector;
        u8     dcount;          //only call gate
        u8     attr;            //p(1) DPL(2) DT(1) TYPE(4)
        u16    offsetH;
}__attribute__((packed));

struct s_desc gdt[16];
u16 gdt_48[3];
struct s_gate idt[256];
u16 idt_48[3];

extern struct s_tss tss;

/* 异常处理程序 */
void divide_error();
void single_step_exception();
void nmi();
void breakpoint_exception();
void overflow();
void bounds_check();
void inval_opcode();
void copr_not_available();
void double_fault();
void copr_seg_overrun();
void inval_tss();
void segment_not_present();
void stack_exception();
void general_protection();
void page_fault();
void untitled();
void copr_error();

/* 中断处理程序 */
void hwint00();
void hwint01();
void hwint02();
void hwint03();
void hwint04();
void hwint05();
void hwint06();
void hwint07();
void hwint08();
void hwint09();
void hwint10();
void hwint11();
void hwint12();
void hwint13();
void hwint14();
void hwint15();

//系统调用
void sys_call();

static void set_idt_desc(u8 vector,u8 desc_type,void* handler,u8 privilege)
{
	struct s_gate *p_gate;
	p_gate=&idt[vector];
	u32 base=(u32)handler;

	p_gate->offsetL  = base & 0xFFFF;
	p_gate->selector = CS;
	p_gate->dcount   = 0;
	p_gate->attr     = desc_type | (privilege<<5);
	p_gate->offsetH  = (base>>16) & 0xFFFF;
}

static void set_gdt_desc(u8 vector, u32 base, u32 limit, u16 attribute)		//from sgos
{
	struct s_desc* pDesc = &gdt[vector];
	pDesc->limitL        = limit & 0x0FFFF;		// 段界限 1 (2 字节)
	pDesc->baseL         = base & 0x0FFFF;		// 段基址 1 (2 字节)
	pDesc->baseHL        = (base >> 16) & 0x0FF;	// 段基址 2 (1 字节)
	pDesc->attr1         = attribute & 0xFF;	// 属性 1
	pDesc->limitH_attr2  =
		((limit >> 16) & 0x0F) |
		((attribute >> 8) & 0xF0); // 段界限 2 + 属性 2
	pDesc->baseHH        = (base >> 24) & 0x0FF; // 段基址 3 (1 字节)
}

void make_gdt_desc()
{
	set_gdt_desc(0, 0, 0, 0);
	set_gdt_desc(1, 0x0, 0xFFFFF, DA_CR|DA_32|DA_LIMIT_4K);	 //32位代码段
	set_gdt_desc(2, 0x0, 0xFFFFF, DA_DRW|DA_LIMIT_4K|DA_32); //可读写数据段
	set_gdt_desc(3, 0x0, 0xFFFFF, DA_CR|DA_LIMIT_4K|DA_32|DA_DPL3); //ring3
	set_gdt_desc(4, 0x0, 0xFFFFF, DA_DRW|DA_LIMIT_4K|DA_32|DA_DPL3);
	set_gdt_desc(5, (u32)&tss, TSS_SIZE - 1, DA_386TSS);  //tss
	set_gdt_desc(6, 0x0, 0xFFFFF, DA_C);
	set_gdt_desc(7, 0x0, 0xFFFFF, DA_DRW);
	
	//init gdt_48
	gdt_48[0] = 8*sizeof(struct s_desc)-1;
	gdt_48[1] = ((u32)gdt)&0xffff;
	gdt_48[2] = ((u32)gdt)>>16;
	/* something */	
}

void make_idt_desc()
{
	//exception
	set_idt_desc( 0, DA_386TGate, divide_error,          PRIVILEGE_KNL);
	set_idt_desc( 1, DA_386TGate, single_step_exception, PRIVILEGE_KNL);
	set_idt_desc( 2, DA_386TGate, nmi,                   PRIVILEGE_KNL);
	set_idt_desc( 3, DA_386TGate, breakpoint_exception,  PRIVILEGE_USER);
	set_idt_desc( 4, DA_386TGate, overflow,              PRIVILEGE_USER);
	set_idt_desc( 5, DA_386TGate, bounds_check,          PRIVILEGE_USER);
	set_idt_desc( 6, DA_386TGate, inval_opcode,          PRIVILEGE_KNL);
	set_idt_desc( 7, DA_386TGate, copr_not_available,    PRIVILEGE_KNL);
	set_idt_desc( 8, DA_386TGate, double_fault,          PRIVILEGE_KNL);
	set_idt_desc( 9, DA_386TGate, copr_seg_overrun,      PRIVILEGE_KNL);
	set_idt_desc(10, DA_386TGate, inval_tss,             PRIVILEGE_KNL);
	set_idt_desc(11, DA_386TGate, segment_not_present,   PRIVILEGE_KNL);
	set_idt_desc(12, DA_386TGate, stack_exception,       PRIVILEGE_KNL);
	set_idt_desc(13, DA_386TGate, general_protection,    PRIVILEGE_KNL);
	set_idt_desc(14, DA_386TGate, page_fault,            PRIVILEGE_KNL);
	set_idt_desc(15, DA_386TGate, untitled,              PRIVILEGE_KNL);
	set_idt_desc(16, DA_386TGate, copr_error,            PRIVILEGE_KNL);
	//hwint
	set_idt_desc(IRQ_0    , DA_386IGate, hwint00, PRIVILEGE_KNL);
	set_idt_desc(IRQ_0 + 1, DA_386IGate, hwint01, PRIVILEGE_KNL);
	set_idt_desc(IRQ_0 + 2, DA_386IGate, hwint02, PRIVILEGE_KNL);
	set_idt_desc(IRQ_0 + 3, DA_386IGate, hwint03, PRIVILEGE_KNL);
	set_idt_desc(IRQ_0 + 4, DA_386IGate, hwint04, PRIVILEGE_KNL);
	set_idt_desc(IRQ_0 + 5, DA_386IGate, hwint05, PRIVILEGE_KNL);
	set_idt_desc(IRQ_0 + 6, DA_386IGate, hwint06, PRIVILEGE_KNL);
	set_idt_desc(IRQ_0 + 7, DA_386IGate, hwint07, PRIVILEGE_KNL);
	set_idt_desc(IRQ_8    , DA_386IGate, hwint08, PRIVILEGE_KNL);
	set_idt_desc(IRQ_8 + 1, DA_386IGate, hwint09, PRIVILEGE_KNL);
	set_idt_desc(IRQ_8 + 2, DA_386IGate, hwint10, PRIVILEGE_KNL);
	set_idt_desc(IRQ_8 + 3, DA_386IGate, hwint11, PRIVILEGE_KNL);
	set_idt_desc(IRQ_8 + 4, DA_386IGate, hwint12, PRIVILEGE_KNL);
	set_idt_desc(IRQ_8 + 5, DA_386IGate, hwint13, PRIVILEGE_KNL);
	set_idt_desc(IRQ_8 + 6, DA_386IGate, hwint14, PRIVILEGE_KNL);
	set_idt_desc(IRQ_8 + 7, DA_386IGate, hwint15, PRIVILEGE_KNL);
	//sys_call
	set_idt_desc(SYSCALL, DA_386TGate, sys_call, PRIVILEGE_USER);

	//idt_48
	idt_48[0] = 256*sizeof(struct s_gate)-1;
	idt_48[1] = ((u32)idt)&0xffff;
	idt_48[2] = ((u32)idt)>>16;
}
