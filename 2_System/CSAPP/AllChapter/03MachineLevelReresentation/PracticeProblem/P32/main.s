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
	leaq	L_.str.2(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_str.9(%rip), %rdi
	callq	_puts
	leaq	L_.str.4(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.5(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_str.10(%rip), %rdi
	callq	_puts
	leaq	L_str.11(%rip), %rdi
	callq	_puts
	leaq	L_.str.8(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	"F1  0x400548    lea     10  --- ---                 0x400565     leap for %%rsi\n"

L_.str.2:                               ## @.str.2
	.asciz	"F2  0x40054c    sub     10  11  ---                 0x400565    sub 1 to %%rdi\n"

L_.str.4:                               ## @.str.4
	.asciz	"L1  0x400540    mov     9   11  ---                 0x400555    mov %%rdi to %%rax\n"

L_.str.5:                               ## @.str.5
	.asciz	"L2  0x400543    imul    9   11  9                   0x400555    imul %%rsi to %%rax\n"

L_.str.8:                               ## @.str.8
	.asciz	"M2  0x400565    mov     --- --- 99                  ---    move %%rax to %%rdx\n"

L_str:                                  ## @str
	.asciz	"M1  0x400560    callq   10  --- --- 0x7ffffffffe820 --- Call first(10)"

L_str.9:                                ## @str.9
	.asciz	"F3  0x400550    callq   9   11  ---                 0x400565    Call last(9, 11)"

L_str.10:                               ## @str.10
	.asciz	"L3  0x400547    retq    9   11  99                  0x400555    return from last"

L_str.11:                               ## @str.11
	.asciz	"F4  0x400555    retq    9   11  99                  0x400565    return from first"

.subsections_via_symbols
