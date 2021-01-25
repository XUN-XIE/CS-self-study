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
	.asciz	"movl    %%eax     (%%rsp)\n"

L_.str.1:                               ## @.str.1
	.asciz	"movw    (%%rax)   %%dx\n"

L_.str.2:                               ## @.str.2
	.asciz	"movb    $0xFF    %%bl\n"

L_.str.3:                               ## @.str.3
	.asciz	"movb    (%%rsp, %%rdx, 4)  %%dl\n"

L_.str.4:                               ## @.str.4
	.asciz	"movq    (%%rdx)   %%rax\n"

L_.str.5:                               ## @.str.5
	.asciz	"movw    %%dx      (%%rax)\n"

.subsections_via_symbols
