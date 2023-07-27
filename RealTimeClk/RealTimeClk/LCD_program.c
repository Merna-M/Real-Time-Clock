#include "LCD_interface.h"
#define F_CPU  8000000UL
#include "util/delay.h"

void LCD_vInit(void)
{
	_delay_ms(150); // wait for the power up
	#if defined EIGHT_BIT_MODE
	DIO_vSetPortDir(LCD_PORT_DATA,PORT_OUTPUT);//setting the direction of a port to be output
	/*set the direction of the control pins as output*/
	DIO_vSetPinDir(LCD_PORT_CONTROL,RS,PIN_OUTPUT);
	DIO_vSetPinDir(LCD_PORT_CONTROL,RW,PIN_OUTPUT);
	DIO_vSetPinDir(LCD_PORT_CONTROL,EN,PIN_OUTPUT);
	/*set RW pin to the Write mode*/
	DIO_vWritePin(LCD_PORT_CONTROL,RW,LOW);
	/* Sending commands to the LCD */
	LCD_vSendCmd(EIGHT_BIT);
	_delay_ms(1);
	LCD_vSendCmd(DISPLAY_ON_CURSOR_ON);
	_delay_ms(1);
	LCD_vSendCmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_vSendCmd(ENTRY_MODE);
	_delay_ms(1);
	#elif defined FOUR_BIT_MODE
	//set the 4 pins direction
	DIO_vSetPinDir(LCD_PORT_DATA , FOUR_BIT_START_PIN   , PIN_OUTPUT);
	DIO_vSetPinDir(LCD_PORT_DATA , FOUR_BIT_START_PIN+1 , PIN_OUTPUT);
	DIO_vSetPinDir(LCD_PORT_DATA , FOUR_BIT_START_PIN+2 , PIN_OUTPUT);
	DIO_vSetPinDir(LCD_PORT_DATA , FOUR_BIT_START_PIN+3 , PIN_OUTPUT);
	//set enable pins direction
	DIO_vSetPinDir(LCD_PORT_CONTROL,RS,PIN_OUTPUT);
	DIO_vSetPinDir(LCD_PORT_CONTROL,RW,PIN_OUTPUT);
	DIO_vSetPinDir(LCD_PORT_CONTROL,EN,PIN_OUTPUT);
	/*set RW pin to the Write mode*/
	DIO_vWritePin(LCD_PORT_CONTROL,RW,LOW);
	/* Sending commands to the LCD */
	LCD_vSendCmd(RETURN_HOME);
	_delay_ms(10);
	LCD_vSendCmd(FOUR_BIT);
	_delay_ms(1);
	LCD_vSendCmd(DISPLAY_ON_CURSOR_OFF);
	_delay_ms(1);
	LCD_vSendCmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_vSendCmd(ENTRY_MODE);
	_delay_ms(1);
	#endif
}


void LCD_vSendCmd(uint8 Copy_u8Command)
{
	#if defined EIGHT_BIT_MODE
	DIO_vWritePort(LCD_PORT_DATA,Copy_u8Command); //send the command to the LCD through the MCU pins
	DIO_vWritePin(LCD_PORT_CONTROL,RS,LOW);       //choose to write a command (RS = 0)
	LCD_vEnable(); //send the enable pulse
	#elif defined FOUR_BIT_MODE
	//send the higher bits to the LCD four pins
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN   , READ_BIT(Copy_u8Command,4));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+1 , READ_BIT(Copy_u8Command,5));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+2 , READ_BIT(Copy_u8Command,6));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+3 , READ_BIT(Copy_u8Command,7));
	DIO_vWritePin(LCD_PORT_CONTROL,RS,LOW);       //choose to write a command (RS = 0)
	LCD_vEnable(); //send the enable pulse
	//send the lower bits to the LCD four pins
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN   , READ_BIT(Copy_u8Command,0));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+1 , READ_BIT(Copy_u8Command,1));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+2 , READ_BIT(Copy_u8Command,2));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+3 , READ_BIT(Copy_u8Command,3));
	DIO_vWritePin(LCD_PORT_CONTROL,RS,LOW);       //choose to write a command (RS = 0)
	LCD_vEnable(); //send the enable pulse
	#endif
}


void LCD_vSendData(uint8 Copy_u8Data)
{
	#if defined EIGHT_BIT_MODE
	DIO_vWritePort(LCD_PORT_DATA,Copy_u8Data); // send the data to the LCD through the MCU pins
	DIO_vWritePin(LCD_PORT_CONTROL,RS,HIGH);   // choose to write a data (RS = 1)
	LCD_vEnable(); // send the enable pulse
	#elif defined FOUR_BIT_MODE
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN   , READ_BIT(Copy_u8Data,4));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+1 , READ_BIT(Copy_u8Data,5));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+2 , READ_BIT(Copy_u8Data,6));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+3 , READ_BIT(Copy_u8Data,7));
	DIO_vWritePin(LCD_PORT_CONTROL,RS,HIGH);       // choose to write a data (RS = 1)
	LCD_vEnable(); // send the enable pulse
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN   , READ_BIT(Copy_u8Data,0));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+1 , READ_BIT(Copy_u8Data,1));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+2 , READ_BIT(Copy_u8Data,2));
	DIO_vWritePin(LCD_PORT_DATA , FOUR_BIT_START_PIN+3 , READ_BIT(Copy_u8Data,3));
	DIO_vWritePin(LCD_PORT_CONTROL,RS,HIGH);       //choose to write a command (RS = 1)
	LCD_vEnable(); //send the enable pulse
	#endif
}


static void LCD_vEnable(void)
{
	DIO_vWritePin(LCD_PORT_CONTROL,EN,HIGH);
	_delay_ms(2);
	DIO_vWritePin(LCD_PORT_CONTROL,EN,LOW);
	_delay_ms(2);
}


void LCD_vClearScreen(void)
{
	LCD_vSendCmd(CLR_SCREEN);//send clear command to LCD
}


void LCD_vMoveCursor(uint8 Copy_u8Row , uint8 Copy_u8Col)
{
	uint8 LOC_Cmd;
	//check if the input parameters are out of range
	if(Copy_u8Row>2 || Copy_u8Col>16 || Copy_u8Col==0 ||Copy_u8Row==0)
	{
		LOC_Cmd = ROW1_START; // 1st row and 1st col
	}
	else if(Copy_u8Row == 1)
	{
		LOC_Cmd = ROW1_START + Copy_u8Col - 1; //add the col offset to the row1 start command 
	}
	else if(Copy_u8Row == 2)
	{
		LOC_Cmd = ROW2_START + Copy_u8Col - 1; //add the col offset to the row2 start command 
	}
	LCD_vSendCmd(LOC_Cmd);
}


void LCD_vSendString(uint8* Copy_u8Data)
{
	//check the end of the string
	while(*Copy_u8Data != '\0')
	{
		LCD_vSendData(*Copy_u8Data); //send the current character
		Copy_u8Data++;               //increment to get the next address of the next char
	}
}

void LCD_vSendNumber(uint16 Copy_u16Number)
{
	sint8 i=0;// counter
	uint8 LOC_arr[8];//array holding numbers
	if(Copy_u16Number/10 == 0)
	{
		LCD_vSendData(Copy_u16Number+48);
	}
	else
	{
		while(Copy_u16Number != 0)
		{
			LOC_arr[i]=Copy_u16Number%10;
			Copy_u16Number = Copy_u16Number / 10;
			i++;
		}
		while(i > 0)
		{
			i--;
			LCD_vSendData(LOC_arr[i]+48);
		}
	}
}