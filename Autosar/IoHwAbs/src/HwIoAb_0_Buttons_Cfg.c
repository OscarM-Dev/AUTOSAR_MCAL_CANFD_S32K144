/**
 * @file HwIoAb_0_Buttons_Cfg.c
 * @brief This file contains the declaration and definition of the instances of the control and config
 * structures related to the IO hardware abstraction for the buttons on board.
 * 
 * @note Here you register the buttons to be used in the state machine.
 * @note The button ID is the element of the configuration array where it was registered. 
 * 
 */

//Headers
#include "HwIoAb_0_Buttons.h"

//Configuration array
const HwIoAb_Buttons_Config ButtonsCfg[ HWIOAB_BUTTONS_MAX ] = {
    {
        .Button = HWIOAB_BUTTONS_1_CHANNEL,
        .Active = HWIOAB_BTN_ACTIVE_LOW,
        .Timeout = HWIOAB_BUTTONS_1_TIMEOUT
    },
    {
        .Button = HWIOAB_BUTTONS_2_CHANNEL,
        .Active = HWIOAB_BTN_ACTIVE_LOW,
        .Timeout = HWIOAB_BUTTONS_2_TIMEOUT
    },
    {
        .Button = HWIOAB_BUTTONS_3_CHANNEL,
        .Active = HWIOAB_BTN_ACTIVE_LOW,
        .Timeout = HWIOAB_BUTTONS_3_TIMEOUT
    }
};

//Global data.
HwIoAb_Buttons_Ctrl ButtonsCtrl; //Control structure instance.
HwIoAb_Buttons_Ctrl *ButtonsControl_Ptr = &ButtonsCtrl; //Pointer to control structure instance. 