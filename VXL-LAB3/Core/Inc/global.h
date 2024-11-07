/*
 * global.h
 *
 *  Created on: Oct 30, 2024
 *      Author: My Laptop
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <software_interrupt.h>
#include <button.h>
#include <main.h>
#include <led7_segment.h>
#include "traffic_light.h"
extern int status;

#define MODE0 1

#define MAN_RED_GREEN 6
#define MAN_RED_YELLOW 7
#define MAN_GREEN_RED 8
#define MAN_YELLOW_RED 9


#define AUTO_RED_GREEN 10
#define AUTO_RED_YELLOW 11
#define AUTO_GREEN_RED 12
#define AUTO_YELLOW_RED 13

#define SET_REDTIME 14
#define SET_AMBERTIME 15
#define SET_GREENTIME 16

#endif /* INC_GLOBAL_H_ */
