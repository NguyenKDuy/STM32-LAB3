/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */


#include "fsm_automatic.h"
#include "fsm_settings.h"
#include "fsm_manual.h"

int count0, count1;
int led_buffer[4];
int second = 0;

void setCount (int index, int value) {
	if (index == 0) count0 = value;
	if (index == 1)	count1 = value;
}
void minusCount(){
	count0--;
	count1--;
}
int getCount (int index) {
	if (index ==0) return count0;
	if (index ==1) return count1;
	return -1;
}

void fsm_INIT() {
	status = MODE0;
	set_off0_off1();
	count0 = RedTime();
	count1 = GreenTime();
	setBuffer(RedTime(), GreenTime());
	if (second < 1) {
		SCH_Add_Task(fsm_INIT, 250, 0);
		second++;
	}
	else {
		second = 0;
		SCH_Add_Task(fsm_AUTO_RED_GREEN, 250, 0);
	}
}

void fsm_AUTO_RED_GREEN () {
	led7seg_run();
	set_red0_green1();
	status = AUTO_RED_GREEN;
	if (second < 3) {
			SCH_Add_Task(fsm_AUTO_RED_GREEN, 250, 0);
			second++;
	}
	else {
		second = 0;
		minusCount();
		setBuffer(count0, count1);
		if (count1 == 0) {
			SCH_Add_Task(fsm_AUTO_RED_YELLOW, 250, 0);
			count1 = AmberTime();
			count0 = AmberTime();
			setBuffer(count0, count1);

		}
		else {
			SCH_Add_Task(fsm_AUTO_RED_GREEN, 250, 0);
		}
	}
}

void fsm_AUTO_RED_YELLOW () {
	set_red0_amber1();
	led7seg_run();
	status = AUTO_RED_YELLOW;
	if (second < 3) {
			SCH_Add_Task(fsm_AUTO_RED_YELLOW, 250, 0);
			second++;
	}
	else {
		second = 0;
		minusCount();
		setBuffer(count0, count1);
		if (count1 == 0) {
			SCH_Add_Task(fsm_AUTO_GREEN_RED, 250, 0);
			count0 = GreenTime();
			count1 = RedTime();
			setBuffer(count0, count1);

		}
		else {
			SCH_Add_Task(fsm_AUTO_RED_YELLOW, 250, 0);
		}
	}
}

void fsm_AUTO_GREEN_RED () {
	set_green0_red1();
	led7seg_run();
	status = AUTO_GREEN_RED;
	if (second < 3) {
			SCH_Add_Task(fsm_AUTO_GREEN_RED, 250, 0);
			second++;
	}
	else {
		second = 0;
		minusCount();
		setBuffer(count0, count1);
		if (count0 == 0) {
			SCH_Add_Task(fsm_AUTO_YELLOW_RED, 250, 0);
			count0 = AmberTime();
			count1 = AmberTime();
			setBuffer(count0, count1);
		}
		else {
			SCH_Add_Task(fsm_AUTO_GREEN_RED, 250, 0);
		}
	}

}

void fsm_AUTO_YELLOW_RED () {
	set_amber0_red1();
	led7seg_run();
	status = AUTO_YELLOW_RED;
	if (second < 3) {
			SCH_Add_Task(fsm_AUTO_YELLOW_RED, 250, 0);
			second++;
	}
	else {
		second = 0;
		minusCount();
		setBuffer(count0, count1);
		if (count0 == 0) {
			SCH_Add_Task(fsm_AUTO_RED_GREEN, 250, 0);
			count0 = RedTime();
			count1 = GreenTime();
			setBuffer(count0, count1);
		}
		else {
			SCH_Add_Task(fsm_AUTO_YELLOW_RED, 250, 0);
		}
	}
}



