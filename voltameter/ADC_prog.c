/*
 * ADC_prog.c
 *
 *  Created on: Dec 9, 2022
 *      Author: Lenovo
 */

#include "types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"

#include "ADC_interface.h"
#include "ADC_priv.h"
#include "ADC_CFG.h"

void ADC_VidInit (void)
{
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
	CLR_BIT(ADMUX, ADLAR);
	CLR_BIT(ADMUX, MUX0);
	CLR_BIT(ADMUX, MUX1);
	CLR_BIT(ADMUX, MUX2);


	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS2);

}




u16 ADC_u16GetReading (u8 ChId)
{
	SET_BIT(ADCSRA, ADEN);
	SET_BIT(ADCSRA, ADSC);

	ChId = ChId & 00000111;
	ADMUX = (ADMUX & 0xF8)| ChId;
	while (GET_BIT( ADCSRA, ADIF)==0);
	return ADC_Data_Reg ;
}






































/*

#define ADC_VREFF   AVCC
#define REG_ADJ     RIGHT

#define PRESCALLER  7



**************************************


#define			ADMUX				*((volatile u8 *)0x27)
#define			ADCSRA				*((volatile u8 *)0x26)
#define			ADC_REG				*((volatile u16 *)0x24)


#define INTERNAL      3
#define AVCC          1
#define EXTERNAL      0


#define RIGHT         0
#define LEFT          1

#define ADEN          7
#define ADSC          6
#define ADIF          4


*****************************************


{
	ADMUX = (ADC_VREFF<<6) | (REG_ADJ<<5);
	ADCSRA |= PRESCALLER ;

}



u16 ADC_u16getReading(u8 Copy_u8ChId)
{
	if(Copy_u8ChId < 8)
	{
		ADMUX = (ADMUX & 0xF8) | Copy_u8ChId;
	}
	ADCSRA = (1<<ADEN)|(1<<ADSC);
	while(GET_BIT(ADCSRA , ADIF) == 0);

	return ADC_REG;
}

**********************************************
*/
