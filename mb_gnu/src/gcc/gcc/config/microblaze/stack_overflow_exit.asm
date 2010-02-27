###################################-*-asm*- 
# 
# Copyright (c) 2001 Xilinx, Inc.  All rights reserved. 
# 
# Xilinx, Inc. CONFIDENTIAL 
# 
# stack_overflow_exit.asm
# 
# Checks for stack overflows and sets the global variable 
# stack_overflow_error with the value of current stack pointer
#
# This routine exits from the program
# 
# $Header: /devl/xcs/repo/env/Jobs/MDT/sw/ThirdParty/gnu/src/gcc/src-3.4/gcc/config/microblaze/stack_overflow_exit.s,v 1.1.2.6 2005/11/15 23:32:47 salindac Exp $
# 
#######################################

	.globl	_stack_overflow_error
	.data
	.align	2
	.type	_stack_overflow_error,@object
	.size	_stack_overflow_error,4
_stack_overflow_error:
	.data32	0

	.text 
	.globl	_stack_overflow_exit	
	.ent	_stack_overflow_exit
	.type	_stack_overflow_exit,@function

_stack_overflow_exit:
#ifdef __PIC__
	mfs	r20,rpc
	addik	r20,r20,_GLOBAL_OFFSET_TABLE_+8
	swi	r1,r20,_stack_overflow_error@GOTOFF
	bri	exit@PLT
#else
	swi	r1,r0,_stack_overflow_error
	bri	exit
#endif

	.end 	_stack_overflow_exit
	.size	_stack_overflow_exit,. - _stack_overflow_exit
