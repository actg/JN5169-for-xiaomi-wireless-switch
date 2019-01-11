# ####################################################################################################
#
# MODULE:      JN-AN-1189 ZigBee HA Demo
#
# DESCRIPTION: Batch file to build OTA client binary file
#
# ####################################################################################################
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
# ####################################################################################################

# $1 target name
# $2 Manufacturer id
# $3 software version
# $4 Chip type

# Change the path to the OTA Build folder.
cd "..\..\..\DimmableLightOpenHome\Build\OTABuild"

# ####################################################################################################:
# ####################################Build Encrpted Client Binary##################################################:

# Add serialisation Data with ImageType = 0x1XXX - Indicates it is for Encrpted devices
../../../../../SDK/JN-SW-4168/Tools/OTAUtils/JET.exe -m combine -f $1.bin -x configOTA_6x_Cer_Keys_HA_Light.txt -v JN516x -g 1 -k 0xffffffffffffffffffffffffffffffff -u $2 -t 0x9101 -j DR1175r1v1--ENCRYPTED0OPN0$4

# Creat an Unencrpted Bootable Client with Veriosn as input
../../../../../SDK/JN-SW-4168/Tools/OTAUtils/JET.exe -m otamerge --embed_hdr -c outputffffffffffffffff.bin -o Client.bin -v JN516x -n $3 -u $2 -t 0x9101 -j DR1175r1v1--ENCRYPTED0OPN0$4

# Creat an Encrypted Image from the Bootable UnEncrpted Client - This must be copied to Ext Flash and then erase internal Flash
../../../../../SDK/JN-SW-4168/Tools/OTAUtils/JET.exe -m bin -f Client.bin -e $1_Client_v$3_Enc.bin -k 0xffffffffffffffffffffffffffffffff -i 0x00000000000000000000000000000000 -v JN516x -j DR1175r1v1--ENCRYPTED0OPN0$4

# ###################Build OTA Encrypted Upgarde Image from the Unencrypted Bootable Client Image #########################:
# Modify Embedded Header to reflect version 2 
../../../../../SDK/JN-SW-4168/Tools/OTAUtils/JET.exe -m otamerge --embed_hdr -c Client.bin -o $1_v$3_tmp.bin -v JN516x -n $3 -u $2 -t 0x9101 -j DR1175r1v1--ENCRYPTED0OPN0$4

# Now Encrypt the above Version 2  
../../../../../SDK/JN-SW-4168/Tools/OTAUtils/JET.exe -m bin -f $1_v$3_tmp.bin -e $1_v$3_tmp_Enc.bin -v JN516x -k ffffffffffffffffffffffffffffffff -i 0x00000000000000000000000000000000 -j DR1175r1v1--ENCRYPTED0OPN0$4

# Wrap the Image with OTA header with version 2
../../../../../SDK/JN-SW-4168/Tools/OTAUtils/JET.exe -m otamerge --ota -c $1_v$3_tmp_Enc.bin -o $1_v$3_Enc.bin -v JN516x -n $3 -u $2 -t 0x9101 -j DR1175r1v1--ENCRYPTED0OPN0$4

../../../../../SDK/JN-SW-4168/Tools/OTAUtils/JET.exe -m otamerge --ota -c $1_v$3_tmp_Enc.bin -o $1_v$3_Enc.ota -p 1 -v JN516x -n $3 -u $2 -t 0x9101 -j DR1175r1v1--ENCRYPTED0OPN0$4

# ####################################################################################################:
# #################################### Clean Up Imtermediate files##################################################:

rm $1.bin 
rm output*.bin
rm $1_v$3_tmp.bin
rm $1_v$3_tmp_Enc.bin
mv Client.bin $1_Client_v$3_Enc.bin

