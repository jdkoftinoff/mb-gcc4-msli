////////////////////////////////////////////////////////////////
//
// Copyright 1995-2002 Xilinx, Inc.  All rights reserved.
//
// MODULE sbrk.c
//
// Purpose: Support xil_malloc to allocate memory. This files should
// replace sbrk from the libc area
//
// $Id: xil_sbrk.c,v 1.1.18.6 2005/11/15 23:41:01 salindac Exp $
//
////////////////////////////////////////////////////////////////

#define sbrk xil_sbrk

char memblk[65536];
int memindex = 0;

void *sbrk(int size) {
  int oldindex;
  oldindex = memindex;
  memindex += size;
  if (memindex >= 65536)
    return 0;
  return (void *)(&memblk[oldindex]);
}
