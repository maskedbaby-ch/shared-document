################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/croutine.c \
../freertos/event_groups.c \
../freertos/fsl_tickless_lptmr.c \
../freertos/fsl_tickless_systick.c \
../freertos/heap_4.c \
../freertos/list.c \
../freertos/port.c \
../freertos/queue.c \
../freertos/tasks.c \
../freertos/timers.c 

OBJS += \
./freertos/croutine.o \
./freertos/event_groups.o \
./freertos/fsl_tickless_lptmr.o \
./freertos/fsl_tickless_systick.o \
./freertos/heap_4.o \
./freertos/list.o \
./freertos/port.o \
./freertos/queue.o \
./freertos/tasks.o \
./freertos/timers.o 

C_DEPS += \
./freertos/croutine.d \
./freertos/event_groups.d \
./freertos/fsl_tickless_lptmr.d \
./freertos/fsl_tickless_systick.d \
./freertos/heap_4.d \
./freertos/list.d \
./freertos/port.d \
./freertos/queue.d \
./freertos/tasks.d \
./freertos/timers.d 


# Each subdirectory must supply rules for building sources it contributes
freertos/%.o: ../freertos/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW36Z512VHT4 -DCPU_MKW36Z512VHT4_cm0plus -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW36 -DFREEDOM -DSDK_OS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DCARD_EMU_SUPPORT -DRW_SUPPORT -DP2P_SUPPORT -DCARDEMU_SUPPORT -DCR_INTEGER_PRINTF -DRW_NDEF_WRITING -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\board" -I../../.. -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\src" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NxpNci\inc" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\TML" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source\tool" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\source" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\CMSIS" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\drivers" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\utilities" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\freertos" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\startup" -I"C:\nxp\Workspace\frdmkw36_rtos_examples_freertos_i2c\NfcLibrary\NdefLibrary\src" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


