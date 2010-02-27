/* The errno variable is stored in the reentrancy structure.  This
   function returns its address for use by the macro errno defined in
   errno.h.  */

#include <errno.h>
#include <reent.h>

#ifndef _REENT_ONLY

#if  0   /* Xilinx: We override this in the Standalone BSP */
int *
__errno ()
{
  return &_REENT->_errno;
}

#endif /* #if 0 */
#endif
