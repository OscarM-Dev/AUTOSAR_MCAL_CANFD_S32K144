/**
 * @file Callbacks.c
 * @brief This file contains the definition of functions 
 * for the timers and tasks to be used in the integration of the scheduler and queue.
 */

//Headers.
#include "callbacks.h"

//Tasks.
/**
 * @brief This is the callback function for the task 1.
 *
 * This function executes the state machine every 50ms.
 */
void Task1_callback( void ) {
    HwIoAb_Buttons_MainFunction();
}

/**
 * @brief This is the callback function for the task 2.
 *
 * This function is called every 100ms and gets the last event detected for each button for executing a certain action.
 * 
 */
void Task2_callback( void ) {
    //local data.
    uint8 i = 0;
    uint8 actual_event = 0; //Actual event of button.

    for ( i = 0; i < ButtonsControl_Ptr->Buttons; i++ ) { //Checking each button and its event detected.
        actual_event =  HwIoAb_Buttons_GetEvent( i );   //Obtaining event of actual button.
        
        if ( actual_event != HWIOAB_BTN_EVENT_IDLE ) {  //A click was detected.
            switch ( i ) {    
                case BTN_1: 
                    switch ( actual_event ) {
                        case HWIOAB_BTN_EVENT_SINGLE_CLICK:
                        break;
                        case HWIOAB_BTN_EVENT_DOUBLE_CLICK:
                        break;
                        case HWIOAB_BTN_EVENT_HOLD_CLICK:
                        break;
                        case HWIOAB_BTN_EVENT_RELEASE:
                        break;
                        default:    //Null event.
                        break;
                    }
                break;
            
                case BTN_2:
                    switch ( actual_event ) {
                        case HWIOAB_BTN_EVENT_SINGLE_CLICK:
                        break;
                        case HWIOAB_BTN_EVENT_DOUBLE_CLICK:
                        break;
                        case HWIOAB_BTN_EVENT_HOLD_CLICK:
                        break;
                        case HWIOAB_BTN_EVENT_RELEASE:
                        break;
                        default:    //Null event.
                        break;
                    }
                break;

                case BTN_3:
                        switch ( actual_event ) {
                            case HWIOAB_BTN_EVENT_SINGLE_CLICK:
                            break;
                            case HWIOAB_BTN_EVENT_DOUBLE_CLICK:
                            break;
                            case HWIOAB_BTN_EVENT_HOLD_CLICK:
                            break;
                            case HWIOAB_BTN_EVENT_RELEASE:
                            break;
                            default:    //Null event.
                            break;
                        }
                break;

                default:    //Invalid button.
                break;
            }
        }
    }
}

//Callbacks.
/**
 * @brief This is the callback function for the timer 1.
 *
 */
void Timer1_callback( void ) {
}

/**
 * @brief This is the callback function for the timer 2.
 *
 */
void Timer2_callback( void ) {
}

/**
 * @brief This is the callback function for the timer 3.
 *
 */
void Timer3_callback( void ) {    
}