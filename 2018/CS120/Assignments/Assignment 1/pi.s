	.file	"pi.c"
	.text
	.globl	circle_pi
	.def	circle_pi;	.scl	2;	.type	32;	.endef
circle_pi:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
	movl	%ecx, 16(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	cvtsi2sd	16(%rbp), %xmm0
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	movl	$1, -4(%rbp)
	jmp	.L2
.L3:
	movsd	-24(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	addsd	%xmm0, %xmm1
	movl	-4(%rbp), %eax
	subl	$1, %eax
	cvtsi2sd	%eax, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	-24(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	-32(%rbp), %xmm0
	mulsd	-32(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	subsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	call	sqrt
	movq	%xmm0, %rax
	movq	%rax, -40(%rbp)
	movsd	-24(%rbp), %xmm0
	addsd	%xmm0, %xmm0
	mulsd	-40(%rbp), %xmm0
	movsd	-16(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	16(%rbp), %eax
	jle	.L3
	movsd	-16(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leave
	ret
	.globl	leibniz_pi
	.def	leibniz_pi;	.scl	2;	.type	32;	.endef
leibniz_pi:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	%ecx, 16(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	16(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L6
	movl	$-1, %eax
	jmp	.L7
.L6:
	movl	$1, %eax
.L7:
	movl	%eax, -12(%rbp)
	jmp	.L8
.L9:
	movl	16(%rbp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	movl	%eax, -16(%rbp)
	cvtsi2sd	-12(%rbp), %xmm1
	cvtsi2sd	-16(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm2
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	negl	-12(%rbp)
	subl	$1, 16(%rbp)
.L8:
	cmpl	$0, 16(%rbp)
	jne	.L9
	movsd	-8(%rbp), %xmm1
	movsd	.LC2(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leave
	ret
	.section .rdata,"dr"
	.align 8
.LC1:
	.long	0
	.long	1073741824
	.align 8
.LC2:
	.long	0
	.long	1074790400
	.align 8
.LC3:
	.long	0
	.long	1072693248
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 7.1.0"
	.def	sqrt;	.scl	2;	.type	32;	.endef
