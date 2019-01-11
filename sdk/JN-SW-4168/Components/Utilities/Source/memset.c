/*===========================================================================
//
//      memset.c
//
//      ANSI standard memset() routine
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
// Purpose:     This file implements the ANSI memset() function
// Description: This file implements the memset() function defined in ANSI para
//              7.11.6.1. This is implemented in the kernel rather than the
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

/* FUNCTIONS */

void *
memset( void *s, int c, size_t n )
{
    char *char_ptr = (char *)s;
    
    while (n-- != 0)
    {
        *char_ptr++ = (char) c;
    }
    return s;
} /* _memset() */

/* EOF memset.c */
