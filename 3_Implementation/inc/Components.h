// Buzzer Header
#ifndef _BUZ_H
#define _BUZ_H
	

	//INCLUDES
	#include	"includes.h"
	

	// DEFINE PORTS
	#define	BUZ_DDR						DDRB
	#define	BUZ_PORT					PORTB
	#define	BUZ_PIN						PB4
	

	//DEFINE MACRO
	#define	buzon()			BUZ_PORT |= _BV(BUZ_PIN)
	#define	buzoff()		BUZ_PORT &= ~_BV(BUZ_PIN)


#endif

// LM35 Header
#ifndef LM35_H
#define LM35_H

#include <LM35.h>
Enum Unity
{
Celsius };

#define LM35_DDR DDRC
#define LM35_PORTPORTC
#define LM35_PIN PC4


#endif

// Smoke MQ2 Header
#ifndef MQ2_H
#define MQ2_H

#include <MQ2.h>

#define LM35_DDR        DDRC
#define LM35_PORT      PORTC
#define LM35_PIN          PC5
#endif
// ADC Header
#ifndef ADC_H
#define ADC_H

#include “includes.h”
#endif
// GSM Header
#ifndef GSM_H
#define GSM_H
#include “includes.h”

#endif

// UART Header
#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include “includes.h”
#define F_CPU 8000000
#define USART_BAUDRATE 9600
#define USART_PRESCALE((F_CPU/(USART_BAUDRATE*16UL))-1)

#endif

// Delay Header
#ifndef DELAY_H
#define DELAY_H

#include “includes.h”
#endif

// LCD Header
#ifndef LCD_H
#define LCD_H

#include “includes.h”
#define OUTPUT    0XFF
#define LCD_DOT  0XFF
#define LCD_SPC   0XFF

#endif

// Send SMS
#ifndef SMS_H
#define SMS_H

#include “includes.h”

#endif
