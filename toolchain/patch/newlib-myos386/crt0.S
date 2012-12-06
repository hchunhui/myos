.global _start
.global environ
.extern main
.extern _init, _fini
.text

_start:
	jmp 1f
	.byte 'X','B','I','N'
1:
	/* init bss */
	movl $__bss_start, %edi
	movl $_end, %ecx
	subl $__bss_start, %ecx
	movl $0, %eax
	cld
	rep stosb
	/* call static constructors */
	call	_init
	pushl	$_fini
	call	atexit
	add	$4, %esp

	/* get environ */
	movl 8(%esp), %eax
	movl %eax, environ

	/* call main */
	call main

	movl %eax, %ebx	/* exit code */
	movl $9, %eax	/* exit system call */
	int $0x80
2:
	jmp	2b

.data
environ:
	.long 0
