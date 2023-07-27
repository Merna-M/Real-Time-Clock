#ifndef GIE_INTERFACE_H
#define GIE_INTERFACE_H

/*############################ Macros #############################*/
/*General Interrupt Enable bit*/
#define Ibit  7

/* ############################# prototypes ############################*/
/*
FUNCTION NAME        : GIE_EnableInterrupt
FUNCTION DESCRIPTION : used to set I bit from the status register
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
void GIE_EnableInterrupt (void);

/*
FUNCTION NAME        : GIE_DisableInterrupt
FUNCTION DESCRIPTION : used to clear I bit from the status register
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
void GIE_DisableInterrupt (void);

#endif