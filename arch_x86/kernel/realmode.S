//改自 grub 1.97~beta4
/*
 *  These next two routines, "real_to_prot" and "prot_to_real" are structured
 *  in a very specific way.  Be very careful when changing them.
 *
 *  NOTE:  Use of either one messes up %eax and %ebp.
 */
.globl real_mode_int, setup_real_code
.extern i8259_irqsave, i8259_irqrestore
REAL_STACK=0x7c00
REAL_CODE=0x7d00
OFFSET=__real_proc - REAL_CODE

__real_proc:
	.code32
	pushfl
	cli
	/* save the protected mode stack */
	movl	%esp, %eax
	movl	%eax, (protstack)
	lidt	real_idt48
	/* set up new stack */
	movl	REAL_STACK, %eax
	movl	%eax, %esp

	/* jump to a 16 bit segment */
	ljmp	$0x30, $(tmpcseg-OFFSET)

tmpcseg:
	.code16
	/* clear the PG PE bit of CR0 */
	movw	$0x38,%ax
	movw	%ax,%ds
	movw	%ax,%es
	movw	%ax,%fs
	movw	%ax,%gs
	movw	%ax,%ss
	movl	%cr0, %eax
	andl 	$0x7ffffffe, %eax
	movl	%eax, %cr0
	/* flush prefetch queue, reload %cs */
	DATA32	ljmp	$0, $(realcseg-OFFSET)

realcseg:
	/* we are in real mode now
	 * set up the real mode segment registers : DS, SS, ES
	 */
	xorl	%eax, %eax
	movw	%ax, %ds
	movw	%ax, %es
	movw	%ax, %fs
	movw	%ax, %gs
	movw	%ax, %ss
	sti
	
	/* real mode code is here */
	movl	%edi,%eax
	movb	%dl,(vec-OFFSET)
	movl	$0x1000,%edi	//for vesa buffer 请与video.c同步
	.byte 0xcd		//int xx
vec:	.byte 0
	movl %eax,%edi
	/* real mode code is here */

	/* begin return */
	cli
	/* load the GDT register */
	xorw	%ax, %ax
	movw	%ax, %ds
	DATA32	ADDR32	lgdt	(tmp_gdt48-OFFSET)

	/* turn on protected mode */
	movl	%cr0, %eax
	orl	$1, %eax		//PE ON
	movl	%eax, %cr0

	/* jump to relocation, flush prefetch queue, and reload %cs */
	DATA32	ljmp	$0x8, $(protcseg)

	.code32
tmp_gdt:
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

tmp_gdt48:
	.word 0x800
	.long tmp_gdt-OFFSET
__real_proc_end:

protcseg:
	.code32
	/* reload other segment registers */
	movw	$0x10, %ax
	movw	%ax, %ds
	movw	%ax, %es
	movw	%ax, %ss

	/* get protected mode stack */
	movl	(protstack), %eax
	movl	%eax, %esp
	
	popfl
	ret

	.code32
real_mode_int:	//(int vec,int *eax,int *ebx)

	call	i8259_irqsave
	movl	%cr0, %eax
	push	%eax
	movl	%cr3, %eax
	push	%eax
	
	push	%esp
	push	%ebp
	push	%esi
	push	%edi
	push	%ebx
	
	//ax-->di
	movl	4*8(%esp),%edx		//vec
	movl	4*9(%esp),%eax		//eax
	movl	(%eax),%edi
	movl	4*10(%esp),%eax		//ebx
	movl	(%eax),%ebx
	movl	%ebx,%ecx		//ecx=ebx,ugly for vesa
	
	movl	$REAL_CODE,%eax
	call	*%eax
	
	movl	4*9(%esp),%eax		//ret eax
	movl	%edi,(%eax)
	movl	4*10(%esp),%eax		//ret ebx
	movl	%ebx,(%eax)
	
	
	pop	%ebx
	pop	%edi
	pop	%esi
	pop	%ebp
	pop	%esp
	
	pop	%eax
	movl	%eax, %cr3
	pop	%eax
	movl	%eax, %cr0
	lgdt	gdt_48
	ljmp	$0x8, $1f
1:	movw	$0x10, %ax
	movw	%ax, %ds
	movw	%ax, %es
	movw	%ax, %ss
	lidt	idt_48
	call	i8259_init
	call	i8259_irqrestore

	inb	$0x60, %al
	inb	$0x60, %al
	inb	$0x60, %al
	inb	$0x60, %al
	ret

setup_real_code:
	push	%esi
	push	%edi
	movl	$__real_proc,%esi
	movl	$REAL_CODE,%edi
	movl	$__real_proc_end,%ecx
	subl	$__real_proc,%ecx
	cld
	rep movsb
	pop	%edi
	pop	%esi
	ret

real_idt48:
	.word 0x3ff
	.long 0
protstack:
	.long 0
//grub end
