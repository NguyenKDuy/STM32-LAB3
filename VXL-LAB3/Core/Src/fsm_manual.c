/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */

#include "fsm_manual.h"
#include "fsm_automatic.h"
#include "fsm_settings.h"

void fms_MAN_RED_GREEN(){
	set_red0_green1();
	update7SEG(4);
	SCH_Add_Task(fsm_AUTO_RED_GREEN, 10000, 0);
	setCount(0, RedTime());
	setCount(1, GreenTime());
	setBuffer(getCount(0), getCount(1));
	countAgain();
}
void fms_MAN_RED_YELLOW(){
	set_red0_amber1();
	update7SEG(4); // Turn off all led
	SCH_Add_Task(fsm_AUTO_RED_YELLOW, 10000, 0);
	setCount(0, AmberTime());
	setCount(1, AmberTime());
	setBuffer(getCount(0), getCount(1));
}
void fms_MAN_GREEN_RED(){
	set_green0_red1();
	update7SEG(4); // Turn off all led
	SCH_Add_Task(fsm_AUTO_GREEN_RED, 10000, 0);
	setCount(0, GreenTime());
	setCount(1, RedTime());
	setBuffer(getCount(0), getCount(1));
	countAgain();

}
void fms_MAN_YELLOW_RED(){
	set_amber0_red1();
	update7SEG(4); // Turn off all led
	SCH_Add_Task(fsm_AUTO_YELLOW_RED, 10000, 0);
	setCount(0, AmberTime());
	setCount(1, AmberTime());
	setBuffer(getCount(0), getCount(1));
	countAgain();
}


