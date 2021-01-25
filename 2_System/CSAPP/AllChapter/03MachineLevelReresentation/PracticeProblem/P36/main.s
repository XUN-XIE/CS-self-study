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
	leaq	L_str.5(%rip), %rdi
	callq	_puts
	leaq	L_str.6(%rip), %rdi
	callq	_puts
	leaq	L_str.7(%rip), %rdi
	callq	_puts
	leaq	L_str.8(%rip), %rdi
	callq	_puts
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_str:                                  ## @str
	.asciz	"P   4   20  xp  xp + 4i"

L_str.5:                                ## @str.5
	.asciz	"Q   2   4   xq  xq + 2i"

L_str.6:                                ## @str.6
	.asciz	"R   8   72  xr  xr + 8i"

L_str.7:                                ## @str.7
	.asciz	"S   8   80  xs  xs + 8i"

L_str.8:                                ## @str.8
	.asciz	"T   8   16  xt  xt + 8i"

.subsections_via_symbols
