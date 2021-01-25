	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_fibonacciWhile         ## -- Begin function fibonacciWhile
	.p2align	4, 0x90
_fibonacciWhile:                        ## @fibonacciWhile
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	.cfi_offset %rbx, -48
	.cfi_offset %r12, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	cmpl	$2, %edi
	jl	LBB0_3
## %bb.1:
	movl	%edi, %r15d
	movl	$1, %eax
	leaq	L_.str(%rip), %r14
	movl	$1, %r12d
	.p2align	4, 0x90
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	movl	%eax, %ebx
	addl	%r12d, %ebx
	movq	%r14, %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	_printf
	movl	%r12d, %eax
	movl	%ebx, %r12d
	cmpl	%r15d, %ebx
	jl	LBB0_2
LBB0_3:
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_fibonacciGuardedDo     ## -- Begin function fibonacciGuardedDo
	.p2align	4, 0x90
_fibonacciGuardedDo:                    ## @fibonacciGuardedDo
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	.cfi_offset %rbx, -48
	.cfi_offset %r12, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	cmpl	$2, %edi
	jl	LBB1_3
## %bb.1:
	movl	%edi, %r15d
	movl	$1, %eax
	leaq	L_.str(%rip), %r14
	movl	$1, %ebx
	.p2align	4, 0x90
LBB1_2:                                 ## =>This Inner Loop Header: Depth=1
	movl	%eax, %r12d
	addl	%eax, %ebx
	movq	%r14, %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	_printf
	movl	%ebx, %eax
	cmpl	%r15d, %ebx
	movl	%r12d, %ebx
	jl	LBB1_2
LBB1_3:
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$10, %edi
	callq	_fibonacciGuardedDo
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"

.subsections_via_symbols
