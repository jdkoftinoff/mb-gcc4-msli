/*
 * Copyright (c) 2010 Xilinx, Inc.  All rights reserved. 
 * 
 * Xilinx, Inc.  
 *
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.  
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * sim-crtinit.S
 *
 * Default second stage of C run-time initialization that does not peform
 * BSS initialization to zero. Typical use is on a simulator.      
 *    
 */

	.globl _crtinit
	.align 2
	.ent _crtinit

_crtinit:
	addi	r1, r1, -20               	/* Save Link register	 */
	swi	r15, r1, 0

    	brlid	r15, _program_init              /* Initialize the program  */
	nop

        brlid   r15, __init                     /* Invoke language initialization functions */
        nop
    
	addi	r6, r0, 0                       /* Initialize argc = 1 and argv = NULL and envp = NULL  */
	addi	r7, r0, 0			
      	brlid	r15, main                       /* Execute the program */
	addi	r5, r0, 0			

        addik   r19, r3, 0                      /* Save return value */
    
        brlid   r15, __fini                     /* Invoke language cleanup functions */
        nop

	brlid	r15, _program_clean             /* Cleanup the program  */
	nop

	lw	r15, r1, r0                     /* Return back to CRT   */
        addik   r3, r19, 0                      /* Restore return value */
	rtsd	r15, 8
    	addi	r1, r1, 20
	.end _crtinit

