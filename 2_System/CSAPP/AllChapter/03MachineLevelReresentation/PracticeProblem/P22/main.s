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
	movl	$1278945280, %esi       ## imm = 0x4C3B2800
	movl	$15, %edx
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	movl	$2147483647, %esi       ## imm = 0x7FFFFFFF
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"result = %d,    count = %d\n"

L_.str.1:                               ## @.str.1
	.asciz	"INT_MAX= %d\n"

.subsections_via_symbols
