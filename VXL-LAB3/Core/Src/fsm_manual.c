/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */

#include "fsm_manual.h"
#include "fsm_automatic.h"
#include "fsm_settings.h"


void fsm_manual_run() {
	switch(status) {
	case MAN_RED_GREEN:
		set_red0_green1();
		update7SEG(4); // Turn off all led
		if (isKeyPressed(1)) {
			status = MAN_RED_YELLOW;
		}
		if (getFlag(1)) {
			setCount(0, RedTime());
			setCount(1, GreenTime());
			setBuffer(getCount(0), getCount(1));
			setTimer(1,1250);
			setTimer(2,250);
			countAgain();
			status = AUTO_RED_YELLOW;
		}
		if (isKeyPressed(0)) {
				status = SET_REDTIME;
		}
		break;

	case MAN_RED_YELLOW:
		set_red0_amber1();
		update7SEG(4); // Turn off all led
		if (isKeyPressed(1)) {
			status = MAN_GREEN_RED;
		}
		if (getFlag(1)) {
			setCount(0, AmberTime());
			setCount(1, AmberTime());
			setBuffer(getCount(0), getCount(1));
			setTimer(1,1250);
			setTimer(2,250);
			countAgain();
			status = AUTO_RED_YELLOW;
		}
		if (isKeyPressed(0)) {
				status = SET_REDTIME;
		}
		break;

	case MAN_GREEN_RED:
		set_green0_red1();
		update7SEG(4); // Turn off all led
		if (isKeyPressed(1)) {
			status = MAN_YELLOW_RED;
		}
		if (getFlag(1)) {
			setCount(0, GreenTime());
			setCount(1, RedTime());
			setBuffer(getCount(0), getCount(1));
			setTimer(1,1250);
			setTimer(2,250);
			countAgain();
			status = AUTO_GREEN_RED;
		}
		if (isKeyPressed(0)) {
				status = SET_REDTIME;
		}
		break;

	case MAN_YELLOW_RED:
		set_amber0_red1();
		update7SEG(4); // Turn off all led
		if (isKeyPressed(1)) {
			status = MAN_RED_GREEN;
		}
		if (getFlag(1)) {
			setCount(0, AmberTime());
			setCount(1, AmberTime());
			setBuffer(getCount(0), getCount(1));
			setTimer(1,1250);
			setTimer(2,250);
			countAgain();
			status = AUTO_YELLOW_RED;
		}
		if (isKeyPressed(0)) {
			status = SET_REDTIME;
			setTimer(2,250);
			setTimer(1,10000);
		}
		break;
	default:
		break;
	}
}
