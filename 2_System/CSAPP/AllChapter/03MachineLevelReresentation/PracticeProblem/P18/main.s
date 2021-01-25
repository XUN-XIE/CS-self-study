	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_test                   ## -- Begin function test
	.p2align	4, 0x90
_test:                                  ## @test
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edx, %ecx
                                        ## kill: def $esi killed $esi def $rsi
	cmpw	$6, %cx
	jl	LBB0_3
## %bb.1:
	movl	%edi, %eax
	cmpw	$3, %si
	jl	LBB0_6
## %bb.2:
	cltd
	idivl	%ecx
	jmp	LBB0_7
LBB0_3:
	cmpw	$2, %cx
	jg	LBB0_4
## %bb.5:
	movl	%ecx, %eax
LBB0_6:
	cltd
	idivl	%esi
	jmp	LBB0_7
LBB0_4:
	subl	%edi, %esi
	leal	(%rcx,%rsi), %eax
LBB0_7:
	cwtl
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
