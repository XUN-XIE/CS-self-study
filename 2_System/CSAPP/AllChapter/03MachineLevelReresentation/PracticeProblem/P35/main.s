	.text
	.globl _rfun
_rfun:
LFB1:
	movl	$0, %eax
	testq	%rdi, %rdi
	jne	L8
	ret
L8:
	pushq	%rbx
LCFI0:
	movq	%rdi, %rbx
	shrq	$2, %rdi
	call	_rfun
	addq	%rbx, %rax
	popq	%rbx
LCFI1:
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
	.byte	0x4
	.set L$set$3,LCFI0-LFB1
	.long L$set$3
	.byte	0xe
	.byte	0x10
	.byte	0x83
	.byte	0x2
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE1:
	.ident	"GCC: (Homebrew GCC 9.2.0_3) 9.2.0"
	.subsections_via_symbols
