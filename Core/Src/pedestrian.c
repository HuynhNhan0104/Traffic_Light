/*
 * pedestrian.c
 *
 *  Created on: Dec 12, 2022
 *      Author: NHAN
 */

#include "pedestrian.h"
int state_of_pedestrian = OFF_PEDESTRIAN;
int freq = 0;
int buzzer_flag = 0;
int safe_time = 3000;

int tik_tek = 1;

void turn_on_buzzer(){
	freq = 200;
	buzzer_flag = 1;
	set_timer(TIMER_BUZZER, 500);
}


void turn_off_buzzer(){
	freq = 0;
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

		if(is_pressed( BUTTON_0 )){
			if(mode == NORMAL_MODE){
				set_timer(TIMER_PEDESTRIAN ,duration_time_of_RED + duration_time_of_YELLOW+ duration_time_of_GREEN);
				if(state_led_traffic_1 != RED){
					state_of_pedestrian = RED_PEDESTRIAN;
					turn_on_led_PED(RED);
				}
				else if(get_time_of_counter(TIMER_LED_TRAFFIC_1) <= safe_time && state_led_traffic_1 == RED){
					state_of_pedestrian = RED_PEDESTRIAN;
					turn_on_led_PED(RED);
				}
				else {
					state_of_pedestrian = GREEN_PEDESTRIAN;
					turn_on_buzzer();
					turn_on_led_PED(GREEN);
				}
			}
			else{
				state_of_pedestrian = YELLOW_PEDESTRIAN;
				turn_on_led_PED(YELLOW);
			}
		}

		if(mode != NORMAL_MODE){
			state_of_pedestrian = YELLOW_PEDESTRIAN;
			turn_on_led_PED(YELLOW);
		}

	break;
	case RED_PEDESTRIAN:

		if(is_pressed( BUTTON_0 )){
			set_timer( TIMER_PEDESTRIAN ,  duration_time_of_RED + duration_time_of_YELLOW+ duration_time_of_GREEN);
		}


		if(is_timer_timeout( TIMER_PEDESTRIAN )){
			turn_off_led_PED();
			state_of_pedestrian = OFF_PEDESTRIAN;
		}


		if(get_time_of_counter(TIMER_LED_TRAFFIC_1) > safe_time && state_led_traffic_1 == RED){
			turn_on_buzzer();
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
			set_timer( TIMER_PEDESTRIAN ,  duration_time_of_RED + duration_time_of_YELLOW+ duration_time_of_GREEN);
		}
		if(is_timer_timeout( TIMER_PEDESTRIAN )){
			turn_off_buzzer();
			turn_off_led_PED();
			state_of_pedestrian = OFF_PEDESTRIAN;
		}

		if(get_time_of_counter(TIMER_LED_TRAFFIC_1) <= safe_time && state_led_traffic_1 == RED){
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
