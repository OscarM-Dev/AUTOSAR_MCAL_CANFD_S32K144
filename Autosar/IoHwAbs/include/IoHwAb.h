/**
 * @file IoHwAb.h
 * @brief This header contains the declaration of general config structures and functions for the IO hardware abstractions 0. 
 */

#ifndef IOHWAB_H
#define IOHWAB_H

//Headers.
#include "HwIoAb_0_Buttons.h"
#include "HwIoAb_1_Leds.h"
#include "HwIoAb_2_Pots.h"
#include "HwIoAb_3_Buzzer.h"

//Config structure.
/**
 * @brief This is the configuration structure of the io hardware abstractions 0
 * 
 * @note In this case is not used, every hardware io abstraction has its own config structure.
 * 
 */
typedef struct _IoHwAb0_ConfigType {
    uint8 dummy;
 } IoHwAb0_ConfigType;

//Functions.
void IoHwAb_Init0( const IoHwAb0_ConfigType* ConfigPtr );
void IoHwAb_GetVersionInfo( Std_VersionInfoType* versioninfo );

#endif