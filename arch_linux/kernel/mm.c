#include <os/type.h>
#include <os/arch_config.h>
#include <os/mm.h>
#include <lib/klib.h>
#include <os/task.h>
#include <lib/string.h>
#include <os/asm.h>
#include <os/shm.h>
#include <os/isr.h>

/* memory size */
static unsigned int mem_size;


//interfaces
void mm_recycle_page(unsigned long pg_no)
{
	kfree((void *)pg_no);
}

unsigned long mm_get_free_page()		/* 不考虑特殊情况，返回页号 */
{
	return (unsigned long)kmalloc(PAGE_SIZE);
}

void mm_fork(struct s_task *task_new, struct s_task *task_old, unsigned int flags)
{
	printk("mm_fork\n");
}

void mm_exit(struct s_task *ptask)
{
	printk("mm_exit\n");
}

void mm_share_page(unsigned long phy_pg, unsigned long logi_pg, int flag)
{

}

void mm_unshare_page(unsigned long phy_pg, unsigned long logi_pg)
{

}

void mm_set_page_info_attr(unsigned long phy_pg, u16 flags)
{

}

void mm_change_page(int pid)
{

}

void mm_refresh_page()
{

}

void mm_switch(struct s_task *prev, struct s_task *next)
{
	printk("mm_switch\n");
}

void mm_init(unsigned int size)
{
	mem_size = size;
	if(mem_size > usr_stack_top)
	{
		mem_size = usr_stack_top;
		printk("mm: only use %dK memory.\n", mem_size / 1024);
	}
	
	if(mem_size <= kernel_brk)
	{
		panic("Memory not enough");
	}
}
