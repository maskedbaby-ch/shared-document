################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_adc16.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_dmamux.c \
../drivers/fsl_edma.c \
../drivers/fsl_flash.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lptmr.c \
../drivers/fsl_sim.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c \
../drivers/fsl_uart_edma.c 

OBJS += \
./drivers/fsl_adc16.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_dmamux.o \
./drivers/fsl_edma.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lptmr.o \
./drivers/fsl_sim.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o \
./drivers/fsl_uart_edma.o 

C_DEPS += \
./drivers/fsl_adc16.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_dmamux.d \
./drivers/fsl_edma.d \
./drivers/fsl_flash.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lptmr.d \
./drivers/fsl_sim.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d \
./drivers/fsl_uart_edma.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCPU_MK64FN1M0VDC12 -DCPU_MK64FN1M0VDC12_cm4 -D__REDLIB__ -I"C:\Users\nxf56274\Documents\MCUXpressoIDE_11.2.0_4095_prc2\workspace\K64F_ADC_DMA_Demo.zip_expanded\K64F_ADC_DMA_Demo\source" -I"C:\Users\nxf56274\Documents\MCUXpressoIDE_11.2.0_4095_prc2\workspace\K64F_ADC_DMA_Demo.zip_expanded\K64F_ADC_DMA_Demo" -I"C:\Users\nxf56274\Documents\MCUXpressoIDE_11.2.0_4095_prc2\workspace\K64F_ADC_DMA_Demo.zip_expanded\K64F_ADC_DMA_Demo\frdmk64f" -I"C:\Users\nxf56274\Documents\MCUXpressoIDE_11.2.0_4095_prc2\workspace\K64F_ADC_DMA_Demo.zip_expanded\K64F_ADC_DMA_Demo\drivers" -I"C:\Users\nxf56274\Documents\MCUXpressoIDE_11.2.0_4095_prc2\workspace\K64F_ADC_DMA_Demo.zip_expanded\K64F_ADC_DMA_Demo\startup" -I"C:\Users\nxf56274\Documents\MCUXpressoIDE_11.2.0_4095_prc2\workspace\K64F_ADC_DMA_Demo.zip_expanded\K64F_ADC_DMA_Demo\utilities" -I"C:\Users\nxf56274\Documents\MCUXpressoIDE_11.2.0_4095_prc2\workspace\K64F_ADC_DMA_Demo.zip_expanded\K64F_ADC_DMA_Demo\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


