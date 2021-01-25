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
	leaq	L_.str.6(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"movb $0xF, (%%ebx). %%ebx is 32 bits, so it cannot be used to be as address register! we must use 64 bits address register to reference memory\n\n"

L_.str.1:                               ## @.str.1
	.asciz	"movl %%rax, (%%rsp). the bits is too small, just 32bits which cannot move the 64bits to 64bits\n\n"

L_.str.2:                               ## @.str.2
	.asciz	"movw (%%rax),4(%%rsp).    it cannot move from memory to memory!\n\n"

L_.str.3:                               ## @.str.3
	.asciz	"movb %%al,%%sl.   there is not a register named %%sl"

L_.str.4:                               ## @.str.4
	.asciz	"movq %%rax,$0x123.       it cannot move from register to immediate value\n\n"

L_.str.5:                               ## @.str.5
	.asciz	"movl %%eax, %%rdx. %%eax is 32bits, whereas %%rdx is 64 bits. we cannot use mov class to move between different size. there are movs, movz to do this\n\n"

L_.str.6:                               ## @.str.6
	.asciz	"movb %%si, 8(%%rbp). the bits is too small, just 8bits which cannot move the 16bits to 64bits\n\n"

.subsections_via_symbols
