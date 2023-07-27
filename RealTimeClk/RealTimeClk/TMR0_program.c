#include "TMR0_interface.h"

/* global void pointers */
void (*GP_TMR0_OVF)(void) = '\0';
void (*GP_TMR0_COMP)(void) = '\0';

/*call back functions */
void TMR0_OVF_SetCallBack(void(*ptr)(void))
{
	GP_TMR0_OVF=ptr;
}

void TMR0_COMP_SetCallBack(void(*ptr)(void))
{
	GP_TMR0_COMP=ptr;
}

void TMR0_vInit(void)
{
	#if defined TMR0_NORMAL_MODE
	//set normal mode WGM01:0 = 00
	
	//set timer clk , prescale /1024 CS00:2=101
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//enable general interrupt
	GIE_EnableInterrupt();
	
	//set OverFlow interrupt Enable
	SET_BIT(TIMSK,TOIE0);
	
	
	#elif defined TMR0_CTC_MODE
	//set CTC mode WGM01:0 = 10
	SET_BIT(TCCR0,WGM01);
	
	//load OCR0 value (157 -> 20msec at ISR)
	OCR0 = 39;//10msec at ISR
	
	//set timer clk , prescale /1024 CS00:2=101
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//enable general interrupt
	GIE_EnableInterrupt();
	
	//set OverFlow interrupt Enable
	SET_BIT(TIMSK,OCIE0);
	
	#elif defined TMR0_NON_PWM
	//set OC0 as output
	DIO_vSetPinDir('B',PIN3,PIN_OUTPUT);
	
	//select CTC mode
	SET_BIT(TCCR0,WGM01);
	
	//frequency = 60Hz
	OCR0=64;
	
	//set timer clk , prescale /1024 CS00:2=101
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//Toggle OC0 on compare match COM01:0 = 01
	SET_BIT(TCCR0,COM00);
	
	#elif defined TMR0_FAST_PWM_MODE
	//set OC0 as output
	DIO_vSetPinDir('B',PIN3,PIN_OUTPUT);
	
	//select fast PWM mode WGM01:0 = 11
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	//set OCR0 value (25% duty cycle)
	OCR0=64;
	
	//set timer clk , prescale /1024 CS00:2=101
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//choose non inverting mode COM01:0 = 10
	SET_BIT(TCCR0,COM01);
	
	#elif defined TMR0_PWM_PHASE_CORRECT_MODE
	//set OC0 as output
	DIO_vSetPinDir('B',PIN3,PIN_OUTPUT);
	
	//select fast PWM mode WGM01:0 = 01
	SET_BIT(TCCR0,WGM00);
	
	//set OCR0 value (25% duty cycle)
	OCR0=64;
	
	//set timer clk , prescale /1024 CS00:2=101
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//Set OC0 on compare match when up-counting COM01:0 = 11
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	#endif
}


/*ISR(TIMER0_COMP_vect) */
void __vector_10()__attribute__((signal)) ;
void __vector_10()
{
	if (GP_TMR0_COMP != '\0')
	{
		GP_TMR0_COMP();
	}
}

/*ISR(TIMER0_OVF_vect) */
void __vector_11()__attribute__((signal)) ;
void __vector_11()
{
	if (GP_TMR0_OVF != '\0')
	{
		GP_TMR0_OVF();
	}
}

