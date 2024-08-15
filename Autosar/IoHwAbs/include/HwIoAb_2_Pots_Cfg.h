/**
 * @file HwIoAb_2_Pots_Cfg.h
 * @brief This header contains the configuration macros for the IO hardware abstraction for the pots on board.
 * 
 */

#ifndef HWIOAB_2_POTS_CFG_H
#define HWIOAB_2_POTS_CFG_H

#define HWIOAB_POTS_DEV_ERROR_DETECT STD_ON  ///< Dev error detect. 

#define HWIOAB_POTS 2 ///< Number of pots to handle on board.

#define HWIOAB_POTS_TOTAL_RESISTANCE 10000  ///< Total resistance in ohms of each pot.

#define HWIOAB_MAX_ADC_VALUE_12_B 2832   ///< Max adc value detected at 12 bits resolution.

#define HWIOAB_POTS_MAIN_RAW_RESULTS PotsControl_Ptr->Raw_results_main     ///< Base address of the main raw results array for the Pots.
#define HWIOAB_POTS_ALTER_RAW_RESULTS PotsControl_Ptr->Raw_results_alter   ///< Base address of the alter raw results array for the Pots. 

#define HWIOAB_POTS_MAIN_RESULTS PotsControl_Ptr->Ohms_results_main    ///< Base address of the main results array for the Pots.
#define HWIOAB_POTS_ALTER_RESULTS PotsControl_Ptr->Ohms_results_alter  ///< Base address of the alter results array for the Pots. 

#endif