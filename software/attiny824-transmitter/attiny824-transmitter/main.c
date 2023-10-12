/*
* Copyright (c) 2023, FibStack
* All rights reserved.
*
* This source code is licensed under the MIT license found in the
* LICENSE file in the root directory of this source tree.
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "transmitter.h"

/************************************************************************/
/*                            TRANSMITTER                               */
/************************************************************************/

ISR(PORTA_PORT_vect)
{
	if((PA4_INTERRUPT) | (PA5_INTERRUPT) | (PA6_INTERRUPT) | (PA7_INTERRUPT)) {
		switch_state = PORTA.IN >> 4;
		PORTA.INTFLAGS &= PIN4_bm;
		PORTA.INTFLAGS &= PIN5_bm;
		PORTA.INTFLAGS &= PIN6_bm;
		PORTA.INTFLAGS &= PIN7_bm;
	}
}

ISR(ADC0_RESRDY_vect)
{
	ADC0_process();
}

int main(void)
{
	USART0_init();
	PORTA_init();
	ADC0_init();
	switch_state = PORTA.IN >> 4;
	sei();
	
	ADC0_start();
	
	while(1)
	{
		USART0_sendByte(0xFF);
		USART0_sendByte(throttle);
		USART0_sendByte(steering);
		USART0_sendByte(switch_state);
		uint8_t data[3] = {throttle, steering, switch_state};
		USART0_sendByte(crc_8(data, 3));
	}
}
