############################################################################
# apps/netutils/homekit/Makefile
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
############################################################################

include $(APPDIR)/Make.defs

CSRCS += \
  HomeKitADK/External/Base64/util_base64.c \
  HomeKitADK/External/HTTP/util_http_reader.c \
  HomeKitADK/External/JSON/util_json_reader.c \
  HomeKitADK/HAP/HAPAccessory+Info.c \
  HomeKitADK/HAP/HAPAccessoryServer+Reset.c \
  HomeKitADK/HAP/HAPAccessoryServer.c \
  HomeKitADK/HAP/HAPAccessorySetup.c \
  HomeKitADK/HAP/HAPAccessorySetupInfo.c \
  HomeKitADK/HAP/HAPAccessoryValidation.c \
  HomeKitADK/HAP/HAPBitSet.c \
  HomeKitADK/HAP/HAPCharacteristic.c \
  HomeKitADK/HAP/HAPCharacteristicTypes.c \
  HomeKitADK/HAP/HAPDeviceID.c \
  HomeKitADK/HAP/HAPIP+ByteBuffer.c \
  HomeKitADK/HAP/HAPIPAccessory.c \
  HomeKitADK/HAP/HAPIPAccessoryProtocol.c \
  HomeKitADK/HAP/HAPIPAccessoryServer.c \
  HomeKitADK/HAP/HAPIPCharacteristic.c \
  HomeKitADK/HAP/HAPIPSecurityProtocol.c \
  HomeKitADK/HAP/HAPIPServiceDiscovery.c \
  HomeKitADK/HAP/HAPJSONUtils.c \
  HomeKitADK/HAP/HAPLegacyImport.c \
  HomeKitADK/HAP/HAPMACAddress.c \
  HomeKitADK/HAP/HAPMFiHWAuth.c \
  HomeKitADK/HAP/HAPMFiTokenAuth.c \
  HomeKitADK/HAP/HAPPDU.c \
  HomeKitADK/HAP/HAPPairing.c \
  HomeKitADK/HAP/HAPPairingBLESessionCache.c \
  HomeKitADK/HAP/HAPPairingPairSetup.c \
  HomeKitADK/HAP/HAPPairingPairVerify.c \
  HomeKitADK/HAP/HAPPairingPairings.c \
  HomeKitADK/HAP/HAPRequestHandlers+AccessoryInformation.c \
  HomeKitADK/HAP/HAPRequestHandlers+HAPProtocolInformation.c \
  HomeKitADK/HAP/HAPRequestHandlers+Pairing.c \
  HomeKitADK/HAP/HAPRequestHandlers.c \
  HomeKitADK/HAP/HAPServiceTypes.c \
  HomeKitADK/HAP/HAPSession.c \
  HomeKitADK/HAP/HAPStringBuilder.c \
  HomeKitADK/HAP/HAPTLV.c \
  HomeKitADK/HAP/HAPTLVMemory.c \
  HomeKitADK/HAP/HAPTLVReader.c \
  HomeKitADK/HAP/HAPTLVWriter.c \
  HomeKitADK/HAP/HAPUUID.c \
  HomeKitADK/HAP/HAPVersion.c \
  HomeKitADK/PAL/HAPAssert.c \
  HomeKitADK/PAL/HAPBase+Crypto.c \
  HomeKitADK/PAL/HAPBase+Double.c \
  HomeKitADK/PAL/HAPBase+Float.c \
  HomeKitADK/PAL/HAPBase+Int.c \
  HomeKitADK/PAL/HAPBase+MACAddress.c \
  HomeKitADK/PAL/HAPBase+RawBuffer.c \
  HomeKitADK/PAL/HAPBase+Sha1Checksum.c \
  HomeKitADK/PAL/HAPBase+String.c \
  HomeKitADK/PAL/HAPBase+UTF8.c \
  HomeKitADK/PAL/HAPLog.c \
  HomeKitADK/PAL/HAPPlatformSystemInit.c \
  HomeKitADK/PAL/Crypto/MbedTLS/HAPMbedTLS.c \
  HomeKitADK/PAL/POSIX/HAPPlatform.c \
  HomeKitADK/PAL/POSIX/HAPPlatformAbort.c \
  HomeKitADK/PAL/POSIX/HAPPlatformAccessorySetup.c \
  HomeKitADK/PAL/POSIX/HAPPlatformAccessorySetupDisplay.c \
  HomeKitADK/PAL/POSIX/HAPPlatformAccessorySetupNFC.c \
  HomeKitADK/PAL/POSIX/HAPPlatformClock.c \
  HomeKitADK/PAL/POSIX/HAPPlatformFileManager.c \
  HomeKitADK/PAL/POSIX/HAPPlatformKeyValueStore.c \
  HomeKitADK/PAL/POSIX/HAPPlatformLog.c \
  HomeKitADK/PAL/POSIX/HAPPlatformMFiHWAuth.c \
  HomeKitADK/PAL/POSIX/HAPPlatformMFiTokenAuth.c \
  HomeKitADK/PAL/POSIX/HAPPlatformRandomNumber.c \
  HomeKitADK/PAL/POSIX/HAPPlatformRunLoop.c \
  HomeKitADK/PAL/POSIX/HAPPlatformServiceDiscovery.c \
  HomeKitADK/PAL/POSIX/HAPPlatformSystemCommand.c \
  HomeKitADK/PAL/POSIX/HAPPlatformTCPStreamManager.c \

include $(APPDIR)/Application.mk
