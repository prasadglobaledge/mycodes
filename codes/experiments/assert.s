	.file	"assert.c"
	.section	.rodata
.LC0:
	.string	"assert.c"
.LC1:
	.string	"ptr"
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0, 28(%esp)
	cmpl	$0, 28(%esp)
	jne	.L2
	movl	$__PRETTY_FUNCTION__.1840, 12(%esp)
	movl	$7, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$.LC1, (%esp)
	call	__assert_fail
.L2:
	movl	28(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.type	__PRETTY_FUNCTION__.1840, @object
	.size	__PRETTY_FUNCTION__.1840, 5
__PRETTY_FUNCTION__.1840:
	.string	"main"
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
