/*
 * traffic_led.h
 *
 *  Created on: Dec 14, 2022
 *      Author: NHAN
 */

#ifndef INC_TRAFFIC_LED_H_
#define INC_TRAFFIC_LED_H_


#include "global.h"
#include "main.h"
#include "timer.h"
#include "button.h"


extern int is_on;
void turn_on_traffic_led_1(int state);
void turn_off_traffic_led_1();
void turn_on_traffic_led_2(int state);
void turn_off_traffic_led_2();
void blinking_led_traffic(int state);


#endif /* INC_TRAFFIC_LED_H_ */
