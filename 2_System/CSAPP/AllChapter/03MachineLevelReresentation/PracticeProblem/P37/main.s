	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
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
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.2(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.4(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"P[1]    short   M[xp + 2]   movw 2(%%rdx), %%ax\n"

L_.str.1:                               ## @.str.1
	.asciz	"P+3+i   short*  xp+6+2i     leap 6(%%rdx, %%rcx, 2), %%rax\n"

L_.str.2:                               ## @.str.2
	.asciz	"P[6i-5] short   M[xp+12i-10]    movw -10(%%rdx, %%rcx, 12), %%ax\n"

L_.str.3:                               ## @.str.3
	.asciz	"P[2]    short   M[xp+4]     movw 4(%%rdx), %%ax\n"

L_.str.4:                               ## @.str.4
	.asciz	"&P[i+2] short*  xp+4i+4     leap 4(%%rdx, %%rcx, 2), %%rax\n"

.subsections_via_symbols
