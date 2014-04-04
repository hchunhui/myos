.text
.globl init_kernel
.extern kmain, gdt_48, idt_48, setup_real_code
.code32

init_kernel:
	movl $init_stack, %esp
	call make_gdt_desc
	call make_idt_desc
	lgdt gdt_48
	ljmp $0x8, $1f
1:	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %ss
	movw $0, %ax
	movw %ax, %fs
	movw %ax, %gs
	lidt idt_48
	call setup_real_code
	call kmain
	jmp .

.fill 4096,1,0
init_stack:
