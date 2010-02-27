/* Target-dependent code for Xilinx MicroBlaze.
 
   Copyright (C) 2007 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

#ifndef MICROBLAZE_TDEP_H
#define MICROBLAZE_TDEP_H 1

#undef MICROBLAZE_DEBUG 
#ifdef MICROBLAZE_DEBUG
int microblaze_debug = 1;
#endif 

/* Microblaze architecture-specific information.  */

struct gdbarch_tdep
{
  int dummy;		// declare something.  
};

struct microblaze_frame_cache
{
  /* Base address.  */
  CORE_ADDR base;
  CORE_ADDR pc;

  /* Do we have a frame?  */
  int frameless_p;

  /* Frame size. */
  int framesize;

  /* Frame register. */
  int fp_regnum;

  /* Offsets to saved registers. */
  int register_offsets[NUM_REGS];

  /* Table of saved registers.  */
  struct trad_frame_saved_reg *saved_regs;
};

/* Register numbers */
enum microblaze_regnum 
{
  MICROBLAZE_R0_REGNUM,
  MICROBLAZE_R1_REGNUM, MICROBLAZE_SP_REGNUM = MICROBLAZE_R1_REGNUM,
  MICROBLAZE_R2_REGNUM,
  MICROBLAZE_R3_REGNUM, MICROBLAZE_RETVAL_REGNUM = MICROBLAZE_R3_REGNUM,
  MICROBLAZE_R4_REGNUM,
  MICROBLAZE_R5_REGNUM,
  MICROBLAZE_R6_REGNUM,
  MICROBLAZE_R7_REGNUM,
  MICROBLAZE_R8_REGNUM,
  MICROBLAZE_R9_REGNUM,
  MICROBLAZE_R10_REGNUM,
  MICROBLAZE_R11_REGNUM,
  MICROBLAZE_R12_REGNUM,
  MICROBLAZE_R13_REGNUM,
  MICROBLAZE_R14_REGNUM,
  MICROBLAZE_R15_REGNUM,
  MICROBLAZE_R16_REGNUM,
  MICROBLAZE_R17_REGNUM,
  MICROBLAZE_R18_REGNUM,
  MICROBLAZE_R19_REGNUM,
  MICROBLAZE_R20_REGNUM,
  MICROBLAZE_R21_REGNUM,
  MICROBLAZE_R22_REGNUM,
  MICROBLAZE_R23_REGNUM,
  MICROBLAZE_R24_REGNUM,
  MICROBLAZE_R25_REGNUM,
  MICROBLAZE_R26_REGNUM,
  MICROBLAZE_R27_REGNUM,
  MICROBLAZE_R28_REGNUM,
  MICROBLAZE_R29_REGNUM,
  MICROBLAZE_R30_REGNUM,
  MICROBLAZE_R31_REGNUM,
  MICROBLAZE_PC_REGNUM,
  MICROBLAZE_MSR_REGNUM,
  MICROBLAZE_EAR_REGNUM,
  MICROBLAZE_ESR_REGNUM,
  MICROBLAZE_FSR_REGNUM,
  MICROBLAZE_BTR_REGNUM,
  MICROBLAZE_PVR0_REGNUM,
  MICROBLAZE_PVR1_REGNUM,
  MICROBLAZE_PVR2_REGNUM,
  MICROBLAZE_PVR3_REGNUM,
  MICROBLAZE_PVR4_REGNUM,
  MICROBLAZE_PVR5_REGNUM,
  MICROBLAZE_PVR6_REGNUM,
  MICROBLAZE_PVR7_REGNUM,
  MICROBLAZE_PVR8_REGNUM,
  MICROBLAZE_PVR9_REGNUM,
  MICROBLAZE_PVR10_REGNUM,
  MICROBLAZE_PVR11_REGNUM
};

/* The base of the current frame is actually in the stack pointer.
   This happens when there is no frame pointer (microblaze ABI does not
   require a frame pointer) or when we're stopped in the prologue or
   epilogue itself.  In these cases, microblaze_analyze_prologue will need
   to update fi->frame before returning or analyzing the register
   save instructions. */
#define MY_FRAME_IN_SP 0x1

/* The base of the current frame is in a frame pointer register.
   This register is noted in frame_extra_info->fp_regnum.

   Note that the existance of an FP might also indicate that the
   function has called alloca. */
#define MY_FRAME_IN_FP 0x2

/* This flag is set to indicate that this frame is the top-most
   frame. This tells frame chain not to bother trying to unwind
   beyond this frame. */
#define NO_MORE_FRAMES 0x4


/* Instruction macros used for analyzing the prologue */
/* This set of instruction macros need to be changed whenever the prologue generated
 * by the compiler could have more instructions or different type of instructions
 * This set also needs to be verified if it is complete 
 */
#define IS_RETURN(op) (op == rtsd || op == rtid)
#define IS_UPDATE_SP(op, rd, ra) ((op == addik || op == addi) && rd == REG_SP && ra == REG_SP)
#define IS_SPILL_SP(op, rd, ra) ((op == swi || op == sw) && rd == REG_SP && ra == REG_SP)
#define IS_SPILL_REG(op, rd, ra) ((op == swi || op == sw) && rd != REG_SP && ra == REG_SP)
/* The base of the current frame is actually in the stack pointer.
   This happens when there is no frame pointer (microblaze ABI does not
   require a frame pointer) or when we're stopped in the prologue or
   epilogue itself.  In these cases, microblaze_analyze_prologue will need
   to update fi->frame before returning or analyzing the register
   save instructions. */
#define MY_FRAME_IN_SP 0x1

/* The base of the current frame is in a frame pointer register.
   This register is noted in frame_extra_info->fp_regnum.

   Note that the existance of an FP might also indicate that the
   function has called alloca. */
#define MY_FRAME_IN_FP 0x2

/* This flag is set to indicate that this frame is the top-most
   frame. This tells frame chain not to bother trying to unwind
   beyond this frame. */
#define NO_MORE_FRAMES 0x4
#define IS_ALSO_SPILL_REG(op, rd, ra, rb) ((op == swi || op == sw) && rd != REG_SP && ra == 0 && rb == REG_SP)
#define IS_SETUP_FP(op, ra, rb) ((op == add || op == addik || op == addk) && ra == REG_SP && rb == 0)
#define IS_SPILL_REG_FP(op, rd, ra, fpregnum) ((op == swi || op == sw) && rd != REG_SP && ra == fpregnum && ra != 0)
#define IS_SAVE_HIDDEN_PTR(op, rd, ra, rb) ((op == add || op == addik) && ra == FIRST_ARGREG && rb == 0)

#endif /* microblaze-tdep.h */
