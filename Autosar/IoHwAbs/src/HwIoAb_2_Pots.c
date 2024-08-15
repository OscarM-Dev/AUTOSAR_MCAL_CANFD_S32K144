/**
 * @file HwIoAb_2_Pots.c
 * @brief This file contains the definition of the functions related to 
 * the IO hardware abstraction for the Pots on board.
 * 
 */

//Headers
#include "HwIoAb_2_Pots.h"

//Functions.

/**
 * @brief This function initialices the use of the Pots on board.
 * 
 * It calibrates both ADC modules and initialices the raw results arrays for the conversions.
 * 
 * @param Pots_Config Pointer to configuration structure instance, in this case is not use. 
 */
void HwIoAb_Pots_Init( const HwIoAb_Pots_Config *Pots_Config ) {
    //local data.
    Adc_CalibrationStatusType Calib_Status_ADC0;
    Adc_CalibrationStatusType Calib_Status_ADC1;

    //Calibrating ADC modules.
    Adc_Calibrate( Adc0, &Calib_Status_ADC0 );
    Adc_Calibrate( Adc1, &Calib_Status_ADC1 );

    //Initializing raw results array.
    Adc_SetupResultBuffer( Adc0Group_0, HWIOAB_POTS_MAIN_RAW_RESULTS );
    Adc_SetupResultBuffer( Adc1Group_0, HWIOAB_POTS_ALTER_RAW_RESULTS );

    PotsControl_Ptr->Pots = HWIOAB_POTS;
    PotsControl_Ptr->Pots_init = TRUE;
}

/**
 * @brief This function triggers the conversion of the group 0 of the main ADC (0) for the Pots on board.
 * 
 * It calculates the resistance values of each pot.
 * 
 * @param Pots Pointer to array of results in Ohms.
 * 
 * @note The group uses hardware average of 4 samples. 
 * @note The total conversion time is 117.42us
 */
void HwIoAb_Pots_GetValue( uint16 *Pots ) {
    //local data.
    uint8 i = 0;
    uint8 status = E_OK;

    #if ( HWIOAB_POTS_DEV_ERROR_DETECT == STD_ON )
        if ( PotsControl_Ptr->Pots_init == FALSE ) {
            Det_ReportError( HWIOAB_POTS_MODULE_ID, HWIOAB_POTS_INSTANCE_ID, HWIOAB_POTS_GETVALUE_ID, HWIOAB_POTS_E_UNINIT );
            status = E_NOT_OK;
        }

        if ( Pots == NULL_PTR ) {
            Det_ReportError( HWIOAB_POTS_MODULE_ID, HWIOAB_POTS_INSTANCE_ID, HWIOAB_POTS_GETVALUE_ID, HWIOAB_POTS_E_PARAM );
            status = E_NOT_OK;
        }
    #endif

    if ( status == E_OK ) {
        Adc_StartGroupConversion( Adc0Group_0 );    //Triggering group conversion.
        while( Adc_GetGroupStatus( Adc0Group_0 ) == ADC_BUSY ); //Wating until group conversion is done.
        Adc_ReadGroup( Adc0Group_0, HWIOAB_POTS_MAIN_RAW_RESULTS ); //Reading group conversion values and storing them to the raw result array.

        //Calculating resistance of each Pot.
        for ( i = 0; i < PotsControl_Ptr->Pots; i++ ) {
            Pots[i] = HWIOAB_POTS_TOTAL_RESISTANCE * 
            ( ( float ) PotsControl_Ptr->Raw_results_main[i] / HWIOAB_MAX_ADC_VALUE_12_B );

            if ( Pots[i] > HWIOAB_POTS_TOTAL_RESISTANCE ) { //Saturating value if needed.
                Pots[i] = HWIOAB_POTS_TOTAL_RESISTANCE;
            }
        }
    }
}

/**
 * @brief This function triggers the conversion of the group 0 of the alter ADC (1) for the Pots on board.
 * 
 * It calculates the resistance values of each pot.
 * 
 * @param AltPots Pointer to array of results in Ohms.
 * 
 * @note The group uses hardware average of 4 samples.
 * @note The total conversion time is 117.42us
 */
void HwIoAb_Pots_GetAltValue( uint16 *AltPots ) {
    //local data.
    uint8 i = 0;
    uint8 status = E_OK;

    #if ( HWIOAB_POTS_DEV_ERROR_DETECT == STD_ON )
        if ( PotsControl_Ptr->Pots_init == FALSE ) {
            Det_ReportError( HWIOAB_POTS_MODULE_ID, HWIOAB_POTS_INSTANCE_ID, HWIOAB_POTS_GETALTVALUE_ID, HWIOAB_POTS_E_UNINIT );
            status = E_NOT_OK;
        }

        if ( AltPots == NULL_PTR ) {
            Det_ReportError( HWIOAB_POTS_MODULE_ID, HWIOAB_POTS_INSTANCE_ID, HWIOAB_POTS_GETALTVALUE_ID, HWIOAB_POTS_E_PARAM );
            status = E_NOT_OK;
        }
    #endif

    if ( status == E_OK ) {
        Adc_StartGroupConversion( Adc1Group_0 );    //Triggering group conversion.
        while( Adc_GetGroupStatus( Adc1Group_0 ) == ADC_BUSY ); //Wating until group conversion is done.
        Adc_ReadGroup( Adc1Group_0, HWIOAB_POTS_ALTER_RAW_RESULTS ); //Reading group conversion values and storing them to the raw result array.

        //Calculating resistance of each Pot.
        for ( i = 0; i < PotsControl_Ptr->Pots; i++ ) {
            AltPots[i] = HWIOAB_POTS_TOTAL_RESISTANCE *
            ( ( float ) PotsControl_Ptr->Raw_results_alter[i] / HWIOAB_MAX_ADC_VALUE_12_B );

            if ( AltPots[i] > HWIOAB_POTS_TOTAL_RESISTANCE ) { //Saturating value if needed.
                AltPots[i] = HWIOAB_POTS_TOTAL_RESISTANCE;
            }
        }
    }
}