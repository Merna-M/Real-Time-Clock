#ifndef _SEVEN_SEGMENT_H
#define _SEVEN_SEGMENT_H

/*################################## Macros ####################################*/
#define ENABLE_MUX	1
#define DISABLE_MUX	0


/*################################## Includes ###################################*/
#include "SEVSEG_config.h"
#include "STD_types.h"
#include "DIO_interface.h"


/* ################################### prototypes ####################################*/

/*
FUNCTION NAME        : SEVSEG_vInit
FUNCTION DESCRIPTION : used to set the direction of the seven segment port to output
FUNCTION INPUTS      : Copy_u8Port: selected port
FUNCTION RETURN      : void
*/
void SEVSEG_vInit (uint8 Copy_u8Port);

/*
FUNCTION NAME        : SEVSEG_vWrite
FUNCTION DESCRIPTION : used to write a number to the seven segment
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Value: value to be displayed
FUNCTION RETURN      : void
*/
void SEVSEG_vWrite (uint8 Copy_u8Port , uint8 Copy_u8Value);

/*
FUNCTION NAME        : SEVSEG_vEnableInit
FUNCTION DESCRIPTION : Enables the control pins in case of using multiplexed seven segments
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
FUNCTION RETURN      : void
*/
void SEVSEG_vEnableInit(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : SEVSEG_vEnableControl
FUNCTION DESCRIPTION : Enables or disables the seven segment to display the number
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin , Copy_u8EnableBit: enable control bit
FUNCTION RETURN      : void
*/
void SEVSEG_vEnableControl(uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8EnableBit);

#endif