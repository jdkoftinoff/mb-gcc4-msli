/* Definitions of target machine for GNU compiler, for Xilinx MicroBlaze.
   Copyright (C) 2000, 2001, 2002, 2003, 2004
   Free Software Foundation, Inc.
   Contributed by Richard Kenner (kenner@vlsi1.ultra.nyu.edu)

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 2, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING.  If not, write to the
   Free Software Foundation, 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA.  */

#ifndef __MICROBLAZE_PROTOS__
#define __MICROBLAZE_PROTOS__

#ifdef RTX_CODE
extern void barrel_shift_left_imm(rtx operands[]);
extern void shift_left_imm(rtx operands[]);
extern void shift_right_imm(rtx operands[]);
extern rtx embedded_pic_offset       PARAMS ((rtx));
extern int pic_address_needs_scratch PARAMS ((rtx));
extern void expand_block_move        PARAMS ((rtx *));
extern void shift_left_imm  PARAMS ((rtx []));
extern void microblaze_expand_prologue (void);
extern void microblaze_expand_epilogue (void);
extern void shift_double_left_imm    PARAMS ((rtx []));
extern void override_options (void);
extern int microblaze_expand_shift PARAMS ((enum shift_type, rtx *));
extern bool microblaze_expand_move PARAMS ((enum machine_mode, rtx *));
extern bool microblaze_expand_block_move PARAMS ((rtx, rtx, rtx, rtx));
extern void rodata_section(void);
extern void sbss_section(void);
extern void sbss2_section(void);
extern void bss_section(void);
extern void sdata2_section(void);
extern int microblaze_can_use_return_insn PARAMS ((void));
extern rtx  microblaze_legitimize_address PARAMS ((rtx , rtx, enum machine_mode));
extern int microblaze_const_double_ok PARAMS ((rtx, enum machine_mode));
extern void print_operand PARAMS ((FILE *, rtx, int));
extern void print_operand_address PARAMS ((FILE *, rtx));
extern void init_cumulative_args PARAMS ((CUMULATIVE_ARGS *,tree, rtx));
extern void output_ascii PARAMS ((FILE *, const char *, int));
extern bool microblaze_legitimate_address_p PARAMS ((enum machine_mode, rtx, int ));
extern void microblaze_gen_conditional_branch PARAMS ((rtx *, enum rtx_code));
extern int microblaze_is_interrupt_handler PARAMS ((void));
extern rtx microblaze_return_addr PARAMS ((int, rtx));
extern HOST_WIDE_INT microblaze_debugger_offset PARAMS ((rtx, HOST_WIDE_INT));
extern void microblaze_order_regs_for_local_alloc PARAMS ((void));
extern int simple_memory_operand PARAMS ((rtx, enum machine_mode));
extern int double_memory_operand PARAMS ((rtx, enum machine_mode));
extern enum reg_class microblaze_secondary_reload_class
   PARAMS ((enum reg_class, enum machine_mode, rtx, int));
extern int microblaze_regno_ok_for_base_p PARAMS ((int, int));
extern HOST_WIDE_INT microblaze_initial_elimination_offset PARAMS ((int, int));
extern void microblaze_output_filename PARAMS ((FILE*, const char*));
extern void microblaze_declare_object PARAMS ((FILE *, const char *, const char *,
   const char *, int));
#endif  /* RTX_CODE */

#ifdef TREE_CODE
extern void function_arg_advance (CUMULATIVE_ARGS *, enum machine_mode,
				  tree, int);
extern rtx function_arg (CUMULATIVE_ARGS *, enum machine_mode, tree, int);
#endif /* TREE_CODE */

#endif  /* __MICROBLAZE_PROTOS__ */
