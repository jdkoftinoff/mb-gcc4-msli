/* { dg-do compile { target microblaze*-*-* } } */

/* { dg-options "" } */

#include <stdio.h>
#include <string.h>

/* { dg-final { scan-assembler "\.data*" } } */
int global = 10;

int testfunc ()
{
/* { dg-final { scan-assembler "\lwi\tr(\[0-9]\|\[1-2]\[0-9]\|3\[0-1]),r0" } } */
    return global;
}
