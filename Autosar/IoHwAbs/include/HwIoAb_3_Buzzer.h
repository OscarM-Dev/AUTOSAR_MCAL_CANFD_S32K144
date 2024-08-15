/**
 * @file HwIoAb_3_Buzzer.h
 * @brief This header contains the declaration of the control structures, functions and global data related to 
 * the IO hardware abstraction for the buzzer on board.
 * 
 */

#ifndef HWIOAB_3_BUZZER_H
#define HWIOAB_3_BUZZER_H

//Headers.
#include "StandardTypes.h"
#include "Det.h"
#include "Pwm.h"

//General configuration.
#define HWIOAB_BUZZER_MODULE_ID 304 ///< Module id.
#define HWIOAB_BUZZER_INSTANCE_ID 0 ///< Instance id.

//Api ids.
#define HWIOAB_BUZZER_INIT_ID 0x00  ///< HwIoAb_Buzzer_Init() id.

#define HWIOAB_BUZZER_BEEP_ID 0x01  ///< HwIoAb_Buzzer_Beep() id.

#define HWIOAB_BUZZER_STOP_ID 0x02  ///< HwIoAb_Buzzer_Stop() id.

//Error ids.
#define HWIOAB_BUZZER_E_TONE 0x00   ///< "Invalid buzzer tone" -->BuzzerBeep.

//Enums.
typedef enum {
    HWIOAB_BUZZER_TONE_1,   ///< Tone 1 for buzzer.
    HWIOAB_BUZZER_TONE_2,   ///< Tone 2 for buzzer.
    HWIOAB_BUZZER_TONE_3    ///< Tone 2 for buzzer.
} BuzzerTones;

//Config structures.
/**
 * @brief Configuration structure for the buzzer.
 * 
 * @note This IO abstraction is no configurable.
 * 
 */
typedef struct _HwIoAb_Buzzer_Config {
    uint8 dummy;
} HwIoAb_Buzzer_Config;

#include "HwIoAb_3_Buzzer_Cfg.h"

//Functions.
void HwIoAb_Buzzer_Init( const HwIoAb_Buzzer_Config *Buzzer_Config );
void HwIoAb_Buzzer_Beep( uint8 Tone );
void HwIoAb_Buzzer_Stop( void );

#endif