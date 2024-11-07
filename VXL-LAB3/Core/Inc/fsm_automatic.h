/*
 * fsm_automatic.h
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_
#include <global.h>

void fsm_automatic_run();
int GreenTime();
int RedTime();
int AmberTime();
void setAmberTime(int value);
void setGreenTime(int value);
void setRedTime (int value);
#endif /* INC_FSM_AUTOMATIC_H_ */
