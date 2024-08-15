/**
 * @file IoHwAb.c
 * @brief This file contains the definition of the general configuration functions for the IO hardware abstractions 0. 
 * 
 */

//Headers.
#include "IoHwAb.h"

//Functions.
/**
 * @brief This function initialices all the IO hardware abstractions.
 * 
 * @param ConfigPtr Pointer to configuration structure instance, in this case is not used.
 */
void IoHwAb_Init0( const IoHwAb0_ConfigType* ConfigPtr ) {
    HwIoAb_Buttons_Init( ButtonsCfg );  //Buttons init.
    HwIoAb_Leds_Init( LedsCfg );    //Leds init.
    HwIoAb_Pots_Init( NULL_PTR );   //Pots init.
    HwIoAb_Buzzer_Init( NULL_PTR ); //Buzzer init.
}

/**
 * @brief This function gets all the version info of IO hardware abstractions 0 according to the Mcal drivers used.
 * 
 * @param versioninfo Pointer to Version info instance struct.
 */
void IoHwAb_GetVersionInfo( Std_VersionInfoType* versioninfo ) {
    versioninfo->moduleID = 0;
    versioninfo->vendorID = 43;
    versioninfo->sw_major_version = 2;
    versioninfo->sw_minor_version = 0;
    versioninfo->sw_patch_version = 0;
}