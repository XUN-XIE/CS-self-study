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
	leaq	L_str.6(%rip), %rdi
	callq	_puts
	leaq	L_str.7(%rip), %rdi
	callq	_puts
	leaq	L_str.8(%rip), %rdi
	callq	_puts
	leaq	L_str.9(%rip), %rdi
	callq	_puts
	leaq	L_str.10(%rip), %rdi
	callq	_puts
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_str:                                  ## @str
	.asciz	"offest for every type       total size      alignment"

L_str.6:                                ## @str.6
	.asciz	"ProblemA : i + c = 5   total=24"

L_str.7:                                ## @str.7
	.asciz	"ProblemB : i = c = s = j = 8    total = 32"

L_str.8:                                ## @str.8
	.asciz	"ProblemC : w = c = 16   total=32 "

L_str.9:                                ## @str.9
	.asciz	"ProblemD : w = c = 16   total=32 "

L_str.10:                               ## @str.10
	.asciz	"ProblemE : a = 32*2, t = 24     total = 96"

.subsections_via_symbols
