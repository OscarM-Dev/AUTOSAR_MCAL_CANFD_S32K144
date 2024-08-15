/**
 * @file HwIoAb_0_Buttons.c
 * @brief This file contains the definition of the functions related to 
 * the IO hardware abstraction for the buttons on board.
 * 
 */

//Headers
#include "HwIoAb_0_Buttons.h"

//Functions
/**
 * @brief This function initialices the control structure for the double click state machine. 
 * 
 * @param Buttons_Config Pointer to configuration array.
 * 
 */
void HwIoAb_Buttons_Init( const HwIoAb_Buttons_Config *Buttons_Config ) {
    //local data 
    uint8 i = 0;
    uint8 status = E_OK;

    #if ( HWIOAB_BUTTONS_DEV_ERROR_DETECT == STD_ON )
            if ( Buttons_Config == NULL_PTR ) {
                Det_ReportError( HWIOAB_BUTTONS_MODULE_ID, HWIOAB_BUTTONS_INSTANCE_ID, HWIOAB_BUTTONS_INIT_ID, HWIOAB_BUTTONS_E_CONFIG );
                status = E_NOT_OK;
            }
    #endif

    if ( status == E_OK ) {
        //Initializing members.
        ButtonsControl_Ptr->Buttons = HWIOAB_BUTTONS_MAX;
        ButtonsControl_Ptr->ButtonsConfig_Ptr = Buttons_Config;

        for ( i = 0; i < ButtonsControl_Ptr->Buttons; i++ ) {   //All button states and events to IDLE.
            ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_IDLE;
            ButtonsControl_Ptr->Events[i] = HWIOAB_BTN_EVENT_IDLE;
        }

        ButtonsControl_Ptr->Buttons_init = TRUE;
    }
}

/**
 * @brief This function indicates the last event detected in a button.
 * 
 * @param Button Button ID. 
 * @return event Last event detected in button.
 * 
 * @note The Button ID must be valid.
 */
uint8 HwIoAb_Buttons_GetEvent( uint8 Button ) {
    //local data.
    uint8 status = E_OK;
    uint8 event = 0;

    #if ( HWIOAB_BUTTONS_DEV_ERROR_DETECT == STD_ON )
        if ( ButtonsControl_Ptr->Buttons_init == FALSE ) {
            Det_ReportError( HWIOAB_BUTTONS_MODULE_ID, HWIOAB_BUTTONS_INSTANCE_ID, HWIOAB_BUTTONS_GETEVENT_ID, HWIOAB_BUTTONS_E_UNINIT );
            status = E_NOT_OK;
            event = HWIOAB_BTN_EVENT_NULL;
        }

        if ( Button > ButtonsControl_Ptr->Buttons - 1 ) {
             Det_ReportError( HWIOAB_BUTTONS_MODULE_ID, HWIOAB_BUTTONS_INSTANCE_ID, HWIOAB_BUTTONS_GETEVENT_ID, HWIOAB_BUTTONS_E_BUTTON_ID );
             status = E_NOT_OK;
             event = HWIOAB_BTN_EVENT_NULL;
        }
    #endif

    if ( status == E_OK ) {
        event = ButtonsControl_Ptr->Events[ Button ]; //Obtaining last event.
        ButtonsControl_Ptr->Events[ Button ] = HWIOAB_BTN_EVENT_IDLE;   //Clearing event of button.
    }

    return event;
}

/**
 * @brief This function is the double click state machine.
 * 
 * @note This function is called every HWIOAB_BUTTONS_PERIOD.
 * @note Remember that the timeout count is for detecting a hold click when the button is pressed 1 and 2 times.
 * @note Each button has its own dedicated count.
 * 
 */
void HwIoAb_Buttons_MainFunction( void ) {
    //local data
    static uint32 count[ HWIOAB_BUTTONS_MAX ] = { 0, 0, 0 };
    uint8 i = 0;
    uint8 status = E_OK;

    #if ( HWIOAB_BUTTONS_DEV_ERROR_DETECT == STD_ON )
        if ( ButtonsControl_Ptr->Buttons_init == FALSE ) {
            Det_ReportError( HWIOAB_BUTTONS_MODULE_ID, HWIOAB_BUTTONS_INSTANCE_ID, HWIOAB_BUTTONS_MAINFUNCTION_ID, HWIOAB_BUTTONS_E_UNINIT );
            status = E_NOT_OK;
        }
    #endif

    if ( status == E_OK ) {
        for ( i = 0; i < ButtonsControl_Ptr->Buttons; i++ ) { //Executing state machine for each button.
            switch( ButtonsControl_Ptr->States[i] ) {
                case HWIOAB_BTN_STATE_IDLE :
                    //Checks if the button is pressed.
                    if ( Dio_ReadChannel( ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Button ) == ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Active ) {
                        count[i] = 0;   //Restarting count.
                        ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_SINGLE_PRESS;
                    }
                break;
        
                case HWIOAB_BTN_STATE_SINGLE_PRESS :
                    count[i] += HWIOAB_BUTTONS_PERIOD;
                
                    //Checking count timeout.
                    if ( count[i] == ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Timeout ) {
                        ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_HOLD_PRESS;
                    }

                    //Checking if the button is released.
                    if ( Dio_ReadChannel( ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Button ) == !ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Active  ) {
                        ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_RELEASE;
                    }
                break;
        
                case HWIOAB_BTN_STATE_RELEASE :
                    count[i] += HWIOAB_BUTTONS_PERIOD;

                    //Checking count timeout.
                    if ( count[i] == ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Timeout ) { //Single click
                        ButtonsControl_Ptr->Events[i] = HWIOAB_BTN_EVENT_SINGLE_CLICK;
                        ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_IDLE;
                    }

                    //Checks if the button is pressed.
                    if ( Dio_ReadChannel( ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Button ) == ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Active  ) {
                        count[i] = 0;   //Restarting count.
                        ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_DOUBLE_PRESS;
                    }
                break;
        
                case HWIOAB_BTN_STATE_DOUBLE_PRESS :
                    count[i] += HWIOAB_BUTTONS_PERIOD;

                    //Checking count timeout.
                    if ( count[i] == ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Timeout ) {
                        ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_HOLD_PRESS;
                    }

                    //Checking if the button is released.
                    if ( Dio_ReadChannel( ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Button ) == !ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Active ) {  //Double click.
                        ButtonsControl_Ptr->Events[i] = HWIOAB_BTN_EVENT_DOUBLE_CLICK;
                        ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_IDLE;
                    }
                break;
        
                case HWIOAB_BTN_STATE_HOLD_PRESS :  //Hold click.
                    ButtonsControl_Ptr->Events[i] = HWIOAB_BTN_EVENT_HOLD_CLICK;
                    //Checking if the button is released.
                    if ( Dio_ReadChannel( ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Button ) == !ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Active ) {
                        ButtonsControl_Ptr->Events[i] = HWIOAB_BTN_EVENT_RELEASE;
                        ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_IDLE;
                    }
                break;
        
                default: //Invalid state
                    #if ( HWIOAB_BUTTONS_DEV_ERROR_DETECT == STD_ON )
                        Det_ReportError( HWIOAB_BUTTONS_MODULE_ID, HWIOAB_BUTTONS_INSTANCE_ID, HWIOAB_BUTTONS_MAINFUNCTION_ID, HWIOAB_BUTTONS_E_STATE );
                    #endif
                break;
            }
        }
    }
}
