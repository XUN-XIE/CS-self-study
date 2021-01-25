	.text
	.globl _test_two
_test_two:
LFB1:
	movl	$64, %edx
	movl	$0, %eax
L2:
	addl	%eax, %eax
	movl	%edi, %ecx
	andl	$1, %ecx
	orl	%ecx, %eax
	shrw	%di
	subw	$1, %dx
	jne	L2
	ret
LFE1:
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
	.ident	"GCC: (Homebrew GCC 9.2.0_3) 9.2.0"
	.subsections_via_symbols
