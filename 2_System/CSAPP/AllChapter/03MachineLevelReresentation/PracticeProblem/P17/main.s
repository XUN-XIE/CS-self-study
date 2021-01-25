	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_absdiff_se             ## -- Begin function absdiff_se
	.p2align	4, 0x90
_absdiff_se:                            ## @absdiff_se
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, %rax
	subq	%rsi, %rax
	jge	LBB0_1
## %bb.2:
	incq	_lt_cnt(%rip)
	subq	%rdi, %rsi
	movq	%rsi, %rax
	popq	%rbp
	retq
LBB0_1:
	incq	_ge_cnt(%rip)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_lt_cnt                 ## @lt_cnt
.zerofill __DATA,__common,_lt_cnt,8,3
	.globl	_ge_cnt                 ## @ge_cnt
.zerofill __DATA,__common,_ge_cnt,8,3
.subsections_via_symbols
