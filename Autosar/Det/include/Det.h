/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef DET_H
#define DET_H

/**
*   @file Det.h
*
*   @addtogroup DET_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Det_h_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once.
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Det_h_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Det.h
* @requirements   DET001_PI
*/

#define DET_VENDOR_ID                       43
#define DET_MODULE_ID                       15
#define DET_AR_RELEASE_MAJOR_VERSION        4
#define DET_AR_RELEASE_MINOR_VERSION        7
#define DET_AR_RELEASE_REVISION_VERSION     0
#define DET_SW_MAJOR_VERSION                2
#define DET_SW_MINOR_VERSION                0
#define DET_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Max numbers of ECU cores supported */
#define DET_NO_ECU_CORES                        (uint8)(1U)

//Configuration macros.
#define DET_MODULES 11  ///< Number of modules that use det.

//Mcu
#define DET_MCU_APIS 4  ///< Number of apis used of the mcu module.

#define DET_MCU_ERRORS 6    ///< Number of errors of the mcu module.

//Platform
#define DET_PLATFORM_APIS 5 ///< Number of apis used of the platform module.

#define DET_PLATFORM_ERRORS 3   ///< Number of errors of the platform module.

//Port
#define DET_PORT_APIS 5 ///< Number of apis used of the port module.

#define DET_PORT_ERRORS 7   ///< Number of errors of the port module.

//Dio
#define DET_DIO_APIS 8 ///< Number of apis used of the dio module.

#define DET_DIO_ERRORS 6   ///< Number of errors of the dio module.

//Pwm
#define DET_PWM_APIS 6 ///< Number of apis used of the pwm module.

#define DET_PWM_ERRORS 6   ///< Number of errors of the pwm module.

//Adc
#define DET_ADC_APIS 9 ///< Number of apis used of the adc module.

#define DET_ADC_ERRORS 6   ///< Number of errors of the adc module.

//Scheduler
#define DET_SCHEDULER_APIS 13 ///< Number of apis used of the scheduler module.

#define DET_SCHEDULER_ERRORS 7   ///< Number of errors of the scheduler module.

//HwIoAb buttons
#define DET_HWIOAB_BUTTTONS_APIS 3 ///< Number of apis used of the buttons module.

#define DET_HWIOAB_BUTTONS_ERRORS 4   ///< Number of errors of the buttons module.

//HwIoAb leds
#define DET_HWIOAB_LEDS_APIS 4 ///< Number of apis used of the leds module.

#define DET_HWIOAB_LEDS_ERRORS 3   ///< Number of errors of the leds module.

//HwIoAb pots
#define DET_HWIOAB_POTS_APIS 3 ///< Number of apis used of the pots module.

#define DET_HWIOAB_POTS_ERRORS 2   ///< Number of errors of the pots module.

//HwIoAb buzzer
#define DET_HWIOAB_BUZZER_APIS 3 ///< Number of apis used of the buzzer module.

#define DET_HWIOAB_BUZZER_ERRORS 1   ///< Number of errors of the buzzer module.

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief This struct is for the hash table of the api names.
 * 
 * @note Each instance of the struct is related to an specific api.
 * 
 */
typedef struct _DetApiName {
    uint8 ApiId;    ///< Api id.
    const char *const ApiName;    ///< Ptr to string of api name.
} DetApiName;

/**
 * @brief This struct is for the hash table of the error meanings.
 * 
 * @note Each instance of the struct is related to an specific error.
 * 
 */
typedef struct _DetErrorMeaning {
    uint8 ErrorId; ///< Error id.
    const char *const ErrorMeaning;   ///< Ptr to string of error meaning.
} DetErrorMeaning;

/**
 * @brief This struct is asociated to the hash tables related to the strings of the error message.
 * 
 * @note Each instance of the struct is related to an specific module.
 * 
 */
typedef struct _DetStrings {
    uint16 ModuleId; ///< Module Id.
    const char *const ModuleName; ///< Ptr to string of module name.
    uint8 Apis; ///< Number of apis used.
    const DetApiName *const ApiNames;   ///< Ptr to hash table of api names of the module.
    uint8 Errors;   ////< Number of errors reported.
    const DetErrorMeaning *const ErrorMeanings;  ///< Ptr to hash table of error meanings of the module.
} DetStrings;
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define DET_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Det_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"
/* Variables to store last DET error */
extern uint8 Det_InstanceId[DET_NO_ECU_CORES];                /**< @brief DET instance ID*/
extern uint8 Det_ApiId[DET_NO_ECU_CORES];                     /**< @brief DET API ID*/
extern uint8 Det_ErrorId[DET_NO_ECU_CORES];                   /**< @brief DET Error ID*/
/* Variables to store last DET runtime error */
extern uint8 Det_RuntimeInstanceId[DET_NO_ECU_CORES];         /**< @brief DET instance ID*/
extern uint8 Det_RuntimeApiId[DET_NO_ECU_CORES];              /**< @brief DET API ID*/
extern uint8 Det_RuntimeErrorId[DET_NO_ECU_CORES];            /**< @brief DET Error ID*/
/* Variables to store last DET transient error */
extern uint8 Det_TransientInstanceId[DET_NO_ECU_CORES];       /**< @brief DET instance ID*/
extern uint8 Det_TransientApiId[DET_NO_ECU_CORES];            /**< @brief DET API ID*/
extern uint8 Det_TransientFaultId[DET_NO_ECU_CORES];          /**< @brief DET Error ID*/
#define DET_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE

//Mcu
extern const DetApiName McuApis[ DET_MCU_APIS ];    ///< Hash table of api names of the MCU.
extern const DetErrorMeaning McuErrors[ DET_MCU_ERRORS ];  ///< Hash table of error meanings of the MCU.

//Platform.
extern const DetApiName PlatformApis[ DET_PLATFORM_APIS ];    ///< Hash table of api names of the Platform.
extern const DetErrorMeaning PlatformErrors[ DET_PLATFORM_ERRORS ];  ///< Hash table of error meanings of the Platform.

//Port
extern const DetApiName PortApis[ DET_PORT_APIS ];    ///< Hash table of api names of the Port.
extern const DetErrorMeaning PortErrors[ DET_PORT_ERRORS ];  ///< Hash table of error meanings of the Port.

//Dio
extern const DetApiName DioApis[ DET_DIO_APIS ];    ///< Hash table of api names of the Dio.
extern const DetErrorMeaning DioErrors[ DET_DIO_ERRORS ];  ///< Hash table of error meanings of the Dio.

//Pwm
extern const DetApiName PwmApis[ DET_PWM_APIS ];    ///< Hash table of api names of the Pwm.
extern const DetErrorMeaning PwmErrors[ DET_PWM_ERRORS ];  ///< Hash table of error meanings of the Pwm.

//Adc
extern const DetApiName AdcApis[ DET_ADC_APIS ];    ///< Hash table of api names of the Adc.
extern const DetErrorMeaning AdcErrors[ DET_ADC_ERRORS ];  ///< Hash table of error meanings of the Adc.

//Scheduler
extern const DetApiName SchedulerApis[ DET_SCHEDULER_APIS ];    ///< Hash table of api names of the Scheduler.
extern const DetErrorMeaning SchedulerErrors[ DET_SCHEDULER_ERRORS ];  ///< Hash table of error meanings of the Scheduler.

//HwIoAb Buttons
extern const DetApiName HwIoAb_ButtonsApis[ DET_HWIOAB_BUTTTONS_APIS ];    ///< Hash table of api names of the Buttons.
extern const DetErrorMeaning HwIoAb_ButtonsErrors[ DET_HWIOAB_BUTTONS_ERRORS ];  ///< Hash table of error meanings of the Buttons.

//HwIoAb Leds
extern const DetApiName HwIoAb_LedsApis[ DET_HWIOAB_LEDS_APIS ];    ///< Hash table of api names of the Leds.
extern const DetErrorMeaning HwIoAb_LedsErrors[ DET_HWIOAB_LEDS_ERRORS ];  ///< Hash table of error meanings of the Leds.

//HwIoAb Pots
extern const DetApiName HwIoAb_PotsApis[ DET_HWIOAB_POTS_APIS ];    ///< Hash table of api names of the Pots.
extern const DetErrorMeaning HwIoAb_PotsErrors[ DET_HWIOAB_POTS_ERRORS ];  ///< Hash table of error meanings of the Pots.

//HwIoAb Buzzer
extern const DetApiName HwIoAb_BuzzerApis[ DET_HWIOAB_BUZZER_APIS ];    ///< Hash table of api names of the Buzzer.
extern const DetErrorMeaning HwIoAb_BuzzerErrors[ DET_HWIOAB_BUZZER_ERRORS ];  ///< Hash table of error meanings of the Buzzer.

extern const DetStrings ModuleStrings[ DET_MODULES ];  ///< Array of structs for the modules.

extern const DetStrings *const ModuleStrings_Ptr;    ///< Pointer to general array.

/*
 * @violates @ref Det_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"

#define DET_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
/*
 * @violates @ref Det_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"
extern uint16 Det_TransientModuleId[DET_NO_ECU_CORES];       /**< @brief DET module ID*/
extern uint16 Det_ModuleId[DET_NO_ECU_CORES];       /**< @brief DET module ID*/
extern uint16 Det_RuntimeModuleId[DET_NO_ECU_CORES];       /**< @brief DET module ID*/
#define DET_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
/*
 * @violates @ref Det_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define DET_START_SEC_CODE
#include "Det_MemMap.h"

//String functions.
const char* Det_SearchApi( uint8 ModuleIndex, uint8 ApiId );
const char* Det_SearchError( uint8 ModuleIndex, uint8 ErrorId );
const char* Det_GetModuleName( uint16 ModuleId );
const char* Det_GetApiName( uint16 ModuleId, uint8 ApiId );
const char* Det_GetErrorMeaning( uint16 ModuleId, uint8 ErrorId );

void Det_Init(void);
Std_ReturnType Det_ReportError(uint16 ModuleId,
                               uint8 InstanceId,
                               uint8 ApiId,
                               uint8 ErrorId);
#if defined(ASR_REL_4_0_REV_0003)
#else
Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId,
                                      uint8 InstanceId,
                                      uint8 ApiId,
                                      uint8 ErrorId);
Std_ReturnType Det_ReportTransientFault(uint16 ModuleId,
                                        uint8 InstanceId,
                                        uint8 ApiId,
                                        uint8 FaultId);
#endif /*if defined(ASR_REL_4_0_REV_0003)*/
void Det_Start(void);

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DET_H */
