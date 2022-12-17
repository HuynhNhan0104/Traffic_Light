/*
 * led_7_seg.c
 *
 *  Created on: Dec 12, 2022
 *      Author: NHAN
 */
#include "led_7_seg.h"

int buffer_output [NUMBER_OF_BUFFER] = {0};


void update_buffer_high(int number){
	number /= 1000;
	buffer_output[0] = number/10;
	buffer_output[1] = number%10;
}
void update_buffer_low(int number){
	number /= 1000;
	buffer_output[2] = number/10;
	buffer_output[3] = number%10;
}



