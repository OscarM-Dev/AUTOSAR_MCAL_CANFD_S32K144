/**
 * @file HwIoAb_2_Pots.h
 * @brief This header contains the declaration of the control structures, functions and global data related to 
 * the IO hardware abstraction for the pots on board.
 */

#ifndef HWIOAB_2_POTS_H
#define HWIOAB_2_POTS_H

//Headers.
#include "StandardTypes.h"
#include "Det.h"
#include "Adc.h"

//General information.
#define HWIOAB_POTS_MODULE_ID 303 ///< Module id.
#define HWIOAB_POTS_INSTANCE_ID 0   ///<Instance id.

//Api ids.
#define HWIOAB_POTS_INIT_ID 0x00    ///< HwIoAb_Pots_Init() id.

#define HWIOAB_POTS_GETVALUE_ID 0x01    ///< HwIoAb_Pots_GetValue() id.

#define HWIOAB_POTS_GETALTVALUE_ID 0x02 ///< HwIoAb_Pots_GetAltValue() id.

//Error ids.
#define HWIOAB_POTS_E_PARAM 0x00    ///<"Invalid input pointer" -->Pots_GetValue, Pots_GetAltValue

#define HWIOAB_POTS_E_UNINIT 0x01   ///< "Module uninitialized" --> All apis except init.

//Config structures.
/**
 * @brief Configuration structure for each Pot
 * 
 * @note This IO abstraction is no configurable.
 * 
 */
typedef struct _HwIoAb_Pots_Config {
    uint8 dummy;
} HwIoAb_Pots_Config;

#include "HwIoAb_2_Pots_Cfg.h"

//Control structures.
/**
 * @brief Control/Config structure for the pots on board.
 * 
 * @note Usually the instance of this struct is variable.
 * @note Each element of the arrays is the conversion result of a pot.
 * @note Element n is pot n.
 * @note In this case we have only 2 ADC groups, one for AC0 and the other for ADC1.
 * @note All pots have the same total resistance value.
 * 
 */
typedef struct _HwIoAb_Pots_Ctrl {
    uint8 Pots;  ///< Number of pots to handle.
    uint16 Raw_results_main[ HWIOAB_POTS ];     ///< Raw conversion results array for the main ADC (0).
    uint16 Raw_results_alter[ HWIOAB_POTS ];    ///< Raw conversion results array for the alter ADC (1).
    uint16 Ohms_results_main[ HWIOAB_POTS ];    ///< Ohms conversion results array for the main ADC (0).
    uint16 Ohms_results_alter[ HWIOAB_POTS ];   ///< Ohms conversion results array for the main ADC (1).
    boolean Pots_init;  ///< Boolean flag that indicates if the control structure was initialized.
} HwIoAb_Pots_Ctrl;

//Reference to global data.
extern HwIoAb_Pots_Ctrl PotsCtrl;
extern HwIoAb_Pots_Ctrl *PotsControl_Ptr;

//Functions.
void HwIoAb_Pots_Init( const HwIoAb_Pots_Config *Pots_Config );
void HwIoAb_Pots_GetValue( uint16 *Pots );
void HwIoAb_Pots_GetAltValue( uint16 *AltPots );

#endif