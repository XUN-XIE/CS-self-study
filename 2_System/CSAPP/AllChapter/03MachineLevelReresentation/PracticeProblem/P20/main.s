	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_arith                  ## -- Begin function arith
	.p2align	4, 0x90
_arith:                                 ## @arith
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
                                        ## kill: def $edi killed $edi def $rdi
	leal	15(%rdi), %ecx
	testw	%di, %di
	cmovgl	%edi, %ecx
	leal	15(%rcx), %eax
	testl	%ecx, %ecx
	cmovnsl	%ecx, %eax
	sarl	$4, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
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
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_str:                                  ## @str
	.asciz	"\345\233\236\345\277\206\347\254\254\344\272\214\347\253\240\347\232\204 \351\231\244\346\263\225\357\274\214 \345\246\202\346\236\234\346\230\257\350\264\237\346\225\260\351\234\200\350\246\201\345\212\240 bias\357\274\214 \346\255\243\346\225\260\345\210\231\344\270\215\351\234\200\350\246\201\357\274\214\346\211\200\344\273\245\345\255\230\345\234\250\344\272\206 comvns \347\224\250\346\235\245\345\210\244\346\226\255\346\255\243\350\264\237\357\274\214\345\206\263\345\256\232\346\230\257\345\220\246\345\212\240 bias"

.subsections_via_symbols
