/*
 * button.c
 *
 *  Created on: Dec 14, 2022
 *      Author: NHAN
 */



#include "button.h"
// gan cac gia trị ban dau cua state_of_button = BUTTON_RELEASED
int state_of_button[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON - 1] = BUTTON_RELEASED};


int flag_for_pressed[NUMBER_OF_BUTTON] = {0};
int flag_for_pressed_3s[NUMBER_OF_BUTTON] = {0};


int is_pressed(int index){
	if(index > NUMBER_OF_BUTTON) return 0;
	if(flag_for_pressed[index]){
		flag_for_pressed[index] = 0;
		return 1;
	}
	return 0;
}
int is_pressed_3s(int index){
	if(index > NUMBER_OF_BUTTON) return 0;
	if(flag_for_pressed_3s[index]){
		flag_for_pressed_3s[index] = 0;
		return 1;
	}
	return 0;
}
int is_button_released(int index){
	if(button_buffer[index] == BUTTON_IS_RELEASED) return 1;
	return 0;
}




int register0_key[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
int register1_key[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
int register2_key[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
int button_buffer[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
void read_input(){
	for(int i = 0 ; i < NUMBER_OF_BUTTON; ++i){
		register0_key[i] = register1_key[i];
		register1_key[i] = register2_key[i];
		switch(i){
		case 0 :
			 register2_key[i] = HAL_GPIO_ReadPin(A0_GPIO_Port, A0_Pin);
			break;
		case 1:
			register2_key[i] = HAL_GPIO_ReadPin(A1_GPIO_Port, A1_Pin);
			break;
		case 2:
			register2_key[i] = HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin);
			break;
		case 3:
			register2_key[i] = HAL_GPIO_ReadPin(A3_GPIO_Port, A3_Pin);
			break;
		default:
			break;
		}

		if(register0_key[i] == register1_key[i] && register1_key[i] == register2_key[i]){
			button_buffer[i] = register2_key[i];
		}
	}
}

void fsm_for_button(){
	for(int i = 0; i < NUMBER_OF_BUTTON; ++i){
		switch(state_of_button[i]){
		case BUTTON_RELEASED:
			if(button_buffer[i] == BUTTON_IS_PRESSED){
				flag_for_pressed[i] = 1;
				set_timer(i, 3000);
				state_of_button[i] = BUTTON_PRESSED;
			}

			break;
		case BUTTON_PRESSED:

			if(is_timer_timeout(i)){
				flag_for_pressed_3s[i] = 1;
				state_of_button[i] = BUTTON_PRESSED_3S;
			}

			if(button_buffer[i] == BUTTON_IS_RELEASED){
				clear_timer(i);
				state_of_button[i] = BUTTON_RELEASED;
			}
			break;
		case BUTTON_PRESSED_3S:

			if(button_buffer[i] == BUTTON_IS_RELEASED){
				state_of_button[i] = BUTTON_RELEASED;
			}

			break;
		default:
			break;



		}
	}
}

