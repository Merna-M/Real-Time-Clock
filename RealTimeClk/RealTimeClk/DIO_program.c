/*
 * CFile1.c
 *
 * Created: 9/20/2022 8:06:41 PM
 *  Author: MERNA
 */ 

#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_private.h"


void DIO_vSetPinDir (uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8Dir)
{
	//switch the selected port
	switch(Copy_u8Port) 
	{
		case 'A':
		case 'a':	//PortA
		if (Copy_u8Dir == 1)	//direction is output
		{
			SET_BIT(DDRA , Copy_u8Pin);
		}
		else                   //direction is input
		{
			CLR_BIT(DDRA , Copy_u8Pin);
		}
		break;
		
		case 'B':
		case 'b':	//PortB
		if (Copy_u8Dir == 1)
		{
			SET_BIT(DDRB , Copy_u8Pin);
		}
		else
		{
			CLR_BIT(DDRB , Copy_u8Pin);
		}
		break;
		
		case 'C':
		case 'c':	//PortC
		if (Copy_u8Dir == 1)
		{
			SET_BIT(DDRC , Copy_u8Pin);
		}
		else
		{
			CLR_BIT(DDRC , Copy_u8Pin);
		}
		break;
		
		case 'D':
		case 'd':	//PortD
		if (Copy_u8Dir == 1)
		{
			SET_BIT(DDRD , Copy_u8Pin);
		}
		else
		{
			CLR_BIT(DDRD , Copy_u8Pin);
		}
		break;
	}
}


void DIO_vWritePin (uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8Value)
{
	switch (Copy_u8Port)
	{
		case 'A':
		case 'a':	//PortA
		if (Copy_u8Value == 1)
		{
			SET_BIT(PORTA , Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTA , Copy_u8Pin);
		}
		break;
		
		case 'B':
		case 'b':	//PortB
		if (Copy_u8Value == 1)
		{
			SET_BIT(PORTB , Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTB , Copy_u8Pin);
		}
		break;
		
		case 'C':
		case 'c':	//PortC
		if (Copy_u8Value == 1)
		{
			SET_BIT(PORTC , Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTC , Copy_u8Pin);
		}
		break;
		
		case 'D':
		case 'd':	//PortD
		if (Copy_u8Value == 1)
		{
			SET_BIT(PORTD , Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTD , Copy_u8Pin);
		}
		break;
	}
}


void DIO_vTogglePin (uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
		case 'A':
		case 'a':
		TOGGLE_BIT(PORTA , Copy_u8Pin);
		break;
		
		case 'B':
		case 'b':
		TOGGLE_BIT(PORTB , Copy_u8Pin);
		break;
		
		case 'C':
		case 'c':
		TOGGLE_BIT(PORTC , Copy_u8Pin);
		break;
		
		case 'D':
		case 'd':
		TOGGLE_BIT(PORTD , Copy_u8Pin);
		break;
	}
}


uint8 DIO_u8ReadPin (uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	uint8 return_value;
	switch (Copy_u8Port)
	{
		case 'A':
		case 'a':
		return_value = READ_BIT(PINA , Copy_u8Pin);
		break;
		
		case 'B':
		case 'b':
		return_value = READ_BIT(PINB , Copy_u8Pin);
		break;
		
		case 'C':
		case 'c':
		return_value = READ_BIT(PINC , Copy_u8Pin);
		break;
		
		case 'D':
		case 'd':
		return_value = READ_BIT(PIND , Copy_u8Pin);
		break;
	}
	return return_value;
}



void DIO_vSetPortDir (uint8 Copy_u8Port , uint8 Copy_u8Dir)
{
	switch(Copy_u8Port)
	{
		case 'A':
		case 'a':
		DDRA = Copy_u8Dir;
		break;
		
		case 'B':
		case 'b':
		DDRB = Copy_u8Dir;
		break;
		
		case 'C':
		case 'c':
		DDRC = Copy_u8Dir;
		break;
		
		case 'D':
		case 'd':
		DDRD = Copy_u8Dir;
		break;
	}
}


void DIO_vWritePort (uint8 Copy_u8Port , uint8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case 'A':
		case 'a':
		PORTA = Copy_u8Value;
		break;
		
		case 'B':
		case 'b':
		PORTB = Copy_u8Value;
		break;
		
		case 'C':
		case 'c':
		PORTC = Copy_u8Value;
		break;
		
		case 'D':
		case 'd':
		PORTD = Copy_u8Value;
		break;
	}
}


void DIO_vTogglePort (uint8 Copy_u8Port)
{
	switch(Copy_u8Port)
	{
		case 'A':
		case 'a':
		PORTA =~PORTA;
		break;
		
		case 'B':
		case 'b':
		PORTB =~PORTB;
		break;
		
		case 'C':
		case 'c':
		PORTC =~PORTC;
		break;
		
		case 'D':
		case 'd':
		PORTD =~PORTD;
		break;
	}
}


uint8 DIO_u8ReadPort(uint8 Copy_u8Port)
{
	uint8 return_value;
	switch (Copy_u8Port)
	{
		case 'A':
		case 'a':
		return_value = PINA;
		break;
		
		case 'B':
		case 'b':
		return_value = PINB;
		break;
		
		case 'C':
		case 'c':
		return_value = PINC;
		break;
		
		case 'D':
		case 'd':
		return_value = PIND;
		break;
	}
	return return_value;
}


void DIO_vConnectPullUp (uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8PullUpCheck)
{
	switch(Copy_u8Port)
	{
		case 'A':
		case 'a':  //Port A
		if (Copy_u8PullUpCheck == 1)	//Pull Up is enabled
		{
			SET_BIT(PORTA , Copy_u8Pin);
		}
		else							//Pull Up is disabled
		{
			CLR_BIT(PORTA , Copy_u8Pin);
		}
		break;
		
		case 'B':
		case 'b': //Port B
		if (Copy_u8PullUpCheck == 1)
		{
			SET_BIT(PORTB , Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTB , Copy_u8Pin);
		}
		break;
		
		case 'C':
		case 'c':  //Port C
		if (Copy_u8PullUpCheck == 1)
		{
			SET_BIT(PORTC , Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTC , Copy_u8Pin);
		}
		break;
		
		case 'D':
		case 'd':  //Port D
		if (Copy_u8PullUpCheck == 1)
		{
			SET_BIT(PORTD , Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTD , Copy_u8Pin);
		}
		break;
	}
}