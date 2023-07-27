
#ifndef _TMR2_PRIVATE_H_
#define _TMR2_PRIVATE_H_

#define TCNT2	*((volatile uint8*)(0x44))
#define TCCR2	*((volatile uint8*)(0x45))
#define TIMSK	*((volatile uint8*)(0x59))
#define TIFR	*((volatile uint8*)(0x58))
#define OCR2	*((volatile uint8*)(0x43))
#define ASSR	*((volatile uint8*)(0x42))


#endif 