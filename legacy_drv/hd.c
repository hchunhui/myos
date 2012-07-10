#include <lib/klib.h>
#include <os/type.h>
#include <os/asm.h>
#include <drv/hd.h>
#define HD_REG_DATA 0x0
#define HD_REG_ERR 0x1
#define HD_REG_COUNT 0x2
#define HD_REG_SEC_NUM 0x3
#define HD_REG_CYL1     0x4
#define HD_REG_CYL2     0x5
#define HD_REG_HD       0x6
#define HD_REG_STATUS   0x7
#define HD_REG_COMMAND  0x7

static struct s_hd_mbr mbr;

struct s_hd_mbr* drv_hd_get_mbr()
{
	return &mbr;
}

void drv_hd_init()
{
	int i;
	drv_hd_read(0,0x0,(u8 *)&mbr);
	/*for(i=0;i<4;i++)
	{
		printk("prtition %d\n",i);
		printk("  active=%x\n",mbr.dpt[i].active);
		printk("  type=%x\n",mbr.dpt[i].type);
		printk("  sec_start=%x\n",mbr.dpt[i].sec_start);
		printk("  sec_count=%x\n",mbr.dpt[i].sec_count);
	}
	printk("sign 55 aa: %x %x\n",mbr.sign55,mbr.signaa);*/
}

//from SHYNA
//这是我在编写SHYNA是用的,现和大家分享.
/*ATA/ATAPI Driver
	2004-2-27 by YaoSiHai

*/
void drv_hd_write(u32 lba,u8 id,u8 *pout)	//out 512b
{
	u8 pd;
	u32 base_reg=0x1f0;
	u8 data;
	if(id==0x2) //Secondary :0
	{
		base_reg=0x170;
		id=0x0;
	}
	else if(id==0x3)//secondary: 1
	{
		base_reg=0x170;
		id=0x1;
	}


	//LBA
	pd=(u8)lba;
	outb(pd,base_reg+HD_REG_SEC_NUM);

	lba>>=8;
	pd=(u8)lba;
	outb(pd,base_reg+HD_REG_CYL1);

	lba>>=8;
	pd=(u8)lba;
	outb(pd,base_reg+HD_REG_CYL2);

	outb(1,base_reg+HD_REG_COUNT);

	lba>>=8;
	pd=(u8)lba;
	pd&=0x0f;
	id<<=4;
	pd|=(u8)id;
	pd|=0xe0;
	outb(pd,base_reg+HD_REG_HD);
	
	do
		data=inb(base_reg+HD_REG_STATUS);
	while( (data&0x80) || (data&8) );
	
	outb(0x30,HD_REG_COMMAND+base_reg);
	
	
	do
		data=inb(HD_REG_STATUS+base_reg);
	while( !(data&8) );
	
	asm volatile (
	"cld\n\t"
	"rep outsw"
	::"S"(pout),"c"(512/2),"d"(HD_REG_DATA+base_reg)
	);
	
	do
		data=inb(HD_REG_STATUS+base_reg);
	while(data&0x80);
}

void drv_hd_read(u32 lba,u8 id,u8 *pout) //in 512b
{
	u8 pd;
	u8 data;
	u32 base_reg=0x1f0;
	if(id==0x2) //Secondary :0
	{
		base_reg=0x170;
		id=0x0;
	}
	else if(id==0x3)//secondary: 1
	{
		base_reg=0x170;
		id=0x1;
	}


	//LBA
	pd=(u8)lba;
	outb(pd,base_reg+HD_REG_SEC_NUM);

	lba>>=8;
	pd=(u8)lba;
	outb(pd,base_reg+HD_REG_CYL1);

	lba>>=8;
	pd=(u8)lba;
	outb(pd,base_reg+HD_REG_CYL2);

	outb(1,base_reg+HD_REG_COUNT);

	lba>>=8;
	pd=(u8)lba;
	pd&=0x0f;
	id<<=4;
	pd|=(u8)id;
	pd|=0xe0;
	outb(pd,base_reg+HD_REG_HD);

	do
		data=inb(base_reg+HD_REG_STATUS);
	while( (data&0x80) || (data&8) );
	
	outb(0x20,HD_REG_COMMAND+base_reg);
	
	do
		data=inb(HD_REG_STATUS+base_reg);
	while( !(data&8) );
	
	asm volatile (
	"cld\n\trep insw"
	:
	:"D"(pout),"c"(512/2),"d"(HD_REG_DATA+base_reg)
	:"memory" );
	
	do
		data=inb(HD_REG_STATUS+base_reg);
	while(data&0x80);
}

