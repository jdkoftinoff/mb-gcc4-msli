/* crti.s for __init, __fini
   This file supplies the prologue for __init and __fini routines */

    .section .init, "ax"
    .global __init
    .align 2
__init: 
    addik   r1, r1, -8
    sw      r15, r0, r1
    la   r11, r0, _stack-16
    mts     rshr, r11
    la   r11, r0, _stack_end+4
    mts     rslr, r11

    .section .fini, "ax"
    .global __fini
    .align 2
__fini: 
    addik   r1, r1, -8
    sw      r15, r0, r1
