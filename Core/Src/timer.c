/*
 * timer.c
 *
 *  Created on: Dec 14, 2022
 *      Author: NHAN
 */


#include "timer.h"

int timer_counter[NUMBER_OF_TIMER] = {0};
int timer_flag[NUMBER_OF_TIMER] = {0};

void set_timer(int index, int duration){
	timer_counter[index] = duration/TIME_CYCLE;
}
void clear_timer(int index){
	timer_counter[index] = 0;
	timer_flag[index] = 0;
}


int get_time_of_counter(int index){
	return timer_counter[index]*TIME_CYCLE;
}


int is_timer_timeout(int index){
	if(timer_flag[index]){
		timer_flag[index] = 0;
		return 1;
	}
	return 0;
}
void timer_run(){
	for(int i = 0 ; i < NUMBER_OF_TIMER; ++i){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0) timer_flag[i] = 1;
		}
	}
}

