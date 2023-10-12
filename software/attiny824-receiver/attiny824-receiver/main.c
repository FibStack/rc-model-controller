/*
* Copyright (c) 2023, FibStack
* All rights reserved.
*
* This source code is licensed under the MIT license found in the
* LICENSE file in the root directory of this source tree.
*/
#include <avr/io.h>
#include "receiver.h"

/************************************************************************/
/*                              RECEIVER                                */
/************************************************************************/

int main(void)
{
	USART0_init();
	PORTA_init();
	TCA0_init();
	
    while(1)
    {
		uint8_t byte = USART0_read();
		if (byte == 0xFF)
		{
			// Start byte has been read, read the other values
			throttle =  USART0_read();
			steering =  USART0_read();
			outputs = USART0_read();
			uint8_t crc_received = USART0_read();
			uint8_t data[3] = {throttle, steering, outputs};
			uint8_t crc_computed = crc_8(data, 3);
			if ( crc_received == crc_computed)
			{
				PORTA.OUT = outputs << 4;
				TCA0.SPLIT.LCMP0 = throttle;
				TCA0.SPLIT.LCMP1 = STEERING_OFFSET + (steering * STEERING_RANGE/255);
			}
			
		}
    }
}
