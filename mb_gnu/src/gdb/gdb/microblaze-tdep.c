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

/*
 * Copyright (c) 2007 Xilinx, Inc.  All rights reserved. 
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by Xilinx, Inc.  The name of the Company may not be used to endorse 
 * or promote products derived from this software without specific prior 
 * written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Xilinx, Inc.
 */

#include "defs.h"
#include "arch-utils.h"
#include "dis-asm.h"
#include "frame.h"
#include "trad-frame.h"
#include "symtab.h"
#include "value.h"
#include "gdbcmd.h"
#include "breakpoint.h"
#include "inferior.h"
#include "regcache.h"
#include "target.h"
#include "frame.h"
#include "frame-base.h"
#include "frame-unwind.h"
#include "dwarf2-frame.h"
#include "osabi.h"

#include "gdb_assert.h"
#include "gdb_string.h"


/* FIXME - this shouldn't be here */
#include "../opcodes/microblaze-opcm.h"

#include "microblaze-tdep.h"

extern enum microblaze_instr get_insn_microblaze (long, bfd_boolean *, 
		enum microblaze_instr_type *, short *);
extern unsigned long microblaze_get_target_address (long inst,
                                                    bfd_boolean immfound,
                                                    int immval,
                                                    long pcval,
                                                    long r1val,
                                                    long r2val,
                                                    bfd_boolean *targetvalid,
                                                    bfd_boolean *unconditionalbranch);


/* The registers of the Xilinx microblaze processor */

static const char *microblaze_register_names[] =
{ 
  "r0",   "r1",  "r2",    "r3",   "r4",   "r5",   "r6",   "r7",
  "r8",   "r9",  "r10",   "r11",  "r12",  "r13",  "r14",  "r15",
  "r16",  "r17", "r18",   "r19",  "r20",  "r21",  "r22",  "r23",
  "r24",  "r25", "r26",   "r27",  "r28",  "r29",  "r30",  "r31",
  "rpc",  "rmsr", "rear", "resr", "rfsr", "rbtr", 
  "rpvr0", "rpvr1", "rpvr2", "rpvr3", "rpvr4", "rpvr5", "rpvr6",
  "rpvr7", "rpvr8", "rpvr9", "rpvr10", "rpvr11",
  "redr", "rpid", "rzpr", "rtlbx", "rtlbsx"
};

static const gdb_byte big_break_insn[] = BIG_BREAKPOINT;
static const gdb_byte little_break_insn[] = LITTLE_BREAKPOINT;

#define MICROBLAZE_NUM_REGS ARRAY_SIZE (microblaze_register_names)

#define mb_error(msg) internal_error (__FILE__, __LINE__, _(msg))

extern enum microblaze_instr microblaze_decode_insn (long, int *, int *, int *, int *);

#ifdef MICROBLAZE_DEBUG
static void
microblaze_dump_insn (char *commnt, CORE_ADDR pc, int insn)
{
  if (microblaze_debug)
    {
      printf_filtered ("MICROBLAZE:  %s %08x %08x ",
		       commnt, (unsigned int) pc, (unsigned int) insn);
      // print_insn_microblaze (pc, &tm_print_insn_info);
      printf_filtered ("\n");
    }
}
#define microblaze_insn_debug(args) { if (microblaze_debug) printf_filtered args; }
#define mb_warn(msg) printf ("mb_warning: %s:%d %s\n", __FILE__, __LINE__, _(msg))
#else /* !MICROBLAZE_DEBUG */
#define microblaze_dump_insn(a,b,c) {}
#define microblaze_insn_debug(args) {}
#define mb_warn(msg) 
#endif

/* Return the name of register REGNUM.  */

static const char *
microblaze_register_name (int regnum)
{
  if (regnum >= 0 && regnum < MICROBLAZE_NUM_REGS)
    return microblaze_register_names[regnum];
  return NULL;
}

static struct type *
microblaze_register_type (struct gdbarch *gdbarch, int regnum)
{
  if (regnum == MICROBLAZE_SP_REGNUM)
    return builtin_type_void_data_ptr;

  if (regnum == MICROBLAZE_PC_REGNUM)
    return builtin_type_void_func_ptr;

  return builtin_type_int32;
}


/* Fetch the instruction at PC.  */

unsigned long
microblaze_fetch_instruction (CORE_ADDR pc)
{
  gdb_byte buf[4];
  unsigned long insn;
  int i;

  /* If we can't read the instruction at PC, return zero.  */
  if (target_read_memory (pc, buf, sizeof (buf)))
    return 0;

  insn = 0;
  if (TARGET_BYTE_ORDER == BFD_ENDIAN_BIG) {
      for (i = 0; i < sizeof (buf); i++)
          insn = (insn << 8) | buf[i];
  } else {
      for (i = 3; i >= 0; i--)
          insn = (insn << 8) | buf[i];
  }
  return insn;
}

/* Return the contents if register REGNUM as an address.  */

CORE_ADDR
microblaze_address_from_register (int regnum)
{
  ULONGEST addr;

  regcache_cooked_read_unsigned (current_regcache, regnum, &addr);
  return addr;
}


static CORE_ADDR
microblaze_push_dummy_code (struct gdbarch *gdbarch, CORE_ADDR sp,
			    CORE_ADDR funcaddr, int using_gcc,
			    struct value **args, int nargs,
			    struct type *value_type,
			    CORE_ADDR *real_pc, CORE_ADDR *bp_addr)
{
  mb_warn ("push_dummy_code not implemented");
  return sp;
}

static CORE_ADDR
microblaze_push_dummy_call (struct gdbarch *gdbarch, struct value *function,
			    struct regcache *regcache, CORE_ADDR bp_addr,
			    int nargs, struct value **args, CORE_ADDR sp,
			    int struct_return, CORE_ADDR struct_addr)
{
  mb_warn ("store_arguments not implemented");
  return sp;
}

/* Use the program counter to determine the contents and size of a
   breakpoint instruction.  Return a pointer to a string of bytes that
   encode a breakpoint instruction, store the length of the string in
   *LEN and optionally adjust *PC to point to the correct memory
   location for inserting the breakpoint.  */
   
static const gdb_byte *
microblaze_breakpoint_from_pc (CORE_ADDR *pc, int *len)
{
  if (TARGET_BYTE_ORDER == BFD_ENDIAN_BIG) 
    {
      *len = sizeof (big_break_insn);
      return big_break_insn;
    } 
  else
    {
      *len = sizeof (little_break_insn);
      return little_break_insn;
    }
}

/* Allocate and initialize a frame cache.  */

static struct microblaze_frame_cache *
microblaze_alloc_frame_cache (void)
{
  struct microblaze_frame_cache *cache;
  int i;

  cache = FRAME_OBSTACK_ZALLOC (struct microblaze_frame_cache);

  /* Base address.  */
  cache->base = 0;
  cache->pc = 0;

  /* Frameless until proven otherwise.  */
  cache->frameless_p = 1;

  return cache;
}

/* Function prologues on the Xilinx microblaze processors consist of:

   - adjustments to the stack pointer (r1) (addi r1, r1, imm)
   - making a copy of r1 into another register (a "frame" pointer) (add r?, r1, r0)
   - store word/multiples that use r1 or the frame pointer as the base address (swi r?, r1, imm OR swi r?, fp, imm)

   Note that microblaze really doesn't have a real frame pointer.
   Instead, the compiler may copy the SP into a register (usually
   r19) to act as an arg pointer.  For our target-dependent purposes,
   the frame info's "frame" member will be the beginning of the
   frame. The SP could, in fact, point below this.

   The prologue ends when an instruction fails to meet either of
   these criteria. */

/* Analyze the prologue to determine where registers are saved,
   the end of the prologue, etc. Return the address of the first line
   of "real" code (i.e., the end of the prologue). */

CORE_ADDR
microblaze_analyze_prologue (CORE_ADDR pc, CORE_ADDR current_pc,
			     struct microblaze_frame_cache *cache)
{
  char *name;
  CORE_ADDR func_addr, func_end, addr, stop, prologue_end_addr = 0;
  unsigned long insn;
  int rn, rd, ra, rb, imm;
  enum microblaze_instr op;
  int flags = 0;
  bfd_boolean save_hidden_pointer_found = FALSE;
  bfd_boolean non_stack_instruction_found = FALSE;

  // printf("microblaze_analyze_prologue (pc = 0x%8.8x, current_pc = 0x%8.8x, cache = 0x%8.8x)\n",
  //	(int) pc, (int) current_pc, (int) cache);

  /* Find the start of this function. */
  find_pc_partial_function (pc, &name, &func_addr, &func_end);
  if (func_addr < pc) 
    pc = func_addr;

  if (current_pc < pc)
    return current_pc;

   /* Initialize info about frame */
   cache->framesize = 0;
   cache->fp_regnum = MICROBLAZE_SP_REGNUM;
   cache->frameless_p = 1;

  /* Start decoding the prologue.  We start by checking two special cases:

     1. We're about to return
     2. We're at the first insn of the prologue.

     If we're about to return, our frame has already been deallocated.
     If we are stopped at the first instruction of a prologue,
     then our frame has not yet been set up. */

  /* Get the first insn from memory */

  insn = microblaze_fetch_instruction (pc);
  op = microblaze_decode_insn (insn, &rd, &ra, &rb, &imm);

  if (IS_RETURN(op)) 
    return pc;

#if 0
  /* Check for first insn of prologue */
  if (pc == func_addr)
    return pc;
#endif

  /* Start at beginning of function and analyze until we get to the
     current pc, or the end of the function, whichever is first. */
  stop = (current_pc < func_end ? current_pc : func_end);

  microblaze_insn_debug(("MICROBLAZE: Scanning prologue: name=%s, func_addr=0x%x, stop=0x%x\n",
		     name, (unsigned int) func_addr, (unsigned int) stop));

  /* Do a block read to minimize the transaction with the Debug Agent */
  int n_insns = (stop == func_addr) ? 1 : ((stop - func_addr) / INST_WORD_SIZE);
  unsigned long *insn_block = (unsigned long *)calloc(n_insns, sizeof(unsigned long));
  gdb_byte *buf_block = (gdb_byte *)calloc(n_insns * INST_WORD_SIZE, sizeof(gdb_byte));

  target_read_memory (func_addr, buf_block, n_insns * INST_WORD_SIZE );

  int ti, tj;
  for(ti = 0; ti < n_insns; ti++){
	  insn_block[ti] = 0;
	  for( tj = ti * INST_WORD_SIZE; tj < (ti + 1) * INST_WORD_SIZE; tj++ )
		  insn_block[ti] = (insn_block[ti] << 8) | buf_block[tj];
  }
  
  for (addr = func_addr; addr < stop; addr += INST_WORD_SIZE)
    {
	    //insn = microblaze_fetch_instruction (addr);
      insn = insn_block[(addr - func_addr) / INST_WORD_SIZE];
      op = microblaze_decode_insn (insn, &rd, &ra, &rb, &imm);
      microblaze_dump_insn ("got 2: ", addr, insn);

      /* This code is very sensitive to what functions are present in the prologue. 
         It assumes that the (addi, addik, swi, sw) can be the only instructions 
         in the prologue.  */
      if (IS_UPDATE_SP(op, rd, ra))
	{
	  microblaze_insn_debug (("MICROBLAZE: got addi r1,r1,%d; contnuing\n", imm));
	  if (cache->framesize) break;	/* break if framesize already computed */
	  cache->framesize = -1 * imm; /* Since stack grows towards low memory */
	  cache->frameless_p = 0; /* Frame found. */
	  save_hidden_pointer_found = FALSE;
	  non_stack_instruction_found = FALSE;
	  continue;
	}
      else if (IS_SPILL_SP(op, rd, ra))
	{
	  /* Spill stack pointer */
	  cache->register_offsets[rd] = imm; /* SP spilled before updating */

	  microblaze_insn_debug (("MICROBLAZE: swi r1 r1 %d, continuing\n", imm));
	  save_hidden_pointer_found = FALSE;
	  if (!cache->framesize)
	  	non_stack_instruction_found = FALSE;
	  continue;
	}
      else if (IS_SPILL_REG(op, rd, ra))
	{
	  /* Spill register */
	  cache->register_offsets[rd] = imm - cache->framesize; /* reg spilled after updating */

	  microblaze_insn_debug (("MICROBLAZE: swi %d r1 %d, continuing\n", rd, imm));
	  save_hidden_pointer_found = FALSE;
	  if (!cache->framesize)
	  	non_stack_instruction_found = FALSE;
	  continue;
	}
      else if (IS_ALSO_SPILL_REG(op, rd, ra, rb))
	{
	  /* Spill register */
	  cache->register_offsets[rd] = 0 - cache->framesize; /* reg spilled after updating */

	  microblaze_insn_debug (("MICROBLAZE: sw %d r0 r1, continuing\n", rd));
	  save_hidden_pointer_found = FALSE;
	  if (!cache->framesize)
	  	non_stack_instruction_found = FALSE;
	  continue;
	}
      else if (IS_SETUP_FP(op, ra, rb))
	{
	  /* We have a frame pointer.  Note
	     the register which is acting as the frame pointer. */
	  flags |= MY_FRAME_IN_FP;
	  flags &= ~MY_FRAME_IN_SP;
	  cache->fp_regnum = rd;
	  microblaze_insn_debug (("MICROBLAZE: Found a frame pointer: r%d\n", cache->fp_regnum));
	  save_hidden_pointer_found = FALSE;
	  if (!cache->framesize)
	  	non_stack_instruction_found = FALSE;
	  continue;
	}
      else if (IS_SPILL_REG_FP(op, rd, ra, cache->fp_regnum))
	{
	  cache->register_offsets[rd] = imm - cache->framesize; /* reg spilled after updating */

	  microblaze_insn_debug (("MICROBLAZE: swi %d %d %d, continuing\n", rd, ra, imm));
	  save_hidden_pointer_found = FALSE;
	  if (!cache->framesize)
	  	non_stack_instruction_found = FALSE;
	  continue;
	}
      else if (IS_SAVE_HIDDEN_PTR(op, rd, ra, rb))
	{
	  /* If the first argument is a hidden pointer to the area where the 
	     return structure is to be saved, then it is saved as part of the 
	     prologue */

	  microblaze_insn_debug (("MICROBLAZE: add %d %d %d, continuing\n", rd, ra, rb));
	  save_hidden_pointer_found = TRUE;
	  if (!cache->framesize)
	  	non_stack_instruction_found = FALSE;
	  continue;
	}

      /* as a result of the modification in the next step where we continue to analyze the 
	 prologue till we reach a control flow instruction, we need another variable to store
	 when exactly a non-stack instruction was encountered, which is the current definition
	 of a prologue
       */
      if (!non_stack_instruction_found)
      		prologue_end_addr = addr;
      non_stack_instruction_found = TRUE;

      /* When optimizations are enabled, it is not guaranteed that prologue instructions
	 are not mixed in with other instructions from the program. Some programs show this 
	 behavior at -O2. This can be avoided by adding -fno-schedule-insns2 switch as of now (edk 8.1)
	 In such cases, we scan the function until we see the first control instruction.
       */

	   
      {
	      unsigned op = (unsigned)insn >> 26;

	      if (!(op == 0x26 || op == 0x27 || op == 0x2d || op == 0x2e || op == 0x2f))
		      continue;    /* continue if not control flow (branch, return) */
	      else if (op == 0x2c)
		      continue;    /* continue if imm */
      }

      /* This is not a prologue insn, so stop here. */
      microblaze_insn_debug (("microblaze: insn is not a prologue insn -- ending scan\n"));
      break;
    }

  microblaze_insn_debug (("microblaze: done analyzing prologue\n"));
  microblaze_insn_debug (("microblaze: prologue end = 0x%x\n", (int) addr));

  /* If the last instruction was an add rd, r5, r0 then don't count it as part of
     the prologue */
  if (save_hidden_pointer_found) {
    prologue_end_addr -= INST_WORD_SIZE;
  }

  free(insn_block);
  free(buf_block);
  return prologue_end_addr;
}

static CORE_ADDR
microblaze_unwind_pc (struct gdbarch *gdbarch, struct frame_info *next_frame)
{
  gdb_byte buf[4];
  CORE_ADDR pc;
  // struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
  // printf ("microblaze_unwind_pc (next_frame = {level=%d, prev_pc=0x%8.8x})\n",
// 	next_frame->level, next_frame->prev_pc.value);
 // debug_frame ("microblaze_unwind_pc", next_frame);
  frame_unwind_register (next_frame, MICROBLAZE_PC_REGNUM, buf);
  pc = extract_typed_address (buf, builtin_type_void_func_ptr);
  /* For sentinel frame, return address is actual PC.  For other frames,
     return address is pc+8.  This is a workaround because gcc does not
     generate correct return address in CIE. */
  if (frame_level(next_frame) >= 0)
    pc += 8;
  return pc;
}

/* Return PC of first real instruction of the function starting at
   START_PC.  */

CORE_ADDR
microblaze_skip_prologue (CORE_ADDR start_pc)
{
  struct symtab_and_line sal;
  CORE_ADDR func_start, func_end, ostart_pc;
  struct microblaze_frame_cache cache;

  /* This is the preferred method, find the end of the prologue by
     using the debugging information. 
     Debugging info does not always give the right answer since 
     parameters are stored on stack after this.  Always analyze the prologue.  */
  if (find_pc_partial_function (start_pc, NULL, &func_start, &func_end))
    {
      sal = find_pc_line (func_start, 0);

      if (sal.end < func_end
	  && start_pc <= sal.end)
	start_pc = sal.end;
    }

  ostart_pc = microblaze_analyze_prologue (func_start, 0xffffffffUL, &cache);

  if (ostart_pc > start_pc)
    return ostart_pc;
  return start_pc;
}

/* Normal frames.  */

struct microblaze_frame_cache *
microblaze_frame_cache (struct frame_info *next_frame, void **this_cache)
{
  struct microblaze_frame_cache *cache;
  CORE_ADDR func, pc, fp;
  int rn;

  // printf ("microblaze_frame_cache (next_frame = 0x%8.8x, this_cache = 0x%8.8x)\n",
  //	(int) next_frame, (int) this_cache);
  if (*this_cache)
    return *this_cache;

  cache = microblaze_alloc_frame_cache ();
  *this_cache = cache;
  cache->saved_regs = trad_frame_alloc_saved_regs (next_frame);

  /* Clear offsets to saved regs in frame. */
  for (rn = 0; rn < NUM_REGS; rn++)
    cache->register_offsets[rn] = -1;

  func = frame_func_unwind (next_frame);
  cache->pc = frame_pc_unwind (next_frame);

  if (cache->pc != 0)
    {
      CORE_ADDR addr_in_block = frame_unwind_address_in_block (next_frame);
      microblaze_analyze_prologue (cache->pc, addr_in_block, cache);
      fp = frame_unwind_register_unsigned (next_frame, cache->fp_regnum);
      cache->base = fp + cache->framesize;
    }
  else 
  {
    // printf ("microblaze_frame_cache:  pc == 0\n");
    /* FIXME:  What do we do now? */
  }

  if (cache->frameless_p)
    {
      /* FIXME:  What do we do here? */
      // printf ("\tframeless function\n");
    }
  else
    {
      /* FIXME:  Find register for current frame. */
      // printf ("\tfunction with frame\n");
    }

  return cache;
}

static void
microblaze_frame_this_id (struct frame_info *next_frame, void **this_cache,
		       struct frame_id *this_id)
{
  struct microblaze_frame_cache *cache =
    microblaze_frame_cache (next_frame, this_cache);

  // printf("microblaze_frame_this_id (next_frame = 0x%.8x, this_cache = 0x%.8x, this_id = 0x%.8x)\n",
  //	(int) next_frame, (int) this_cache, (int) this_id);
  /* This marks the outermost frame.  */
  if (cache->base == 0)
    return;

  (*this_id) = frame_id_build (cache->base, cache->pc);
}

static void
microblaze_frame_prev_register (struct frame_info *next_frame, void **this_cache,
			        int regnum, int *optimizedp,
			        enum lval_type *lvalp, CORE_ADDR *addrp,
			        int *realnump, gdb_byte *valuep)
{
  struct microblaze_frame_cache *cache =
    microblaze_frame_cache (next_frame, this_cache);

  // printf("microblaze_frame_prev_register (next_frame = 0x%8.8x (level = %d),\n"
  //		  "\t*this_cache = 0x%8.8x, frameless_p = %d, regnum = %d)\n", 
  //   (int) next_frame, frame_level(next_frame), (int) cache, cache->frameless_p, regnum);

  /* FIXME:  Rework this code and add comments. */
  if (cache->frameless_p) 
  {
    if (regnum == MICROBLAZE_PC_REGNUM) regnum = 15;
    if (regnum == MICROBLAZE_SP_REGNUM) regnum = 1;
    trad_frame_get_prev_register (next_frame, cache->saved_regs, regnum,
				  optimizedp, lvalp, addrp, realnump, valuep);
  } 
  else if (regnum == MICROBLAZE_PC_REGNUM && !cache->frameless_p)
    {
      *optimizedp = 0;
      *lvalp = not_lval;
      *addrp = 0;
      *realnump = -1;
      if (valuep)
	/* FIXME:  use symbolic values */
	get_frame_memory (next_frame, cache->base + cache->register_offsets[15], valuep, 4);
    }
  else
    trad_frame_get_prev_register (next_frame, cache->saved_regs, regnum,
				  optimizedp, lvalp, addrp, realnump, valuep);

}

static const struct frame_unwind microblaze_frame_unwind =
{
  NORMAL_FRAME,
  microblaze_frame_this_id,
  microblaze_frame_prev_register
};

static const struct frame_unwind *
microblaze_frame_sniffer (struct frame_info *next_frame)
{
  return &microblaze_frame_unwind;
}

static CORE_ADDR
microblaze_frame_base_address (struct frame_info *next_frame, void **this_cache)
{
  struct microblaze_frame_cache *cache =
    microblaze_frame_cache (next_frame, this_cache);

  // printf ("microblaze_frame_base_address (next_frame = 0x%8.8x, this_cache = 0x%8.8x)\n",
  //	(int) next_frame, (int) this_cache);
  return cache->base;
}

static const struct frame_base microblaze_frame_base =
{
  &microblaze_frame_unwind,
  microblaze_frame_base_address,
  microblaze_frame_base_address,
  microblaze_frame_base_address
};

static struct frame_id
microblaze_unwind_dummy_id (struct gdbarch *gdbarch, struct frame_info *next_frame)
{
  CORE_ADDR sp;

  // printf("microblaze_unwind_dummy_id (gdbarch = 0x%8.8x, next_frame = 0x%8.8x)\n",
  //	(int) gdbarch, (int) next_frame);
  sp = frame_unwind_register_unsigned (next_frame, MICROBLAZE_SP_REGNUM);
  return frame_id_build (sp, frame_pc_unwind (next_frame));
}

/* Extract from an array REGBUF containing the (raw) register state, a
   function return value of TYPE, and copy that into VALBUF.  */
static void
microblaze_extract_return_value (struct type *type, struct regcache *regcache,
			         gdb_byte *valbuf)
{
  gdb_byte buf[8];

  // printf("microblaze_extract_return_value (type = 0x%.8x, regcache = 0x%.8x, valbuf = 0x%.8x)\n",
  //	(int) type, (int) regcache, (int) valbuf);
  /* Copy the return value (starting) in RETVAL_REGNUM to VALBUF. */
  switch (TYPE_LENGTH(type)) {
	  case 1:	/* return last byte in the register */
		  regcache_cooked_read (regcache, MICROBLAZE_RETVAL_REGNUM, buf);
		  memcpy(valbuf, buf + REGISTER_SIZE - 1, 1);
		  return;
	  case 2:	/* return last 2 bytes in register */
		  memcpy(valbuf, buf + REGISTER_SIZE - 2, 2);
		  return;
	  case 4:	/* for sizes 4 or 8, copy the required length */
	  case 8:
		  regcache_cooked_read (regcache, MICROBLAZE_RETVAL_REGNUM, buf);
		  regcache_cooked_read (regcache, MICROBLAZE_RETVAL_REGNUM+1, buf+4);
		  memcpy (valbuf, buf, TYPE_LENGTH (type));
		  return;
	  default:
		  printf_filtered("Fatal error: unsupported return value size requested (%s @ %d)\n", 
				  __FILE__, __LINE__);
  }
}

/* Store the return value in VALBUF (of type TYPE) where the caller
   expects to see it.

   Integers are stored in r3.

   Values less than 32 bits (short, boolean) are stored in r2, right justified and
   sign or zero extended.		FIXME

   Longs are stored in r3 (most significant word) and r4 (least significant word).
   Small structures are always returned on stack.
*/

static void
microblaze_store_return_value (struct type *type, struct regcache *regcache,
			       const gdb_byte *valbuf)
{
  int len = TYPE_LENGTH (type);
  gdb_byte buf[8];

  memset (buf, 0, sizeof(buf));
  
  /* Integral and pointer return values.  */

  if (len > 4)
    {
       gdb_assert (len == 8);
       memcpy (buf, valbuf, 8);
       regcache_cooked_write (regcache, MICROBLAZE_RETVAL_REGNUM+1, buf + 4);
    }
  else
    {
       /* ??? Do we need to do any sign-extension here?  */
       memcpy (buf + 4 - len, valbuf, len);
    }
  regcache_cooked_write (regcache, MICROBLAZE_RETVAL_REGNUM, buf);
}

static enum return_value_convention
microblaze_return_value (struct gdbarch *gdbarch, struct type *type,
		      struct regcache *regcache, gdb_byte *readbuf,
		      const gdb_byte *writebuf)
{
  if (readbuf)
    microblaze_extract_return_value (type, regcache, readbuf);
  if (writebuf)
    microblaze_store_return_value (type, regcache, writebuf);

  return RETURN_VALUE_REGISTER_CONVENTION;
}

static int
microblaze_stabs_argument_has_addr (struct gdbarch *gdbarch, struct type *type)
{
  return (TYPE_LENGTH (type) == 16);		/* FIXME */
}

#if 0
static void
microblaze_dwarf2_frame_init_reg (struct gdbarch *gdbarch, int regnum,
			          struct dwarf2_frame_state_reg *reg,
			          struct frame_info *next_frame)
{
  switch (regnum)
    {
    case MICROBLAZE_R0_REGNUM:
      reg->how = DWARF2_FRAME_REG_SAME_VALUE;
      break;
    case MICROBLAZE_SP_REGNUM:
      reg->how = DWARF2_FRAME_REG_CFA;
      break;
    case MICROBLAZE_PC_REGNUM:
      reg->how = DWARF2_FRAME_REG_SAVED_OFFSET;
      reg->loc.offset = 0;
      break;
    }
}
#endif

int microblaze_can_use_hardware_watchpoints (enum bptype type, int len, int ot) {
    int count = 0;
    switch (type) {
        case bp_hardware_breakpoint:
            count = 2;
            break;
        case bp_read_watchpoint:
            count = 1;
            break;
        case bp_hardware_watchpoint:
            count = 1;
            break;
        default:
            count = 0;
    }
    return count;
}

/* Simulate single-step calls, since microblaze does not support 
   single-stepping */

/* single_step() is called just before we want to resume the inferior,
   if we want to single-step it but there is no hardware or kernel single-step
   support.  We find all the possible targets of the
   coming instruction and breakpoint them.

   single_step is also called just after the inferior stops.  If we had
   set up a simulated single-step, we undo our damage.  */

void
microblaze_software_single_step (enum target_signal sig, int insert_breakpoints_p)
{
  struct gdbarch *arch = current_gdbarch;
  struct gdbarch_tdep *tdep = gdbarch_tdep (arch);
  static char le_breakp[] = LITTLE_BREAKPOINT;
  static char be_breakp[] = BIG_BREAKPOINT;
  char *breakp = TARGET_BYTE_ORDER == BFD_ENDIAN_BIG ? be_breakp : le_breakp;

  /* Save the address and the values of the next_pc and the target */
  static struct sstep_breaks
  {
    CORE_ADDR address;
    bfd_boolean valid;
    /* Shadow contents.  */
    char data[INST_WORD_SIZE];
  } stepbreaks[2];
  int ii;

  if (insert_breakpoints_p)
    {
      CORE_ADDR pc;
      long insn;
      enum microblaze_instr minstr;
      bfd_boolean isunsignednum;
      enum microblaze_instr_type insn_type;
      short delay_slots;
      int imm;
      bfd_boolean immfound = FALSE;

      /* Set a breakpoint at the next instruction */
      /* If the current instruction is an imm, set it at the inst after */
      /* If the instruction has a delay slot, skip the delay slot */
      pc = microblaze_address_from_register (MICROBLAZE_PC_REGNUM);
      insn = microblaze_fetch_instruction (pc);
      minstr = get_insn_microblaze (insn, &isunsignednum, &insn_type, &delay_slots);
      if (insn_type == immediate_inst) 
	{
	  int rd, ra, rb;
	  immfound = TRUE;
	  minstr = microblaze_decode_insn (insn, &rd, &ra, &rb, &imm);
	  pc = pc + INST_WORD_SIZE;
	  insn = microblaze_fetch_instruction (pc);
	  minstr = get_insn_microblaze (insn, &isunsignednum, &insn_type, &delay_slots);
	}
      stepbreaks[0].address = pc + (delay_slots * INST_WORD_SIZE) + INST_WORD_SIZE;
      if (insn_type != return_inst) {
	stepbreaks[0].valid = TRUE;
      } else {
	stepbreaks[0].valid = FALSE;
      }

      /* Now check for branch or return instructions */
      if (insn_type == branch_inst || insn_type == return_inst) {
	int limm;
	int lrd, lra, lrb;
	int ra, rb;
	bfd_boolean targetvalid;
	bfd_boolean unconditionalbranch;
	microblaze_decode_insn(insn, &lrd, &lra, &lrb, &limm);
	if (lra >= 0 && lra < NUM_REGS)
	  ra = read_register(lra);
	else
	  ra = 0;
	if (lrb >= 0 && lrb < NUM_REGS)
	  rb = read_register(lrb);
	else
	  rb = 0;
	stepbreaks[1].address = microblaze_get_target_address (insn, immfound, imm, pc, ra, rb, &targetvalid, &unconditionalbranch);
	if (unconditionalbranch)
	  stepbreaks[0].valid = FALSE; /* This is a unconditional branch: will not come to the next address */
	if (targetvalid && (stepbreaks[0].valid == FALSE || 
			    (stepbreaks[0].address != stepbreaks[1].address))
	                && (stepbreaks[1].address != pc)) {
	  stepbreaks[1].valid = TRUE;
	} else {
	  stepbreaks[1].valid = FALSE;
	}
      } else {
	stepbreaks[1].valid = FALSE;
      }

      /* Insert the breakpoints */
      for (ii = 0; ii < 2; ++ii)
        {

          /* ignore invalid breakpoint. */
          if (stepbreaks[ii].valid) {
	    target_read_memory (stepbreaks[ii].address, stepbreaks[ii].data, INST_WORD_SIZE);
	    target_write_memory (stepbreaks[ii].address, breakp, INST_WORD_SIZE);
	  }
	}

    } else {
      /* Remove the breakpoints */
      for (ii = 0; ii < 2; ++ii)
        {
          /* ignore invalid breakpoint. */
          if (stepbreaks[ii].valid) {
	    target_write_memory (stepbreaks[ii].address, stepbreaks[ii].data, INST_WORD_SIZE);
	  }
	}
    }
}

static void
microblaze_write_pc (CORE_ADDR pc, ptid_t ptid)
{
  struct gdbarch_tdep *tdep = gdbarch_tdep (current_gdbarch);

  write_register_pid (MICROBLAZE_PC_REGNUM, pc, ptid);
}

/* FIXME -- why special init file? */
void microblaze_before_main_loop(void) {
#if 0
  /* PATH to ENV variable XILINX_EDK */
  char* xilinx_edk_dir;
  /* String to hold the path to mb-gdb's custom init file 
     $XILINX_EDK/data/mb-gdb.ini */
  char* mb_gdb_init;
  char mbgdbinit_filename[] = "/data/mb-gdb.ini";
  
#ifdef __CYGWIN__
  {
    char *tmp = getenv ("XILINX_EDK");

    if (tmp != NULL)
      {
	xilinx_edk_dir = (char *) xmalloc (PATH_MAX + 1);
	cygwin32_conv_to_posix_path (tmp, xilinx_edk_dir);
      }
    else
      xilinx_edk_dir = NULL;
  }
#else
  xilinx_edk_dir = getenv ("XILINX_EDK");
#endif
  if (xilinx_edk_dir)
    {
      mb_gdb_init = (char *) xmalloc (strlen (xilinx_edk_dir) +
				     strlen (mbgdbinit_filename) + 10);
      strcpy (mb_gdb_init, xilinx_edk_dir);
      strcat (mb_gdb_init, "/");
      strcat (mb_gdb_init, mbgdbinit_filename);

      if (!inhibit_gdbinit)
	{
	  catch_command_errors (source_command, mb_gdb_init, 0, RETURN_MASK_ALL);
	}
    }
#endif
}

static int dwarf2_to_reg_map[78] =
{ 0  /* r0  */,   1  /* r1  */,   2  /* r2  */,   3  /* r3  */,  /*  0- 3 */
  4  /* r4  */,   5  /* r5  */,   6  /* r6  */,   7  /* r7  */,  /*  4- 7 */
  8  /* r8  */,   9  /* r9  */,  10  /* r10 */,  11  /* r11 */,  /*  8-11 */
  12 /* r12 */,  13  /* r13 */,  14  /* r14 */,  15  /* r15 */,  /* 12-15 */
  16 /* r16 */,  17  /* r17 */,  18  /* r18 */,  19  /* r19 */,  /* 16-19 */
  20 /* r20 */,  21  /* r21 */,  22  /* r22 */,  23  /* r23 */,  /* 20-23 */
  24 /* r24 */,  25  /* r25 */,  26  /* r26 */,  27  /* r27 */,  /* 24-25 */
  28 /* r28 */,  29  /* r29 */,  30  /* r30 */,  31  /* r31 */,  /* 28-31 */
  -1 /* $f0 */,  -1  /* $f1 */,  -1  /* $f2 */,  -1  /* $f3 */,  /* 32-35 */
  -1 /* $f4 */,  -1  /* $f5 */,  -1  /* $f6 */,  -1  /* $f7 */,  /* 36-39 */
  -1 /* $f8 */,  -1  /* $f9 */,  -1  /* $f10 */, -1  /* $f11 */, /* 40-43 */
  -1 /* $f12 */, -1  /* $f13 */, -1  /* $f14 */, -1  /* $f15 */, /* 44-47 */
  -1 /* $f16 */, -1  /* $f17 */, -1  /* $f18 */, -1  /* $f19 */, /* 48-51 */
  -1 /* $f20 */, -1  /* $f21 */, -1  /* $f22 */, -1  /* $f23 */, /* 52-55 */
  -1 /* $f24 */, -1  /* $f25 */, -1  /* $f26 */, -1  /* $f27 */, /* 56-59 */
  -1 /* $f28 */, -1  /* $f29 */, -1  /* $f30 */, -1  /* $f31 */, /* 60-63 */
  -1 /* hi   */, -1  /* lo   */, -1  /* accum*/, 33  /* rmsr */, /* 64-67 */
  -1 /* $fcc1*/, -1  /* $fcc2*/, -1  /* $fcc3*/, -1  /* $fcc4*/, /* 68-71 */
  -1 /* $fcc5*/, -1  /* $fcc6*/, -1  /* $fcc7*/, -1  /* $ap  */, /* 72-75 */
  -1 /* $rap */, -1  /* $frp */					 /* 76-77 */
};

#define DWARF2_FRAME_RETURN_COLUMN 64
static int
microblaze_dwarf2_reg_to_regnum (int reg)
{
//  if (reg == DWARF2_FRAME_RETURN_COLUMN)
//    return MICROBLAZE_LR_REGNUM;
  return dwarf2_to_reg_map[reg];
}

static struct gdbarch *
microblaze_gdbarch_init (struct gdbarch_info info, struct gdbarch_list *arches)
{
  struct gdbarch_tdep *tdep;
  struct gdbarch *gdbarch;

  /* If there is already a candidate, use it.  */
  arches = gdbarch_list_lookup_by_info (arches, &info);
  if (arches != NULL)
    return arches->gdbarch;

  /* Allocate space for the new architecture.  */
  tdep = XMALLOC (struct gdbarch_tdep);
  gdbarch = gdbarch_alloc (&info, tdep);

  set_gdbarch_long_double_bit (gdbarch, 128);
  /* set_gdbarch_long_double_format (gdbarch, &floatformat_microblaze_quad); */

  set_gdbarch_num_regs (gdbarch, MICROBLAZE_NUM_REGS);
  set_gdbarch_register_name (gdbarch, microblaze_register_name);
  set_gdbarch_register_type (gdbarch, microblaze_register_type);
  /* set_gdbarch_num_pseudo_regs (gdbarch, MICROBLAZE_NUM_PSEUDO_REGS); */
  /* set_gdbarch_pseudo_register_read (gdbarch, microblaze_pseudo_register_read); */
  /* set_gdbarch_pseudo_register_write (gdbarch, microblaze_pseudo_register_write); */

  /* Register numbers of various important registers.  */
  set_gdbarch_sp_regnum (gdbarch, MICROBLAZE_SP_REGNUM); /* $sp */
  set_gdbarch_pc_regnum (gdbarch, MICROBLAZE_PC_REGNUM); /* $pc */

  /* Map Dwarf2 registers to GDB registers. */
  set_gdbarch_dwarf2_reg_to_regnum (gdbarch, microblaze_dwarf2_reg_to_regnum);

  /* Call dummy code.  */
  set_gdbarch_call_dummy_location (gdbarch, ON_STACK);
  set_gdbarch_push_dummy_code (gdbarch, microblaze_push_dummy_code);
  set_gdbarch_push_dummy_call (gdbarch, microblaze_push_dummy_call);

  set_gdbarch_return_value (gdbarch, microblaze_return_value);
  set_gdbarch_stabs_argument_has_addr
    (gdbarch, microblaze_stabs_argument_has_addr);

  set_gdbarch_skip_prologue (gdbarch, microblaze_skip_prologue);

  /* Stack grows downward.  */
  set_gdbarch_inner_than (gdbarch, core_addr_lessthan);

  set_gdbarch_breakpoint_from_pc (gdbarch, microblaze_breakpoint_from_pc);

  set_gdbarch_frame_args_skip (gdbarch, 8);

  set_gdbarch_print_insn (gdbarch, print_insn_microblaze);

  set_gdbarch_software_single_step (gdbarch, microblaze_software_single_step);
  set_gdbarch_write_pc (gdbarch, microblaze_write_pc);

  set_gdbarch_unwind_dummy_id (gdbarch, microblaze_unwind_dummy_id);

  set_gdbarch_unwind_pc (gdbarch, microblaze_unwind_pc);

  frame_base_set_default (gdbarch, &microblaze_frame_base);

  /* Hook in the DWARF CFI frame unwinder.  */
  // dwarf2_frame_set_init_reg (gdbarch, microblaze_dwarf2_frame_init_reg);

  /* Hook in ABI-specific overrides, if they have been registered.  */
  gdbarch_init_osabi (info, gdbarch); 

  /* Hook in the DWARF CFI frame unwinder.  */
  frame_unwind_append_sniffer (gdbarch, dwarf2_frame_sniffer);

  frame_unwind_append_sniffer (gdbarch, microblaze_frame_sniffer);

  return gdbarch;
}


/* Provide a prototype to silence -Wmissing-prototypes.  */
void _initialize_microblaze_tdep (void);

void
_initialize_microblaze_tdep (void)
{
  register_gdbarch_init (bfd_arch_microblaze, microblaze_gdbarch_init);
}

int
microblaze_frame_num_args_p (struct gdbarch *gdbarch)
{
  return 0;
}

