/**
 * @file HwIoAb_1_Leds_Cfg.c
 * @brief This file contains the declaration and definition of the instances of the control and config
 * structures related to the IO hardware abstraction for the leds on board.
 * 
 * @note Here you register the Leds to be used.
 * @note The led ID is the element of the configuration array where it was registered. 
 */

//Headers
#include "HwIoAb_1_Leds.h"

//Configuration array.
const HwIoAb_Leds_Config LedsCfg[ HWIOAB_LEDS ] = {
    {
        .Led = HWIOAB_LEDS_0_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    },
    {
        .Led = HWIOAB_LEDS_1_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    },
    {
        .Led = HWIOAB_LEDS_2_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    }
};

//Global data.
HwIoAb_Leds_Ctrl LedsCtrl;  //Control structure instance.
HwIoAb_Leds_Ctrl *LedsControl_Ptr = &LedsCtrl; //Pointer to control struct instance