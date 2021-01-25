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
	leaq	L_str(%rip), %rdi
	callq	_puts
	leaq	L_.str.1(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_str.10(%rip), %rdi
	callq	_puts
	leaq	L_str.11(%rip), %rdi
	callq	_puts
	leaq	L_.str.4(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.5(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.6(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.8(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.9(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	"%%rax        0x100=256\n"

L_.str.4:                               ## @.str.4
	.asciz	"(%%rax)      0xFF\n"

L_.str.5:                               ## @.str.5
	.asciz	"4(%%rax)     M[4+0x100]  M[0x104]    = 0xAB\n"

L_.str.6:                               ## @.str.6
	.asciz	"9(%%rax, %%rdx)   M[9 + 0x100 + 0x3]  M[0x10C]    =0x11\n"

L_.str.7:                               ## @.str.7
	.asciz	"260(%%rcx, %%rdx) M[260 + 0x1 + 0x3]  M[264] M[0x0x108]=0x13\n"

L_.str.8:                               ## @.str.8
	.asciz	"0xFC(, %%rcx, 4)     M[0xFC + 0x1 * 4]   M[0x100]    =0xFF\n"

L_.str.9:                               ## @.str.9
	.asciz	"(%%rax, %%rdx, 4)     M[0x100 + 0x3 * 4]  M[0x10C]    =0x11\n"

L_str:                                  ## @str
	.asciz	"Operand     Value"

L_str.10:                               ## @str.10
	.asciz	"0x104       0xAB"

L_str.11:                               ## @str.11
	.asciz	"$0x108      0x108"

.subsections_via_symbols
