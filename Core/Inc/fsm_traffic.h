/*
 * fsm_traffic.h
 *
 *  Created on: Dec 14, 2022
 *      Author: NHAN
 */

#ifndef INC_FSM_TRAFFIC_H_
#define INC_FSM_TRAFFIC_H_

#include "global.h"
#include "timer.h"
#include "button.h"
#include "traffic_led.h"
#include "led_7_seg.h"




void fsm_traffic_1_run();
void fsm_traffic_2_run();

void fsm_system_run();


#endif /* INC_FSM_TRAFFIC_H_ */
