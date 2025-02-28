	.file	"Lab5gpt.cpp"
	.text
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
.lcomm _ZStL8__ioinit,1,1
	.text
	.globl	_Z17manhattanDistanceRK7Point3DS1_
	.def	_Z17manhattanDistanceRK7Point3DS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z17manhattanDistanceRK7Point3DS1_
_Z17manhattanDistanceRK7Point3DS1_:
.LFB1847:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %edx
	movq	24(%rbp), %rax
	movl	(%rax), %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, %ecx
	sarl	$31, %ecx
	xorl	%ecx, %eax
	movl	%eax, %edx
	subl	%ecx, %edx
	movq	16(%rbp), %rax
	movl	4(%rax), %ecx
	movq	24(%rbp), %rax
	movl	4(%rax), %r8d
	movl	%ecx, %eax
	subl	%r8d, %eax
	movl	%eax, %ecx
	sarl	$31, %ecx
	xorl	%ecx, %eax
	subl	%ecx, %eax
	leal	(%rdx,%rax), %r8d
	movq	16(%rbp), %rax
	movl	8(%rax), %edx
	movq	24(%rbp), %rax
	movl	8(%rax), %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	cltd
	xorl	%edx, %eax
	subl	%edx, %eax
	addl	%r8d, %eax
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1848:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$88, %rsp
	.seh_stackalloc	88
	leaq	80(%rsp), %rbp
	.seh_setframe	%rbp, 80
	.seh_endprologue
	call	__main
	leaq	-36(%rbp), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx
.LEHB0:
	call	_ZNSirsERi
.LEHE0:
	movl	$0, -12(%rbp)
.L10:
	movl	-36(%rbp), %eax
	cmpl	%eax, -12(%rbp)
	jge	.L4
	movq	%rsp, %rax
	movq	%rax, %rbx
	cmpl	$0, -12(%rbp)
	jle	.L5
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
.LEHB1:
	call	_ZNSolsEPFRSoS_E
.L5:
	leaq	-40(%rbp), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx
	call	_ZNSirsERi
	movl	-40(%rbp), %eax
	cltq
	leaq	-1(%rax), %rcx
	movq	%rcx, -24(%rbp)
	movq	%rcx, %rax
	addq	$1, %rax
	movq	%rax, %rsi
	movl	$0, %edi
	imulq	$96, %rdi, %rdx
	imulq	$0, %rsi, %rax
	leaq	(%rdx,%rax), %r8
	movl	$96, %eax
	mulq	%rsi
	addq	%rdx, %r8
	movq	%r8, %rdx
	movq	%rcx, %rax
	leaq	1(%rax), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	%rcx, %rax
	addq	$1, %rax
	movq	%rax, %r12
	movl	$0, %r13d
	imulq	$96, %r13, %rdx
	imulq	$0, %r12, %rax
	leaq	(%rdx,%rax), %r8
	movl	$96, %eax
	mulq	%r12
	addq	%rdx, %r8
	movq	%r8, %rdx
	movq	%rcx, %rax
	leaq	1(%rax), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	call	___chkstk_ms
	subq	%rax, %rsp
	leaq	32(%rsp), %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -32(%rbp)
	movl	$0, -8(%rbp)
.L7:
	movl	-40(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	jge	.L6
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx
	call	_ZNSirsERi
	movq	%rax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rdx
	addq	%rdx, %rax
	addq	$4, %rax
	movq	%rax, %rdx
	call	_ZNSirsERi
	movq	%rax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rdx
	addq	%rdx, %rax
	addq	$8, %rax
	movq	%rax, %rdx
	call	_ZNSirsERi
	addl	$1, -8(%rbp)
	jmp	.L7
.L6:
	movl	$0, -4(%rbp)
.L9:
	movl	-40(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -4(%rbp)
	jge	.L8
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rdx
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movq	%rcx, %rax
	addq	%rax, %rax
	addq	%rcx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rcx
	addq	%rcx, %rax
	movq	%rax, %rcx
	call	_Z17manhattanDistanceRK7Point3DS1_
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
.LEHE1:
	addl	$1, -4(%rbp)
	jmp	.L9
.L8:
	movq	%rbx, %rsp
	addl	$1, -12(%rbp)
	jmp	.L10
.L4:
	movl	$0, %eax
	jmp	.L14
.L13:
	movq	%rbx, %rsp
	movq	%rax, %rcx
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L14:
	leaq	8(%rbp), %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	popq	%r13
	popq	%rbp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA1848:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1848-.LLSDACSB1848
.LLSDACSB1848:
	.uleb128 .LEHB0-.LFB1848
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1848
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L13-.LFB1848
	.uleb128 0
	.uleb128 .LEHB2-.LFB1848
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE1848:
	.text
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2347:
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
.LFB2346:
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
	jne	.L18
	cmpl	$65535, 24(%rbp)
	jne	.L18
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L18:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I__Z17manhattanDistanceRK7Point3DS1_;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z17manhattanDistanceRK7Point3DS1_
_GLOBAL__sub_I__Z17manhattanDistanceRK7Point3DS1_:
.LFB2348:
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
	.quad	_GLOBAL__sub_I__Z17manhattanDistanceRK7Point3DS1_
	.ident	"GCC: (tdm64-1) 10.3.0"
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
