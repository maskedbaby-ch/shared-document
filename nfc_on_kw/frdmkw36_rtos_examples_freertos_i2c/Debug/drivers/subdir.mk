################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_flash.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_i2c_freertos.c \
../drivers/fsl_lptmr.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_lpuart_freertos.c \
../drivers/fsl_smc.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_i2c_freertos.o \
./drivers/fsl_lptmr.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_lpuart_freertos.o \
./drivers/fsl_smc.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_flash.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_i2c_freertos.d \
./drivers/fsl_lptmr.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_lpuart_freertos.d \
./drivers/fsl_smc.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -DRW_NDEF_WRITING -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


