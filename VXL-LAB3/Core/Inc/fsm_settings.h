/*
 * fsm_settings.h
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */

#ifndef INC_FSM_SETTINGS_H_
#define INC_FSM_SETTINGS_H_

#include "global.h"
void fsm_mode();
void fsm_increase();
void fsm_confirm();
int GreenTime();
int RedTime();
int AmberTime();
void setAmberTime(int value);
void setGreenTime(int value);
void setRedTime (int value);
void fsm_SET_REDTIME();
void fsm_SET_AMBERTIME();
void fsm_SET_GREENTIME();


#endif /* INC_FSM_SETTINGS_H_ */
