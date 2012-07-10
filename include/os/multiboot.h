#ifndef _MULTIBOOT_H_
#define _MULTIBOOT_H_
/* The symbol table for a.out. */
typedef struct aout_symbol_table
{
	unsigned long tabsize;
	unsigned long strsize;
	unsigned long addr;
	unsigned long reserved;
} aout_symbol_table_t;
/* The section header table for ELF. */

typedef struct elf_section_header_table
{
	unsigned long num;
	unsigned long size;
	unsigned long addr;
	unsigned long shndx;
} elf_section_header_table_t;


/* The Multiboot information. */
typedef struct multiboot_info
{
	unsigned long flags;
	unsigned long mem_lower;
	unsigned long mem_upper;
	unsigned long boot_device;
	unsigned long cmdline;
	unsigned long mods_count;
	unsigned long mods_addr;
	union
	{
		aout_symbol_table_t aout_sym;
		elf_section_header_table_t elf_sec;
	}u;
	unsigned long mmap_length;
	unsigned long mmap_addr;
} multiboot_info_t;

/* The module structure. */
typedef struct module
{
unsigned long mod_start;
unsigned long mod_end;
unsigned long string;
unsigned long reserved;
}module_t;

/* The memory map. Be careful that the offset 0 is base_addr_low
but no size. */
typedef struct memory_map
{
	unsigned long size;
	unsigned long base_addr_low;
	unsigned long base_addr_high;
	unsigned long length_low;
	unsigned long length_high;
	unsigned long type;
} memory_map_t;

extern multiboot_info_t *pmultiboot_info;

#endif

