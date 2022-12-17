/*
 * led_7_seg.h
 *
 *  Created on: Dec 12, 2022
 *      Author: NHAN
 */

#ifndef INC_LED_7_SEG_H_
#define INC_LED_7_SEG_H_
#include "global.h"
#define NUMBER_OF_BUFFER 																4
extern int buffer_output [NUMBER_OF_BUFFER];


void update_buffer_high(int number);
void update_buffer_low(int number);



#endif /* INC_LED_7_SEG_H_ */
