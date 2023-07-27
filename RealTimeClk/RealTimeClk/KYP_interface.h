
#ifndef _KYP_INTERFACE_H_
#define _KYP_INTERFACE_H_

/* ##################### Macros #########################*/
#define KYP_ROW1_PIN	0
#define KYP_ROW2_PIN	1
#define KYP_ROW3_PIN	2
#define KYP_ROW4_PIN	3
#define KYP_COL1_PIN	4
#define KYP_COL2_PIN	5
#define KYP_COL3_PIN	6
#define KYP_COL4_PIN	7

#define NOT_PRESSED		0xFF

/* ##################### Includes #######################*/
#include "STD_types.h"
#include "DIO_interface.h"
#include "KYP_config.h"

/* ##################### prototypes ###########################*/

/*
FUNCTION NAME        : KYP_vInit
FUNCTION DESCRIPTION : Initialize the keypad by setting the port direction, connecting pull up, and writing the initial values 
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
void KYP_vInit(void);

/*
FUNCTION NAME        : KYP_u8CheckPress
FUNCTION DESCRIPTION : checks if any switch is pressed by returning its ascii value or not by returning 0xFF
FUNCTION INPUTS      : void
FUNCTION RETURN      : returns ascii of the value pressed or 0xFF if nothing is pressed
*/
uint8 KYP_u8CheckPress(void);


#endif