	.file	"sections.c"
	.comm	a,4,4
	.globl	b
	.section	.rodata
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	10
	.local	c
	.comm	c,4,4
	.align 4
	.type	d, @object
	.size	d, 4
d:
	.long	20
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
	subl	$16, %esp
	movl	$3, -4(%ebp)
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
	.type	i.1378, @object
	.size	i.1378, 4
i.1378:
	.long	1
	.local	h.1377
	.comm	h.1377,4,4
	.data
	.align 4
	.type	g.1376, @object
	.size	g.1376, 4
g.1376:
	.long	2
	.local	f.1375
	.comm	f.1375,4,4
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
