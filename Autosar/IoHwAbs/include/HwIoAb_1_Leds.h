/**
 * @file HwIoAb_1_Leds.h
 * @brief This header contains the declaration of the control structures, functions and global data related to 
 * the IO hardware abstraction for the leds on board.
 * 
 */

#ifndef HWIOAB_1_LEDS_H
#define HWIOAB_1_LEDS_H

//Headers.
#include "StandardTypes.h"
#include "Det.h"
#include "Dio.h"

//General information.
#define HWIOAB_LEDS_MODULE_ID 302 ///< Module ID.
#define HWIOAB_LEDS_INSTANCE_ID 0   ///< Instance ID.

//Api ids.
#define HWIOAB_LEDS_INIT_ID 0x00   ///< HwIoAb_Leds_Init() id.

#define HWIOAB_LEDS_TURNON_ID 0x01  ///< HwIoAb_Leds_TurnOn() id.

#define HWIOAB_LEDS_TURNOFF_ID 0x02 ///< HwIoAb_Leds_TurnOff() id.

#define HWIOAB_LEDS_TURNTOGGLE_ID 0x03  ///< HwIoAb_Leds_TurnToggle() id.

//Error ids.
#define HWIOAB_LEDS_E_CONFIG 0x00   ///< "Invalid config pointer" -->Leds_Init

#define HWIOAB_LEDS_E_LED_ID 0x01   ///< "Invalid led id" --> Leds_TurnOn, Leds_TurnOff, Leds_TurnToggle

#define HWIOAB_LEDS_E_UNINIT 0x02   ///< "Module uninitialized" --> All apis except init.

//Enums
typedef enum {
    HWIOAB_LED_ACTIVE_LOW,         ///< LED is active low.
    HWIOAB_LED_ACTIVE_HIGH         ///< LED is active high.
} LedActive; //Led active status.

//Config structures
/**
 * @brief Configuration structure for each LED.
 * 
 * @note Usually the instance of this struct is constant.
 * 
 */
typedef struct _HwIoAb_Leds_Config
{
    Dio_ChannelType Led;     ///< Dio channel where the Led is connected.
    uint8 Active;               ///< Led active status.
} HwIoAb_Leds_Config;

#include "HwIoAb_1_Leds_Cfg.h"

//Control structures.
/**
 * @brief Control/Config structure for the leds on board.
 * 
 * @note Usually the instance of this struct is variable.
 * 
 */
typedef struct _HwIoAb_Leds_Ctrl
{
    uint8 Leds;  ///< Number of leds to handle.
    const HwIoAb_Leds_Config *LedsConfig_Ptr; ///< Ptr to configuration array.
    boolean Leds_init;  ///< Flag that indicates if control structure was initialized.
} HwIoAb_Leds_Ctrl;

//Reference to global data.
extern const HwIoAb_Leds_Config LedsCfg[ HWIOAB_LEDS ]; //Configuration array.
extern HwIoAb_Leds_Ctrl LedsCtrl; //Control structure instance.
extern HwIoAb_Leds_Ctrl *LedsControl_Ptr; //Pointer to control structure instance.

//Functions.
void HwIoAb_Leds_Init( const HwIoAb_Leds_Config *Leds_Config );
void HwIoAb_Leds_TurnOn( uint8 Led );
void HwIoAb_Leds_TurnOff( uint8 Led );
void HwIoAb_Leds_TurnToggle( uint8 Led );

#endif