/**
 * @file Scheduler.h
 * @brief This header contains the declaration of the config/control structures and the functions of the round robin scheduler 
 * as well as the structure TCB for the tasks and timers.
 * It also contains the config/control structures and functions related to the queue.
 * 
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H
//Headers.
#include "StandardTypes.h"
#include "Det.h"
#include "Scheduler_Cfg.h"
#include "OsIf.h"
#include "Bfx.h"

//General information
#define SCHEDULER_MODULE_ID 300 ///< Module ID.
#define SCHEDULER_INSTANCE_ID 0 ///< Instance ID.

//Api Adis
#define SCHEDULER_INIT_ID 0x00  ///< Scheduler_Init() Id.

#define SCHEDULER_INITQUEUE_ID 0x01 ///< Scheduler_InitQueue() Id.

#define SCHEDULER_GETSTATUSQUEUE_ID 0x02  ///< Scheduler_GetStatusQueue() Id.

#define SCHEDULER_FLUSHQUEUE_ID 0x03  ///< Scheduler_FlushQueue() Id.

#define SCHEDULER_WRITEQUEUE_ID 0x04  ///< Scheduler_WriteQueue() Id.

#define SCHEDULER_READQUEUE_ID 0x05 ///< Scheduler_ReadQueue() Id.

#define SCHEDULER_STARTTASK_ID 0x06 ///< Scheduler_StartTask() Id.

#define SCHEDULER_STOPTASK_ID 0x07  ///< Scheduler_StopTask() Id.

#define SCHEDULER_PERIODTASK_ID 0x08  ///< Scheduler_PeriodTask() Id.

#define SCHEDULER_STARTTIMER_ID 0x09  ///< Scheduler_StartTimer() Id.

#define SCHEDULER_STOPTIMER_ID 0x0A ///< Scheduler_StopTimer() Id.

#define SCHEDULER_GETTIMER_ID 0x0B  ///< Scheduler_GetTimer() Id.

#define SCHEDULER_RELOADTIMER_ID  0x0C  ///< Scheduler_ReloadTimer() Id.

#define SCHEDULER_MAINFUNCTION_ID   0x0D ///< Scheduler_MainFunction() Id.

//Error Ids.
#define SCHEDULER_E_PARAM_CONFIG 0x00 ///< "invalid config pointer" -->Scheduler_Init.

#define SCHEDULER_E_QUEUE_ID 0x01 ///< "Queue id out of range" -->GetStatusQueue, Flushqueue, WriteQueue, ReadQueue.

#define SCHEDULER_E_QUEUE_STATUS 0x02 ///< "Invalid queue status flag" -->GetStatusQueue.

#define SCHEDULER_E_TASK_ID 0x03  ///< "Task id out of range" -->StartTask, StopTask, PeriodTask.

#define SCHEDULER_E_PERIODICITY 0x04  ///< "Invalid task or timer periodicity" -->PeriodTask, ReloadTimer.

#define SCHEDULER_E_TIMER_ID 0x05 ///< "Timer id out of range" -->StartTimer, StopTimer, GetTimer y ReloadTimer.

#define SCHEDULER_E_UNINIT 0x06 ///< "Scheduler uninitialized" --> All apis.

//Types
typedef uint32 TickType; ///< Type for tick value.
typedef uint8 TaskType; ///< Type for the number of tasks to handle.
typedef uint8 TimerType; ///< Type for the number of timers to handle.
typedef uint8 QueueType; ///< Type for the number of queues to handle.

//Config structures
/**
  * @brief Config structure for operating the queues which members are related to a singular queue.
  * @note Usually the instances of this struct are constant.
*/
typedef struct _Queue_ConfigType 
{
    uint8 Size; ///< Number of bytes of each element of the queue.
    uint32 Elements;  ///< Number of elements of the queue.
    void *Buffer; ///< Ptr to array (Queue).
} Queue_ConfigType;

/**
  * @brief Task config block (TCB) for the tasks to be managed which members are related
  * to the execution of each registered task.
  * @note Usually the instances of this struct are constant.
*/
typedef struct _Task_ConfigType {   
    //members
    uint32 InitPeriod;          ///< Initial periodicity of the task in ms.
    uint8 InitFlag;             ///< Initial flag value.
    void ( *TaskFunc ) ( void );   ///< Pointer to task function.
} Task_ConfigType;

/**
  * @brief Timer config block (TCB) for the timers to be managed which members are related
  * to the execution of each registered timer.
  * @note Usually the instances of this struct are constant.
*/
typedef struct _Timer_ConfigType {
    //members
    uint32 InitTimeout;       ///< Initial reference value for timer -->desired timing in ms.
    uint8 InitFlag;           ///< Initial flag value.
    void ( *CallbackFunc ) ( void ); ///< Pointer to callback function.
} Timer_ConfigType;

/**
  * @brief Config structure to operate scheduler which members are related
  * to the time base and the buffers of tasks, timers and queues.
  * @note Usually the instance of this struct is constant.
*/
typedef struct _Scheduler_ConfigType {
    //members
    TickType Tick;         ///< Time monitoring interval in ms.
    TaskType Tasks;        ///< Number of tasks to handle/register in buffer.
    const Task_ConfigType *TaskPtr;  ///< Pointer to buffer of tasks.
    TimerType Timers;       ///< Number of timers to handle/register in buffer.
    const Timer_ConfigType *TimerPtr; ///< Pointer to buffer of timers.
    QueueType Queues; ///< Number of queues to handle/register in buffer.
    const Queue_ConfigType *QueuePtr; ///< Pointer to buffer of queues, each element is a queue.
} Scheduler_ConfigType;

/**
  * @brief Control structure to operate scheduler which members are related
  * to the operation of the tasks, timers and queues registered in their corresponding buffers.
  * @note Usually the instance of this struct is variable.
*/
typedef struct _Scheduler_CtrlType { 
    //members
    uint32 TaskPeriod[ SCHEDULER_MAX_TASKS ]; ///< Actual periodicity values of the tasks in ms, element n is the periodicity of task n (id - 1).
    uint32 TaskElapsed[ SCHEDULER_MAX_TASKS ]; ///< Time since last task execution (time follow up of task), element n is the time follow up of task n (id - 1).
    uint32 TimerTimeout[ SCHEDULER_MAX_TIMERS ];  ///< Actual reference values for timers -->desired timing in ms, element n is the reference value for timer n (id - 1).
    uint32 TimerCount[ SCHEDULER_MAX_TIMERS ]; ///< Timers counter values, element n is the counter value of timer n   (id - 1).
    uint32 TaskFlags; ///< Start flags for tasks, each bit is a flag, bit n flag n.
    uint32 TimerFlags; ///< Start flags for timers, each bit is a flag, bit n flag n.
    uint32 QueueHeads[ SCHEDULER_MAX_QUEUES ]; ///< Indexes for writing, element n is the Head index of queue n.
    uint32 QueueTails[ SCHEDULER_MAX_QUEUES ];  ///< Indexes for reading, element n is the Tail index of queue n.
    uint32 QueueEmpties;  ///< Empty flags, each bit is a flag, bit n flag n.
    uint32 QueueFulls;  ///< Full flags, each bit is a flag, bit n flag n.
    boolean SchedulerInit;  ///< Flag that indicates if the control structure was initialized.
} Scheduler_CtrlType;

//Reference to global data.
extern const Scheduler_ConfigType Scheduler_Config; //Config structure instance.
extern Scheduler_CtrlType Scheduler_Control; //Control structure instance.
extern const Scheduler_ConfigType *SchedulerConfig_Ptr;//Pointer to control structure 1.
extern Scheduler_CtrlType *SchedulerCtrl_Ptr; //Pointer to control structure 2.

//Functions.
/// @cond IGNORE
void MemCopy( void *Dest, void *Src, uint32 Size );
void Scheduler_InitQueue( Scheduler_CtrlType *Scheduler_Ptr );
uint8 Scheduler_GetStatusQueue( QueueType Queue, uint8 Status );
Std_ReturnType Scheduler_FlushQueue( QueueType Queue );
Std_ReturnType Scheduler_WriteQueue( QueueType Queue, void *Data );
Std_ReturnType Scheduler_ReadQueue( QueueType Queue, void *Data );
Std_ReturnType Scheduler_Init( Scheduler_CtrlType *SchedulerPtr );
Std_ReturnType Scheduler_StopTask( TaskType Task );
Std_ReturnType Scheduler_StartTask( TaskType Task );
Std_ReturnType Scheduler_PeriodTask( TaskType Task, uint32 NewPeriod );
Std_ReturnType Scheduler_StartTimer( TimerType Timer );
Std_ReturnType Scheduler_StopTimer( TimerType Timer );
uint32 Scheduler_GetTimer( TimerType Timer );
Std_ReturnType Scheduler_ReloadTimer( TimerType Timer, uint32 NewTimeout );
void Scheduler_MainFunction( void );

//Reference to callback functions.
extern void Task1_callback( void );
extern void Task2_callback( void );
extern void Timer1_callback( void );
extern void Timer2_callback( void );
extern void Timer3_callback( void );

/// @endcond

#endif