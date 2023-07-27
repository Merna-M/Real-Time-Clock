#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

/* ################################# Includes ##################################*/
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_interface.h"
#include "LCD_config.h"

/* ################################## Macros ####################################*/



/* Commands */
#define EIGHT_BIT			  0x38
#define FOUR_BIT			  0x28
#define CLR_SCREEN			  0x01
#define DISPLAY_ON_CURSOR_ON  0x0E
#define DISPLAY_ON_CURSOR_OFF 0x0C
#define ENTRY_MODE			  0x06
#define RETURN_HOME			  0x02
#define ROW1_START			  0x80
#define ROW2_START			  0xC0 //0x80 + 0x40


/* ################################## prototypes ###################################*/

/*
FUNCTION NAME        : LCD_vInit
FUNCTION DESCRIPTION : initialize LCD by sending some commands and setting pins diection of MCU 
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
void LCD_vInit(void);

/*
FUNCTION NAME        : LCD_vSendCmd
FUNCTION DESCRIPTION : used to send commands to the LCD
FUNCTION INPUTS      : Copy_u8Command: command to be sent
FUNCTION RETURN      : void
*/
void LCD_vSendCmd(uint8 Copy_u8Command);

/*
FUNCTION NAME        : LCD_vSendData
FUNCTION DESCRIPTION : used to send data to be displayed at the LCD screen
FUNCTION INPUTS      : Copy_u8Data: data to be sent
FUNCTION RETURN      : void
*/
void LCD_vSendData(uint8 Copy_u8Data);

/*
FUNCTION NAME        : LCD_vEnable
FUNCTION DESCRIPTION : used to send a pulse to EN pin in the LCD to send data or command
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
static void LCD_vEnable(void);

/*
FUNCTION NAME        : LCD_vClearScreen
FUNCTION DESCRIPTION : used to clear LCD screen
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
void LCD_vClearScreen(void);

/*
FUNCTION NAME        : LCD_vMoveCursor
FUNCTION DESCRIPTION : change the cursor location according to the inputs
FUNCTION INPUTS      : Copy_u8Row: row number (1 or 2) , Copy_u8Col: column number (1->16)
FUNCTION RETURN      : void
*/
void LCD_vMoveCursor(uint8 Copy_u8Row , uint8 Copy_u8Col);

/*
FUNCTION NAME        : LCD_vSendString
FUNCTION DESCRIPTION : used to send a whole string to the LCD
FUNCTION INPUTS      : address of the first char of string
FUNCTION RETURN      : void
*/
void LCD_vSendString(uint8* Copy_u8Data);

/*
FUNCTION NAME        : LCD_vSendNumber
FUNCTION DESCRIPTION : used to display a decimal number not ascii
FUNCTION INPUTS      : Copy_u16Number: decimal number to be displayed
FUNCTION RETURN      : void
*/
void LCD_vSendNumber(uint16 Copy_u16Number);

#endif