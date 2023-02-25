/*
 * ADC_priv.h
 *
 *  Created on: Dec 9, 2022
 *      Author: Lenovo
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_


#define ADC_polling       0       // anhy number .. as i understood from abdullah..
#define adc_Interrupt     1       // same-->any value







/*regisyers and pins definition*/
#define ADMUX             *((volatile u8*) 0x27)

#define REFS1     7
#define REFS0     6
#define ADLAR     5
#define MUX0      0
#define MUX1      1
#define MUX2      2
#define MUX3      3
#define MUX4      4


#define  ADCSRA            *((volatile u8*) 0x26)

#define  ADEN     7
#define  ADSC     6
#define  ADATE    5
#define  ADIF     4
#define  ADIE     3
#define  ADPS2    2
#define  ADPS1    1
#define  ADPS0    0



#define ADC_Data_Reg      *((volatile u16*) 0x24)




#define SFIOR             *((volatile u8*) 0x50)

#define ADTS2      7
#define ADTS1      6
#define ADTS0      5


#endif /* ADC_PRIV_H_ */



/* بصي المفروض اكتب جمب كل سطر كومنت بيوضحه دا لو عازة اكتب كود بروفشنال يعني ...*/
// لكن ، ونظرا لضيق الوقت مش هعمل كدا


