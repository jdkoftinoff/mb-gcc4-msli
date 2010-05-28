/*
 *
 *  _program_init.S
 * 
 *  Stub program init hook.
 */
	
.text
.align	2
.globl	_program_init
.ent	_program_init
_program_init:
    rtsd	r15,8 
    nop
.end	_program_init
