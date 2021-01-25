	.text
	.globl _test_one
_test_one:
LFB1:
L2:
	testw	%di, %di
	je	L4
	shrw	%di
	jmp	L2
L4:
	movl	$0, %eax
	ret
LFE1:
	.cstring
lC0:
	.ascii "Problem A: jump to middle\0"
	.section __TEXT,__text_startup,regular,pure_instructions
	.globl _main
_main:
LFB2:
	subq	$8, %rsp
LCFI0:
	leaq	lC0(%rip), %rdi
	call	_puts
	movl	$0, %eax
	addq	$8, %rsp
LCFI1:
	ret
LFE2:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB1-.
	.set L$set$2,LFE1-LFB1
	.quad L$set$2
	.byte	0
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$3,LEFDE3-LASFDE3
	.long L$set$3
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB2-.
	.set L$set$4,LFE2-LFB2
	.quad L$set$4
	.byte	0
	.byte	0x4
	.set L$set$5,LCFI0-LFB2
	.long L$set$5
	.byte	0xe
	.byte	0x10
	.byte	0x4
	.set L$set$6,LCFI1-LCFI0
	.long L$set$6
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE3:
	.ident	"GCC: (Homebrew GCC 9.2.0_3) 9.2.0"
	.subsections_via_symbols
