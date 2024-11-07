/*
 * software_interrupt.c
 *
 *  Created on: Oct 29, 2024
 *      Author: My Laptop
 */

#include "software_interrupt.h"

int timer_flag[NUM_TIM];
int timer_counter[NUM_TIM];

void setTimer(int index ,int duration) {
	if (index < NUM_TIM) {
		timer_counter[index] = duration/TIME_CYCLE;
		timer_flag[index] = 0;
	}
}

void timerRun() {
	for (int i = 0; i < NUM_TIM; i++) {
		if (timer_counter[i] >= 0)
		{
			timer_counter[i] --;
			if (timer_counter[i] <= 0)
			{
				timer_flag[i] = 1;
			}
		}
	}
}

int getFlag (int index) {
	if (index < NUM_TIM) {
		if (timer_flag[index] == 1) {
			timer_flag[index] = 0;
			return 1;
		}
		return 0;
	}
	return -1;
}





