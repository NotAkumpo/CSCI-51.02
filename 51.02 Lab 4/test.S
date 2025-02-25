	.file	"test.cpp"
	.text
	.globl	_Z8multiplyi
	.def	_Z8multiplyi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8multiplyi
_Z8multiplyi:
.LFB0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	negl	16(%rbp)
	movl	16(%rbp), %eax
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 10.3.0"
