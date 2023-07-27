
#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

/* ################################## Macros ###############################################*/

/*  Pins IDs  */
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

/*  Pin Direction IDs  */
#define PIN_OUTPUT	1
#define PIN_INPUT	0	

/*  Port Direction IDs  */
#define PORT_OUTPUT	0xFF
#define PORT_INPUT	0x00

/* PullUp */
#define PULLUP_ON	1
#define PULLUP_OFF	0

/*  Other Macros  */
#define HIGH	1
#define LOW		0


/*################################################### Prototypes ##############################################################*/

/*
FUNCTION NAME        : DIO_vSetPinDir
FUNCTION DESCRIPTION : This function is used to determine the direction of a pin whether it's input or output
FUNCTION INPUTS		 : Copy_u8Port: selected port , Copy_u8Pin: selected pin , Copy_u8Dir:direction (1 for output and 0 for input)
*/
void DIO_vSetPinDir (uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8Dir);

/*
FUNCTION NAME        : DIO_vWritePin
FUNCTION DESCRIPTION : This function is used to write a zero or a one on an output pin
FUNCTION INPUTS		 : Copy_u8Port: selected port , Copy_u8Pin: selected pin , Copy_u8Value: value written 
*/
void DIO_vWritePin (uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8Value);

/*
FUNCTION NAME        : DIO_vTogglePin
FUNCTION DESCRIPTION : This function is used to toggle the current bit in an output pin (change 1 to 0 and 0 to 1)
FUNCTION INPUTS		 : Copy_u8Port: selected port , Copy_u8Pin: selected pin 
*/
void DIO_vTogglePin (uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : DIO_u8ReadPin
FUNCTION DESCRIPTION : This function is used to get the value of an input pin 
FUNCTION INPUTS		 : Copy_u8Port: selected port , Copy_u8Pin: selected pin 
FUNCTION RETURN		 : returns the value of a pin from PIN register of the selected port
*/
uint8 DIO_u8ReadPin (uint8 Copy_u8Port , uint8 Copy_u8Pin);


/*
FUNCTION NAME        : DIO_vSetPortDir
FUNCTION DESCRIPTION : This function is used to determine the direction of the whole port whether it's input or output
FUNCTION INPUTS		 : Copy_u8Port: selected port , Copy_u8Dir:direction (1 for output and 0 for input)
*/
void DIO_vSetPortDir (uint8 Copy_u8Port , uint8 Copy_u8Dir);

/*
FUNCTION NAME        : DIO_vWritePort
FUNCTION DESCRIPTION : This function is used to write a certain value on an output port
FUNCTION INPUTS		 : Copy_u8Port: selected port , Copy_u8Value: value written 
*/
void DIO_vWritePort (uint8 Copy_u8Port , uint8 Copy_u8Value);

/*
FUNCTION NAME        : DIO_vTogglePort
FUNCTION DESCRIPTION : This function is used to toggle each bit in an output port (change 1 to 0 and 0 to 1)
FUNCTION INPUTS		 : Copy_u8Port: selected port
*/
void DIO_vTogglePort (uint8 Copy_u8Port);

/*
FUNCTION NAME        : DIO_u8ReadPort
FUNCTION DESCRIPTION : This function is used to get the value of an input port
FUNCTION INPUTS		 : Copy_u8Port: selected port
FUNCTION RETURN		 : returns the value of PIN register of the selected port
*/
uint8 DIO_u8ReadPort(uint8 Copy_u8Port);

/*
FUNCTION NAME        : DIO_vConnectPullUp
FUNCTION DESCRIPTION : This function is enable or disable the Pull up of a pin
FUNCTION INPUTS		 : Copy_u8Port: selected port , Copy_u8Pin: selected pin , Copy_u8PullUpCheck: condition (1 if pullup enabled , 0 if pullup disabled)
FUNCTION RETURN		 : void
*/
void DIO_vConnectPullUp (uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8PullUpCheck);



#endif 