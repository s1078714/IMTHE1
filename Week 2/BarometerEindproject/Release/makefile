################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include uart/subdir.mk
-include i2chw/subdir.mk
-include bmp085/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
BarometerEindproject.lss \

FLASH_IMAGE += \
BarometerEindproject.hex \

EEPROM_IMAGE += \
BarometerEindproject.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: BarometerEindproject.elf secondary-outputs

# Tool invocations
BarometerEindproject.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,BarometerEindproject.map -mmcu=atmega328p -o "BarometerEindproject.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

BarometerEindproject.lss: BarometerEindproject.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S BarometerEindproject.elf  >"BarometerEindproject.lss"
	@echo 'Finished building: $@'
	@echo ' '

BarometerEindproject.hex: BarometerEindproject.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex BarometerEindproject.elf  "BarometerEindproject.hex"
	@echo 'Finished building: $@'
	@echo ' '

BarometerEindproject.eep: BarometerEindproject.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex BarometerEindproject.elf  "BarometerEindproject.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: BarometerEindproject.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p BarometerEindproject.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) BarometerEindproject.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
