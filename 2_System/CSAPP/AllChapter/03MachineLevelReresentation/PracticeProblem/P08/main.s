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
L_.str.1:                               ## @.str.1
	.asciz	"addq %%rcx,(%%rax)    0x100       0x100\n"

L_.str.2:                               ## @.str.2
	.asciz	"subq %%rdx,8(%%rax)   0x108       0xA8\n"

L_.str.3:                               ## @.str.3
	.asciz	"imulq $16,(%%rax,%%rdx,8)     0x118   0x110\n"

L_.str.4:                               ## @.str.4
	.asciz	"incq 16(%%rax)       0x110       0x14\n"

L_.str.5:                               ## @.str.5
	.asciz	"decq %%rcx           %%rcx        0x0\n"

L_.str.6:                               ## @.str.6
	.asciz	"subq %%rdx,%%rax      %%rax        0xFD\n"

L_str:                                  ## @str
	.asciz	"Instruction         Destination Value"

.subsections_via_symbols
