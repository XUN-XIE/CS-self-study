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
	leaq	L_str.7(%rip), %rdi
	callq	_puts
	leaq	L_str.8(%rip), %rdi
	callq	_puts
	leaq	L_str.9(%rip), %rdi
	callq	_puts
	leaq	L_str.10(%rip), %rdi
	callq	_puts
	leaq	L_str.11(%rip), %rdi
	callq	_puts
	leaq	L_str.12(%rip), %rdi
	callq	_puts
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_str:                                  ## @str
	.asciz	"Problem A:"

L_str.7:                                ## @str.7
	.asciz	"p: 0    s.x: 8  s.y:10  next: 12"

L_str.8:                                ## @str.8
	.asciz	"\nProblem B: 8 + 4 + 8 = 20"

L_str.9:                                ## @str.9
	.asciz	"\nProblem C:"

L_str.10:                               ## @str.10
	.asciz	"st->s.y = st->s.x;"

L_str.11:                               ## @str.11
	.asciz	"st->p   = &(st->s.y)"

L_str.12:                               ## @str.12
	.asciz	"st->next = st"

.subsections_via_symbols
