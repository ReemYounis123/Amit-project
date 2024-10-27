################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../02-Source/02-HAL/Eeprom24C16/Src/\ Eeprom24C16.c 

OBJS += \
./02-Source/02-HAL/Eeprom24C16/Src/\ Eeprom24C16.o 

C_DEPS += \
./02-Source/02-HAL/Eeprom24C16/Src/\ Eeprom24C16.d 


# Each subdirectory must supply rules for building sources it contributes
02-Source/02-HAL/Eeprom24C16/Src/\ Eeprom24C16.o: ../02-Source/02-HAL/Eeprom24C16/Src/\ Eeprom24C16.c 02-Source/02-HAL/Eeprom24C16/Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\02-HAL\Eeprom24C16\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\01-MCAL\EEPROM\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\01-MCAL\I2C\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\00-Library\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\02-HAL\BUZZER\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\02-HAL\LCD\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\02-HAL\LED\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\01-MCAL\ADC\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\01-MCAL\DIO\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\01-MCAL\Interrupt\EXT_INT\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\01-MCAL\Interrupt\Global interrupt\Inc" -I"C:\Users\El-Wattaneya\eclipse-workspace\SignLanguageToText\02-Source\01-MCAL\UART\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"02-Source/02-HAL/Eeprom24C16/Src/ Eeprom24C16.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


