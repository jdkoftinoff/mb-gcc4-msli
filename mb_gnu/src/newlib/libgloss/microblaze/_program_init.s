#################################################-asm-
#
#  _program_init.s
# 
# Dummy file to be replaced by LibGen
#
# $Id: _program_init.s,v 1.2.16.6 2005/11/15 23:41:01 salindac Exp $
#################################################
	
	.text
	.align	2
	.globl	_program_init
	.ent	_program_init
_program_init:
	rtsd	r15,8 
	nop
	.end	_program_init
