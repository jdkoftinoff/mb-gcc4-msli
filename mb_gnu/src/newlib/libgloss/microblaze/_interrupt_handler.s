###################################-*-asm*- 
# 
# Copyright (c) 2001 Xilinx, Inc.  All rights reserved. 
# 
# Xilinx, Inc. CONFIDENTIAL 
# 
# _interrupt_handler.s 
#
#	Interrupt handler rountine.
#	MicroBlaze set the register r14, on an interrupt
#
#	This is the dummy routine provided by Xilinx
#	Users can change the routine as per their requirement
# 
# $Header: /devl/xcs/repo/env/Jobs/MDT/sw/libxil/src/_interrupt_handler.s,v 1.1.18.6 2005/11/15 23:41:01 salindac Exp $
# 
#######################################

	.text
	.globl _interrupt_handler    # Interrupt Handler Label 
	.align 2

	_interrupt_handler:
	rtid    r14, 0
	nop
