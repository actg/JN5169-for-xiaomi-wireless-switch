###############################################################################
#
# MODULE:   Config_MAC.mk
#
# DESCRIPTION: MAC stack configuration
# defines tool, library and header file details
#
############################################################################
#
# This software is owned by NXP B.V. and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on NXP products [NXP Microcontrollers such as JN5148, JN5142, JN5139]. 
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
# Copyright NXP B.V. 2012. All rights reserved
#
############################################################################


###############################################################################
# ROM based software components

INCFLAGS += -I$(COMPONENTS_BASE_DIR)/MAC/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/TimerServer/Include
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/PDM/Include
ifeq ($(JENNIC_CHIP_FAMILY), JN514x)	
INCFLAGS += -I$(COMPONENTS_BASE_DIR)/Random/Include
endif

###############################################################################
# RAM based software components

ifeq ($(JENNIC_CHIP_FAMILY), JN514x)	
APPLIBS +=DBG
APPLIBS +=AES_SW
APPLIBS +=PDM
endif
ifeq ($(JENNIC_CHIP_FAMILY), JN513x)	
APPLIBS +=Random
endif

INCFLAGS += $(addsuffix /Include,$(addprefix -I$(COMPONENTS_BASE_DIR)/,$(APPLIBS)))

ifeq ($(TRACE), 1)
CFLAGS  += -DDBG_ENABLE
LDLIBS += DBG_$(JENNIC_CHIP_FAMILY)
$(info Building trace version ...)
endif

###############################################################################
