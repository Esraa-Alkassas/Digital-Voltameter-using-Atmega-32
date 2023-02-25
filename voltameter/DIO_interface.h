/*
 * interface.h
 *
 *  Created on: Nov 18, 2022
 *      Author: Lenovo
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_HIGH     1
#define DIO_LOW      0

#define DIO_OUTPUT   1
#define DIO_INPUT    0      // i'm not sure from this two lines , originally it sends error here and for the previeous two lines

#define PORT_OUTPUT   0xff
#define PORT_INPUT    0x00

void DIO_vidSetPinVal (u8 PortId, u8 pinId, u8 val);
void DIO_vidSetPinDir (u8 PortId, u8 pinId, u8 dir);
void DIO_vidSetPortVal (u8 PortId, u8 val);
void DIO_vidSetPortDir (u8 PortId, u8 val);
u8   DIO_u8GetPinValue (u8 PortId, u8 pinId);


// ports definition
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

//pins definition
#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

#endif /* DIO_INTERFACE_H_ */
