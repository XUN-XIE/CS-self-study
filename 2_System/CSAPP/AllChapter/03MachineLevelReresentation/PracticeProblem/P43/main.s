	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_get                    ## -- Begin function get
	.p2align	4, 0x90
_get:                                   ## @get
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	(%rdi), %rax
	movq	%rax, (%rsi)
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
	.asciz	"up->t1.u    long    movq (%%rdi), %%rax      movq %%rax, (%%rsi)\n"

L_.str.1:                               ## @.str.1
	.asciz	"up->t1.v    short   movw 8(%%rdi), %%ax      movw %%ax, (%%rsi)\n"

L_.str.2:                               ## @.str.2
	.asciz	"&up->ti.w   char*   leap 10(%%rdi), %%rax    leap (%%rax), (%%rsi)\n"

L_.str.3:                               ## @.str.3
	.asciz	"up->t2.a    int*    leap (%%rdi), %%rax    leap (%%rax), (%%rs)    i\n"

L_.str.4:                               ## @.str.4
	.asciz	"up->t2.a[up->t1.u]  int         "

L_.str.5:                               ## @.str.5
	.asciz	"movq (%%rdi), %%rcx      movl (%%rdi, %%rcx, 4), %%rax     movl %%eax, (%%rsi)\n"

L_.str.6:                               ## @.str.6
	.asciz	"*up->t2.p   char    leap 8(%%rdi), %%rax    movb (%%rax), %%al,     movb %%al, (%%rsi)\n"

.subsections_via_symbols
