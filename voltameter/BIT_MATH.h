
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Variable, Bit_Num)       Variable |= (1<<(Bit_Num))


#define CLR_BIT(Variable, Bit_Num)       Variable &= ~(1<<(Bit_Num))


#define GET_BIT(Variable, Bit_Num)       (Variable>>Bit_Num)&0x1


#define TOG_BIT (Variable, Bit_Num)      Variable ^ = (1<< Bit_Num)








#endif
