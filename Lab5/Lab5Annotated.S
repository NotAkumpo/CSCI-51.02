	.file	"Lab5.cpp"
	.text
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
.lcomm _ZStL8__ioinit,1,1
	.text
	.globl	_Z5getMD7Point3DS_
	.def	_Z5getMD7Point3DS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5getMD7Point3DS_
_Z5getMD7Point3DS_:
.LFB1847:
	pushq	%rbp	#Save old bp to stack
	.seh_pushreg	%rbp
	pushq	%rsi	#Save p to stack
	.seh_pushreg	%rsi
	pushq	%rbx	#Save q to stack
	.seh_pushreg	%rbx
	leaq	(%rsp), %rbp	#Set up new base pointer
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, %rsi	#p pointer goes to %rsi
	movq	%rdx, %rbx	#q pointer goes to %rsi
	movl	(%rsi), %eax	#p.x goes to %eax
	movl	(%rbx), %edx	#q.x goes to %edx
	subl	%edx, %eax	#p.x - q.x to %eax
	movl	%eax, %ecx	#result to %ecx
	sarl	$31, %ecx	#produce a string of 1s in %ecx if - and 0s if + (get abs val starts here)
	xorl	%ecx, %eax	#if negative all bits are flipped, if positive nothing
	movl	%eax, %edx	#result to %edx
	subl	%ecx, %edx	#if positive just - 0, result in %edx, if negative - (-1) so +1, doing a complete two's comp (get abs val starts here)
	movl	4(%rsi), %eax	#p.y - q.y starts here
	movl	4(%rbx), %ecx
	subl	%ecx, %eax
	movl	%eax, %ecx
	sarl	$31, %ecx
	xorl	%ecx, %eax
	subl	%ecx, %eax	#p.y - q.y ends here
	leal	(%rdx,%rax), %ecx	#x-diff + y-diff goes to %ecx
	movl	8(%rsi), %eax	#p.z - q.z starts here
	movl	8(%rbx), %edx
	subl	%edx, %eax
	cltd	#same as sarl but on rax
	xorl	%edx, %eax	
	subl	%edx, %eax	#p.y - q.y ends here
	addl	%ecx, %eax	#add z-diff to total
	popq	%rbx	
	popq	%rsi
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
	subq	$120, %rsp
	.seh_stackalloc	120
	leaq	112(%rsp), %rbp
	.seh_setframe	%rbp, 112
	.seh_endprologue
	call	__main
	leaq	-36(%rbp), %rax		#Address of t
	movq	%rax, %rdx	#Address of t to %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx	#cin to %rcx
.LEHB0:
	call	_ZNSirsERi	#cin >> t
.LEHE0:
	movl	$0, -12(%rbp)
.L10:	#Test case loop
	movl	-36(%rbp), %eax		
	cmpl	%eax, -12(%rbp)		
	jge	.L4		#Skip to .L4 if all test cases done
	movq	%rsp, %rax
	movq	%rax, %rbx
	leaq	-40(%rbp), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx
.LEHB1:
	call	_ZNSirsERi
	movl	-40(%rbp), %eax		#cin >> p
	cltq
	leaq	-1(%rax), %rcx
	movq	%rcx, -24(%rbp)
	movq	%rcx, %rax
	addq	$1, %rax
	movq	%rax, %rsi
	movl	$0, %edi
	imulq	$96, %rdi, %rdx		#Calculate space size
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
.L6:
	movl	-40(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	jge	.L5
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rdx		#Get address of points
	addq	%rdx, %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx
	call	_ZNSirsERi		#Read x
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
	call	_ZNSirsERi	#Read y
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
	call	_ZNSirsERi	#Read z
	addl	$1, -8(%rbp)
	jmp	.L6
.L5:	#End of point reading loop
	movl	$0, -4(%rbp)
.L8:	#Start of distance calculation loop
	movl	-40(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -4(%rbp)
	jge	.L7
	movl	-4(%rbp), %eax
	leal	1(%rax), %ecx
	movq	-32(%rbp), %r8
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%r8, %rax
	movq	(%rax), %rdx
	movq	%rdx, -64(%rbp)
	movl	8(%rax), %eax
	movl	%eax, -56(%rbp)
	movq	-32(%rbp), %r8
	movslq	%ecx, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%r8, %rax
	movq	(%rax), %rdx
	movq	%rdx, -80(%rbp)
	movl	8(%rax), %eax
	movl	%eax, -72(%rbp)
	leaq	-80(%rbp), %rdx		# Address of points[i+1]
	leaq	-64(%rbp), %rax		# Address of points[i]
	movq	%rax, %rcx		#Set up for function call
	call	_Z5getMD7Point3DS_		#Execute getMD function
	movl	%eax, %edx		#Result to %edx
	movq	.refptr._ZSt4cout(%rip), %rcx	#cout to %rcx
	call	_ZNSolsEi	#Print result
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	addl	$1, -4(%rbp)
	jmp	.L8
.L7:	#End of distance calculation loop
	movl	-36(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	jge	.L9
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEPFRSoS_E
.LEHE1:
.L9:	#Optional blank line between test cases
	movq	%rbx, %rsp
	addl	$1, -12(%rbp)
	jmp	.L10
.L4:	#Exit after processing all test cases
	movl	$0, %eax
	jmp	.L14
.L13:
	movq	%rbx, %rsp
	movq	%rax, %rcx
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L14:	#Program exit and cleanup
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
	.def	_GLOBAL__sub_I__Z5getMD7Point3DS_;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z5getMD7Point3DS_
_GLOBAL__sub_I__Z5getMD7Point3DS_:
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
	.quad	_GLOBAL__sub_I__Z5getMD7Point3DS_
	.ident	"GCC: (tdm64-1) 10.3.0"
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
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
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
