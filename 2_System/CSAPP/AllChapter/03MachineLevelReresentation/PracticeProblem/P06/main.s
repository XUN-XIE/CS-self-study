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
	leaq	L_.str.5(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"leaq 9(%%rdx), %%rax            q+9\n"

L_.str.1:                               ## @.str.1
	.asciz	"leaq (%%rdx,%%rbx), %%rax       q+p\n"

L_.str.2:                               ## @.str.2
	.asciz	"leaq (%%rdx,%%rbx,3), %%rax     q+3*p\n"

L_.str.3:                               ## @.str.3
	.asciz	"leaq 2(%%rbx,%%rbx,7), %%rax    8*p+2\n"

L_.str.4:                               ## @.str.4
	.asciz	"leaq 0xE(,%%rdx,3), %%rax       3*q+14\n"

L_.str.5:                               ## @.str.5
	.asciz	"leaq 6(%%rbx,%%rdx,7), %%rax    p+7*q+6\n"

.subsections_via_symbols
