/*
 * button.h
 *
 *  Created on: Dec 14, 2022
 *      Author: NHAN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_


#include "global.h"
#include "main.h"
#include "timer.h"
extern int state_of_button[NUMBER_OF_BUTTON];
extern int flag_for_pressed[NUMBER_OF_BUTTON];
extern int flag_for_pressed_3s[NUMBER_OF_BUTTON];

extern int register0_key[NUMBER_OF_BUTTON];
extern int register1_key[NUMBER_OF_BUTTON];
extern int register2_key[NUMBER_OF_BUTTON];
extern int button_buffer[NUMBER_OF_BUTTON];

int is_pressed(int index);
int is_pressed_3s(int index);
int is_button_released(int index);

void read_input();
void fsm_for_button();

#endif /* INC_BUTTON_H_ */
