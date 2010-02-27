/* 
 * setjmp  - save stack context for non-local goto
 * args    - r5 - jmp_buf
 *    
 * jmpbuf frame structure
 * ---------------------
 *
 *      +-------------+         + 0
 *      |     r1      |
 *      +-------------+         + 4    
 *      |     r13     |
 *      |      .      |
 *      |      .      |
 *      |      .      |
 *      |     r31     |         
 *      +-------------+         + 80
 *      |      .      |
 *      |      .      |        
 */        

    
.globl setjmp
.section .text
.align 2  
.ent setjmp    
setjmp:
    swi     r1, r5, 0
    swi     r13, r5, 4
    swi     r14, r5, 8
    swi     r15, r5, 12       
    swi     r16, r5, 16
    swi     r17, r5, 20
    swi     r18, r5, 24       
    swi     r19, r5, 28
    swi     r20, r5, 32
    swi     r21, r5, 36
    swi     r22, r5, 40
    swi     r23, r5, 44
    swi     r24, r5, 48
    swi     r25, r5, 52
    swi     r26, r5, 56
    swi     r27, r5, 60                        
    swi     r28, r5, 64                        
    swi     r29, r5, 68                        
    swi     r30, r5, 72
    swi     r31, r5, 76                                            

    rtsd    r15, 8
    or      r3, r0, r0
.end setjmp    
