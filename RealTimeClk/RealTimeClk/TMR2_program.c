#include "TMR2_interface.h"

/* global void pointers */
void (*GP_TMR2_OVF)(void) = '\0';
void (*GP_TMR2_COMP)(void) = '\0';

/*call back functions */
void TMR2_OVF_SetCallBack(void(*ptr)(void))
{
	GP_TMR2_OVF=ptr;
}

void TMR2_COMP_SetCallBack(void(*ptr)(void))
{
	GP_TMR2_COMP=ptr;
}


void TMR2_vInit(void)
{
	#if defined TMR2_NORMAL_MODE
	//set normal mode WGM01:0 = 00
	
	//select timer clock
	#ifdef EXTERNAL_CLK
	SET_BIT(ASSR,AS2); // clk from a crystal or external clk connected to TOSC1 pin
	#else
	CLR_BIT(ASSR,AS2); // MC clock
	#endif
	//set timer clk , prescale /128 CS22:0=101
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	
	//enable general interrupt
	GIE_EnableInterrupt();
	
	//set OverFlow interrupt Enable
	SET_BIT(TIMSK,TOIE2);
	
	
	#elif defined TMR2_CTC_MODE
	//set CTC mode WGM01:0 = 10
	SET_BIT(TCCR2,WGM21);
	
	//load OCR0 value (157 -> 20msec at ISR)
	OCR2 = 79;//10msec at ISR
	
	//set timer clk , prescale /1024 CS20:2=111
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
	//enable general interrupt
	GIE_EnableInterrupt();
	
	//set OverFlow interrupt Enable
	SET_BIT(TIMSK,OCIE2);
	
	#elif defined TMR2_NON_PWM
	//set OC2 as output
	DIO_vSetPinDir('D',PIN7,PIN_OUTPUT);
	
	//select CTC mode
	SET_BIT(TCCR2,WGM21);
	
	//frequency = 60Hz
	OCR2=64;
	
	//set timer clk , prescale /1024 CS22:0=111
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
	//Toggle OC2 on compare match COM21:0 = 01
	SET_BIT(TCCR2,COM20);
	
	#elif defined TMR2_FAST_PWM_MODE
	//set OC2 as output
	DIO_vSetPinDir('D',PIN7,PIN_OUTPUT);
	
	//select fast PWM mode WGM21:0 = 11
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	
	//set OCR2 value (25% duty cycle)
	OCR2=64;
	
	//set timer clk , prescale /1024 CS20:2=111
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
	//choose non inverting mode COM21:0 = 10
	SET_BIT(TCCR2,COM21);
	
	#elif defined TMR2_PWM_PHASE_CORRECT_MODE
	//set OC2 as output
	DIO_vSetPinDir('D',PIN7,PIN_OUTPUT);
	
	//select fast PWM mode WGM21:0 = 01
	SET_BIT(TCCR2,WGM20);
	
	//set OCR0 value (25% duty cycle)
	OCR2=64;
	
	//set timer clk , prescale /1024 CS20:2=111
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
	//Set OC2 on compare match when up-counting COM21:0 = 11
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	
	#endif
}


/*ISR(TIMER2_COMP_vect) */
void __vector_4()__attribute__((signal)) ;
void __vector_4()
{
	if (GP_TMR2_COMP != '\0')
	{
		GP_TMR2_COMP();
	}
}

/*ISR(TIMER2_OVF_vect) */
void __vector_5()__attribute__((signal)) ;
void __vector_5()
{
	if (GP_TMR2_OVF != '\0')
	{
		GP_TMR2_OVF();
	}
}

