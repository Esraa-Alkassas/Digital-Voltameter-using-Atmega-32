/*
 * CFG.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Lenovo
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/*Description: LCD Data Port config*/
/*Range: DIO_u8PORTRA
 */


#define LCD_DATA_PORT     DIO_PORTD



#define LCD_RS_PORT     DIO_PORTC
#define LCD_RS_PIN        DIO_PIN0

#define LCD_RW_PORT        DIO_PORTC
#define LCD_RW_PIN        DIO_PIN1

#define LCD_E_PORT        DIO_PORTC
#define LCD_E_PIN         DIO_PIN2

#endif /* LCD_CFG_H_ */
