################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include frdmk64f/subdir.mk
-include drivers/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: K64F_ADC_DMA_Demo.axf

# Tool invocations
K64F_ADC_DMA_Demo.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="K64F_ADC_DMA_Demo.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -T K64F_ADC_DMA_Demo_Debug.ld -o "K64F_ADC_DMA_Demo.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) K64F_ADC_DMA_Demo.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "K64F_ADC_DMA_Demo.axf"; # arm-none-eabi-objcopy -v -O binary "K64F_ADC_DMA_Demo.axf" "K64F_ADC_DMA_Demo.bin" ; # checksum -p MK64FN1M0xxx12 -d "K64F_ADC_DMA_Demo.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
