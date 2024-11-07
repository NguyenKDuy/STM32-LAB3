/*
 * traffic_light.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */

#include <traffic_light.h>
#include <led7_segment.h>
// - ways
void set_off0_off1(){
	HAL_GPIO_WritePin(led_red0_GPIO_Port, led_red0_Pin, SET);
	HAL_GPIO_WritePin(led_amber0_GPIO_Port, led_amber0_Pin, SET);
	HAL_GPIO_WritePin(led_green0_GPIO_Port, led_green0_Pin, SET);
	HAL_GPIO_WritePin(led_red1_GPIO_Port, led_red1_Pin, SET);
	HAL_GPIO_WritePin(led_amber1_GPIO_Port, led_amber1_Pin, SET);
	HAL_GPIO_WritePin(led_green1_GPIO_Port, led_green1_Pin, SET);
}

void set_red0_green1(){
	HAL_GPIO_WritePin(led_red0_GPIO_Port, led_red0_Pin, RESET);
	HAL_GPIO_WritePin(led_amber0_GPIO_Port, led_amber0_Pin, SET);
	HAL_GPIO_WritePin(led_green0_GPIO_Port, led_green0_Pin, SET);
	HAL_GPIO_WritePin(led_red1_GPIO_Port, led_red1_Pin, SET);
	HAL_GPIO_WritePin(led_amber1_GPIO_Port, led_amber1_Pin, SET);
	HAL_GPIO_WritePin(led_green1_GPIO_Port, led_green1_Pin, RESET);
}
void set_red0_amber1() {
	HAL_GPIO_WritePin(led_red0_GPIO_Port, led_red0_Pin, RESET);
	HAL_GPIO_WritePin(led_amber0_GPIO_Port, led_amber0_Pin, SET);
	HAL_GPIO_WritePin(led_green0_GPIO_Port, led_green0_Pin, SET);
	HAL_GPIO_WritePin(led_red1_GPIO_Port, led_red1_Pin, SET);
	HAL_GPIO_WritePin(led_amber1_GPIO_Port, led_amber1_Pin, RESET);
	HAL_GPIO_WritePin(led_green1_GPIO_Port, led_green1_Pin, SET);
}
void set_green0_red1() {
	HAL_GPIO_WritePin(led_red0_GPIO_Port, led_red0_Pin, SET);
	HAL_GPIO_WritePin(led_amber0_GPIO_Port, led_amber0_Pin, SET);
	HAL_GPIO_WritePin(led_green0_GPIO_Port, led_green0_Pin, RESET);
	HAL_GPIO_WritePin(led_red1_GPIO_Port, led_red1_Pin, RESET);
	HAL_GPIO_WritePin(led_amber1_GPIO_Port, led_amber1_Pin, SET);
	HAL_GPIO_WritePin(led_green1_GPIO_Port, led_green1_Pin, SET);
}
void set_amber0_red1()
{
	HAL_GPIO_WritePin(led_red0_GPIO_Port, led_red0_Pin, SET);
	HAL_GPIO_WritePin(led_amber0_GPIO_Port, led_amber0_Pin, RESET);
	HAL_GPIO_WritePin(led_green0_GPIO_Port, led_green0_Pin, SET);
	HAL_GPIO_WritePin(led_red1_GPIO_Port, led_red1_Pin, RESET);
	HAL_GPIO_WritePin(led_amber1_GPIO_Port, led_amber1_Pin, SET);
	HAL_GPIO_WritePin(led_green1_GPIO_Port, led_green1_Pin, SET);

}

void setallRed() {
	HAL_GPIO_WritePin(led_red0_GPIO_Port, led_red0_Pin, RESET);
	HAL_GPIO_WritePin(led_amber0_GPIO_Port, led_amber0_Pin, SET);
	HAL_GPIO_WritePin(led_green0_GPIO_Port, led_green0_Pin, SET);
	HAL_GPIO_WritePin(led_red1_GPIO_Port, led_red1_Pin, RESET);
	HAL_GPIO_WritePin(led_amber1_GPIO_Port, led_amber1_Pin, SET);
	HAL_GPIO_WritePin(led_green1_GPIO_Port, led_green1_Pin, SET);
}
void setallGreen() {
	HAL_GPIO_WritePin(led_red0_GPIO_Port, led_red0_Pin, SET);
	HAL_GPIO_WritePin(led_amber0_GPIO_Port, led_amber0_Pin, SET);
	HAL_GPIO_WritePin(led_green0_GPIO_Port, led_green0_Pin, RESET);
	HAL_GPIO_WritePin(led_red1_GPIO_Port, led_red1_Pin, SET);
	HAL_GPIO_WritePin(led_amber1_GPIO_Port, led_amber1_Pin, SET);
	HAL_GPIO_WritePin(led_green1_GPIO_Port, led_green1_Pin, RESET);
}
void setallAmber() {
	HAL_GPIO_WritePin(led_red0_GPIO_Port, led_red0_Pin, SET);
	HAL_GPIO_WritePin(led_amber0_GPIO_Port, led_amber0_Pin, RESET);
	HAL_GPIO_WritePin(led_green0_GPIO_Port, led_green0_Pin, SET);
	HAL_GPIO_WritePin(led_red1_GPIO_Port, led_red1_Pin, SET);
	HAL_GPIO_WritePin(led_amber1_GPIO_Port, led_amber1_Pin, RESET);
	HAL_GPIO_WritePin(led_green1_GPIO_Port, led_green1_Pin, SET);
}
void setallOff() {
	HAL_GPIO_WritePin(led_red0_GPIO_Port, led_red0_Pin, SET);
	HAL_GPIO_WritePin(led_amber0_GPIO_Port, led_amber0_Pin, SET);
	HAL_GPIO_WritePin(led_green0_GPIO_Port, led_green0_Pin, SET);
	HAL_GPIO_WritePin(led_red1_GPIO_Port, led_red1_Pin, SET);
	HAL_GPIO_WritePin(led_amber1_GPIO_Port, led_amber1_Pin, SET);
	HAL_GPIO_WritePin(led_green1_GPIO_Port, led_green1_Pin, SET);
}
