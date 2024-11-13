/*
 * scheduler_v1.c
 *
 *  Created on: Nov 12, 2024
 *      Author: My Laptop
 */

#include <scheduler.h>

sTasks SCH_tasks_G[SCH_MAX_TASK];

void SCH_Delete_Task(const unsigned char TASK_INDEX) {
	if (TASK_INDEX < SCH_MAX_TASK ) {
		SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
		SCH_tasks_G[TASK_INDEX].Delay = 0;
		SCH_tasks_G[TASK_INDEX].Period = 0;
		SCH_tasks_G[TASK_INDEX].Runme = 0;
		SCH_tasks_G[TASK_INDEX].TaskID = 0;
	}
}

void SCH_Init(void) {
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASK; i++) {
		SCH_Delete_Task(i);
	}
}

void SCH_Update(void) {
	unsigned char Index;
	for (Index = 0; Index < SCH_MAX_TASK; Index++) {
		if (SCH_tasks_G[Index].pTask) {
			if (SCH_tasks_G[Index].Delay == 0) {
				SCH_tasks_G[Index].Runme += 1;
				if (SCH_tasks_G[Index].Period){
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			}
			else {
				SCH_tasks_G[Index].Delay--;
			}
		}
	}
}
void SCH_Dispatch_Tasks(void) {
	unsigned char Index;
	for (Index = 0; Index < SCH_MAX_TASK; Index++) {
		if (SCH_tasks_G[Index].Runme > 0) {
			(*SCH_tasks_G[Index].pTask)();
			SCH_tasks_G[Index].Runme--;
			if (SCH_tasks_G[Index].Period == 0) {
				SCH_Delete_Task(Index);
			}
		}
	}
}
void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
	unsigned char Index = 0;
	while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASK)) {
		Index++;
	}
	if (Index < SCH_MAX_TASK) {
		SCH_tasks_G[Index].pTask = pFunction;
		SCH_tasks_G[Index].Delay = DELAY/TICK;
		SCH_tasks_G[Index].Period = PERIOD/TICK;
		SCH_tasks_G[Index].Runme = 0;
		SCH_tasks_G[Index].TaskID = Index;
	}

}

