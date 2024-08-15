/**
 * @file HwIoAb_3_Buzzer_Cfg.h
 * @brief This header contains the configuration macros for the IO hardware abstraction for the buzzer on board.
 * 
 */

#ifndef HWIOAB_3_BUZZER_CFG_H
#define HWIOAB_3_BUZZER_CFG_H

#define HWIOAB_BUZZER_DEV_ERROR_DETECT STD_ON  ///< Dev error detect. 

#define HWIOAB_BUZZER_CH Ftm1Ch7   ///< Pwm channel for the buzzer.

#define HWIOAB_BUZZER_PERIOD_1 5333 ///< Period value for tone 1 ( 1.5 Khz ).
#define HWIOAB_BUZZER_PERIOD_2 2666 ///< Period value for tone 2 ( 3 Khz ).
#define HWIOAB_BUZZER_PERIOD_3 1600 ///< Period value for tone 3 ( 5 Khz ).

#define HWIOAB_BUZZER_25_DUTY_CYCLE 8192    ///< 25% duty cycle value.
#define HWIOAB_BUZZER_50_DUTY_CYCLE 16384   ///< 50% duty cycle value.

#endif