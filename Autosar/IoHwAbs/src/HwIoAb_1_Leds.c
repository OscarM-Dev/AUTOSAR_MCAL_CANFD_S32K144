/**
 * @file HwIoAb_1_Leds.c
 * @brief This file contains the definition of the functions related to 
 * the IO hardware abstraction for the leds on board.
 * 
 */

//Headers.
#include "HwIoAb_1_Leds.h"

/**
 * @brief This function initialices the control structure for the leds.
 * 
 * @param [in] Leds_Config Pointer to configuration array.
 */
void HwIoAb_Leds_Init( const HwIoAb_Leds_Config *Leds_Config ) {
    //local data.
    uint8 status = E_OK;
    
    #if ( HWIOAB_LEDS_DEV_ERROR_DETECT == STD_ON )
        if ( Leds_Config == NULL_PTR ) {
            Det_ReportError( HWIOAB_LEDS_MODULE_ID, HWIOAB_LEDS_INSTANCE_ID, HWIOAB_LEDS_INIT_ID, HWIOAB_LEDS_E_CONFIG );
            status = E_NOT_OK;
        }
    #endif
    
    if ( status == E_OK ) {
        //Initializing members.
        LedsControl_Ptr->Leds = HWIOAB_LEDS;
        LedsControl_Ptr->LedsConfig_Ptr = Leds_Config;
        LedsControl_Ptr->Leds_init = TRUE;
    }
}

/**
 * @brief This function turns on a given led.
 * 
 * @param Led Led ID.
 * 
 * @note The led ID must be valid.
 */
void HwIoAb_Leds_TurnOn( uint8 Led ) {
    //local data,
    uint8 status = E_OK;
    
    #if ( HWIOAB_LEDS_DEV_ERROR_DETECT == STD_ON )
        if ( LedsControl_Ptr->Leds_init == FALSE ) {
            Det_ReportError( HWIOAB_LEDS_MODULE_ID, HWIOAB_LEDS_INSTANCE_ID, HWIOAB_LEDS_TURNON_ID, HWIOAB_LEDS_E_UNINIT );
            status = E_NOT_OK;
        }

        if ( Led > LedsControl_Ptr->Leds - 1 ) {
            Det_ReportError( HWIOAB_LEDS_MODULE_ID, HWIOAB_LEDS_INSTANCE_ID, HWIOAB_LEDS_TURNON_ID, HWIOAB_LEDS_E_LED_ID );
            status = E_NOT_OK;
        }
    #endif

    if ( status == E_OK ) {
        Dio_WriteChannel( LedsControl_Ptr->LedsConfig_Ptr[ Led ].Led, LedsControl_Ptr->LedsConfig_Ptr[ Led ].Active );
    }
}

/**
 * @brief This function turns off a given led.
 * 
 * @param Led Led ID.
 * 
 * @note The led ID must be valid.
 */
void HwIoAb_Leds_TurnOff( uint8 Led ) {
    //local data,
    uint8 status = E_OK;
    
    #if ( HWIOAB_LEDS_DEV_ERROR_DETECT == STD_ON )
        if ( LedsControl_Ptr->Leds_init == FALSE ) {
            Det_ReportError( HWIOAB_LEDS_MODULE_ID, HWIOAB_LEDS_INSTANCE_ID, HWIOAB_LEDS_TURNOFF_ID, HWIOAB_LEDS_E_UNINIT );
            status = E_NOT_OK;
        }

        if ( Led > LedsControl_Ptr->Leds - 1 ) {
            Det_ReportError( HWIOAB_LEDS_MODULE_ID, HWIOAB_LEDS_INSTANCE_ID, HWIOAB_LEDS_TURNOFF_ID, HWIOAB_LEDS_E_LED_ID );
            status = E_NOT_OK;
        }
    #endif

    if ( status == E_OK ) {
        Dio_WriteChannel( LedsControl_Ptr->LedsConfig_Ptr[ Led ].Led, !LedsControl_Ptr->LedsConfig_Ptr[ Led ].Active );
    }
}

/**
 * @brief This function toggles a given led.
 * 
 * @param Led Led ID.
 * 
 * @note The led ID must be valid.
 */
void HwIoAb_Leds_TurnToggle( uint8 Led ) {
    //local data.
    uint8 status = E_OK;    

    #if ( HWIOAB_LEDS_DEV_ERROR_DETECT == STD_ON )
        if ( LedsControl_Ptr->Leds_init == FALSE ) {
            Det_ReportError( HWIOAB_LEDS_MODULE_ID, HWIOAB_LEDS_INSTANCE_ID, HWIOAB_LEDS_TURNTOGGLE_ID, HWIOAB_LEDS_E_UNINIT );
            status = E_NOT_OK;
        }

        if ( Led > LedsControl_Ptr->Leds - 1 ) {
            Det_ReportError( HWIOAB_LEDS_MODULE_ID, HWIOAB_LEDS_INSTANCE_ID, HWIOAB_LEDS_TURNTOGGLE_ID, HWIOAB_LEDS_E_LED_ID );
            status = E_NOT_OK;
        }
    #endif

    if ( status == E_OK ) {
        Dio_FlipChannel( LedsControl_Ptr->LedsConfig_Ptr[ Led ].Led );
    }
}
