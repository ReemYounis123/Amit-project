################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 02-Source/04-Application/subdir.mk
-include 02-Source/02-HAL/LED/Src/subdir.mk
-include 02-Source/02-HAL/LCD/Src/subdir.mk
-include 02-Source/02-HAL/Eeprom24C16/Src/subdir.mk
-include 02-Source/02-HAL/BUZZER/Src/subdir.mk
-include 02-Source/01-MCAL/UART/Src/subdir.mk
-include 02-Source/01-MCAL/Interrupt/Global\ interrupt/Src/subdir.mk
-include 02-Source/01-MCAL/Interrupt/EXT_INT/Scr/subdir.mk
-include 02-Source/01-MCAL/I2C/Src/subdir.mk
-include 02-Source/01-MCAL/EEPROM/Src/subdir.mk
-include 02-Source/01-MCAL/DIO/Src/subdir.mk
-include 02-Source/01-MCAL/ADC/Src/subdir.mk
-include 02-Source/00-Library/Scr/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SignLanguageToText
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SignLanguageToText.lss \

FLASH_IMAGE += \
SignLanguageToText.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: SignLanguageToText.elf secondary-outputs

# Tool invocations
SignLanguageToText.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SignLanguageToText.map -mmcu=atmega32 -o "SignLanguageToText.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SignLanguageToText.lss: SignLanguageToText.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SignLanguageToText.elf  >"SignLanguageToText.lss"
	@echo 'Finished building: $@'
	@echo ' '

SignLanguageToText.hex: SignLanguageToText.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SignLanguageToText.elf  "SignLanguageToText.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SignLanguageToText.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SignLanguageToText.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SignLanguageToText.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
