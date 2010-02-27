/* 
 * longjmp - non-local jump to a saved stack context
 * args    - r5 - jmp_buf
 *           r6 - val
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

    
.globl longjmp
.section .text
.align 2  
.ent longjmp    
longjmp:
    lwi     r1, r5, 0
    lwi     r13, r5, 4
    lwi     r14, r5, 8
    lwi     r15, r5, 12       
    lwi     r16, r5, 16
    lwi     r17, r5, 20
    lwi     r18, r5, 24       
    lwi     r19, r5, 28
    lwi     r20, r5, 32
    lwi     r21, r5, 36
    lwi     r22, r5, 40
    lwi     r23, r5, 44
    lwi     r24, r5, 48
    lwi     r25, r5, 52
    lwi     r26, r5, 56
    lwi     r27, r5, 60                        
    lwi     r28, r5, 64                        
    lwi     r29, r5, 68                        
    lwi     r30, r5, 72
    lwi     r31, r5, 76                                            

    rtsd    r15, 8
    or      r3, r0, r6
.end longjmp    
