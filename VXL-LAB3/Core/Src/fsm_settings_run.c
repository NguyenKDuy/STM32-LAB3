/*
 * fsm_settings_run.c
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */
#include <fsm_settings.h>

void fsm_settings_run () {
	switch (status) {
	case SET_REDTIME:
		if (isKeyPressed(0)) {
			status = SET_AMBERTIME;
		}
		break;
	case SET_AMBERTIME:
		if (isKeyPressed(0)) {
			status = SET_GREENTIME;
		}
		break;
	case SET_GREENTIME:
		if (isKeyPressed(0)) {
			status = MODE0;
		}
		break;
	default:
		break;
	}
}
