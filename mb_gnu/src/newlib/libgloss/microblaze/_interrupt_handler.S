/*
 * 
 * Copyright (c) 2010 Xilinx, Inc.  All rights reserved. 
 * 
 * Xilinx, Inc. CONFIDENTIAL 
 * 
 * _interrupt_handler.S
 * Stub interrupt handler
 * 
 */

.text
.globl _interrupt_handler
.align 2

_interrupt_handler:
    rtid    r14, 0
    nop
