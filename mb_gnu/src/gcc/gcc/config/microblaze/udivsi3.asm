###################################-*-asm*- 
# 
# Copyright (c) 2001 Xilinx, Inc.  All rights reserved. 
# 
# Xilinx, Inc. CONFIDENTIAL 
# 
# udivsi3.asm 
# 
# Unsigned divide operation.
#	Input :	Divisor in Reg r5
#		Dividend in Reg r6
#	Output: Result in Reg r3
# 
# $Header: /devl/xcs/repo/env/Jobs/MDT/sw/ThirdParty/gnu/src/gcc/src-3.4/gcc/config/microblaze/udivsi3.s,v 1.1.2.6 2005/11/15 23:32:47 salindac Exp $
# 
#######################################
	
	.globl	__udivsi3
	.ent	__udivsi3
	.type	__udivsi3,@function
__udivsi3:
	.frame	r1,0,r15	

	ADDIK   r1,r1,-12
    	SWI     r29,r1,0
	SWI     r30,r1,4
	SWI     r31,r1,8

	BEQI    r6,$LaDiv_By_Zero           # Div_by_Zero   # Division Error
	BEQID   r5,$LaResult_Is_Zero        # Result is Zero 
	ADDIK   r30,r0,0                    # Clear mod
	ADDIK   r29,r0,32                   # Initialize the loop count

        # Check if r6 and r5 are equal # if yes, return 1
	RSUB 	r18,r5,r6
	BEQID	r18,$LaRETURN_HERE
	ADDIK	r3,r0,1

        # Check if (uns)r6 is greater than (uns)r5. In that case, just return 0
	XOR	r18,r5,r6
	BGEID	r18,16
	ADD	r3,r0,r0                    # We would anyways clear r3
	BLTI	r6,$LaRETURN_HERE           # r6[bit 31 = 1] hence is greater
	BRI	$LCheckr6
	RSUB	r18,r6,r5                   # MICROBLAZEcmp
	BLTI	r18,$LaRETURN_HERE

        # If r6 [bit 31] is set, then return result as 1
$LCheckr6:
	BGTI	r6,$LaDIV0
	BRID	$LaRETURN_HERE
	ADDIK	r3,r0,1

        # First part try to find the first '1' in the r5
$LaDIV0:
	BLTI    r5,$LaDIV2	
$LaDIV1:
	ADD     r5,r5,r5                    # left shift logical r5
	BGTID   r5,$LaDIV1       
	ADDIK   r29,r29,-1
$LaDIV2:
	ADD     r5,r5,r5                    # left shift logical  r5 get the '1' into the Carry
	ADDC    r30,r30,r30                 # Move that bit into the Mod register
	RSUB    r31,r6,r30                  # Try to subtract (r30 a r6)
    	BLTI    r31,$LaMOD_TOO_SMALL
	OR      r30,r0,r31                  # Move the r31 to mod since the result was positive
	ADDIK   r3,r3,1
$LaMOD_TOO_SMALL:
	ADDIK   r29,r29,-1
	BEQi    r29,$LaLOOP_END
	ADD     r3,r3,r3 # Shift in the '1' into div
	BRI     $LaDIV2   # Div2
$LaLOOP_END:
	BRI     $LaRETURN_HERE
$LaDiv_By_Zero:
$LaResult_Is_Zero:
	OR      r3,r0,r0 # set result to 0
$LaRETURN_HERE:
        # Restore values of CSRs and that of r3 and the divisor and the dividend
	LWI     r29,r1,0
	LWI     r30,r1,4
	LWI     r31,r1,8
	RTSD    r15,8
	ADDIK   r1,r1,12
        .end __udivsi3
	.size	__udivsi3, . - __udivsi3
