/*
 * traffic_led.c
 *
 *  Created on: Dec 14, 2022
 *      Author: NHAN
 */


#include "traffic_led.h"

int is_on = 0;


void turn_on_traffic_led_1(int state){
	switch(state){
		case RED:
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
		break;
		case YELLOW:
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
		break;
		case GREEN:
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
		break;
		default:
		break;
	}
}

void turn_off_traffic_led_1(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
}

void turn_on_traffic_led_2(int state){
	switch(state){
		case RED:
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
		break;
		case YELLOW:
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		break;
		case GREEN:
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		break;
		case OFF:
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
		break;
		default:
		break;
	}
}
void turn_off_traffic_led_2(){
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
}

void blinking_led_traffic(int state){
	if(is_timer_timeout( TIMER_BLINKING_LED )){
		if(is_on){
			turn_on_traffic_led_1(state);
			turn_on_traffic_led_2(state);
			is_on = 0;
		}
		else{
			turn_off_traffic_led_1();
			turn_off_traffic_led_2();
			is_on = 1;
		}
		set_timer(TIMER_BLINKING_LED, 500);
	}
}


