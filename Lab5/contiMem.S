	.file	"contiMem.cpp"
	.text
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
.lcomm _ZStL8__ioinit,1,1
	.text
	.globl	_Z3retPi
	.def	_Z3retPi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3retPi
_Z3retPi:
.LFB1632:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)   # move x to stack
	movl	$0, -8(%rbp)   # move 0 to stack as i
	movl	$0, -4(%rbp)   # move 0 to stack as ret
.L3:
	movq	16(%rbp), %rax   # move x to register
	movl	(%rax), %eax   # load x to another register
	testl	%eax, %eax   # check if x is 0 and set flags
	jle	.L2   # jump to L2 if x is le to 0
	movq	16(%rbp), %rax   # move x to register
	movl	(%rax), %eax   # load x to another register
	addl	%eax, -4(%rbp)   # add x to ret
	addq	$4, 16(%rbp)   # move x to the next element in the array
	movq	16(%rbp), %rdx   # 
	movq	.refptr._ZSt4cout(%rip), %rcx   # 
	call	_ZNSolsEPKv   # 
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx   # 
	movq	%rax, %rcx   # 
	call	_ZNSolsEPFRSoS_E   # 
	jmp	.L3
.L2:
	movl	-4(%rbp), %eax   # 
	addq	$48, %rsp   # 
	popq	%rbp   # 
	ret   # 
	.seh_endproc   # 
	.def	__main;	.scl	2;	.type	32;	.endef   # 
	.globl	main   # 
	.def	main;	.scl	2;	.type	32;	.endef   # 
	.seh_proc	main   # 
main:
.LFB1633:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$5, -16(%rbp)
	movl	$3, -12(%rbp)
	movl	$9, -8(%rbp)
	movl	$0, -4(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_Z3retPi
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2133:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB2132:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L10
	cmpl	$65535, 24(%rbp)
	jne	.L10
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L10:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I__Z3retPi;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z3retPi
_GLOBAL__sub_I__Z3retPi:
.LFB2134:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z3retPi
	.ident	"GCC: (tdm64-1) 10.3.0"
	.def	_ZNSolsEPKv;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
