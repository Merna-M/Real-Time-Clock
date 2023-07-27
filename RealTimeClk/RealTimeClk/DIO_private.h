/*
 * IncFile1.h
 *
 * Created: 9/22/2022 9:19:31 PM
 *  Author: MERNA
 */ 


#ifndef _DIO_PRIVATE_H
#define _DIO_PRIVATE_H

//macros for IO registers of portA 
#define DDRA *((volatile uint8*)(0x3A))
#define PORTA *((volatile uint8*)(0x3B))
#define PINA *((volatile uint8*)(0x39))

//macros for IO registers of portB 
#define DDRB *((volatile uint8*)(0x37))
#define PORTB *((volatile uint8*)(0x38))
#define PINB *((volatile uint8*)(0x36))

//macros for IO registers of portC
#define DDRC *((volatile uint8*)(0x34))
#define PORTC *((volatile uint8*)(0x35))
#define PINC *((volatile uint8*)(0x33))

//macros for IO registers of portD
#define DDRD *((volatile uint8*)(0x31))
#define PORTD *((volatile uint8*)(0x32))
#define PIND *((volatile uint8*)(0x30))

#endif 