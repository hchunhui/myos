.text
.code32
.global _start, errno
.extern main, libc_init
.extern __start_ctors, __end_ctors
.extern __cxa_finalize

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
	/* init libc */
	call libc_init
	/* call static constructors */
	call call_ctors
	
	/* call main */
	call main
	pushl %eax
	
	/* call __cxa_finalize */
	pushl $0
	call __cxa_finalize
	add $4, %esp
	
	popl %eax
	movl %eax,%ebx	/*exit code*/
	movl $9,%eax	/*exit system call*/
	int $0x80

call_ctors:
	pushl %ebx
	movl $__start_ctors, %ebx
	jmp 2f
1:	call *(%ebx)
	addl $4, %ebx
2:	cmpl $__end_ctors, %ebx
	jb 1b
	popl %ebx
	ret

errno:
	.long 0
