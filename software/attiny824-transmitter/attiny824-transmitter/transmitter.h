/*
* Copyright (c) 2023, FibStack
* All rights reserved.
*
* This source code is licensed under the MIT license found in the
* LICENSE file in the root directory of this source tree.
*/

#ifndef TRANSMITTER_H_
#define TRANSMITTER_H_

#include <avr/io.h>

#define F_CPU 3333333
#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (16 * (float)BAUD_RATE)) + 0.5)
#define ADC_CHANNELS 2
#define PA4_INTERRUPT PORTA.INTFLAGS & PIN4_bm
#define PA5_INTERRUPT PORTA.INTFLAGS & PIN5_bm
#define PA6_INTERRUPT PORTA.INTFLAGS & PIN6_bm
#define PA7_INTERRUPT PORTA.INTFLAGS & PIN7_bm

extern uint8_t switch_state;
extern uint8_t adc_muxpos[ADC_CHANNELS];
extern uint8_t adc_channel;
extern uint8_t throttle;
extern uint8_t steering;
extern uint8_t crc8_table[256];

extern void USART0_init();
extern void USART0_sendByte(uint8_t byte);
extern void PORTA_init();

extern void ADC0_init();
extern void ADC0_start();
extern void ADC0_clear_interrupt_flag();
extern void ADC0_process();
extern uint8_t ADC_adjust_value(uint8_t value);

extern uint8_t crc_8(uint8_t *data, uint8_t len);

#endif /* TRANSMITTER_H_ */