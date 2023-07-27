


#ifndef _STD_MACROS_H
#define _STD_MACROS_H

#define SET_BIT(reg,bit)		reg|=(1<<bit)
#define CLR_BIT(reg,bit)		reg&=~(1<<bit)
#define TOGGLE_BIT(reg,bit)		reg^=(1<<bit)
#define READ_BIT(reg,bit)		((reg>>bit)&1)
#define ROR(reg,bit)			reg= (reg>>bit)|(reg<<(8-bit))
#define ROL(reg,bit)			reg= (reg<<bit)|(reg>>(8-bit))



#endif 