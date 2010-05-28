/*
 *  _program_clean.S
 *
 *  Stub program clean hook.
 *
 */
	
.text
.align	2
.globl	_program_clean
.ent	_program_clean
_program_clean:
    rtsd	r15,8 
    nop
.end	_program_clean
