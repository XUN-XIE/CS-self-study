	.text
	.p2align 4
	.globl _test
_test:
LFB1:
	testw	%di, %di
	movl	%edi, %eax
	js	L7
	cmpw	$9, %si
	jle	L8
	cwtl
	movswl	%si, %ecx
	cltd
	idivl	%ecx
	ret
	.p2align 4,,10
	.p2align 3
L8:
	leal	12(%rsi), %eax
	ret
	.p2align 4,,10
	.p2align 3
L7:
	movswl	%di, %edx
	movswl	%si, %ecx
	cmpl	%ecx, %edx
	js	L3
	orl	%esi, %eax
	ret
	.p2align 4,,10
	.p2align 3
L3:
	imull	%esi, %eax
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
