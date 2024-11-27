/*
 * scheduler.h
 *
 *  Created on: Nov 27, 2024
 *      Author: My Laptop
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>


typedef struct {
	void (* pTask)(void);
	uint32_t 	Delay;
	uint32_t 	Period;
	uint8_t 	Runme;

	uint32_t	TaskID;
}sTasks;

#define SCH_MAX_TASK 10
#define TICK 10
void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Delete_Task(const unsigned char TASK_INDEX);
void SCH_Delete_Short_Task(void);

#endif /* INC_SCHEDULER_H_ */
