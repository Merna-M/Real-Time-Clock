
#ifndef _TMR2_INTERFACE_H_
#define _TMR2_INTERFACE_H_

/*########################## Macros ###############################*/
/* TCCR2 Register */
#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21	5
#define WGM20	6
#define FOC2	7

/* TIMSK Register */
#define TOIE2	6
#define OCIE2	7

/* TIFR Register */
#define TOV2	6
#define OCF2	7

/* ASSR Register */
#define AS2		3


/*########################### Includes ############################## */
#include "STD_types.h"
#include "BIT_math.h"
#include "TMR2_private.h"
#include "TMR2_config.h"
#include "GIE_interface.h"
#include "DIO_interface.h"

/*################################ prototypes #################################*/

/*
FUNCTION NAME	     : TMR1_vInit
FUNCTION DESCRIPTION : initializes the timer according to the chosen mode
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
void TMR2_vInit(void);

/*
FUNCTION NAME	     : TMR2_OVF_SetCallBack
FUNCTION DESCRIPTION : returns the address of ISR function to the TMR.c file when an overflow occurs
FUNCTION INPUTS      : void pointer to function (address of the ISR function in the main file)
FUNCTION RETURN      : void
*/
void TMR2_OVF_SetCallBack(void(*ptr)(void));

/*
FUNCTION NAME	     : TMR2_COMP_SetCallBack
FUNCTION DESCRIPTION : returns the address of ISR function to the TMR.c file when a compare match occurs
FUNCTION INPUTS      : void pointer to function (address of the ISR function in the main file)
FUNCTION RETURN      : void
*/
void TMR2_COMP_SetCallBack(void(*ptr)(void));


#endif 