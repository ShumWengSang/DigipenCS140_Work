	.file	"driver.c"
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Approximations for pi\0"
	.align 8
.LC1:
	.ascii "Iterations      Circle Method   Leibniz Method\0"
	.align 8
.LC2:
	.ascii "----------------------------------------------\0"
.LC3:
	.ascii "%10i%20.12f%16.12f\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$64, %rsp
	call	__main
	leaq	.LC0(%rip), %rcx
	call	puts
	leaq	.LC1(%rip), %rcx
	call	puts
	leaq	.LC2(%rip), %rcx
	call	puts
	movl	$1, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	circle_pi
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	leibniz_pi
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm3
	movsd	-24(%rbp), %xmm1
	movsd	-16(%rbp), %xmm2
	movsd	-16(%rbp), %xmm0
	movl	-4(%rbp), %eax
	movq	%xmm1, %r9
	movq	%xmm0, %r8
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, -4(%rbp)
.L2:
	cmpl	$1000000, -4(%rbp)
	jle	.L3
	movl	$0, %eax
	leave
	ret
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 7.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	circle_pi;	.scl	2;	.type	32;	.endef
	.def	leibniz_pi;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
