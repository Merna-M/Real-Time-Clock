#include "SEVSEG_interface.h"


void SEVSEG_vInit (uint8 Copy_u8Port)
{
	DIO_vSetPortDir(Copy_u8Port,0xFF); //all ones to make all the port output
}

void SEVSEG_vWrite (uint8 Copy_u8Port , uint8 Copy_u8Value)
{
	#ifdef COMCATHODE
	uint8 SEVSEG_arr[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; // all the 7 segment numbers in hex in the com cathode mode
	#else
	uint8 SEVSEG_arr[]={~0x3F,~0x06,~0x5B,~0x4F,~0x66,~0x6D,~0x7D,~0x07,~0x7F,~0x6F}; // all the 7 segment numbers in hex in the com anode mode
	#endif
	DIO_vWritePort(Copy_u8Port,SEVSEG_arr[Copy_u8Value]);
}

void SEVSEG_vEnableInit(uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	//set the pin as output
	DIO_vSetPinDir(Copy_u8Port,Copy_u8Pin,PIN_OUTPUT);
}


void SEVSEG_vEnableControl(uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8EnableBit)
{
	if(Copy_u8EnableBit == ENABLE_MUX)
	{
		DIO_vWritePin(Copy_u8Port,Copy_u8Pin,LOW); // clear the pin to work as ground
	}
	else if(Copy_u8EnableBit == DISABLE_MUX)
	{
		DIO_vWritePin(Copy_u8Port,Copy_u8Pin,HIGH);
	}
}
