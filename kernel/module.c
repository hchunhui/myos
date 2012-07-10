#include <lib/klib.h>
#include <os/multiboot.h>
#include <lib/string.h>

void module_init()
{
	int i;
	int j;
	module_t *mod;
	multiboot_info_t *pmbi=pmultiboot_info;
	
	//show mods
	printk("fs_init:\n  find %d modules\n",pmbi->mods_count);
	for (i = 0, mod = (module_t *) pmbi->mods_addr; i < pmbi->mods_count; i++, mod ++)
	{
		for(j = strlen((char *)(mod->string)); j >= 0 ; j--)
		{
			if(((char *)(mod->string))[j] == '/')
			{
				mod->string += j;
				break;
			}
		}
		printk("    start addr: %x  end addr: %x  file name: %s\n",
			mod->mod_start,mod->mod_end,(char*)(mod->string));
	}
}

int module_get(char* filename,char* buf)
{
	module_t *mod;
	multiboot_info_t *pmbi=pmultiboot_info;
	int i;
	for (i = 0, mod = (module_t *) pmbi->mods_addr; i < pmbi->mods_count; i++, mod ++)
	{
		if(strcmp(filename,(char*)(mod->string))==0)
		{
			memcpy(buf,(void *)mod->mod_start,mod->mod_end-mod->mod_start);
			return 1;
		}
	}
	return 0;
}

long module_get_size(char *filename)
{
	module_t *mod;
	multiboot_info_t *pmbi=pmultiboot_info;
	int i;
	for (i = 0, mod = (module_t *) pmbi->mods_addr; i < pmbi->mods_count; i++, mod ++)
	{
		if(strcmp(filename,(char*)(mod->string))==0)
		{
			return mod->mod_end-mod->mod_start;
		}
	}
	return 0;
}

long sys_get_module_size(char* filename)
{
	return module_get_size(filename);
}

long sys_get_module(char* filename, char* buf)
{
	return module_get(filename,buf);
}
