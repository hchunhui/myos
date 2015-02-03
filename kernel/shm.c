#include <os/type.h>
#include <os/arch_config.h>
#include <os/mm.h>
#include <lib/klib.h>
#include <os/task.h>
#include <lib/string.h>
#include <os/asm.h>
#include <os/shm.h>

#define SHM_INFO_LEN 16
#define EINVAL 2


struct s_shminfo
{
	int key;
	int count;
	unsigned long page_table[4*1024*1024/PAGE_SIZE];
	int page_count;
};

struct s_shminfo shm_info[SHM_INFO_LEN];

void shm_init()
{
	int i;
	
	memset(shm_info, 0, sizeof(shm_info));
	for(i = 0; i < SHM_INFO_LEN; i++)
	{
		shm_info[i].key = -1;
	}
}

int find_key(int key)
{
	int i;
	for(i = 0; i < SHM_INFO_LEN; i++)
	{
		if(shm_info[i].key == key)
			return i;
	}
	return -1;
}

int shm_at(int key, unsigned long base_addr, unsigned int flag)
{
	unsigned long start_pg;
	int i;
	int j;
	
	if((base_addr) & (PAGE_SIZE - 1))
		return -EINVAL;
	
	start_pg = base_addr / PAGE_SIZE;
	
	i = find_key(key);
	if(i == -1)
		return -EINVAL;
	
	for(j = 0; j < shm_info[i].page_count; j++)
	{
		//printk("share phy(%d) to (%d)\n", shm_info[i].page_table[j], start_pg + j);
		mm_share_page(
			shm_info[i].page_table[j], start_pg + j, flag);
	}
	
	shm_info[i].count++;
	mm_refresh_page();
	return 0;
}

int shm_dt(int key, unsigned long base_addr)
{
	unsigned long start_pg;
	int i;
	int j;
	
	if((base_addr) & (PAGE_SIZE - 1))
		return -EINVAL;
	
	start_pg = base_addr / PAGE_SIZE;
	
	i = find_key(key);
	if(i == -1)
		return -EINVAL;
	
	printk("shm_dt, page_count = %d\n", shm_info[i].page_count);
	for(j = 0; j < shm_info[i].page_count; j++)
	{
		//printk("remove share phy(%d) to (%d)\n", shm_info[i].page_table[j], start_pg + j);
		mm_unshare_page(
			shm_info[i].page_table[j], start_pg + j);
	}
	
	shm_info[i].count--;
	if(shm_info[i].count == 0)
	{
		shm_free(key);
	}
	mm_refresh_page();
	return 0;
}

int shm_free(int key)
{
	int i;

	i = find_key(key);
	if(i == -1)
		return -EINVAL;
	
	memset(shm_info + i, 0, sizeof(struct s_shminfo));
	shm_info[i].key = -1;
	printk("shm_free: free shm_info.\n");
	return 0;
}

int shm_get(int key, unsigned long size)
{
	int page_count;
	int i;
	int j;
	
	page_count = size / PAGE_SIZE;
	if(size % PAGE_SIZE)
		page_count++;
	
	if(key <= 0)
		return -1;
	
	if(find_key(key) != -1)
		return -1;

	i = find_key(-1);
	if(i == -1)
		return -1;

	shm_info[i].key = key;
	shm_info[i].count = 0;
	
	for(j = 0; j < page_count; j++)
	{
		shm_info[i].page_table[j] = mm_get_free_page();
		mm_set_page_info_attr(
			shm_info[i].page_table[j],
			MM_PI_SHARE);
	}
	shm_info[i].page_count = page_count;
	
	printk("shm_shmget: got %d pages.\n", page_count);
	return 0;
}

asmlinkage long sys_shm_at(int key, unsigned long base_addr, unsigned int flag)
{
	printk("shm_at\n");
	return shm_at(key, base_addr, flag);
}

asmlinkage long sys_shm_dt(int key, unsigned long base_addr)
{
	return shm_dt(key, base_addr);
}

asmlinkage long sys_shm_free(int key)
{
	return shm_free(key);
}

asmlinkage long sys_shm_get(int key, unsigned long size)
{
	return shm_get(key, size);
}
