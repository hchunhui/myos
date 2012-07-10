/*
 * Huang Guan
 * 090803
 */

/* multiboot defines */
MULTIBOOT_PAGE_ALIGN =  (1 << 0)	/* modules are page aligned */
MULTIBOOT_MEMORY_INFO = (1 << 1)
MULTIBOOT_VIDEO_INFO =  (1 << 2)
MULTIBOOT_AOUT_KLUDGE = (1 << 16)
MULTIBOOT_HEADER_MAGIC = (0x1BADB002)
MULTIBOOT_HEADER_FLAGS = (MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE | MULTIBOOT_VIDEO_INFO)
MULTIBOOT_CHECKSUM = -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
OFFSET=0x0 ;//0xd00000		/*14M*/
.global _start, pmultiboot_info

_start:
	jmp multiboot_entry+OFFSET
.align 4
_multiboot_header:
	.long 	MULTIBOOT_HEADER_MAGIC
	.long	MULTIBOOT_HEADER_FLAGS
	.long	MULTIBOOT_CHECKSUM
	.long	(_multiboot_header+OFFSET)	/* header addr */
	.long	(_start+OFFSET)			/* load addr */
	.long	(__bss_start+OFFSET)		/* load end addr */
	.long	(_end+OFFSET)			/* bss end addr */
	.long	(multiboot_entry+OFFSET)	/* entry addr */
	.long	0				/* video mode type */
	.long	0				/* width */
	.long	0				/* height */
	.long	0				/* depth */
meminfo_addr:
	.long	0

pmultiboot_info:
	.long	0

multiboot_entry:
	/* save multiboot info */
	movl %ebx,(pmultiboot_info+OFFSET)
	lgdt (__gdt_48+OFFSET)
	ljmp $0x08,$(ref+OFFSET)
ref:	movw $0x10,%ax
	movw %ax,%ds
	movw %ax,%es
	movw %ax,%fs
	movw %ax,%gs
	movw %ax,%ss
	
	/* save grub's string */
	//movl $0,%esi
	//movl $OFFSET2,%edi
	//movl $(256*1024),%ecx	/*1M*/
	//cld
	//rep movsd
	
	/* move kernel */
	//movl $OFFSET,%esi
	//movl $0,%edi
	//movl $_end/*256*40*/,%ecx
	//add $4,%ecx
	//shr $2,%ecx
	//cld
	//rep movsd
	
	/* init bss */
	movl $__bss_start,%edi
	movl $_end,%ecx
	subl $__bss_start,%ecx
	movl $0,%eax
	cld
	rep stosb
	
	ljmpl $8,$start
	
__gdt:
	.word 0,0,0,0 				/*dummy*/
	.word 0xffff				/*code seg*/
	.word 0
	.byte 0
	.byte 0x9a
	.byte 0xcf
	.byte 0
	
	.word 0xffff				/*data seg*/
	.word 0x0
	.byte 0
	.byte 0x92
	.byte 0xcf
	.byte 0

__gdt_48:
	.word 0x800
	.long OFFSET+__gdt
