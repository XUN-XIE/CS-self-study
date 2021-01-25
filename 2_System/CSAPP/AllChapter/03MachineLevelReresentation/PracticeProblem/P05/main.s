	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_decode1                ## -- Begin function decode1
	.p2align	4, 0x90
_decode1:                               ## @decode1
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	(%rdi), %rax
	movq	(%rsi), %rcx
	movq	(%rdx), %r8
	movq	%rax, (%rsi)
	movq	%rcx, (%rdx)
	movq	%r8, (%rdi)
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
	leaq	L_str(%rip), %rdi
	callq	_puts
	leaq	L_.str.1(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	"movq    (%%rdi), %%rax\nmovq    (%%rsi), %%rcx\nmovq    (%%rdx), %%r8\nmovq    %%rax, (%%rsi)\nmovq    %%rcx, (%%rdx)\nmovq    %%r8, (%%rdi)\nretq\n"

L_str:                                  ## @str
	.asciz	"the assemble code is shown as below:"

.subsections_via_symbols
