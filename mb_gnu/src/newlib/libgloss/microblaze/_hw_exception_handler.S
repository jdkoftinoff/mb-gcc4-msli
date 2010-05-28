/*
 * 
 * Copyright (c) 2010 Xilinx, Inc.  All rights reserved. 
 * 
 * Xilinx, Inc. CONFIDENTIAL 
 * 
 * _hw_exception_handler.S
 * Stub hardware exception handler
 * 
 */

.text
.globl _hw_exception_handler    
.align 2
_hw_exception_handler:
    rted    r17, 0
    nop
