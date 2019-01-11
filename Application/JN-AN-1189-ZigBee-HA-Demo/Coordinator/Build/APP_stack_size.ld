/*****************************************************************************
 *
 * MODULE:             App_Stack_Size.ld
 *
 * DESCRIPTION:        Linker command file defining the default app stack size
 *                     
 *****************************************************************************
 *
 * This software is owned by Jennic and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on Jennic products. You, and any third parties must reproduce
 * the copyright and warranty notice and any other legend of ownership on each
 * copy or partial copy of the software.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS". JENNIC MAKES NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE,
 * ACCURACY OR LACK OF NEGLIGENCE. JENNIC SHALL NOT, IN ANY CIRCUMSTANCES,
 * BE LIABLE FOR ANY DAMAGES, INCLUDING, BUT NOT LIMITED TO, SPECIAL,
 * INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER.
 *
 * Copyright Jennic Ltd. 2009 All rights reserved
 *
 *****************************************************************************
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/Stack/Modules/ZBPro/Branches/ZBProv1.1/Build/App_Stack_Size.ld $
 *
 * $Revision: 59767 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2014-03-12 17:59:49 +0000 (Wed, 12 Mar 2014) $
 *
 * $Id: App_Stack_Size.ld 59767 2014-03-12 17:59:49Z nxp29741 $
 *
 ****************************************************************************/

/* Default stack size for ZBPro applications.
 * To override the default setting, copy this
 * file to your apoplication build folder and
 * alter the stack size as required. */
 
 _minimum_heap_size = 1000;
_stack_size = 3500;
