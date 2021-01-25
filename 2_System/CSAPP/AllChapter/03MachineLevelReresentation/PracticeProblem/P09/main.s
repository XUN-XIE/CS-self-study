	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_shift_left4_rightn     ## -- Begin function shift_left4_rightn
	.p2align	4, 0x90
_shift_left4_rightn:                    ## @shift_left4_rightn
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rsi, %rcx
	movq	%rdi, %rax
	shlq	$4, %rax
                                        ## kill: def $cl killed $cl killed $rcx
	sarq	%cl, %rax
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
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"movq    %%rdi, %%rax    Get x\n"

L_.str.1:                               ## @.str.1
	.asciz	"salq    $ 4, %%rax        x<<=4\n"

L_.str.2:                               ## @.str.2
	.asciz	"movl    %%esi, %%ecx      Get n (4 bytes)\n"

L_.str.3:                               ## @.str.3
	.asciz	"sarq    %%cl, %%rax      x >>= n\n"

.subsections_via_symbols
