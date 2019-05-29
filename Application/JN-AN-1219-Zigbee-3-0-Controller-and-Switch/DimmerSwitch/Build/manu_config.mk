##############################################################################
#
# MODULE:      JN-AN-1189 ZigBee HA Demo
#
# DESCRIPTION: Manufacturer Configurable Parameters
# 
##############################################################################
#
# This software is owned by NXP B.V. and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on NXP products [NXP Microcontrollers such as  JN5168, JN5164,
# JN5161, JN5148, JN5142, JN5139]. 
# You, and any third parties must reproduce the copyright and warranty notice
# and any other legend of ownership on each copy or partial copy of the 
# software.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Copyright NXP B.V. 2014. All rights reserved
#
##############################################################################
# The manufacturer code is allocated by the ZigBee Alliance and is reported
# by a device when responding to a Node Descriptor Request. In addition to
# changing the macro below the manufacturer code in the Node Descriptor
# contained within the ZigBee Configuration diagram must also be changed to
# the same value. 
MANUFACTURER_CODE         	?= 0x1037

# The following parameters are all reported by a device when the relevant
# attribute in the Basic Cluster is read. These are all optional attributes
# and if not required can be disabled via macros in zcl_options.h 
# Attrib: 0x0001 (UINT8)
APP_SW_VERSION            	?= 7					 
# TODO - Add stack version attribute ?
# Attrib: 0x0003 (UINT8)
HW_VERSION                	?= 1
# Attrib: 0x0004 (String - 32 bytes max)
MANUFACTURER_NAME         	?= NXP
# Attrib: 0x0005 (String - 32 bytes max)
MODEL_ID                  	?= DIMMER_SW
# Attrib: 0x0006 (String - 16 bytes max)
DATE_CODE                 	?= 10-31-2014

# Set the following variable to one to enable OTA client functionality on 
# this device. In addition to changing this macro the OTA output cluster must
# be added/removed on the ZigBee configuration diagram in order to enable
# and disable this functionality. Note that Further OTA settings can be
# found in zcl_options.h
#OTA                       	?= 1


##############################################################################
# Create definitions for use in the source code. 
# YOU SHOULD NOT NEED TO EDIT BELOW THIS LINE...
CFLAGS += -DCONFIG_MANUFACTURER_CODE=$(MANUFACTURER_CODE)
CFLAGS += -DCONFIG_APP_SW_VERSION=$(APP_SW_VERSION)				
CFLAGS += -DCONFIG_HW_VERSION=$(HW_VERSION)						
CFLAGS += -DCONFIG_MANUFACTURER_NAME=\"$(MANUFACTURER_NAME)\"
CFLAGS += -DCONFIG_MODEL_ID=\"$(MODEL_ID)\"				
CFLAGS += -DCONFIG_DATE_CODE=\"$(DATE_CODE)\"		
#CFLAGS += -DCONFIG_OTA=$(OTA)

##############################################################################
