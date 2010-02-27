###################################-*-asm*- 
# 
# Copyright (c) 2001 Xilinx, Inc.  All rights reserved. 
# 
# Xilinx, Inc. CONFIDENTIAL 
# 
# _hw_exception_handler.s 
#
#	Exception handler rountine for Microblaze Hardware Exceptions. 
#	This is the dummy routine provided by Xilinx.
#	The corresponding standalone BSP, if present, will over-ride this.
# 
# $Header: /devl/xcs/repo/env/Jobs/MDT/sw/libxil/src/_hw_exception_handler.s,v 1.1.8.6 2005/11/15 23:41:01 salindac Exp $
# 
#######################################

	.text
	.globl _hw_exception_handler    # HW Exception Handler Label 
	.align 2
	
	_hw_exception_handler:
	rted    r17, 0
	nop
