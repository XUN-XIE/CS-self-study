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
	leaq	L_str(%rip), %rdi
	callq	_puts
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
	.asciz	"char --> int     1btye --> 4bytes   movsbl (%%rdi), %%eax     movl %%eax, (%%rsi)\n"

L_.str.2:                               ## @.str.2
	.asciz	"unsigned char --> long  movzbq   (%%rdi), %%rax     movq     %%rax, (%%rsi)\n"

L_.str.3:                               ## @.str.3
	.asciz	"int --> char    movl (%%rdi), %%eax     movb (%%al), (%%rsi)\n"

L_.str.4:                               ## @.str.4
	.asciz	"unsigned --> unsigned char      movl (%%rdi), %%eax     movb %%al,    (%%rsi)\n"

L_.str.5:                               ## @.str.5
	.asciz	"char --> short  movsbw   (%%rdi), %%ax  movw     %%ax, (%%rsi)\n"

L_str:                                  ## @str
	.asciz	"same as above, because the source type is same, so we don't need to change movsbl to movzbl"

.subsections_via_symbols
