	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_cond                   ## -- Begin function cond
	.p2align	4, 0x90
_cond:                                  ## @cond
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	testw	%di, %di
	je	LBB0_3
## %bb.1:
	cmpw	%di, (%rsi)
	jge	LBB0_3
## %bb.2:
	movw	%di, (%rsi)
LBB0_3:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
