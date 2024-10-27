/*
 * Dio_Types.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

/* User Defined Data Types */
typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}port_type;     /* MC Port ID */

typedef enum{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}pin_type;     /* MC Pin ID */ //output æáÇ input ãÔ pin ÑÞã Çá

typedef enum{
	INPUT,
	OUTPUT
}direction_type;

typedef enum{
	STD_LOW,
	STD_HIGH
}level_type;

#endif /* DIO_TYPES_H_ */
