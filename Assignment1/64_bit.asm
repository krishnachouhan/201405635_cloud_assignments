	.file	"a.cpp"
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	%rsp, %rbp
	.cfi_def_cfa_register 6
	
	subq	$32, %rsp
	movl	$10, 20(%rsp)
	movl	$10, 24(%rsp)
	movl	24(%rsp), %eax
	movl	20(%rsp), %edx
	addl	%edx, %eax
	movl	%eax, 28(%rsp)
	movl	28(%rsp), %eax
	movl	%eax, 4(%rsp)
	movl	$.LC0, (%rsp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
