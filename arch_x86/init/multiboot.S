/* multiboot defines */
MULTIBOOT_PAGE_ALIGN =  (1 << 0)
MULTIBOOT_MEMORY_INFO = (1 << 1)
MULTIBOOT_VIDEO_INFO =  (1 << 2)
MULTIBOOT_AOUT_KLUDGE = (1 << 16)
MULTIBOOT_HEADER_MAGIC = (0x1BADB002)
MULTIBOOT_HEADER_FLAGS = (MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE)
MULTIBOOT_CHECKSUM = -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
.global _start, pmultiboot_info
.extern init_kernel

_start:
	jmp multiboot_entry
.align 4
_multiboot_header:
	.long 	MULTIBOOT_HEADER_MAGIC
	.long	MULTIBOOT_HEADER_FLAGS
	.long	MULTIBOOT_CHECKSUM
	/* header addr */
	.long	_multiboot_header
	/* load addr */
	.long	_start
	/* load end addr */
	.long	__bss_start
	/* bss end addr */
	.long	_end
	/* entry addr */
	.long	multiboot_entry

pmultiboot_info:
	.long	0

multiboot_entry:
	/* save multiboot info */
	movl %ebx, pmultiboot_info
	lgdt __gdt_48
	ljmp $0x8,$1f
1:	movw $0x10,%ax
	movw %ax,%ds
	movw %ax,%es
	movw %ax,%fs
	movw %ax,%gs
	movw %ax,%ss
	
	/* init bss */
	movl $__bss_start,%edi
	movl $_end,%ecx
	subl $__bss_start,%ecx
	movl $0,%eax
	cld
	rep stosb
	
	ljmpl $0x8,$init_kernel
	
__gdt:
	/* dummy */
	.word 0,0,0,0
	/* code seg */
	.word 0xffff
	.word 0
	.byte 0
	.byte 0x9a
	.byte 0xcf
	.byte 0
	/* data seg */
	.word 0xffff
	.word 0
	.byte 0
	.byte 0x92
	.byte 0xcf
	.byte 0

__gdt_48:
	.word 0x800
	.long __gdt
