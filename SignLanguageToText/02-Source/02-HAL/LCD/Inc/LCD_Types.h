/*
 * Lcd_types.h
 *
 *  Created on: ??�/??�/????
 *      Author: El-Wattaneya
 */

#ifndef _LCD_TYPES_H_
#define _LCD_TYPES_H_

//LCD COMMANDS from datasheet
typedef enum{
 _LCD_CLEAR = 0x01,
 _LCD_CURSOR_OFF = 0x0C,
 _LCD_CURSOR_ON = 0x0F,
 _LCD_4BIT_MODE = 0x28,
 _LCD_8BIT_MODE= 0x38,
 _LCD_ON = 0x0F,
 _LCD_CURSOR_UNDERLINE = 0x0E,
 _LCD_CURSOR_SHIFT_LEFT = 0x10,
 _LCD_CURSOR_SHIFT_RIGHT = 0x14,
 _LCD_CURSOR_INCREMENT = 0x06,
 _LCD_CGRAM_START_ADDRESS = 0x40
}Lcd_Cmd_types;

#endif /* 02_SOURCE_02_HAL_LCD_INC_LCD_TYPES_H_ */
