###################################-*-asm*- 
# 
# Copyright (c) 2001 Xilinx, Inc.  All rights reserved. 
# 
# Xilinx, Inc. CONFIDENTIAL 
# 
# _exception_handler.s 
#
#	Exception handler rountine. 
#	MicroBlaze set the register r17 on an exception.
#
#	This is the dummy routine provided by Xilinx
#	Users can change the routine as per their requirement
# 
# $Header: /devl/xcs/repo/env/Jobs/MDT/sw/libxil/src/_exception_handler.s,v 1.1.18.6 2005/11/15 23:41:01 salindac Exp $
# 
#######################################

	.text
	.globl _exception_handler    # Exception Handler Label 
	.align 2
	
	_exception_handler:
	rtsd    r17, 0
	nop
