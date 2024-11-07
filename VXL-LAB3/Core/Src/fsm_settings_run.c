/*
 * fsm_settings_run.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */
#include <fsm_settings.h>
#include <fsm_automatic.h>
int toggle = 0;
int greentime = 92;
int redtime = 98;
int ambertime = 6;

int tmp_greentime = 92;
int tmp_redtime = 98;
int tmp_ambertime = 6;

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

void fsm_settings_run () {
	switch (status) {
	case SET_REDTIME:
		setBuffer(tmp_redtime, 2);
		if (isKeyPressed(0)) {
			setTimer(1,10000);
			status = SET_AMBERTIME;
			toggle = 0;
			countAgain();
		}
		if (isKeyPressed(1)) {
			setTimer(1,10000);
			tmp_redtime = (tmp_redtime + 1 > 99) ? 0 : tmp_redtime + 1;
			setBuffer(tmp_redtime, 2);
		}
		if (isKeyPressed(2)) {
			setTimer(1,10000);
			redtime = (tmp_redtime - ambertime < 0) ? redtime : tmp_redtime;
			tmp_redtime = (redtime == tmp_ambertime) ? tmp_redtime : redtime;
			greentime = (redtime - ambertime);
			tmp_greentime = greentime;
		}
		if (getFlag(2)) {
			setTimer(2,250);
			led7seg_run();
			if (!(toggle++)) setallRed();
			else if (toggle) {
				setallOff();
				toggle = 0;
			}
		}
		if (getFlag(1)) {
			toggle = 0;
			status = MODE0;
			countAgain();
		}
		break;

	case SET_AMBERTIME:
		setBuffer(tmp_ambertime, 3);
		if (isKeyPressed(0)) {
			status = SET_GREENTIME;
			setTimer(1,10000);
			toggle = 0;
			countAgain();
		}
		if (isKeyPressed(1)) {
			setTimer(1,10000);
			tmp_ambertime = (tmp_ambertime + 1 > 99) ? 0 : tmp_ambertime + 1;
			setBuffer(tmp_redtime, 2);
		}
		if (isKeyPressed(2)) {
			setTimer(1,10000);
			ambertime = (tmp_ambertime + greentime > 99) ? ambertime : tmp_ambertime;
			tmp_ambertime = (tmp_ambertime == ambertime) ? tmp_ambertime : ambertime;
			redtime = greentime + ambertime;
			tmp_redtime = redtime;
		}
		if (getFlag(2)) {
			setTimer(2,250);
			led7seg_run();
			if (!(toggle++)) setallAmber();
			else if (toggle) {
				setallOff();
				toggle = 0;
			}
		}
		if (getFlag(1)) {
			toggle = 0;
			status = MODE0;
			countAgain();
		}
		break;
	case SET_GREENTIME:
		setBuffer(tmp_greentime, 4);
		if (isKeyPressed(0) || getFlag(1)) {
			toggle = 0;
			status = MODE0;
			countAgain();
		}
		if (isKeyPressed(1)) {
			setTimer(1,10000);
			tmp_greentime = (tmp_greentime + 1 > 99) ? 0 : tmp_greentime + 1;
			setBuffer(tmp_greentime, 2);
		}
		if (isKeyPressed(2)) {
			setTimer(1,10000);
			greentime = (tmp_greentime + ambertime > 99) ? greentime : tmp_greentime;
			tmp_greentime = (tmp_greentime == greentime) ? tmp_greentime : greentime;
			redtime = greentime + ambertime;
			tmp_redtime = redtime;
		}
		if (getFlag(2)) {
			setTimer(2,250);
			led7seg_run();
			if (!(toggle++)) setallGreen();
			else if (toggle) {
				setallOff();
				toggle = 0;
			}
		}
		break;
	default:
		break;
	}
}
