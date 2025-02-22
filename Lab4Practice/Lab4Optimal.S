	.file	"Lab4Optimal.cpp"
	.text
	.globl	_Z5dummyii
	.def	_Z5dummyii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5dummyii
_Z5dummyii:
.LFB0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %eax
	imull	24(%rbp), %eax
	movl	%eax, -4(%rbp)
	cmpl	$0, 16(%rbp)
	je	.L2
	cmpl	$0, 24(%rbp)
	jne	.L3
.L2:
	movl	$0, %eax
	jmp	.L4
.L3:
	movl	-4(%rbp), %eax
.L4:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 10.3.0"
