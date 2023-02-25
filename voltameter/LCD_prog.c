/*
 * LCD_prog.c
 *
 *  Created on: Nov 27, 2022
 *      Author: Lenovo
 */

#define F_CPU  8000000UL
#include <avr/delay.h>

/*lIB */
#include "types.h"
#include "BIT_MATH.h"

/* DIO */
#include "DIO_interface.h"
//#include "DIO_priv.h"     // it's wrong to include private file of other prepherals (the only private file that is included is that of the  prerheral which i'm writting
// is the CFG file is the same as private ? and of course that means that we include only interface files of other prephrals that we will use ?
////////////////////////////////////////

/*LCD*/
#include "LCD_interface.h"
#include "LCD_priv.h"
#include "LCD_CFG.h"



void HLCD_vidInit ( void)
{
	_delay_ms(0);
	HLCD_vidsendCMD(LCD_FUNCSET_8BIT);
	_delay_ms(1);
	HLCD_vidsendCMD (LCD_DISPON_CURSON);
	_delay_ms(1);
	HLCD_vidsendCMD (LCD_CLR);
	_delay_ms(1);
	HLCD_vidsendCMD (LCD_ENTRYMODE);

}


void HLCD_vidsendCMD (u8 Copy_u8CMD)
{
	//CLEAR RS PIN
	DIO_vidSetPinVal (LCD_RS_PORT, DIO_PIN0, DIO_LOW);
	//CLEAR RW PIN
	DIO_vidSetPinVal (LCD_RW_PORT, LCD_RW_PIN, DIO_LOW);
	//SET E PIN TO HIGH
	DIO_vidSetPinVal(LCD_E_PORT,LCD_E_PIN ,DIO_HIGH);
	//LOAD THE COMMAND
	DIO_vidSetPortVal (LCD_DATA_PORT, Copy_u8CMD);
	//CLEAR E PIN
	DIO_vidSetPinVal(LCD_E_PORT,LCD_E_PIN ,DIO_LOW);
}


void HLCD_vidsendChar (u8 Copy_u8Char)
{
	//SET RS PIN (data mode)
	DIO_vidSetPinVal(LCD_RS_PORT,LCD_RS_PIN ,DIO_HIGH);
	_delay_ms(1);
	//clear RW PIN(Write mode)
	DIO_vidSetPinVal(LCD_RW_PORT,LCD_RW_PIN ,DIO_LOW);
	_delay_ms(1);
	//SET E PIN TO HIGH
	DIO_vidSetPinVal(LCD_E_PORT,LCD_E_PIN ,DIO_HIGH);
	_delay_ms(1);
	//LOAD THE COMMAND
	DIO_vidSetPortVal(LCD_DATA_PORT, Copy_u8Char);
	_delay_ms (1);
	//CLEAR E PIN
	DIO_vidSetPinVal(LCD_E_PORT,LCD_E_PIN ,DIO_LOW);
	//I think there should be delay here...!////////////////////////////////////////////////////
}



void HLCD_vidWriteStr (u8* pu8str)
{
	u8 i =0;
	while (pu8str[i] != '\0')  /*or != 0 */           // where did he declares that this is an array? he only declared about pointer!////////////////////////////////////////////////////////////
	                                              // i think because here, in the implementation, i pass a pointer, that means when i call this function in the main i should pass an address to it, and for sure, the name of any array is an address to its first location////////right?//////////////////////////////////////////////////////////
	{
		 HLCD_vidsendChar (pu8str[i]);
		 //_delay_ms (1);                       // why did he put this delay?    /////////////////////////////////////////////////////////////////////////
		 i++;
	}

//	while (*pu8str)
//	{
//		 HLCD_vidsendChar (*pu8str++);
//	}

}




void HLCD_vidGoToXY(u8 x, u8 y)                    // I didn't recognize what he has done here (need some illustration)////////////////////////////////////////////////////////////////////////////
{
//	if (y==0)
//	{
//		HLCD_vidsendCMD (x | LCD_SETCURSOR );
//	}
//	else if (y==1)
//	{
//		HLCD_vidsendCMD((x+0x40) | LCD_SETCURSOR );
//	}
//	else
//	{
//		return ;
//	}


	u8 address;
	if (x <2 && y <16)
	{
		address = (x * 0x40) + y ;
		address = SET_BIT(address, 7);
		HLCD_vidsendCMD (address);
	}
}
