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
	leaq	L_str.4(%rip), %rdi
	callq	_puts
	leaq	L_str.5(%rip), %rdi
	callq	_puts
	leaq	L_str.6(%rip), %rdi
	callq	_puts
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_str:                                  ## @str
	.asciz	"Problem A, data_t = int     COMP = <"

L_str.4:                                ## @str.4
	.asciz	"Problem B, data_t = short   COMP = >="

L_str.5:                                ## @str.5
	.asciz	"Problem C, data_t = unsigned char    COMP = <="

L_str.6:                                ## @str.6
	.asciz	"Problem D, data_t = long or unsigned long(because setne don't distinguish signed or unsigned')    COMP = !="

.subsections_via_symbols
