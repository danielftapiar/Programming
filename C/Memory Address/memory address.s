	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:
Leh_func_begin1:
	pushq	%rbp
Ltmp0:
	movq	%rsp, %rbp
Ltmp1:
	subq	$128, %rsp
Ltmp2:
	movl	%edi, %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	movl	%eax, -12(%rbp)
	movq	%rsi, -24(%rbp)
	movb	$98, -33(%rbp)
	leaq	-33(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	xorb	%cl, %cl
	leaq	L_.str(%rip), %rdx
	movq	%rdx, %rdi
	movq	%rax, %rsi
	movb	%cl, %al
	callq	_printf
	movq	-56(%rbp), %rcx
	xorb	%dl, %dl
	leaq	L_.str1(%rip), %rdi
	movl	%ecx, %esi
	movb	%dl, %al
	callq	_printf
	leaq	-113(%rbp), %rax
	movq	%rax, %rcx
	movabsq	$8535856707940741231, %rdx
	movq	%rdx, 40(%rcx)
	movabsq	$7957135325236127847, %rdx
	movq	%rdx, 32(%rcx)
	movabsq	$7378413942531512921, %rdx
	movq	%rdx, 24(%rcx)
	movabsq	$6365651522798441041, %rdx
	movq	%rdx, 16(%rcx)
	movabsq	$5786930140093827657, %rdx
	movq	%rdx, 8(%rcx)
	movabsq	$5208208757389214273, %rdx
	movq	%rdx, (%rcx)
	movb	$0, 52(%rcx)
	movl	$2054781047, 48(%rcx)
	movq	%rax, %rdi
	callq	_puts
	movl	$0, -60(%rbp)
	jmp	LBB1_2
LBB1_1:
	movl	-60(%rbp), %eax
	movslq	%eax, %rax
	leaq	-113(%rbp), %rcx
	addq	%rax, %rcx
	movq	%rcx, -48(%rbp)
	movl	-60(%rbp), %eax
	movslq	%eax, %rax
	movb	-113(%rbp,%rax), %al
	movsbl	%al, %eax
	xorb	%cl, %cl
	leaq	L_.str3(%rip), %rdx
	movq	%rdx, %rdi
	movl	%eax, %esi
	movb	%cl, %al
	callq	_printf
	movl	-60(%rbp), %ecx
	movslq	%ecx, %rcx
	movb	-113(%rbp,%rcx), %cl
	movsbl	%cl, %ecx
	xorb	%dl, %dl
	leaq	L_.str4(%rip), %rdi
	movl	%ecx, %esi
	movb	%dl, %al
	callq	_printf
	movl	-60(%rbp), %ecx
	movq	-48(%rbp), %rdx
	xorb	%dil, %dil
	leaq	L_.str5(%rip), %r8
	movb	%dil, -114(%rbp)
	movq	%r8, %rdi
	movl	%ecx, %esi
	movb	-114(%rbp), %cl
	movb	%cl, %al
	callq	_printf
	movl	-60(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -60(%rbp)
LBB1_2:
	movl	-60(%rbp), %eax
	cmpl	$52, %eax
	jle	LBB1_1
	movl	$0, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -120(%rbp)
	jne	LBB1_6
	movl	-120(%rbp), %eax
	addq	$128, %rsp
	popq	%rbp
	ret
LBB1_6:
	callq	___stack_chk_fail
Leh_func_end1:

	.section	__TEXT,__cstring,cstring_literals
	.align	3
L_.str:
	.asciz	 "Address in Hexadecimal is: %p \n"

L_.str1:
	.asciz	 "Address in Decimal is: %d \n"

	.align	3
L_.str2:
	.asciz	 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

L_.str3:
	.asciz	 "Array Letter: %c    | "

L_.str4:
	.asciz	 "Decimal: %d |  "

	.align	3
L_.str5:
	.asciz	 "Address in Hexadecimal for position %d is: %p\n"

	.section	__TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame0:
Lsection_eh_frame:
Leh_frame_common:
Lset0 = Leh_frame_common_end-Leh_frame_common_begin
	.long	Lset0
Leh_frame_common_begin:
	.long	0
	.byte	1
	.asciz	 "zR"
	.byte	1
	.byte	120
	.byte	16
	.byte	1
	.byte	16
	.byte	12
	.byte	7
	.byte	8
	.byte	144
	.byte	1
	.align	3
Leh_frame_common_end:
	.globl	_main.eh
_main.eh:
Lset1 = Leh_frame_end1-Leh_frame_begin1
	.long	Lset1
Leh_frame_begin1:
Lset2 = Leh_frame_begin1-Leh_frame_common
	.long	Lset2
Ltmp3:
	.quad	Leh_func_begin1-Ltmp3
Lset3 = Leh_func_end1-Leh_func_begin1
	.quad	Lset3
	.byte	0
	.byte	4
Lset4 = Ltmp0-Leh_func_begin1
	.long	Lset4
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset5 = Ltmp1-Ltmp0
	.long	Lset5
	.byte	13
	.byte	6
	.align	3
Leh_frame_end1:


.subsections_via_symbols
