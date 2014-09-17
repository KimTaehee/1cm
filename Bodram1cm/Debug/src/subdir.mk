################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AppResourceId.cpp \
../src/FormFactory.cpp \
../src/ImagePanel.cpp \
../src/LockApp.cpp \
../src/LockForm.cpp \
../src/LockFrame.cpp \
../src/MainForm.cpp \
../src/MyCardForm.cpp \
../src/MyCardManager.cpp \
../src/NfcController.cpp \
../src/NfcP2pBump.cpp \
../src/NfcP2pBumpEntry.cpp \
../src/VcardTranslator.cpp 

OBJS += \
./src/AppResourceId.o \
./src/FormFactory.o \
./src/ImagePanel.o \
./src/LockApp.o \
./src/LockForm.o \
./src/LockFrame.o \
./src/MainForm.o \
./src/MyCardForm.o \
./src/MyCardManager.o \
./src/NfcController.o \
./src/NfcP2pBump.o \
./src/NfcP2pBumpEntry.o \
./src/VcardTranslator.o 

CPP_DEPS += \
./src/AppResourceId.d \
./src/FormFactory.d \
./src/ImagePanel.d \
./src/LockApp.d \
./src/LockForm.d \
./src/LockFrame.d \
./src/MainForm.d \
./src/MyCardForm.d \
./src/MyCardManager.d \
./src/NfcController.d \
./src/NfcP2pBump.d \
./src/NfcP2pBumpEntry.d \
./src/VcardTranslator.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	clang++.exe -I"pch" -D_DEBUG -I"D:\development\tizen\Bodram1cm\inc" -O0 -g3 -Wall -c -fmessage-length=0 -target arm-tizen-linux-gnueabi -gcc-toolchain "C:/tizen-sdk/tools/smart-build-interface/../arm-linux-gnueabi-gcc-4.5/" -ccc-gcc-name arm-linux-gnueabi-g++ -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mtune=cortex-a8 -Wno-gnu -fPIE --sysroot="C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include/libxml2" -I"C:\tizen-sdk\library" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include/osp" -D_APP_LOG -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


