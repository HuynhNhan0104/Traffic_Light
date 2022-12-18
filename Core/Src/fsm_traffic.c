/*
 * fsm_traffic.c
 *
 *  Created on: Dec 14, 2022
 *      Author: NHAN
 */


#include "fsm_traffic.h"



void fsm_traffic_1_run(){
	switch(state_led_traffic_1){
		case RED:
			//TODO
			//STATE STRANSION
			// time out, RED-->GREEN
			if(is_timer_timeout(TIMER_LED_TRAFFIC_1)){
				state_led_traffic_1 =GREEN;
				turn_on_traffic_led_1(state_led_traffic_1);
				set_timer(TIMER_LED_TRAFFIC_1,duration_time_of_GREEN);
			}
		break;

		case YELLOW:
			//TODO
			//STATE STRANSION
			// time out, YELLOW --> RED
			if(is_timer_timeout(TIMER_LED_TRAFFIC_1)){
				state_led_traffic_1 = RED;
				turn_on_traffic_led_1(state_led_traffic_1);
				set_timer(TIMER_LED_TRAFFIC_1,duration_time_of_RED);
			}
		break;

		case GREEN:
			//TODO
			//STATE STRANSION
			// timeout, GREEN-->YELLOW
			if(is_timer_timeout(TIMER_LED_TRAFFIC_1)){
				state_led_traffic_1 = YELLOW;
				turn_on_traffic_led_1(state_led_traffic_1);
				set_timer(TIMER_LED_TRAFFIC_1,duration_time_of_YELLOW);
			}
		break;
		default:
		break;
	}
}


void fsm_traffic_2_run(){
	switch(state_led_traffic_2){
		case RED:
			//TODO
			//STATE STRANSION
			// time out, RED-->GREEN
			if(is_timer_timeout(TIMER_LED_TRAFFIC_2)){
				state_led_traffic_2 = GREEN;
				turn_on_traffic_led_2(state_led_traffic_2);
				set_timer(TIMER_LED_TRAFFIC_2,duration_time_of_GREEN);
			}
		break;
		case YELLOW:
			//TODO
			//STATE STRANSION
			// time out, YELLOW --> RED
			if(is_timer_timeout(TIMER_LED_TRAFFIC_2)){
				state_led_traffic_2 = RED;
				turn_on_traffic_led_2(state_led_traffic_2);
				set_timer(TIMER_LED_TRAFFIC_2,duration_time_of_RED);
			}
		break;
		case GREEN:
			//TODO
			//STATE STRANSION
			// timeout, GREEN-->YELLOW
			if(is_timer_timeout(TIMER_LED_TRAFFIC_2)){
				state_led_traffic_2 = YELLOW;
				turn_on_traffic_led_2(state_led_traffic_2);
				set_timer(TIMER_LED_TRAFFIC_2,duration_time_of_YELLOW);
			}
		break;
		default:
		break;
	}
}


void fsm_system_run(){
	switch(mode){
		case INIT_SYSTEM:
			//TODO
			state_led_traffic_1 = RED;
			turn_on_traffic_led_1(state_led_traffic_1);
			state_led_traffic_2 = GREEN;
			turn_on_traffic_led_2(state_led_traffic_2);

			set_timer(TIMER_LED_TRAFFIC_1, duration_time_of_RED);
			set_timer(TIMER_LED_TRAFFIC_2, duration_time_of_GREEN);

			update_buffer_high(get_time_of_counter(TIMER_LED_TRAFFIC_1));
			update_buffer_low(get_time_of_counter(TIMER_LED_TRAFFIC_2));
			//STATE STRANSITION
			mode = NORMAL_MODE;
		break;
		case NORMAL_MODE:
			//TODO
			fsm_traffic_1_run();
			fsm_traffic_2_run();
			update_buffer_high(get_time_of_counter(TIMER_LED_TRAFFIC_1));
			update_buffer_low(get_time_of_counter(TIMER_LED_TRAFFIC_2));

			//STATE STRANSITION
			//button 1 is pressed,  NORMAl_MODE -> MODIFY_RED_MODE
			if(is_pressed(BUTTON_1)){
				clear_timer(TIMER_LED_TRAFFIC_1);
				clear_timer(TIMER_LED_TRAFFIC_2);
				state_led_traffic_1 = RED;
				turn_on_traffic_led_1(state_led_traffic_1);
				state_led_traffic_2 = RED;
				turn_on_traffic_led_2(state_led_traffic_2);

				is_led_ON= 0;
				set_timer(TIMER_BLINKING_LED, 500);
				buffer_duration_time = duration_time_of_RED;


				update_buffer_high(1000);
				update_buffer_low(buffer_duration_time);
				mode = MODIFY_RED_MODE;
			}
		break;
		case MODIFY_RED_MODE:
			//todo

			blinking_led_traffic(state_led_traffic_1);



			//button 2 is pressed, buffer_duration_time increase 1, if buffer exceed 99, buffer = 0;
			if(is_pressed(BUTTON_2)){
				buffer_duration_time = (buffer_duration_time +1000)% (100*1000);
				update_buffer_low(buffer_duration_time);
			}
			//button 3 is pressed,  duration time of system = buffer_duration_time;
			if(is_pressed(BUTTON_3)){
				duration_time_of_RED = buffer_duration_time;
			}
			//STATE STRANSITION
			//button 1 is pressed, MODIFY_RED_MODE -> MODIFY_YELLOW_MODE
			if(is_pressed(BUTTON_1)){
				state_led_traffic_1 = YELLOW;
				turn_on_traffic_led_1(state_led_traffic_1);
				state_led_traffic_2 = YELLOW;
				turn_on_traffic_led_2(state_led_traffic_2);

				is_led_ON= 0;
				set_timer(TIMER_BLINKING_LED, 500);
				buffer_duration_time = duration_time_of_YELLOW;

				update_buffer_high(2000);
				update_buffer_low(buffer_duration_time);

				mode = MODIFY_YELLOW_MODE;
			}
		break;
		case MODIFY_YELLOW_MODE:
			blinking_led_traffic(state_led_traffic_1);

			//button 2 is pressed, buffer_duration_time increase 1, if buffer exceed 99, buffer = 0;
			if(is_pressed(BUTTON_2)){
				buffer_duration_time = (buffer_duration_time +1000)% (100*1000);
				update_buffer_low(buffer_duration_time);
			}
			//button 3 is pressed,  duration time of system = buffer_duration_time;
			if(is_pressed(BUTTON_3)){
				duration_time_of_YELLOW = buffer_duration_time;
			}

			//STATE STRANSITION
			//button 1 is pressed,MODIFY_YELLOW_MODE  ->  MODIFY_GREEN_MODE
			if(is_pressed(BUTTON_1)){
				state_led_traffic_1 = GREEN;
				turn_on_traffic_led_1(state_led_traffic_1);
				state_led_traffic_2 = GREEN;
				turn_on_traffic_led_2(state_led_traffic_2);

				is_led_ON= 0;
				set_timer(TIMER_BLINKING_LED, 500);
				buffer_duration_time = duration_time_of_GREEN;

				update_buffer_high(3000);
				update_buffer_low(buffer_duration_time);

				mode = MODIFY_GREEN_MODE;
			}
		break;
		case MODIFY_GREEN_MODE:
			blinking_led_traffic(state_led_traffic_1);
			//button 2 is pressed, buffer_duration_time increase 1, if buffer exceed 99, buffer = 0;
			if(is_pressed(BUTTON_2)){
				buffer_duration_time = (buffer_duration_time +1000)% (100*1000);
				update_buffer_low(buffer_duration_time);
			}
			//button 3 is pressed,  duration time of system = buffer_duration_time;
			if(is_pressed(BUTTON_3)){
				duration_time_of_GREEN = buffer_duration_time;
			}

			//STATE STRANSITION
			//button 1 is pressed, MODIFY_GREEN_MODE -> NORMAL_MODE
			if(is_pressed(BUTTON_1)){
				clear_timer(TIMER_BLINKING_LED);
				state_led_traffic_1 = RED;
				turn_on_traffic_led_1(state_led_traffic_1);
				state_led_traffic_2 = GREEN;
				turn_on_traffic_led_2(state_led_traffic_2);
				set_timer(TIMER_LED_TRAFFIC_1, duration_time_of_RED);
				set_timer(TIMER_LED_TRAFFIC_2, duration_time_of_GREEN);
				update_buffer_high(get_time_of_counter(TIMER_LED_TRAFFIC_1));
				update_buffer_low(get_time_of_counter(TIMER_LED_TRAFFIC_2));
				mode = NORMAL_MODE;
			}
		break;
		default:
		break;
	}
}



