/*
 * button.h
 *
 *  Created on: Oct 29, 2024
 *      Author: My Laptop
 */
#include "main.h"
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL GPIO_PIN_SET
#define PRESSED GPIO_PIN_RESET

#define NUM_BUT 3
extern int button_flag[NUM_BUT];

void getKeyInput();
int isKeyPressed(int index);
int isReadfrom (int index);


#endif /* INC_BUTTON_H_ */
