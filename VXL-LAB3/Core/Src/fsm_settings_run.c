/*
 * fsm_settings_run.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */
#include <fsm_settings.h>
#include <fsm_automatic.h>
#include <fsm_manual.h>
int toggle = 0;
int greentime = 5;
int redtime = 8;
int ambertime = 3;

int tmp_greentime = 5;
int tmp_redtime = 8;
int tmp_ambertime = 3;

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

void fsm_SET_REDTIME(){
	setBuffer(tmp_redtime, 2);
	led7seg_run();
	if (!(toggle++)) setallRed();
	else if (toggle) {
		setallOff();
		toggle = 0;
	}
	SCH_Add_Task(fsm_SET_REDTIME, 250, 0);
}
void fsm_SET_AMBERTIME(){
	setBuffer(tmp_ambertime, 3);
	led7seg_run();
	if (!(toggle++)) setallAmber();
	else if (toggle) {
		setallOff();
		toggle = 0;
	}
	SCH_Add_Task(fsm_SET_AMBERTIME, 250, 0);
}
void fsm_SET_GREENTIME(){
	setBuffer(tmp_greentime, 4);
	led7seg_run();
	if (!(toggle++)) setallGreen();
	else if (toggle) {
		setallOff();
		toggle = 0;
	}
	SCH_Add_Task(fsm_SET_GREENTIME, 250, 0);
}

void fsm_mode () {
	if (isKeyPressed(0)) {
		switch (status) {
		case AUTO_RED_GREEN:
			SCH_Delete_Short_Task();
			status = MAN_RED_GREEN;
			SCH_Add_Task(fms_MAN_RED_GREEN, 10, 0);
			break;
		case AUTO_RED_YELLOW:
			SCH_Delete_Short_Task();
			status = MAN_RED_YELLOW;
			SCH_Add_Task(fms_MAN_RED_YELLOW, 10, 0);
			break;
		case AUTO_GREEN_RED:
			SCH_Delete_Short_Task();
			status = MAN_GREEN_RED;
			SCH_Add_Task(fms_MAN_GREEN_RED, 10, 0);
			break;
		case AUTO_YELLOW_RED:
			SCH_Delete_Short_Task();
			status = MAN_YELLOW_RED;
			SCH_Add_Task(fms_MAN_YELLOW_RED, 10, 0);
			break;
		case SET_REDTIME:
			SCH_Delete_Short_Task();
			status = SET_AMBERTIME;
			toggle = 0;
			countAgain();
			SCH_Add_Task(fsm_SET_AMBERTIME, 10, 0);
			break;
		case SET_AMBERTIME:
			SCH_Delete_Short_Task();
			status = SET_GREENTIME;
			toggle = 0;
			countAgain();
			SCH_Add_Task(fsm_SET_GREENTIME, 10, 0);
			break;
		case SET_GREENTIME:
			SCH_Delete_Short_Task();
			status = MODE0;
			toggle = 0;
			countAgain();
			SCH_Add_Task(fsm_INIT, 10, 0);
			break;
		case MAN_RED_GREEN:
		case MAN_RED_YELLOW:
		case MAN_GREEN_RED:
		case MAN_YELLOW_RED:
			SCH_Delete_Short_Task();
			status = SET_REDTIME;
			SCH_Add_Task(fsm_SET_REDTIME, 10, 0);
			break;
		default:
			break;
		}
	}
}

void fsm_increase() {
	if (isKeyPressed(1)) {
		switch(status) {
		case MAN_RED_GREEN:
			status = MAN_RED_YELLOW;
			SCH_Delete_Short_Task();
			SCH_Add_Task(fms_MAN_RED_YELLOW, 10, 0);
			break;

		case MAN_RED_YELLOW:
			status = MAN_GREEN_RED;
			SCH_Delete_Short_Task();
			SCH_Add_Task(fms_MAN_GREEN_RED, 10, 0);
			break;

		case MAN_GREEN_RED:
			status = MAN_YELLOW_RED;
			SCH_Delete_Short_Task();
			SCH_Add_Task(fms_MAN_YELLOW_RED, 10, 0);
			break;
		case MAN_YELLOW_RED:
			status = MAN_RED_GREEN;
			SCH_Delete_Short_Task();
			SCH_Add_Task(fms_MAN_RED_GREEN, 10, 0);
			break;

		case SET_REDTIME:
			tmp_redtime = (tmp_redtime + 1 > 99) ? 0 : tmp_redtime + 1;
			setBuffer(tmp_redtime, 2);
			break;

		case SET_AMBERTIME:
			tmp_ambertime = (tmp_ambertime + 1 > 99) ? 0 : tmp_ambertime + 1;
			setBuffer(tmp_redtime, 2);
			break;

		case SET_GREENTIME:
			tmp_greentime = (tmp_greentime + 1 > 99) ? 0 : tmp_greentime + 1;
			setBuffer(tmp_greentime, 2);
			break;

		default:
			break;
		}
	}
}
void fsm_confirm(){
	if (isKeyPressed(2)) {
		switch (status) {
		case SET_REDTIME:
			redtime = (tmp_redtime - ambertime < 0) ? redtime : tmp_redtime;
			tmp_redtime = (redtime == tmp_ambertime) ? tmp_redtime : redtime;
			greentime = (redtime - ambertime);
			tmp_greentime = greentime;
			break;

		case SET_AMBERTIME:
			ambertime = (tmp_ambertime + greentime > 99) ? ambertime : tmp_ambertime;
			tmp_ambertime = (tmp_ambertime == ambertime) ? tmp_ambertime : ambertime;
			redtime = greentime + ambertime;
			tmp_redtime = redtime;
			break;

		case SET_GREENTIME:
			redtime = (tmp_redtime - ambertime < 0) ? redtime : tmp_redtime;
			tmp_redtime = (redtime == tmp_ambertime) ? tmp_redtime : redtime;
			greentime = (redtime - ambertime);
			tmp_greentime = greentime;
			break;

		default:
			break;
		}
	}
}

