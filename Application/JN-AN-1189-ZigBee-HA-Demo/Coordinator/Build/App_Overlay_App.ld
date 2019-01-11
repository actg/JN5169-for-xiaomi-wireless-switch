/*****************************************************************************
 *
 * MODULE:             JN-AN-1171
 *
 * COMPONENT:          App_Overlay_App.ld
 *
 * AUTHOR:             JV
 *
 * DESCRIPTION:        Linker command file for the application
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Application_Notes/JN-AN-1171-ZigBee-LightLink-Demo/Trunk/Light_DimmableLight/Build/App_Overlay_App.ld $
 *
 * $Revision: 50402 $
 *
 * $LastChangedBy: nxp46755 $
 *
 * $LastChangedDate: 2012-12-12 12:18:00 +0530 (Wed, 12 Dec 2012) $
 *
 * $Id: App_Overlay_App.ld 50402 2012-12-12 06:48:00Z nxp46755 $
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139]. 
 * You, and any third parties must reproduce the copyright and warranty notice
 * and any other legend of ownership on each copy or partial copy of the 
 * software.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ***************************************************************************/

SECTIONS
{  
        .APP _overlay_start :
        AT ( _overlay_lma )
        {
        *(.ovly.APP)
        *(.ovly.APP.*)
        . = ALIGN((.), 16);
        } >ram

        _overlay_len = MAX((_overlay_len), SIZEOF(.APP));
        _overlay_lma = ALIGN(_overlay_lma + SIZEOF(.APP) - (_enc_offset), 16) + _enc_offset;
        
        _overlays += 1;
        
        .overlay_location :
        {
        LONG(0)
        SHORT(SIZEOF(.APP))
        SHORT(0)
        LONG(0)
        LONG(0)
        } > flash
                
}
