/*
 * 
 * Copyright (c) 2010 Xilinx, Inc.  All rights reserved. 
 * 
 * Xilinx, Inc. CONFIDENTIAL 
 * 
 * Stub exception handler rountine. 
 * 
 */

.text
.globl _exception_handler    
.align 2
_exception_handler:
	rtsd    r17, 0
	nop
