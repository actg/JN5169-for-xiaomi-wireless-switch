/*===========================================================================
//
//      memcpy.c
//
//      ANSI standard memcpy() routine
//
//==========================================================================
//####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Red Hat, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 or (at your option) any later version.
//
// eCos is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with eCos; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
//
// As a special exception, if other files instantiate templates or use macros
// or inline functions from this file, or you compile this file and link it
// with other works to produce a work based on this file, this file does not
// by itself cause the resulting work to be covered by the GNU General Public
// License. However the source code for this file must still be made available
// in accordance with section (3) of the GNU General Public License.
//
// This exception does not invalidate any other reasons why a work based on
// this file might be covered by the GNU General Public License.
//
// Alternative licenses for eCos may be arranged by contacting Red Hat, Inc.
// at http://sources.redhat.com/ecos/ecos-license/
// -------------------------------------------
//####ECOSGPLCOPYRIGHTEND####
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):   jlarmour
// Contributors:  jlarmour
// Date:        1998-06-04
// Purpose:     This file implements the ANSI memcpy() function
// Description: This file implements the memcpy() function defined in ANSI para
//              7.11.2.1. This is implemented in the kernel rather than the
//              C library due to it being required by gcc whether or not the
//              C library has been configured in.
//
//####DESCRIPTIONEND####
//
//==========================================================================*/


/* INCLUDES */
#include <stddef.h>             /* Compiler defns such as size_t, NULL etc. */
#include "jendefs.h"

/* MACROS */

/* Nonzero if either X or Y is not aligned on a word boundary. */
#define CYG_STR_UNALIGNED(X, Y) \
     (((uint32)(X) & (sizeof (uint32) - 1)) | \
      ((uint32)(Y) & (sizeof (uint32) - 1)))

/* How many bytes are copied each iteration of the 4X unrolled loop in the
 * optimised string implementation
 */
#define CYG_STR_OPT_BIGBLOCKSIZE     (sizeof(uint32) << 2)


/* How many bytes are copied each iteration of the word copy loop in the
 * optimised string implementation
 */
#define CYG_STR_OPT_LITTLEBLOCKSIZE (sizeof (uint32))

void *
memcpy( void *s1, const void *s2, size_t n )
{
    char *dst;
    const char *src;
    uint32 *aligned_dst;
    const uint32 *aligned_src;

    dst = (char *)s1;
    src = (const char *)s2;

    /* If the size is small, or either SRC or DST is unaligned,
     * then punt into the byte copy loop.  This should be rare.
     */
    if (n < sizeof(uint32) || CYG_STR_UNALIGNED (src, dst))
    {
        while (n--)
            *dst++ = *src++;
        return s1;
    } /* if */

    aligned_dst = (uint32 *)dst;
    aligned_src = (const uint32 *)src;

    /* Copy 4X long words at a time if possible.  */
    while (n >= CYG_STR_OPT_BIGBLOCKSIZE)
    {
        *aligned_dst++ = *aligned_src++;
        *aligned_dst++ = *aligned_src++;
        *aligned_dst++ = *aligned_src++;
        *aligned_dst++ = *aligned_src++;
        n -= CYG_STR_OPT_BIGBLOCKSIZE;
    } /* while */

    /* Copy one long word at a time if possible.  */
    while (n >= CYG_STR_OPT_LITTLEBLOCKSIZE)
    {
        *aligned_dst++ = *aligned_src++;
        n -= CYG_STR_OPT_LITTLEBLOCKSIZE;
    } /* while */

    /* Pick up any residual with a byte copier.  */
    dst = (char*)aligned_dst;
    src = (const char*)aligned_src;
    while (n--)
        *dst++ = *src++;

    return s1;
} /* _memcpy() */

#if 0
void
bcopy( const void *s1, void *s2, int n )
{
    memcpy(s2,s1,(size_t)n);
}
#endif

/* EOF memcpy.c */
