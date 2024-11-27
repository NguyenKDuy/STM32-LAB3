/*
 * button.c
 *
 *  Created on: Oct 29, 2024
 *      Author: My Laptop
 */

#include "button.h"


int KeyReg0[NUM_BUT] = {[0 ... NUM_BUT-1] = NORMAL};
int KeyReg1[NUM_BUT] = {[0 ... NUM_BUT-1] = NORMAL};
int KeyReg2[NUM_BUT] = {[0 ... NUM_BUT-1] = NORMAL};
int KeyReg3[NUM_BUT] = {[0 ... NUM_BUT-1] = NORMAL};

int button_counter[NUM_BUT];
int counter[NUM_BUT] = {100,100,100};
int button_flag[NUM_BUT];


void getKeyInput(){
	for (int i = 0; i < NUM_BUT; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = isReadfrom(i);
		if (KeyReg0[i] == KeyReg1[i] && KeyReg1[i] == KeyReg2[i]){
			if (KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED){
					button_counter[i] = counter[i];
					button_flag[i] = 1;
				}
			}
			else {
				button_counter[i]--;
				if (button_counter[i] == 0) {
					KeyReg3[i] = NORMAL;
				}
			}
		}
	}
}
int isKeyPressed(int index) {
	if (index <NUM_BUT) {
		if (button_flag[index] == 1){
			button_flag[index] = 0;
			return 1;
		}
		return 0;
	}
	return -1;
}



int isReadfrom (int index) {
	if (index < NUM_BUT) {
		switch (index){
			case 0:
				return HAL_GPIO_ReadPin(Button0_GPIO_Port, Button0_Pin);
				break;
			case 1:
				return HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
				break;
			case 2:
				return HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
				break;
			default:
				break;
		}
	}
	return -1;
}
