/**
 * @file HwIoAb_0_Buttons_Cfg.h
 * @brief This header contains the configuration macros for the IO hardware abstraction for the buttons on board.
 * 
 */

#ifndef HWIOAB_0_BUTTONS_CFG_H
#define HWIOAB_0_BUTTONS_CFG_H

#define HWIOAB_BUTTONS_DEV_ERROR_DETECT STD_ON  ///< Dev error detect. 

#define HWIOAB_BUTTONS_MAX 3 ///< Max number of buttons to manage.

#define HWIOAB_BUTTONS_PERIOD 50    ///< Periodicity for the main function in ms.

#define HWI0AB_BUTTONS_1_ID 0   ///< Button 1 ID.
#define HWIOAB_BUTTONS_2_1D 1   ///< Button 2 ID.
#define HWIOAB_BUTTONS_3_ID 2   ///< Button 3 ID.

#define HWIOAB_BUTTONS_1_CHANNEL DioConf_DioChannel_PTE12 ///< Dio channel where the button 1 is connected.
#define HWIOAB_BUTTONS_2_CHANNEL DioConf_DioChannel_PTD17 ///< Dio channel where the button 2 is connected.
#define HWIOAB_BUTTONS_3_CHANNEL DioConf_DioChannel_PTA12 ///< Dio channel where the button 3 is connected.

#define HWIOAB_BUTTONS_1_TIMEOUT 300    ///< Timeout for the press of button 1 in ms.
#define HWIOAB_BUTTONS_2_TIMEOUT 300    ///< Timeout for the press of button 2 in ms.
#define HWIOAB_BUTTONS_3_TIMEOUT 300    ///< Timeout for the press of button 3 in ms.

#endif