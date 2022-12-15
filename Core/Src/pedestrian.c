/*
 * pedestrian.c
 *
 *  Created on: Dec 14, 2022
 *      Author: NHAN
 */




//mode of system
extern int mode;

#define INIT_SYSTEM														0
#define NORMAL_MODE													1
#define MODIFY_RED_MODE											2
#define MODIFY_YELLOW_MODE										3
#define MODIFY_GREEN_MODE										4
//state of led traffic
#define RED																		10
#define YELLOW																11
#define GREEN																	12
#define OFF																		14




//Timer
#define TIME_CYCLE 														10 //(10ms)
#define NUMBER_OF_TIMER												15

#define TIMER_BUTTON_0												0
#define TIMER_BUTTON_1												1
#define TIMER_BUTTON_2												2
#define TIMER_BUTTON_3												3

#define TIMER_LED_TRAFFIC_1											4
#define TIMER_LED_TRAFFIC_2											5
#define TIMER_BLINKING_LED												6

#define TIMER_PEDESTRIAN												7



//SINGLE LED OF TRAFFIC

extern int duration_time_of_RED;
extern int duration_time_of_YELLOW;
extern int duration_time_of_GREEN;

extern int buffer_duration_time;

extern int state_led_traffic_1;
extern int state_led_traffic_2;

// BUTTON
#define NUMBER_OF_BUTTON																			4

#define BUTTON_IS_PRESSED																			GPIO_PIN_RESET
#define BUTTON_IS_RELEASED																			GPIO_PIN_SET

#define BUTTON_RELEASED																				20
#define BUTTON_PRESSED																				21
#define BUTTON_PRESSED_3S																			22

#define BUTTON_0																							0
#define BUTTON_1																							1
#define BUTTON_2																							2
#define BUTTON_3																							3
// PEDESTRIAN
#define OFF_PEDESTRIAN																						30
#define RED_PEDESTRIAN																					31
#define GREEN_PEDESTRIAN 																				32
#define YELLOW_PEDESTRIAN																				33



extern int cycle_buzzer;
