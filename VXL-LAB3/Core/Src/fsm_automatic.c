/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */


#include "fsm_automatic.h"
#include "fsm_settings.h"

int count0, count1;
int led_buffer[4];

void setCount (int index, int value) {
	if (index == 0) count0 = value;
	if (index == 1)	count1 = value;
}
int getCount (int index) {
	if (index ==0) return count0;
	if (index ==1) return count1;
	return -1;
}


void fsm_automatic_run() {
	switch(status){
	case MODE0:
		//TODO:
		set_off0_off1();
		setTimer(1,1250);
		setTimer(2,250);
		count0 = RedTime();								//changable
		count1 = GreenTime();
		status = AUTO_RED_GREEN;
		setBuffer(RedTime(), GreenTime());
		break;
	case AUTO_RED_GREEN:
		set_red0_green1();
		//auto switch to the next light if finish count
		if (getFlag(1) == 1) {
			setTimer(1, 1000);
			count0--;
			count1--;
			setBuffer(count0, count1);
			if (count1 == 0) {
				status = AUTO_RED_YELLOW;
				count1 = AmberTime();
				count0 = AmberTime();
				setBuffer(count0, count1);
			}
//			countdown();
		}
		if (getFlag(2)) {
			setTimer(2,250);
			led7seg_run();
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
			setTimer(1, 1000);
			count0--;
			count1--;
			setBuffer(count0, count1);
			if (count1 == 0) {
				status = AUTO_GREEN_RED;
				count0 = GreenTime();						//changable
				count1 = RedTime();
				setBuffer(count0, count1);

			}
//			countdown();
		}
		if (getFlag(2)) {
			setTimer(2,250);
			led7seg_run();
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
			setTimer(1, 1000);
			count0--;
			count1--;
			setBuffer(count0, count1);
			if (count0 == 0) {
				status = AUTO_YELLOW_RED;
				count0 = AmberTime();						//changable
				setBuffer(count0, count1);
			}
//			countdown();
		}
		if (getFlag(2)) {
			setTimer(2,250);
			led7seg_run();
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
			setTimer(1, 1000);
			count0--;
			count1--;
			setBuffer(count0, count1);
			if (count0 == 0) {
				status = AUTO_RED_GREEN;
				count1 = GreenTime();						//changable
				count0 = RedTime();
				setBuffer(count0, count1);
			}
//			countdown();
		}
		if (getFlag(2)) {
			setTimer(2,250);
			led7seg_run();
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


