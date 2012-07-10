#include <lib/klib.h>
#include <os/multiboot.h>

multiboot_info_t mbi;
multiboot_info_t *pmultiboot_info = &mbi;

void kmain();
void real_mode_int()
{
}

void kmalloc_init()
{
}

int main(int argc, char **argv)
{
	printf("myos in linux\n");
	pmultiboot_info->mem_upper = 128*1024;
	kmain();
	return 0;
}
