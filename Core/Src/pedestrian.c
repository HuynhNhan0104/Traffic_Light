/*
 * pedestrian.c
 *
 *  Created on: Dec 12, 2022
 *      Author: NHAN
 */

#include "pedestrian.h"

int state_of_pedestrian = OFF_PEDESTRIAN;
int cycle_of_pedestrian = 20000;



int freq = 0;
int buzzer_flag = 0;
int safe_time = 5000;
int time = 0;
int step = 1;



int is_buzzer_active= 1;

void turn_on_buzzer(){
	freq = 500;
	time = 300;
	buzzer_flag = 1;
	set_timer(TIMER_BUZZER, time);
}

void turn_off_buzzer(){
	freq = 0;
	time = 0;
	buzzer_flag = 0;
	clear_timer(TIMER_BUZZER);
}


void turn_on_led_PED(int state){
	switch(state){
		case RED:
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
		break;
		case GREEN:
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		break;
		case YELLOW:
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		break;
		default:
		break;
	}
}
void turn_off_led_PED(){
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
}




void fsm_pedestrian_run(){
	switch(state_of_pedestrian){
	case OFF_PEDESTRIAN:
		cycle_of_pedestrian =( duration_time_of_RED + duration_time_of_YELLOW+ duration_time_of_GREEN) *2;
		if(is_pressed( BUTTON_0 )){
			set_timer(TIMER_PEDESTRIAN ,cycle_of_pedestrian);
			if(state_led_traffic_1 != RED){
				state_of_pedestrian = RED_PEDESTRIAN;
				turn_on_led_PED(RED);
			}
			else {
				state_of_pedestrian = GREEN_PEDESTRIAN;
				turn_on_led_PED(GREEN);
			}
		}

		if(mode != NORMAL_MODE){
			state_of_pedestrian = YELLOW_PEDESTRIAN;
			turn_on_led_PED(YELLOW);
		}

	break;
	case RED_PEDESTRIAN:

		if(is_pressed( BUTTON_0 )){
			set_timer(TIMER_PEDESTRIAN ,cycle_of_pedestrian);
		}


		if(is_timer_timeout( TIMER_PEDESTRIAN )){
			turn_off_led_PED();
			state_of_pedestrian = OFF_PEDESTRIAN;
		}


		if(state_led_traffic_1 == RED){
			state_of_pedestrian = GREEN_PEDESTRIAN;
			turn_on_led_PED(GREEN);
		}

		if(mode != NORMAL_MODE){
			clear_timer( TIMER_PEDESTRIAN );
			turn_on_led_PED(YELLOW);
			state_of_pedestrian = YELLOW_PEDESTRIAN;
		}


	break;
	case GREEN_PEDESTRIAN:


		if(is_pressed( BUTTON_0 )){
			set_timer(TIMER_PEDESTRIAN ,cycle_of_pedestrian);
		}
// bat loa khi chi con 1 khoang thoi gian cuoi
		if(get_time_of_counter(TIMER_LED_TRAFFIC_1) <= safe_time && state_led_traffic_1 == RED){
			if(buzzer_flag == 0) turn_on_buzzer();
		}

		if(is_timer_timeout( TIMER_PEDESTRIAN )){
			turn_off_buzzer();
			turn_off_led_PED();
			state_of_pedestrian = OFF_PEDESTRIAN;
		}

		if(state_led_traffic_1 != RED){
			turn_off_buzzer();
			state_of_pedestrian = RED_PEDESTRIAN;
			turn_on_led_PED(RED);
		}

		if(mode != NORMAL_MODE){
			turn_off_buzzer();
			clear_timer( TIMER_PEDESTRIAN );
			turn_on_led_PED(YELLOW);
			state_of_pedestrian = YELLOW_PEDESTRIAN;
		}
	break;

	case YELLOW_PEDESTRIAN:
		if(mode == NORMAL_MODE){
			turn_off_led_PED();
			state_of_pedestrian = OFF_PEDESTRIAN;
		}
	break;
	default:

	break;
	}


}
