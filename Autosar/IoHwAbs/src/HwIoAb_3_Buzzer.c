/**
 * @file HwIoAb_3_Buzzer.c
 * @brief This file contains the definition of the functions related to 
 * the IO hardware abstraction for the Buzzer on board.
 * 
 */

//Headers.
#include "HwIoAb_3_Buzzer.h"

//Functions.

/**
 * @brief This function initialices the buzzer.
 * 
 * It does the configurations neccesary for using the buzzer.
 * In this case no configurations are needeed.
 * 
 * @param Buzzer_Config Pointer to config structure instance, in this case is not use.
 */
void HwIoAb_Buzzer_Init( const HwIoAb_Buzzer_Config *Buzzer_Config ) {

}

/**
 * @brief This function beeps the buzzer according to the tone given.
 * 
 * @param Tone Tone of interest.
 */
void HwIoAb_Buzzer_Beep( uint8 Tone ) {
    switch ( Tone ) {
        case HWIOAB_BUZZER_TONE_1:  //Setting frequency to 1.5Khz and 25% duty cycle.
            Pwm_SetPeriodAndDuty( HWIOAB_BUZZER_CH, HWIOAB_BUZZER_PERIOD_1, HWIOAB_BUZZER_25_DUTY_CYCLE );
        break;
        case HWIOAB_BUZZER_TONE_2:  //Setting frequency to 3Khz and 25% duty cycle.
            Pwm_SetPeriodAndDuty( HWIOAB_BUZZER_CH, HWIOAB_BUZZER_PERIOD_2, HWIOAB_BUZZER_25_DUTY_CYCLE );
        break;
        case HWIOAB_BUZZER_TONE_3:  //Setting frequency to 5Khz and 25% duty cycle.
            Pwm_SetPeriodAndDuty( HWIOAB_BUZZER_CH, HWIOAB_BUZZER_PERIOD_3, HWIOAB_BUZZER_25_DUTY_CYCLE );
        break;
        default:    //Invalid tone.
            #if ( HWIOAB_BUZZER_DEV_ERROR_DETECT == STD_ON )
                Det_ReportError( HWIOAB_BUZZER_MODULE_ID, HWIOAB_BUZZER_INSTANCE_ID, HWIOAB_BUZZER_BEEP_ID, HWIOAB_BUZZER_E_TONE );
           #endif
        break;
    }
}

/**
 * @brief This function stops the beep of the buzzer.
 * 
 */
void HwIoAb_Buzzer_Stop( void ) {
    Pwm_SetOutputToIdle( HWIOAB_BUZZER_CH );    //Stopping buzzer.
}
