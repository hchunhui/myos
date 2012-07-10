#ifndef _HD_H_
#define _HD_H_

struct s_hd_dpt
{
	BYTE active;
	BYTE head;
	WORD sec_cyl; 		/* 0-5 bit -- sector,6-15 bit -- cylinder */
	BYTE type;			/*00H--未用 06H--FAT16基本分区 0BH--FAT32基本分区 05H--扩展分区 07H--NTFS分区 0FH--扩展分区 83H--Linux分区*/
	BYTE head2;
	WORD sec_cyl2;
	DWORD sec_start;
	DWORD sec_count;
}__attribute__((packed));

struct s_hd_mbr
{
	BYTE bootcode[0x1be];
	struct s_hd_dpt dpt[4];
	BYTE sign55;
	BYTE signaa;
}__attribute__((packed));

struct s_hd_ebr
{
	
};



void drv_hd_read(u32 lba,u8 id,u8 *pout); //in 512b
void drv_hd_write(u32 lba,u8 id,u8 *pout);
struct s_hd_mbr* drv_hd_get_mbr();

#endif
