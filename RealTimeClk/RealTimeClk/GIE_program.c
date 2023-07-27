#include "STD_types.h"
#include "BIT_math.h"
#include "GIE_private.h"
#include "GIE_interface.h"

void GIE_EnableInterrupt (void)
{
	SET_BIT(SREG,Ibit); // set Ibit(bit 7) of Status register
}

void GIE_DisableInterrupt (void)
{
	CLR_BIT(SREG,Ibit); // clear Ibit(bit 7) of Status register
}