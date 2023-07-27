#include "KYP_interface.h"

void KYP_vInit(void)
{
	DIO_vSetPortDir(KYP_PORT,0x0F);//first 4 pins are output and last 4 pins are input
	/* connect pull up */
	DIO_vConnectPullUp(KYP_PORT,KYP_COL1_PIN,1);
	DIO_vConnectPullUp(KYP_PORT,KYP_COL2_PIN,1);
	DIO_vConnectPullUp(KYP_PORT,KYP_COL3_PIN,1);
	DIO_vConnectPullUp(KYP_PORT,KYP_COL4_PIN,1);
	/* Initialize rows with 1 */
	DIO_vWritePin(KYP_PORT,KYP_ROW1_PIN,HIGH);
	DIO_vWritePin(KYP_PORT,KYP_ROW2_PIN,HIGH);
	DIO_vWritePin(KYP_PORT,KYP_ROW3_PIN,HIGH);
	DIO_vWritePin(KYP_PORT,KYP_ROW4_PIN,HIGH);
}

uint8 KYP_u8CheckPress(void)
{
	//local array for the ascii values of keypad
	uint8 LOC_KYP_ARR[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	uint8 LOC_row , LOC_col; // counters for the loops
	uint8 LOC_ReadX = 1;
	uint8 Return_Value = NOT_PRESSED; //value to be returned
	for(LOC_row = 0 ; LOC_row < 4 ; LOC_row++)
	{
		DIO_vWritePin(KYP_PORT,LOC_row,LOW);
		for(LOC_col=0 ; LOC_col<4 ; LOC_col++)
		{
			LOC_ReadX = DIO_u8ReadPin(KYP_PORT,LOC_col+4);//read the switch , col+4 as the first pin starts from 4
			if(LOC_ReadX == 0)
			{
				Return_Value = LOC_KYP_ARR[LOC_row][LOC_col];
				break;
			}
		}
		//return the pin to default 1
		DIO_vWritePin(KYP_PORT,LOC_row,HIGH);
		if(LOC_ReadX == 0)
		{
			break;
		}	
	}
	return Return_Value;
}