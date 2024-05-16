#ifndef Bit_Utilies
#define Bit_Utilies

#define GET_BIT(reg,bit)   ((reg>>bit)&1)
#define GET_REG(reg)        (reg&0xff)

#define SET_REG(reg,val)        reg |= val
#define SET_BIT(reg,val)        reg |= (1<<val)
#define TOG_BIT(reg,val)		reg ^= (1<<val)

#define CLR_REG(reg,val)        reg &=~val
#define CLR_BIT(reg,val)        reg &=~(1<<val)

#endif

