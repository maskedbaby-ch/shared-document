################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NfcLibrary/NdefLibrary/src/P2P_NDEF.c \
../NfcLibrary/NdefLibrary/src/RW_NDEF.c \
../NfcLibrary/NdefLibrary/src/RW_NDEF_MIFARE.c \
../NfcLibrary/NdefLibrary/src/RW_NDEF_T1T.c \
../NfcLibrary/NdefLibrary/src/RW_NDEF_T2T.c \
../NfcLibrary/NdefLibrary/src/RW_NDEF_T3T.c \
../NfcLibrary/NdefLibrary/src/RW_NDEF_T4T.c \
../NfcLibrary/NdefLibrary/src/RW_NDEF_T5T.c \
../NfcLibrary/NdefLibrary/src/T4T_NDEF_emu.c 

OBJS += \
./src/P2P_NDEF.o \
./src/RW_NDEF.o \
./src/RW_NDEF_MIFARE.o \
./src/RW_NDEF_T1T.o \
./src/RW_NDEF_T2T.o \
./src/RW_NDEF_T3T.o \
./src/RW_NDEF_T4T.o \
./src/RW_NDEF_T5T.o \
./src/T4T_NDEF_emu.o 

C_DEPS += \
./src/P2P_NDEF.d \
./src/RW_NDEF.d \
./src/RW_NDEF_MIFARE.d \
./src/RW_NDEF_T1T.d \
./src/RW_NDEF_T2T.d \
./src/RW_NDEF_T3T.d \
./src/RW_NDEF_T4T.d \
./src/RW_NDEF_T5T.d \
./src/T4T_NDEF_emu.d 


# Each subdirectory must supply rules for building sources it contributes
src/P2P_NDEF.o: C:/nxp/Workspace/frdmkw36_rtos_examples_freertos_i2c/NfcLibrary/NdefLibrary/src/P2P_NDEF.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RW_NDEF.o: C:/nxp/Workspace/frdmkw36_rtos_examples_freertos_i2c/NfcLibrary/NdefLibrary/src/RW_NDEF.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RW_NDEF_MIFARE.o: C:/nxp/Workspace/frdmkw36_rtos_examples_freertos_i2c/NfcLibrary/NdefLibrary/src/RW_NDEF_MIFARE.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RW_NDEF_T1T.o: C:/nxp/Workspace/frdmkw36_rtos_examples_freertos_i2c/NfcLibrary/NdefLibrary/src/RW_NDEF_T1T.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RW_NDEF_T2T.o: C:/nxp/Workspace/frdmkw36_rtos_examples_freertos_i2c/NfcLibrary/NdefLibrary/src/RW_NDEF_T2T.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RW_NDEF_T3T.o: C:/nxp/Workspace/frdmkw36_rtos_examples_freertos_i2c/NfcLibrary/NdefLibrary/src/RW_NDEF_T3T.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RW_NDEF_T4T.o: C:/nxp/Workspace/frdmkw36_rtos_examples_freertos_i2c/NfcLibrary/NdefLibrary/src/RW_NDEF_T4T.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RW_NDEF_T5T.o: C:/nxp/Workspace/frdmkw36_rtos_examples_freertos_i2c/NfcLibrary/NdefLibrary/src/RW_NDEF_T5T.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/T4T_NDEF_emu.o: C:/nxp/Workspace/frdmkw36_rtos_examples_freertos_i2c/NfcLibrary/NdefLibrary/src/T4T_NDEF_emu.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


