/*
 * software_interrupt.h
 *
 *  Created on: Oct 29, 2024
 *      Author: My Laptop
 */
#include "main.h"
#ifndef INC_SOFTWARE_INTERRUPT_H_
#define INC_SOFTWARE_INTERRUPT_H_

#define TIME_CYCLE 10
#define NUM_TIM 3

void setTimer(int index, int duration);
void timerRun();
int getFlag (int index);

#endif /* INC_SOFTWARE_INTERRUPT_H_ */

