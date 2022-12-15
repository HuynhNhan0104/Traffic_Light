/*
 * timer.h
 *
 *  Created on: Dec 14, 2022
 *      Author: NHAN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


#include "global.h"

// timer 0, 1, 2, 3 use for button 0, 1, 2, 3
//timer 4 for traffic led 1
//timer 5 for traffic led 2
//timer 6 for blinking 4 led of system
//timer 7 for pedestrian
extern int timer_counter[NUMBER_OF_TIMER];
extern int timer_flag[NUMBER_OF_TIMER];

void set_timer(int index, int duration);
void clear_timer(int index);
int is_timer_timeout(int index);
int get_time_of_counter(int index);
void timer_run();


#endif /* INC_TIMER_H_ */
