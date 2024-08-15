/**
 * @file Scheduler_Cfg.c
 * @brief This file contains the declaration and definition of the constant instances of the control structures of the round robin scheduler.
 * 
 * @note The register of tasks and timers is done in the initialization of the buffers
 * @note The periodicity and timeout value must be >= tick and a multiple of tick.
 * @note The timer, task or queue ID is the element of the buffer where it was registered.
 * @note In order to register new timers or tasks is neccesary to do it manually.
 * @note Remember that all the timers and tasks registered must be different, different callback functions!!.
 * 
 */

//Headers.
#include "Scheduler.h"

//Queues
extern QueueMessage Queue1[ SCHEDULER_QUEUE1_ELEMENTS ];

//Constant control structure global instances.
//Queue buffer.
const Queue_ConfigType Queue_Config[ SCHEDULER_MAX_QUEUES ] = 
{
    {
        .Size = SCHEDULER_QUEUE1_SIZE,
        .Elements = SCHEDULER_QUEUE1_ELEMENTS,
        .Buffer = Queue1
    }
};

//Task buffer.
const Task_ConfigType Task_Config[ SCHEDULER_MAX_TASKS ]  = {
    {
        .InitPeriod = SCHEDULER_TASK1_PERIOD_50MS,
        .InitFlag = FALSE,
        .TaskFunc = Task1_callback
    },
    {
        .InitPeriod = SCHEDULER_TASK2_PERIOD_100MS,
        .InitFlag = FALSE,
        .TaskFunc = Task2_callback
    }
};

//Timer buffer.
const Timer_ConfigType Timer_Config[ SCHEDULER_MAX_TIMERS ] = {
    {
        .InitTimeout = SCHEDULER_TIMER1_TIMEOUT_100MS,
        .InitFlag = FALSE,
        .CallbackFunc = Timer1_callback
    }
};

//Scheduler config structure instance.
const Scheduler_ConfigType Scheduler_Config = {
    .Tick = SCHEDULER_TICK,
    .Tasks = SCHEDULER_MAX_TASKS,
    .TaskPtr = Task_Config,
    .Timers = SCHEDULER_MAX_TIMERS,
    .TimerPtr = Timer_Config,
    .Queues = SCHEDULER_MAX_QUEUES,
    .QueuePtr = Queue_Config
};

//Global data
Scheduler_CtrlType Scheduler_Control; //Control structure nstance.
const Scheduler_ConfigType *SchedulerConfig_Ptr = &Scheduler_Config; //Pointer to control structure 1.
Scheduler_CtrlType *SchedulerCtrl_Ptr = &Scheduler_Control; //Pointer to control structure 2.