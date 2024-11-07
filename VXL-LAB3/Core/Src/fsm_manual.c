/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */

#include "fsm_manual.h"
#include "global.h"
#include "fsm_automatic.h"


void fsm_manual_run() {
	switch(status) {
	case MAN_RED_GREEN:
		set_red0_green1();
		if (isKeyPressed(1)) {
			status = MAN_RED_YELLOW;
		}
		if (getFlag(1)) {
			setTimer(1, GreenTime());
			status = AUTO_RED_YELLOW;
		}
		if (isKeyPressed(0)) {
				status = SET_REDTIME;
		}
		break;

	case MAN_RED_YELLOW:
		set_red0_amber1();
		if (isKeyPressed(1)) {
			status = MAN_GREEN_RED;
		}
		if (getFlag(1)) {
			setTimer(1, AmberTime());
			status = AUTO_RED_YELLOW;
		}
		if (isKeyPressed(0)) {
				status = SET_REDTIME;
		}
		break;

	case MAN_GREEN_RED:
		set_green0_red1();
		if (isKeyPressed(1)) {
			status = MAN_YELLOW_RED;
		}
		if (getFlag(1)) {
			setTimer(1, GreenTime());
			status = AUTO_GREEN_RED;
		}
		if (isKeyPressed(0)) {
				status = SET_REDTIME;
		}
		break;

	case MAN_YELLOW_RED:
		set_amber0_red1();
		if (isKeyPressed(1)) {
			status = MAN_RED_GREEN;
		}
		if (getFlag(1)) {
			setTimer(1, AmberTime());
			status = AUTO_YELLOW_RED;
		}
		if (isKeyPressed(0)) {
				status = SET_REDTIME;
		}
		break;
	default:
		break;
	}
}
