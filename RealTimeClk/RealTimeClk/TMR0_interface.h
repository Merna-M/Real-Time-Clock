
#ifndef _TMR0_INTERFACE_H_
#define _TMR0_INTERFACE_H_

/*########################## Macros ###############################*/
/* TCCR0 Register */
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7

/* TIMSK Register */
#define TOIE0	0
#define OCIE0	1

/* TIFR Register */
#define TOV0	0
#define OCF0	1

/*########################### Includes ############################## */
#include "STD_types.h"
#include "BIT_math.h"
#include "TMR0_private.h"
#include "TMR0_config.h"
#include "GIE_interface.h"
#include "DIO_interface.h"

/*############################ Prototypes ############################*/

/*
FUNCTION NAME	     : TMR0_vInit
FUNCTION DESCRIPTION : initializes the timer according to the chosen mode
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
void TMR0_vInit(void);

/*
FUNCTION NAME	     : TMR0_OVF_SetCallBack
FUNCTION DESCRIPTION : returns the address of ISR function to the TMR.c file when an overflow occurs
FUNCTION INPUTS      : void pointer to function (address of the ISR function in the main file)
FUNCTION RETURN      : void
*/
void TMR0_OVF_SetCallBack(void(*ptr)(void));

/*
FUNCTION NAME	     : TMR0_COMP_SetCallBack
FUNCTION DESCRIPTION : returns the address of ISR function to the TMR.c file when a compare match occurs
FUNCTION INPUTS      : void pointer to function (address of the ISR function in the main file)
FUNCTION RETURN      : void
*/
void TMR0_COMP_SetCallBack(void(*ptr)(void));

#endif 