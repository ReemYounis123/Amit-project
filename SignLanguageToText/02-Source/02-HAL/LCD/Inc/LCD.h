/*
 * LCD.h
 *
 *      Author: Reem Younis
 */
#include"Dio.h"
#include"LCD_Cfg.h"
#include"LCD_Types.h"
#include <util/delay.h>

#ifndef _LCD_H_
#define _LCD_H_



void Lcd_Init(void);
void Lcd_Cmd(Lcd_Cmd_types cmd);
void Lcd_DisplayNUM(u16 num);
void Lcd_DisplayChr(u8 chr);
void Lcd_DisplayStr(u8* str);
void Lcd_Clear_Display(void);
void Lcd_Goto_Row_Column(u8 row, u8 col);

#endif /* 02_SOURCE_02_HAL_LCD_INC_LCD_H_ */
