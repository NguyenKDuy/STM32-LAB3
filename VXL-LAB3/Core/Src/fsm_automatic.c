/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */


#include "fsm_automatic.h"

int greentime;
int redtime;
int ambertime;




void fsm_automatic_run() {
	switch(status){
	case MODE0:
		//TODO:
		set_off0_off1();
		setGreenTime(3000);
		setRedTime(5000);
		setAmberTime(2000);
		setTimer(1, GreenTime());
		status = AUTO_RED_GREEN;

		break;
	case AUTO_RED_GREEN:
		set_red0_green1();
		//auto switch to the next light if finish count
		if (getFlag(1) == 1) {
			status = AUTO_RED_YELLOW;
			setTimer(1, AmberTime());
		}
		//handle mode manual
		if (isKeyPressed(0)) {
			status = MAN_RED_GREEN;
			setTimer(1, 10000);
		}
		break;
	case AUTO_RED_YELLOW:
		set_red0_amber1();
		//auto switch to the next light if finish count
		if (getFlag(1) == 1) {
			status = AUTO_GREEN_RED;
			setTimer(1, GreenTime());
		}
		//handle mode manual
		if (isKeyPressed(0)) {
			setTimer(1, 10000);
			status = MAN_RED_YELLOW;
		}
		break;
	case AUTO_GREEN_RED:
		set_green0_red1();
		//auto switch to the next light if finish count
		if (getFlag(1) == 1) {
			status = AUTO_YELLOW_RED;
			setTimer(1, AmberTime());
		}
		//handle mode manual
		if (isKeyPressed(0)) {
			setTimer(1, 10000);
			status = MAN_GREEN_RED;
		}
		break;
	case AUTO_YELLOW_RED:
		set_amber0_red1();
		//auto switch to the next light if finish count
		if (getFlag(1) == 1) {
			status = AUTO_RED_GREEN;
			setTimer(1, GreenTime());
		}
		//handle mode manual
		if (isKeyPressed(0)) {
			setTimer(1, 10000);
			status = MAN_YELLOW_RED;
		}
		break;
	default:
		break;
	}

}

	int GreenTime() {
		return greentime;
	}
	int RedTime() {
		return redtime;
	}
	int AmberTime() {
		return ambertime;
	}

	void setGreenTime(int value) {
		greentime = value;
	}
	void setRedTime (int value) {
		redtime = value;
	}
	void setAmberTime(int value){
		ambertime = value;
	}

