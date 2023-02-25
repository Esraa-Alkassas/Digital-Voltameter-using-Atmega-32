/*
 * vltameter_main.c
 *
 *  Created on: Dec 21, 2022
 *      Author: Lenovo
 */

#define F_CPU  8000000UL
#include <avr/delay.h>

/* LIBs */
#include "types.h"
#include "BIT_MATH.h"
#include <stdlib.h>

/*interface files */
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"

/*CFGs files*/
#include "LCD_CFG.h"
#include "ADC_CFG.h"


//int main ()
//{
//
//	f64 Vo;
//	u8 arr [5];
//
//	HLCD_vidInit();
//	ADC_VidInit ();
//
//
//	DIO_vidSetPinDir (DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
//	DIO_vidSetPortDir (DIO_PORTD, PORT_OUTPUT);
//	DIO_vidSetPinDir (DIO_PORTC, DIO_PIN0, DIO_OUTPUT);
//	DIO_vidSetPinDir (DIO_PORTC, DIO_PIN1, DIO_OUTPUT);
//	DIO_vidSetPinDir (DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
//
//	DIO_vidSetPinDir (DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
//
//
//
//	/*pull up pin B1 */
//	DIO_vidSetPinVal (DIO_PORTB, DIO_PIN1, DIO_HIGH);
//
//	while (1)
//	{
//		u16 x = ADC_u16GetReading (0);
//		if (GET_BIT(DIO_PORTB, DIO_PIN1) == 0) // --> 5v mode
//		{
//
//			DIO_vidSetPinVal (DIO_PORTB, DIO_PIN0, DIO_HIGH);
//
//			Vo = x * 4.8;
//			itoa (Vo, arr, 10);
//			HLCD_vidWriteStr (arr);
//
//		}
//		else // --> 10 v mode
//		{
//
//		}
//	}
//
//}
















int main ()
{
		f64 Vo;
		u8 arr [5];
		DIO_vidSetPinDir (DIO_PORTA, DIO_PIN0, DIO_INPUT);
		DIO_vidSetPortDir (DIO_PORTD, PORT_OUTPUT);
		DIO_vidSetPinDir (DIO_PORTC, DIO_PIN0, DIO_OUTPUT);
		DIO_vidSetPinDir (DIO_PORTC, DIO_PIN1, DIO_OUTPUT);
		DIO_vidSetPinDir (DIO_PORTC, DIO_PIN2, DIO_OUTPUT);

		DIO_vidSetPinDir (DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
		DIO_vidSetPinDir (DIO_PORTB, DIO_PIN1, DIO_INPUT);

	HLCD_vidInit();
	ADC_VidInit ();
	//_delay_ms(1);               //what is the benefit of that delay?

		/*pull up pin B1 */
		DIO_vidSetPinVal (DIO_PORTB, DIO_PIN1, DIO_HIGH);

		while (1)
		{
			u8 SW = DIO_u8GetPinValue(DIO_PORTB, DIO_PIN1);
			u16 x = ADC_u16GetReading (0);

			if (SW == 0) // --> 5v mode

			{

				DIO_vidSetPinVal (DIO_PORTB, DIO_PIN0, DIO_HIGH);

				HLCD_vidGoToXY(0, 0);
				HLCD_vidWriteStr("MODE: 5V");
				Vo = x * 4.8;
				itoa (Vo, arr, 10);
				HLCD_vidGoToXY(1, 0);
				HLCD_vidWriteStr (arr);
				HLCD_vidGoToXY(1, 6);
				HLCD_vidWriteStr ("mV");


			}

			else if( SW == 1) // -->10 v mode

			{
				DIO_vidSetPinVal (DIO_PORTB, DIO_PIN0, DIO_LOW);

				//HLCD_vidsendCMD (0x01);
				HLCD_vidGoToXY(0, 0);
				HLCD_vidWriteStr("MODE: 10V");
				Vo = x * 4.8 * 2 ;
				itoa (Vo, arr, 10);
				HLCD_vidGoToXY(1, 0);
				HLCD_vidWriteStr (arr);
				HLCD_vidGoToXY(1, 6);
				HLCD_vidWriteStr ("mV");

			}

}
}
