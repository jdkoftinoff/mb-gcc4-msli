/* Xilinx MicroBlaze support for BFD.
   Copyright (C) 1995, 1999 Free Software Foundation, Inc.

This file is part of BFD, the Binary File Descriptor library.

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
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

/*
 * Copyright (c) 2001 Xilinx, Inc.  All rights reserved. 
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

/* This file holds definitions specific to the MICROBLAZE ELF ABI. */
#ifndef _ELF_MICROBLAZE_H
#define _ELF_MICROBLAZE_H

#include "elf/reloc-macros.h"

/* Relocations.  */
START_RELOC_NUMBERS (elf_microblaze_reloc_type)
  RELOC_NUMBER (R_MICROBLAZE_NONE, 0)
  RELOC_NUMBER (R_MICROBLAZE_32, 1)
  RELOC_NUMBER (R_MICROBLAZE_32_PCREL, 2)
  RELOC_NUMBER (R_MICROBLAZE_64_PCREL, 3)
  RELOC_NUMBER (R_MICROBLAZE_32_PCREL_LO, 4)
  RELOC_NUMBER (R_MICROBLAZE_64, 5)
  RELOC_NUMBER (R_MICROBLAZE_32_LO, 6)
  RELOC_NUMBER (R_MICROBLAZE_SRO32, 7)
  RELOC_NUMBER (R_MICROBLAZE_SRW32, 8)
  RELOC_NUMBER (R_MICROBLAZE_64_NONE, 9)
  RELOC_NUMBER (R_MICROBLAZE_32_SYM_OP_SYM, 10)
  RELOC_NUMBER (R_MICROBLAZE_GNU_VTINHERIT, 11)
  RELOC_NUMBER (R_MICROBLAZE_GNU_VTENTRY, 12)
  RELOC_NUMBER (R_MICROBLAZE_GOTPC_64, 13) /* PC-relative GOT offset */
  RELOC_NUMBER (R_MICROBLAZE_GOT_64, 14) /* GOT entry offset */
  RELOC_NUMBER (R_MICROBLAZE_PLT_64, 15) /* PLT offset (PC-relative) */
  RELOC_NUMBER (R_MICROBLAZE_REL, 16) /* adjust by program base */
  RELOC_NUMBER (R_MICROBLAZE_JUMP_SLOT, 17) /* create PLT entry */
  RELOC_NUMBER (R_MICROBLAZE_GLOB_DAT, 18) /* create GOT entry */
  RELOC_NUMBER (R_MICROBLAZE_GOTOFF_64, 19) /* offset relative to GOT */
  RELOC_NUMBER (R_MICROBLAZE_GOTOFF_32, 20) /* offset relative to GOT */
  RELOC_NUMBER (R_MICROBLAZE_COPY, 21) /* runtime copy */
   
#if 0
#ifndef MICROBLAZE_CYGWIN_VERSION
  EMPTY_RELOC  (R_MICROBLAZE_max)
END_RELOC_NUMBERS
#else
END_RELOC_NUMBERS (R_MICROBLAZE_max)
#endif
#endif
END_RELOC_NUMBERS (R_MICROBLAZE_max)

/* Global base address names */
#define RO_SDA_ANCHOR_NAME "_SDA2_BASE_"
#define RW_SDA_ANCHOR_NAME "_SDA_BASE_"

/* Section Attributes.  */
#define SHF_MICROBLAZE_NOREAD	0x80000000

#endif /* _ELF_MICROBLAZE_H */
