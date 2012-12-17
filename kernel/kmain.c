#include <os/arch_config.h>
#include <os/type.h>
#include <lib/klib.h>
#include <os/multiboot.h>

void print_early_init();
void isr_init();
void mm_init(unsigned int size);
void shm_init();
void task_init();
void drv_init();
void idle_task_func();
void time_init();
void fpu_fault_init();
void devfs_init();
void timer_init();
void drv_init();
void vfs_start();

void kmain()
{
	unsigned long memsize;
	multiboot_info_t *pmbi=pmultiboot_info;
	memsize=pmbi->mem_upper<<10;
	print_early_init();	
	printk("mem size:%lu\n",memsize);

	/* init begin */
	kmalloc_init();
	devfs_init();
	pic_init();
	isr_init();
	mm_init(memsize);
	shm_init();
	fpu_fault_init();
	time_init();
	timer_init();
	vfs_start();
	drv_init();
	task_init();
	/* init end */
	
	/* move to user mode */
	idle_task_func();

	/* 不可能到达这里 */
	panic("kernel!");
}

