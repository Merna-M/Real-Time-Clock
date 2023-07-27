
#ifndef _LED_INTERFACE_H
#define _LED_INTERFACE_H

/*############################### prototypes ################################ */

/*
FUNCTION NAME        : LED_vInit
FUNCTION DESCRIPTION : Set direction of the pin of the LED to make it output
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
*/
void LED_vInit(uint8 Copy_u8Port,uint8 Copy_u8Pin);

/*
FUNCTION NAME        : LED_vSwitchON
FUNCTION DESCRIPTION : write 1 to the selected pin to switch the led on
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
*/
void LED_vSwitchON(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : LED_vSwitchOFF
FUNCTION DESCRIPTION : write 0 to the selected pin to switch the led off
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
*/
void LED_vSwitchOFF(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : LED_vToggle
FUNCTION DESCRIPTION : change the current status of the led (from ON to OFF and from OFF to ON)
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
*/
void LED_vToggle(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : LED_vReadStatus
FUNCTION DESCRIPTION : Read the current status of the led whether it's ON or OFF
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
FUNCTION RETURN      : returns 1 if the LED is ON and 0 if it's OFF
*/
uint8 LED_vReadStatus (uint8 Copy_u8Port , uint8 Copy_u8Pin);



#endif 