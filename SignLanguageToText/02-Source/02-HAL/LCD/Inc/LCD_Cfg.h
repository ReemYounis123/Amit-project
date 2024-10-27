/*
 * LCD_Cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#ifndef _LCD_CFG_H_
#define _LCD_CFG_H_

#define LCD_Mask 0X0F //For safety

#define NO_CUSTOM_CHAR        (8)
#define NO_CUSTOM_CHAR_BYTES  (8)

/*#define LCD_PORT_Dataln      DIO_PORTA
#define LCD_PIN_Dataln0      DIO_PIN4
#define LCD_PIN_Dataln1      DIO_PIN5
#define LCD_PIN_Dataln2      DIO_PIN6
#define LCD_PIN_Dataln3      DIO_PIN7*/
#define LCD_PORT_Dataln      DIO_PORTC
#define LCD_PIN_Dataln0      DIO_PIN0
#define LCD_PIN_Dataln1      DIO_PIN1
#define LCD_PIN_Dataln2      DIO_PIN2
#define LCD_PIN_Dataln3      DIO_PIN3

#define LCD_PORT_Controlln   DIO_PORTB
#define LCD_PIN_RS           DIO_PIN1
#define LCD_PIN_RW           DIO_PIN2
#define LCD_PIN_EN           DIO_PIN3

#endif /* 02_SOURCE_02_HAL_LCD_INC_LCD_CFG_H_ */
