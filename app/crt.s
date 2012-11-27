.text
.code32
.global _start, errno, environ
.extern main,libc_init
_start:
	jmp 1f
	.byte 'X','B','I','N'
1:
	/* init bss */
	movl $__bss_start,%edi
	movl $_end,%ecx
	sub $__bss_start,%ecx
	movl $0,%eax
	cld
	rep stosb
	
	call libc_init
	call main
	movl %eax,%ebx	/*exit code*/
	movl $9,%eax	/*exit system call*/
	int $0x80
errno:
	.long 0
