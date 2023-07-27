
/** Libraries **/
#include "STD_types.h"
#define F_CPU 8000000UL
#include "util/delay.h"
/** MCAL **/
#include "TMR0_interface.h"
#include "TMR2_interface.h"
/** HAL **/
#include "LCD_interface.h"
#include "KYP_interface.h"
#include "SEVSEG_interface.h"
#include "LED_interface.h"

/* Global Variables */
volatile uint16 TMR0_counter = 0;
volatile uint8  TMR_seconds  = 0;
volatile uint8  TMR_minutes  = 0;
volatile uint8  TMR_hours    = 0;
volatile uint8 user_mode = 0;

void TMR0_ISR(void)
{
	TMR0_counter++;
	if(TMR0_counter>=6)
	{
		TMR0_counter=0;
	}
}

void TMR2_ISR(void)
{
	if(user_mode == 0 || user_mode == 2)
	{
		TMR_seconds++;
	}
	else if(user_mode == 1)
	{
		TMR_seconds--;
	}
}


int main(void)
{
	uint8 press = NOT_PRESSED;
	uint8 timer;
	/* Initializations */
	LCD_vInit();
	KYP_vInit();
	SEVSEG_vInit('D');
	SEVSEG_vEnableInit('C',0);
	SEVSEG_vEnableInit('C',1);
	SEVSEG_vEnableInit('C',2);
	SEVSEG_vEnableInit('C',3);
	SEVSEG_vEnableInit('C',4);
	SEVSEG_vEnableInit('C',5);
	
	/* Initialze a LED */
	LED_vInit('A',7);
	
	TMR0_vInit();
	TMR0_COMP_SetCallBack(TMR0_ISR);

	TMR2_vInit();
	TMR2_OVF_SetCallBack(TMR2_ISR);
	
	
    while(1)
    {
		LCD_vClearScreen();
        LCD_vSendString("1:Clock  2:Timer");
       	LCD_vMoveCursor(2,1);
       	LCD_vSendString("3:Stop Watch");
       	
       	do
       	{
	       	press = KYP_u8CheckPress();
	       	_delay_ms(150);
       	} while (press != '1' && press != '2' && press != '3');
       	_delay_ms(150);
       	LCD_vClearScreen();
       	if(press == '1' || press == '2')
       	{
	       	if(press == '1')	//clock
	       	{
	        	user_mode=0;
	       	}
	       	else               // timer
	       	{
	        	user_mode=1;
	       	}
	       	do{
	        	LCD_vSendString("Set Hour: ");
	        	do{
		        	press = KYP_u8CheckPress();
		        	_delay_ms(150);
	        	}while(press < '0' || press > '9');
	        	LCD_vSendData(press);
	        	_delay_ms(150);
	        	TMR_hours = 10*(press-48);
	        	do{
		        	press = KYP_u8CheckPress();
		        	_delay_ms(150);
	        	}while(press < '0' || press > '9');
	        	LCD_vSendData(press);
	        	_delay_ms(150);
	        	TMR_hours = TMR_hours + (press-48);
	        	if(TMR_hours>=24)
	        	{
		        	LCD_vClearScreen();
		        	LCD_vSendString("Unavailable");
		        	LCD_vMoveCursor(2,1);
		        	LCD_vSendString("From 00 -> 23");
		        	_delay_ms(1000);
		        	LCD_vClearScreen();
	        	}
	       	}while(TMR_hours>=24);
	       	
	       	do{
	        	LCD_vMoveCursor(2,1);
	        	LCD_vSendString("Set Mins: ");
	        	do{
		        	press = KYP_u8CheckPress();
		        	_delay_ms(150);
	        	}while(press < '0' || press > '9');
	        	LCD_vSendData(press);
	        	_delay_ms(150);
	        	TMR_minutes = 10*(press-48);
	        	do{
		        	press = KYP_u8CheckPress();
		        	_delay_ms(150);
	        	}while(press < '0' || press > '9');
	        	LCD_vSendData(press);
	        	_delay_ms(150);
	        	TMR_minutes = TMR_minutes + (press-48);
	        	if(TMR_minutes>=60)
	        	{
		        	LCD_vClearScreen();
		        	LCD_vSendString("Unavailable");
		        	LCD_vMoveCursor(2,1);
		        	LCD_vSendString("From 00 -> 59");
		        	_delay_ms(1000);
		        	LCD_vClearScreen();
		        	LCD_vSendString("Set Hour: ");
		        	if(TMR_hours<10)
		        	{
			        	LCD_vSendData('0');
		        	}
		        	LCD_vSendNumber(TMR_hours);
	        	}
	       	}while(TMR_minutes>=60);
			
			if(user_mode == 1)
			{
				LCD_vClearScreen();
				LCD_vSendString("Set Mins: ");

				if(TMR_minutes<10)
				{
					LCD_vSendData('0');
				}
				LCD_vSendNumber(TMR_minutes);
				do{
					LCD_vMoveCursor(2,1);
					LCD_vSendString("Set Secs: ");
					do{
						press = KYP_u8CheckPress();
						_delay_ms(150);
					}while(press < '0' || press > '9');
					LCD_vSendData(press);
					_delay_ms(150);
					timer = 10*(press-48);
					do{
						press = KYP_u8CheckPress();
						_delay_ms(150);
					}while(press < '0' || press > '9');
					LCD_vSendData(press);
					_delay_ms(150);
					timer = timer + (press-48);
					if(timer>=60)
					{
						LCD_vClearScreen();
						LCD_vSendString("Unavailable");
						LCD_vMoveCursor(2,1);
						LCD_vSendString("From 00 -> 59");
						_delay_ms(1000);
					}
				}while(timer>=60);
			}				
       	}
       	else if(press == '3')//stop watch
       	{
	       	user_mode = 2;
			TMR_minutes=0;
			TMR_hours=0;
       	}
		LCD_vClearScreen();
		if(user_mode == 0)
		{
			LCD_vSendString("     Clock");		   
		}			   
		else if(user_mode == 1)
		{
			LCD_vSendString("     Timer");
		}
		else if(user_mode == 2)
		{
			LCD_vSendString("   Stop Watch");
		}
			
		LCD_vMoveCursor(2,1);
		LCD_vSendString("Press ON to Stop");
		
		press = NOT_PRESSED;	
		SEVSEG_vEnableControl('C',0,DISABLE_MUX);
		SEVSEG_vEnableControl('C',1,DISABLE_MUX);
		SEVSEG_vEnableControl('C',2,DISABLE_MUX);
		SEVSEG_vEnableControl('C',3,DISABLE_MUX);
		SEVSEG_vEnableControl('C',4,DISABLE_MUX);
		SEVSEG_vEnableControl('C',5,DISABLE_MUX);
		TMR_seconds=0;
		if(user_mode == 1)
		{
			TMR_seconds = timer;
		}
		while(press != 'A')
		{
			press = KYP_u8CheckPress();
			TMR0_counter=0;
			SEVSEG_vEnableControl('C',0,DISABLE_MUX);
			SEVSEG_vEnableControl('C',5,ENABLE_MUX);	
			SEVSEG_vWrite('D',TMR_hours/10);
			while(TMR0_counter == 0);
			SEVSEG_vEnableControl('C',5,DISABLE_MUX);
			SEVSEG_vEnableControl('C',4,ENABLE_MUX);
			SEVSEG_vWrite('D',TMR_hours%10);
			while(TMR0_counter == 1);
			SEVSEG_vEnableControl('C',4,DISABLE_MUX);
			SEVSEG_vEnableControl('C',3,ENABLE_MUX);
			SEVSEG_vWrite('D',TMR_minutes/10);
			while(TMR0_counter == 2);
			SEVSEG_vEnableControl('C',3,DISABLE_MUX);
			SEVSEG_vEnableControl('C',2,ENABLE_MUX);
			SEVSEG_vWrite('D',TMR_minutes%10);
			while(TMR0_counter == 3);
			SEVSEG_vEnableControl('C',2,DISABLE_MUX);
			SEVSEG_vEnableControl('C',1,ENABLE_MUX);
			SEVSEG_vWrite('D',TMR_seconds/10);
			while(TMR0_counter == 4);
			SEVSEG_vEnableControl('C',1,DISABLE_MUX);
			SEVSEG_vEnableControl('C',0,ENABLE_MUX);
			SEVSEG_vWrite('D',TMR_seconds%10);
			while(TMR0_counter == 5);
			if(user_mode == 0 || user_mode==2) //clock OR stop watch
			{
				if(TMR_seconds >= 60)	
				{
					TMR_seconds=0;
					TMR_minutes++;
				}
				if(TMR_minutes >= 60)
				{
					TMR_minutes=0;
					TMR_hours++;
				}
				if(TMR_hours >= 24)
				{
					TMR_hours=0;
				}
			}
			else if(user_mode == 1)//timer
			{
				if(TMR_seconds == 0)
				{
					TMR_seconds=59;
					TMR_minutes--;
				}
				if(TMR_minutes > 100)//overflow (-ve) makes the value of TMR_minutes = 255, I chose a bigger number than 60 
				{
					TMR_minutes=59;
					TMR_hours--;
				}
				if(TMR_hours > 100)
				{
					TMR_hours=0;
					TMR_minutes=0;
					TMR_seconds=0;
					user_mode=3; // change mode to stop changing the timer values after 00:00:00
					LED_vSwitchON('A',7);
				}
			}
		}
		_delay_ms(200);		
		SEVSEG_vEnableControl('C',0,DISABLE_MUX);
		SEVSEG_vEnableControl('C',1,DISABLE_MUX);
		SEVSEG_vEnableControl('C',2,DISABLE_MUX);
		SEVSEG_vEnableControl('C',3,DISABLE_MUX);
		SEVSEG_vEnableControl('C',4,DISABLE_MUX);
		SEVSEG_vEnableControl('C',5,DISABLE_MUX);	
		LED_vSwitchOFF('A',7);
    }
}