/*
* Copyright (c) 2023, FibStack
* All rights reserved.
*
* This source code is licensed under the MIT license found in the
* LICENSE file in the root directory of this source tree.
*/

#ifndef RECEIVER_H_
#define RECEIVER_H_

#define F_CPU 3333333
#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (16 * (float)BAUD_RATE)) + 0.5)
#define DEFAULT_STEERING 127
#define DEFAULT_THROTTLE 0
#define STEERING_OFFSET 13
#define STEERING_RANGE 13

extern void USART0_init();
extern uint8_t USART0_read();
extern void PORTA_init();
extern void TCA0_init();

extern uint8_t throttle;
extern uint8_t steering;
extern uint8_t outputs;

extern uint8_t crc8_table[256];
extern uint8_t crc_8(uint8_t *data, uint8_t len);
#endif /* RECEIVER_H_ */