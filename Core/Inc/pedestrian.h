/*
 * pedestrian.h
 *
 *  Created on: Dec 12, 2022
 *      Author: NHAN
 */

#ifndef INC_PEDESTRIAN_H_
#define INC_PEDESTRIAN_H_


#include "main.h"
#include "timer.h"
#include "button.h"
#include "fsm_traffic.h"
#include "global.h"


extern int freq;
extern int buzzer_flag;
extern int tik_tek;

void turn_on_buzzer();
void turn_off_buzzer();

void turn_on_led_PED(int state);
void turn_off_led_PED();

void fsm_pedestrian_run();


#endif /* INC_PEDESTRIAN_H_ */
