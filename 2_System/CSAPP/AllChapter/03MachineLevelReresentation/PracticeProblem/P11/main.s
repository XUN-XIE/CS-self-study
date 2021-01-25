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
	leaq	L_str(%rip), %rdi
	callq	_puts
	leaq	L_str.5(%rip), %rdi
	callq	_puts
	leaq	L_.str.4(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"makes the register value in %%rcx to be 0\n"

L_.str.1:                               ## @.str.1
	.asciz	"movq $0, %%rcx\n"

L_.str.4:                               ## @.str.4
	.asciz	"Other ways to set %%rcx to zero rely on the property that any instruction that updates the lower 4 bytes will cause the high-order bytes to be set to zero. Thus, we could use either xorl %%ecx,%%ecx (2 bytes) or movl $0,%%ecx (5 bytes).\n"

L_str:                                  ## @str
	.asciz	"\n\n\n \344\270\215\347\237\245\351\201\223\350\277\231\344\270\252\346\214\207\344\273\244\347\232\204\345\255\227\350\212\202\346\230\257\346\200\216\344\271\210\350\256\241\347\256\227\347\232\204"

L_str.5:                                ## @str.5
	.asciz	"From book answer: the version with xorq requires only 3 bytes, while the version with movq requires 7."

.subsections_via_symbols
