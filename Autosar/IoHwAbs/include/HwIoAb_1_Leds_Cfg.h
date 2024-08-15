/**
 * @file HwIoAb_1_Leds_Cfg.h
 * @brief This header contains the configuration macros for the IO hardware abstraction for the leds on board.
 * 
 */

#ifndef HWIOAB_1_LEDS_CFG_H
#define HWIOAB_1_LEDS_CFG_H

#define HWIOAB_LEDS_DEV_ERROR_DETECT STD_ON  ///< Dev error detect. 

#define HWIOAB_LEDS 3   ///< Number of leds to handle on board.

#define HWIOAB_LEDS_0_ID 0   ///< Led 0 ID.
#define HWI0AB_LEDS_1_ID 1   ///< Led 1 ID.
#define HWIOAB_LEDS_2_ID 2   ///< Led 2 ID.
#define HWIOAB_LEDS_3_ID 3   ///< Led 3 ID.
#define HWIOAB_LEDS_4_ID 4   ///< Led 4 ID.
#define HWIOAB_LEDS_5_ID 5   ///< Led 5 ID.

#define HWIOAB_LEDS_0_CHANNEL DioConf_DioChannel_PTC8 ///< Dio channel where the led 0 is connected.
#define HWIOAB_LEDS_1_CHANNEL DioConf_DioChannel_PTC9 ///< Dio channel where the led 1 is connected.
#define HWIOAB_LEDS_2_CHANNEL DioConf_DioChannel_PTC10 ///< Dio channel where the led 2 is connected.
#define HWIOAB_LEDS_3_CHANNEL DioConf_DioChannel_PTC11 ///< Dio channel where the led 3 is connected.
#define HWIOAB_LEDS_4_CHANNEL DioConf_DioChannel_PTC13 ///< Dio channel where the led 4 is connected.
#define HWIOAB_LEDS_5_CHANNEL DioConf_DioChannel_PTC14 ///< Dio channel where the led 5 is connected.

#endif