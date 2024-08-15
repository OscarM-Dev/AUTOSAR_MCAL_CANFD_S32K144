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

/**
*   @file Det.c
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
* @section Det_c_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once.
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Det_c_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Det.c
* @requirements   DET004
*/
#include "Mcal.h"
#include "OsIf.h"
#include "Det.h"
#include "Mcu.h"
#include "Platform.h"
#include "Port.h"
#include "Dio.h"
#include "Pwm.h"
#include "Adc.h"
#include "Scheduler.h"
#include "IoHwAb.h"
#include "SEGGER_RTT.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define DET_VENDOR_ID_C                     43
#define DET_AR_RELEASE_MAJOR_VERSION_C      4
#define DET_AR_RELEASE_MINOR_VERSION_C      7
#define DET_AR_RELEASE_REVISION_VERSION_C   0
#define DET_SW_MAJOR_VERSION_C              2
#define DET_SW_MINOR_VERSION_C              0
#define DET_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and DET header file are of the same vendor */
#if (DET_VENDOR_ID_C != DET_VENDOR_ID)
    #error "Det.c and Det.h have different vendor ids"
#endif

/* Check if source file and DET header file are of the same Autosar version */
#if ((DET_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
     (DET_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) || \
     (DET_AR_RELEASE_REVISION_VERSION_C != DET_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Det.c and Det.h are different"
#endif

/* Check if source file and DET header file are of the same Software version */
#if ((DET_SW_MAJOR_VERSION_C != DET_SW_MAJOR_VERSION) || \
     (DET_SW_MINOR_VERSION_C != DET_SW_MINOR_VERSION) || \
     (DET_SW_PATCH_VERSION_C != DET_SW_PATCH_VERSION))
    #error "Software Version Numbers of Det.c and Det.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if DET source file and STD header file are of the same Autosar version */
    #if ((DET_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
        (DET_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Det.c and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
//Hash tables for reporting errors.
//Mcu.
const DetApiName McuApis[ DET_MCU_APIS ] = {
    {
        .ApiId = MCU_INIT_ID,
        .ApiName = "Mcu_Init()"
    },
    {
        .ApiId = MCU_INITCLOCK_ID,
        .ApiName = "Mcu_InitClock()"
    },
    {
        .ApiId = MCU_SETMODE_ID,
        .ApiName = "Mcu_SetMode()"
    },
    {
        .ApiId = MCU_GETVERSIONINFO_ID,
        .ApiName = "Mcu_GetVersionInfo()"
    }
};  ///< Hash table of api names of the MCU.

const DetErrorMeaning McuErrors[ DET_MCU_ERRORS ] = {
    {
        .ErrorId = MCU_E_INIT_FAILED,
        .ErrorMeaning = "Invalid conf pointer"
    },
    {
        .ErrorId = MCU_E_UNINIT,
        .ErrorMeaning = "Driver uninitialized"
    },
    {
        .ErrorId = MCU_E_ALREADY_INITIALIZED,
        .ErrorMeaning = "Driver already initialized"
    },
    {
        .ErrorId = MCU_E_PARAM_CLOCK,
        .ErrorMeaning = "Invalid input parameter"
    },
    {
        .ErrorId = MCU_E_PARAM_MODE,
        .ErrorMeaning = "Invalid input parameter"
    },
    {
        .ErrorId = MCU_E_PARAM_POINTER,
        .ErrorMeaning = "Invalid input parameter"
    }
};  ///< Hash table of error meanings of the MCU.

//Platform.
const DetApiName PlatformApis[ DET_PLATFORM_APIS ] = {
    {
        .ApiId = PLATFORM_INIT_ID,
        .ApiName = "Platform_Init()"
    },
    {
        .ApiId = PLATFORM_SET_IRQ_ID,
        .ApiName = "Platform_SetIrq()"
    },
    {
        .ApiId = PLATFORM_SET_IRQ_PRIO_ID,
        .ApiName = "Platform_SetIrqPriority()"
    },
    {
        .ApiId = PLATFORM_GET_IRQ_PRIO_ID,
        .ApiName = "Platform_GetIrqPriority()"
    },
    {
        .ApiId = PLATFORM_INSTALL_HANDLER_ID,
        .ApiName = "Platform_InstallIrqHandler()"
    }
};    ///< Hash table of api names of the Platform.

const DetErrorMeaning PlatformErrors[ DET_PLATFORM_ERRORS ] = {
    {
        .ErrorId = PLATFORM_E_PARAM_POINTER,
        .ErrorMeaning = "Invalid pointer"
    },
    {
        .ErrorId = PLATFORM_E_PARAM_CONFIG,
        .ErrorMeaning = "Call from wrong mapped partition"
    },
    {
        .ErrorId = PLATFORM_E_PARAM_OUT_OF_RANGE,
        .ErrorMeaning = "Parameter out of range"
    }
};  ///< Hash table of error meanings of the Platform.

//Port.
const DetApiName PortApis[ DET_PORT_APIS ] = {
    {
        .ApiId = PORT_INIT_ID,
        .ApiName = "Port_Init()"
    },
    {
        .ApiId = PORT_SETPINDIRECTION_ID,
        .ApiName = "Port_SetPinDirection()"
    },
    {
        .ApiId = PORT_SETPINMODE_ID,
        .ApiName = "Port_SetPinMode()"
    },
    {
        .ApiId = PORT_REFRESHPINDIRECTION_ID,
        .ApiName = "Port_RefreshPortDirection()"
    },
    {
        .ApiId = PORT_GETVERSIONINFO_ID,
        .ApiName = "Port_GetVersionInfo()"
    }
};    ///< Hash table of api names of the Port.

const DetErrorMeaning PortErrors[ DET_PORT_ERRORS ] = {
    {
        .ErrorId = PORT_E_PARAM_PIN,
        .ErrorMeaning = "Invalid Port Pin ID"
    },
    {
        .ErrorId = PORT_E_MODE_UNCHANGEABLE,
        .ErrorMeaning = "Port pin mode is unchangeable"
    },
    {
        .ErrorId = PORT_E_INIT_FAILED,
        .ErrorMeaning = "Invalid conf pointer"
    },
    {
        .ErrorId = PORT_E_PARAM_CONFIG,
        .ErrorMeaning = "Invalid conf pointer"
    },
    {
        .ErrorId = PORT_E_PARAM_INVALID_MODE,
        .ErrorMeaning = "Invalid port pin mode"
    },
    {
        .ErrorId = PORT_E_UNINIT,
        .ErrorMeaning = "Driver uninitialized"
    },
    {
        .ErrorId = PORT_E_PARAM_POINTER,
        .ErrorMeaning = "Invalid input parameter"
    }
};  ///< Hash table of error meanings of the Port.

//Dio.
const DetApiName DioApis[ DET_DIO_APIS ] = {
    {
        .ApiId = DIO_WRITECHANNEL_ID,
        .ApiName = "Dio_WriteChannel()"
    },
    {
        .ApiId = DIO_READCHANNEL_ID,
        .ApiName = "Dio_ReadChannel()"
    },
    {
        .ApiId = DIO_FLIPCHANNEL_ID,
        .ApiName = "Dio_FlipChannel()"
    },
    {
        .ApiId = DIO_WRITECHANNELGROUP_ID,
        .ApiName = "Dio_WriteChannelGroup()"
    },
    {
        .ApiId = DIO_READCHANNELGROUP_ID,
        .ApiName = "Dio_ReadChannelGroup()"
    },
    {
        .ApiId = DIO_WRITEPORT_ID,
        .ApiName = "Dio_WritePort()"
    },
    {
        .ApiId = DIO_READPORT_ID,
        .ApiName = "Dio_ReadPort()"
    },
    {
        .ApiId = DIO_GETVERSIONINFO_ID,
        .ApiName = "Dio_GetVersionInfo()"
    }
};    ///< Hash table of api names of the Dio.

const DetErrorMeaning DioErrors[ DET_DIO_ERRORS ] = {
    {
        .ErrorId = DIO_E_PARAM_LEVEL,
        .ErrorMeaning = "Invalid dio channel level"
    },
    {
        .ErrorId = DIO_E_PARAM_POINTER,
        .ErrorMeaning = "Invalid input parameter"
    },
    {
        .ErrorId = DIO_E_PARAM_INVALID_CHANNEL_ID,
        .ErrorMeaning = "Invalid dio channel id"
    },
    {
        .ErrorId = DIO_E_PARAM_INVALID_PORT_ID,
        .ErrorMeaning = "Invalid port id"
    },
    {
        .ErrorId = DIO_E_PARAM_INVALID_GROUP_ID,
        .ErrorMeaning = "Invalid channel group id"
    },
    {
        .ErrorId = DIO_E_PARAM_CONFIG,
        .ErrorMeaning = "Invalid config parameter"
    }
}; ///< Hash table of error meanings of the Dio.

//Pwm.
const DetApiName PwmApis[ DET_PWM_APIS ] = {
    {
        .ApiId = PWM_INIT_ID,
        .ApiName = "Pwm_Init()"
    },
    {
        .ApiId = PWM_DEINIT_ID,
        .ApiName = "Pwm_DeInit()"
    },
    {
        .ApiId = PWM_SETDUTYCYCLE_ID,
        .ApiName = "Pwm_SetDutyCycle()"
    },
    {
        .ApiId = PWM_SETPERIODANDDUTY_ID,
        .ApiName = "Pwm_SetPeriodAndDuty()"
    },
    {
        .ApiId = PWM_SETOUTPUTTOIDLE_ID,
        .ApiName = "Pwm_SetOutputToIdle()"
    },
    {
        .ApiId = PWM_GETVERSIONINFO_ID,
        .ApiName = "Pwm_GetVersionInfo()"
    }
};    ///< Hash table of api names of the Pwm.

const DetErrorMeaning PwmErrors[ DET_PWM_ERRORS ] = {
    {
        .ErrorId = PWM_E_INIT_FAILED,
        .ErrorMeaning = "Invalid config pointer"
    },
    {
        .ErrorId = PWM_E_UNINIT,
        .ErrorMeaning = "Driver uninitialized"
    },
    {
        .ErrorId = PWM_E_ALREADY_INITIALIZED,
        .ErrorMeaning = "Driver already initialized"
    },
    {
        .ErrorId = PWM_E_PARAM_CHANNEL,
        .ErrorMeaning = "Invalid pwm channel"
    },
    {
        .ErrorId = PWM_E_PERIOD_UNCHANGEABLE,
        .ErrorMeaning = "Pwm channel period is unchangeable"
    }, 
    {
        .ErrorId = PWM_E_PARAM_POINTER,
        .ErrorMeaning = "Invalid input parameter"
    }
};  ///< Hash table of error meanings of the Pwm.

//Adc.
const DetApiName AdcApis[ DET_ADC_APIS ] = {
    {
        .ApiId = ADC_INIT_ID,
        .ApiName = "Adc_Init()"
    }, 
    {
        .ApiId = ADC_DEINIT_ID,
        .ApiName = "Adc_DeInit()"
    },
    {
        .ApiId = ADC_STARTGROUPCONVERSION_ID,
        .ApiName = "Adc_StartGroupConversion()"
    },
    {
        .ApiId = ADC_STOPGROUPCONVERSION_ID,
        .ApiName = "Adc_StopGroupConversion()"
    },
    {
        .ApiId = ADC_VALUEREADGROUP_ID,
        .ApiName = "Adc_ReadGroup()"
    },
    {
        .ApiId =  ADC_GETGROUPSTATUS_ID,
        .ApiName = "Adc_GetGroupStatus()"
    },
    {
        .ApiId =  ADC_CALIBRATE_ID,
        .ApiName = "Adc_Calibrate()"
    },
    {
        .ApiId =  ADC_SETUPRESULTBUFFER_ID,
        .ApiName = "Adc_SetupResultBuffer()"
    },
    {
        .ApiId =  ADC_GETVERSIONINFO_ID,
        .ApiName = "Adc_GetVersionInfo()"
    }
}; ///< Hash table of api names of the Adc.

const DetErrorMeaning AdcErrors[ DET_ADC_ERRORS ] = {
    {
        .ErrorId = ADC_E_UNINIT,
        .ErrorMeaning = "Driver uninitialized"
    }, 
    {
        .ErrorId = ADC_E_ALREADY_INITIALIZED,
        .ErrorMeaning = "Driver already initialized"
    },
    {
        .ErrorId = ADC_E_PARAM_POINTER,
        .ErrorMeaning = "Invalid pointer"
    },
    {
        .ErrorId = ADC_E_PARAM_GROUP,
        .ErrorMeaning = "Invalid adc group"
    },
    {
        .ErrorId = ADC_E_BUFFER_UNINIT,
        .ErrorMeaning = "Buffer pointer not initialized"
    },
    {
        .ErrorId = ADC_E_TIMEOUT,
        .ErrorMeaning = "Calibration operation timed out"
    }
};  ///< Hash table of error meanings of the Adc.

//Scheduler.
const DetApiName SchedulerApis[ DET_SCHEDULER_APIS ] = {
    {
        .ApiId =  SCHEDULER_INIT_ID,
        .ApiName = "Scheduler_Init()"
    },
    {
        .ApiId =  SCHEDULER_GETSTATUSQUEUE_ID,
        .ApiName = "Scheduler_GetStatusQueue()"
    },
    {
        .ApiId =  SCHEDULER_FLUSHQUEUE_ID,
        .ApiName = "Scheduler_FlushQueue()"
    },
    {
        .ApiId =  SCHEDULER_WRITEQUEUE_ID,
        .ApiName = "Scheduler_WriteQueue()"
    }, 
    {
        .ApiId =  SCHEDULER_READQUEUE_ID,
        .ApiName = "Scheduler_ReadQueue()"
    },
    {
        .ApiId =  SCHEDULER_STARTTASK_ID,
        .ApiName = "Scheduler_StartTask()"
    },
    {
        .ApiId =  SCHEDULER_STOPTASK_ID,
        .ApiName = "Scheduler_StopTask()"
    },
    {
        .ApiId =  SCHEDULER_PERIODTASK_ID,
        .ApiName = "Scheduler_PeriodTask()"
    },
    {
        .ApiId =  SCHEDULER_STARTTIMER_ID,
        .ApiName = "Scheduler_StartTimer()"
    },
    {
        .ApiId =  SCHEDULER_STOPTIMER_ID,
        .ApiName = "Scheduler_StopTimer()"
    },
    {
        .ApiId =  SCHEDULER_GETTIMER_ID,
        .ApiName = "Scheduler_GetTimer()"
    },
    {
        .ApiId =  SCHEDULER_RELOADTIMER_ID,
        .ApiName = "Scheduler_ReloadTimer()"
    },
    {
        .ApiId =  SCHEDULER_MAINFUNCTION_ID,
        .ApiName = "Scheduler_MainFunction()"
    }
};    ///< Hash table of api names of the Scheduler.

const DetErrorMeaning SchedulerErrors[ DET_SCHEDULER_ERRORS ] = {
    {
        .ErrorId = SCHEDULER_E_PARAM_CONFIG,
        .ErrorMeaning = "Invalid config pointer"
    },
    {
        .ErrorId = SCHEDULER_E_QUEUE_ID,
        .ErrorMeaning = "Queue id out of range"
    },
    {
        .ErrorId = SCHEDULER_E_QUEUE_STATUS,
        .ErrorMeaning = "Invalid queue status flag"
    },
    {
        .ErrorId = SCHEDULER_E_TASK_ID,
        .ErrorMeaning = "Task id out of range"
    },
    {
        .ErrorId = SCHEDULER_E_PERIODICITY,
        .ErrorMeaning = "Invalid task or timer periodicity"
    },
    {
        .ErrorId = SCHEDULER_E_TIMER_ID,
        .ErrorMeaning = "Timer id out of range"
    },
    {
        .ErrorId = SCHEDULER_E_UNINIT,
        .ErrorMeaning = "Scheduler uninitialized"
    }
};  ///< Hash table of error meanings of the Scheduler.

//HwIoAb buttons.
const DetApiName HwIoAb_ButtonsApis[ DET_HWIOAB_BUTTTONS_APIS ] = {
    {
        .ApiId =  HWIOAB_BUTTONS_INIT_ID,
        .ApiName = "HwIoAb_Buttons_Init()"
    },
    {
        .ApiId =  HWIOAB_BUTTONS_GETEVENT_ID,
        .ApiName = "HwIoAb_Buttons_GetEvent()"
    },
    {
        .ApiId =  HWIOAB_BUTTONS_MAINFUNCTION_ID,
        .ApiName = "HwIoAb_Buttons_MainFunction()"
    }
};  ///< Hash table of api names of the Buttons.

const DetErrorMeaning HwIoAb_ButtonsErrors[ DET_HWIOAB_BUTTONS_ERRORS ] = {
    {
        .ErrorId = HWIOAB_BUTTONS_E_CONFIG,
        .ErrorMeaning = "Invalid config pointer"
    },
    {
        .ErrorId = HWIOAB_BUTTONS_E_BUTTON_ID,
        .ErrorMeaning = "Invalid button id" 
    },
    {
        .ErrorId = HWIOAB_BUTTONS_E_STATE,
        .ErrorMeaning = "Invalid button state"
    },
    {
        .ErrorId = HWIOAB_BUTTONS_E_UNINIT,
        .ErrorMeaning = "Module uninitialized"
    }
};  ///< Hash table of error meanings of the Buttons.

//HwIoAb leds.
const DetApiName HwIoAb_LedsApis[ DET_HWIOAB_LEDS_APIS ] = {
    {
        .ApiId =  HWIOAB_LEDS_INIT_ID,
        .ApiName = "HwIoAb_Leds_Init()"
    },
    {
        .ApiId =  HWIOAB_LEDS_TURNON_ID,
        .ApiName = "HwIoAb_Leds_TurnOn()"
    },
    {
        .ApiId =  HWIOAB_LEDS_TURNOFF_ID,
        .ApiName = "HwIoAb_Leds_TurnOff()"
    },
    {
        .ApiId =  HWIOAB_LEDS_TURNTOGGLE_ID,
        .ApiName = "HwIoAb_Leds_TurnToggle()"
    }
};    ///< Hash table of api names of the Leds.

const DetErrorMeaning HwIoAb_LedsErrors[ DET_HWIOAB_LEDS_ERRORS ] = {
    {
        .ErrorId = HWIOAB_LEDS_E_CONFIG,
        .ErrorMeaning = "Invalid config pointer"
    },
    {
        .ErrorId = HWIOAB_LEDS_E_LED_ID,
        .ErrorMeaning = "Invalid led id"
    },
    {
        .ErrorId = HWIOAB_LEDS_E_UNINIT,
        .ErrorMeaning = "Module uninitialized"
    }
};  ///< Hash table of error meanings of the Leds.

//HwIoAb pots.
const DetApiName HwIoAb_PotsApis[ DET_HWIOAB_POTS_APIS ] = {
    {
        .ApiId =  HWIOAB_POTS_INIT_ID,
        .ApiName = "HwIoAb_Pots_Init()"
    },
    {
        .ApiId =  HWIOAB_POTS_GETVALUE_ID,
        .ApiName = "HwIoAb_Pots_GetValue()"
    },
    {
        .ApiId =  HWIOAB_POTS_GETALTVALUE_ID,
        .ApiName = "HwIoAb_Pots_GetAltValue()"
    }
};    ///< Hash table of api names of the Pots.

const DetErrorMeaning HwIoAb_PotsErrors[ DET_HWIOAB_POTS_ERRORS ] = {
    {
        .ErrorId = HWIOAB_POTS_E_PARAM,
        .ErrorMeaning = "Invalid input pointer"
    },
    {
        .ErrorId = HWIOAB_POTS_E_UNINIT,
        .ErrorMeaning = "Module uninitialized"
    }
};  ///< Hash table of error meanings of the Pots.

//HwIoAb buzzer.
const DetApiName HwIoAb_BuzzerApis[ DET_HWIOAB_BUZZER_APIS ] = {
    {
        .ApiId =  HWIOAB_BUZZER_INIT_ID,
        .ApiName = "HwIoAb_Buzzer_Init()"
    },
    {
        .ApiId =  HWIOAB_BUZZER_BEEP_ID,
        .ApiName = "HwIoAb_Buzzer_Beep()"
    },
    {
        .ApiId =  HWIOAB_BUZZER_STOP_ID,
        .ApiName = "HwIoAb_Buzzer_Stop()"
    }
};    ///< Hash table of api names of the Buzzer.

const DetErrorMeaning HwIoAb_BuzzerErrors[ DET_HWIOAB_BUZZER_ERRORS ] = {
    {
        .ErrorId = HWIOAB_BUZZER_E_TONE,
        .ErrorMeaning = "Invalid buzzer tone"
    }
};  ///< Hash table of error meanings of the Buzzer.

//General array.
const DetStrings ModuleStrings[ DET_MODULES ] = {  ///< Array of structs for the modules.
    {
        .ModuleId = MCU_MODULE_ID,
        .ModuleName = "Mcu module",
        .Apis = DET_MCU_APIS,
        .ApiNames = McuApis,
        .Errors = DET_MCU_ERRORS,
        .ErrorMeanings = McuErrors
    },
    {
        .ModuleId = CDD_PLATFORM_MODULE_ID,
        .ModuleName = "Platform module",
        .Apis = DET_PLATFORM_APIS,
        .ApiNames = PlatformApis,
        .Errors = DET_PLATFORM_ERRORS,
        .ErrorMeanings = PlatformErrors
    },
    {
        .ModuleId = PORT_MODULE_ID,
        .ModuleName = "Port module",
        .Apis = DET_PORT_APIS,
        .ApiNames = PortApis,
        .Errors = DET_PORT_ERRORS,
        .ErrorMeanings = PortErrors
    },
    {
        .ModuleId = DIO_MODULE_ID,
        .ModuleName = "Dio module",
        .Apis = DET_DIO_APIS,
        .ApiNames = DioApis,
        .Errors = DET_DIO_ERRORS,
        .ErrorMeanings = DioErrors
    },
    {
        .ModuleId = PWM_MODULE_ID,
        .ModuleName = "Pwm module",
        .Apis = DET_PWM_APIS,
        .ApiNames = PwmApis,
        .Errors = DET_PWM_ERRORS,
        .ErrorMeanings = PwmErrors
    },
    {
        .ModuleId = ADC_MODULE_ID,
        .ModuleName = "Adc module",
        .Apis = DET_ADC_APIS,
        .ApiNames = AdcApis,
        .Errors = DET_ADC_ERRORS,
        .ErrorMeanings = AdcErrors
    },
    {
        .ModuleId = SCHEDULER_MODULE_ID,
        .ModuleName = "Scheduler module",
        .Apis = DET_SCHEDULER_APIS,
        .ApiNames = SchedulerApis,
        .Errors = DET_SCHEDULER_ERRORS,
        .ErrorMeanings = SchedulerErrors
    },
    {
        .ModuleId = HWIOAB_BUTTONS_MODULE_ID,
        .ModuleName = "Buttons IO abstraction module",
        .Apis = DET_HWIOAB_BUTTTONS_APIS,
        .ApiNames = HwIoAb_ButtonsApis,
        .Errors = DET_HWIOAB_BUTTONS_ERRORS,
        .ErrorMeanings = HwIoAb_ButtonsErrors
    },
    {
        .ModuleId = HWIOAB_LEDS_MODULE_ID,
        .ModuleName = "Leds IO abstraction module",
        .Apis = DET_HWIOAB_LEDS_APIS,
        .ApiNames = HwIoAb_LedsApis,
        .Errors = DET_HWIOAB_LEDS_ERRORS,
        .ErrorMeanings = HwIoAb_LedsErrors
    },
    {
        .ModuleId = HWIOAB_POTS_MODULE_ID,
        .ModuleName = "Pots IO abstraction module",
        .Apis = DET_HWIOAB_POTS_APIS,
        .ApiNames = HwIoAb_PotsApis,
        .Errors = DET_HWIOAB_POTS_ERRORS,
        .ErrorMeanings = HwIoAb_PotsErrors
    },
    {
        .ModuleId = HWIOAB_BUZZER_MODULE_ID,
        .ModuleName = "Buzzer IO abstraction module",
        .Apis = DET_HWIOAB_BUTTTONS_APIS,
        .ApiNames = HwIoAb_BuzzerApis,
        .Errors = DET_HWIOAB_BUZZER_ERRORS,
        .ErrorMeanings = HwIoAb_BuzzerErrors
    }
};

const DetStrings *const ModuleStrings_Ptr = ModuleStrings;    ///< Pointer to general array.

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define DET_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Det_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"
/* Variables to store last DET error */
uint8 Det_InstanceId[DET_NO_ECU_CORES];                /**< @brief DET instance ID*/
uint8 Det_ApiId[DET_NO_ECU_CORES];                     /**< @brief DET API ID*/
uint8 Det_ErrorId[DET_NO_ECU_CORES];                   /**< @brief DET Error ID*/
/* Variables to store last DET runtime error */
uint8 Det_RuntimeInstanceId[DET_NO_ECU_CORES];         /**< @brief DET instance ID*/
uint8 Det_RuntimeApiId[DET_NO_ECU_CORES];              /**< @brief DET API ID*/
uint8 Det_RuntimeErrorId[DET_NO_ECU_CORES];            /**< @brief DET Error ID*/
/* Variables to store last DET transient error */
uint8 Det_TransientInstanceId[DET_NO_ECU_CORES];       /**< @brief DET instance ID*/
uint8 Det_TransientApiId[DET_NO_ECU_CORES];            /**< @brief DET API ID*/
uint8 Det_TransientFaultId[DET_NO_ECU_CORES];          /**< @brief DET Error ID*/
#define DET_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Det_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"

#define DET_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
/*
 * @violates @ref Det_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"
uint16 Det_TransientModuleId[DET_NO_ECU_CORES];       /**< @brief DET module ID*/
uint16 Det_ModuleId[DET_NO_ECU_CORES];       /**< @brief DET module ID*/
uint16 Det_RuntimeModuleId[DET_NO_ECU_CORES];       /**< @brief DET module ID*/
#define DET_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
/*
 * @violates @ref Det_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* put all DET code into defined section */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define DET_START_SEC_CODE
#include "Det_MemMap.h"

/*================================================================================================*/
/**
* @brief          This function initializes the DET module.
* @details        This is a function stub only. Functionality is void in this implementation
*
* @requirements   DET008
*
*/
void Det_Init(void)
{
    SEGGER_RTT_Init();  //Initializing RTT library.
}

/*================================================================================================*/
/**
 * @brief This function searchs an specific api name of a module.
 * 
 * @param[in] ModuleIndex Index where the module is registered in array.
 * @param[in] ApiId Api id where error was detected.
 * @return StringPtr Ptr to string of api name.
 * 
 * @note If the Api Id isn´t registered in the hash table it will return NULL; 
 */
const char* Det_SearchApi( uint8 ModuleIndex, uint8 ApiId ) {
    //local data.
    uint8 i = 0;
    const char *StringPtr = NULL_PTR;

    for ( i = 0; i < ModuleStrings_Ptr[ ModuleIndex ].Apis; i++ ) { //Searching for api.
        if ( ModuleStrings_Ptr[ ModuleIndex ].ApiNames[i].ApiId == ApiId ) {
            StringPtr = ModuleStrings_Ptr[ ModuleIndex ].ApiNames[i].ApiName;
            break;
        }
    }

    return StringPtr;
}

/**
 * @brief This function searchs an specific error meaning of a module.
 * 
 * @param[in] ModuleIndex Index where the module is registered in array.
 * @param[in] ErrorId Error id reported.
 * @return StringPtr Ptr to string of error meaning.
 * 
 * @note If the Error Id isn´t registered in the hash table it will return NULL; 
 */
const char* Det_SearchError( uint8 ModuleIndex, uint8 ErrorId ) {
    //local data.
    uint8 i = 0;
    const char *StringPtr = NULL_PTR;

    for ( i = 0; i < ModuleStrings_Ptr[ ModuleIndex ].Errors; i++ ) { //Searching for api.
        if ( ModuleStrings_Ptr[ ModuleIndex ].ErrorMeanings[i].ErrorId == ErrorId ) {
            StringPtr = ModuleStrings_Ptr[ ModuleIndex ].ErrorMeanings[i].ErrorMeaning;
            break;
        }
    }

    return StringPtr;
}

/**
 * @brief This function gets the string name corresponding to a module Id.
 * 
 * @param[in] ModuleId Module Id where error was detected.
 * @return StringPtr Pointer to string module name.
 * 
 * @note If the module Id isn´t registered it will return NULL;
 */
const char* Det_GetModuleName( uint16 ModuleId ) {
    //local data 
    uint8 i = 0;
    const char *StringPtr = NULL_PTR;

    for ( i = 0; i < DET_MODULES; i++ ) {  //Searching module name.
        if ( ModuleStrings_Ptr[i].ModuleId == ModuleId ) {
            StringPtr = ModuleStrings_Ptr[i].ModuleName;
            break;
        }
    }

    return StringPtr;
}

/*================================================================================================*/
/**
 * @brief This function gets the string name corresponding to an Api Id.
 * 
 * @param[in] ModuleId Module Id where error was detected. 
 * @param[in] ApiId Api Id where error was detected 
 * @return StringPtr Pointer to string Api name.
 * 
 * @note If the Api Id isn´t registered in the hash table it will return NULL;
 */
const char* Det_GetApiName( uint16 ModuleId, uint8 ApiId ) {
    //local data.
    uint8 i = 0;
    const char *StringPtr = NULL_PTR;

    for ( i = 0; i < DET_MODULES; i++ ) {  //Searching for module.
        if ( ModuleStrings_Ptr[i].ModuleId == ModuleId ) {
            StringPtr = Det_SearchApi( i , ApiId ); //Searching Api.
            break;
        }
    }

    return StringPtr;
}

/*================================================================================================*/
/**
 * @brief This function gets the error meaning according to the Error Id.
 * 
 * @param[in] ModuleId Module Id where error was detected.
 * @param[in] ErrorId Error Id reported. 
 * @return StringPtr Pointer to string Error meaning.
 * 
 * @note If the Error Id isn´t registered in the hash table it will return NULL;
 */
const char* Det_GetErrorMeaning( uint16 ModuleId, uint8 ErrorId ) {
    //local data.
    uint8 i = 0;
    const char * StringPtr = NULL_PTR;

    for ( i = 0; i < DET_MODULES; i++ ) {  //Searching for module.
        if ( ModuleStrings_Ptr[i].ModuleId == ModuleId ) {
            StringPtr = Det_SearchError( i, ErrorId );
            break;
        }
    }

    return StringPtr;
}

/*================================================================================================*/
/**
* @brief   This function provides the service for reporting of development errors.
* @details This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
*
* @param[in]     ModuleId    Module ID of Calling Module
* @param[in]     InstanceId  Index of Module starting at 0
* @param[in]     ApiId       ID of API with Error
* @param[in]     ErrorId     ID of Error
*
* @requirement DET009
*/
Std_ReturnType Det_ReportError(uint16 ModuleId,
                               uint8 InstanceId,
                               uint8 ApiId,
                               uint8 ErrorId)
{
    //local data.
    const char* Strings_error[3]; //Pointer to strings for the error message.

    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    Det_ModuleId[u32CoreId] = ModuleId;
    Det_InstanceId[u32CoreId] = InstanceId;
    Det_ApiId[u32CoreId] = ApiId;
    Det_ErrorId[u32CoreId] = ErrorId;

    //Obtaining strings for error message.
    Strings_error[0] = Det_GetModuleName( ModuleId );
    Strings_error[1] = Det_GetApiName( ModuleId, ApiId );
    Strings_error[2] = Det_GetErrorMeaning( ModuleId, ErrorId );

    SEGGER_RTT_printf( 0, "Error: Error in %s in function %s with the instance %d, %s\n", 
    Strings_error[0], Strings_error[1], InstanceId, Strings_error[2] );

    return E_OK;
}

/*================================================================================================*/
/**
* @brief   This function provides the service for reporting of runtime errors.
* @details This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
*
* @param[in]     ModuleId    Module ID of Calling Module
* @param[in]     InstanceId  Index of Module starting at 0
* @param[in]     ApiId       ID of API with Error
* @param[in]     ErrorId     ID of Error
*
* @requirement SWS_Det_01001
*/
Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId,
                                      uint8 InstanceId,
                                      uint8 ApiId,
                                      uint8 ErrorId)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    Det_RuntimeModuleId[u32CoreId] = ModuleId;
    Det_RuntimeInstanceId[u32CoreId] = InstanceId;
    Det_RuntimeApiId[u32CoreId] = ApiId;
    Det_RuntimeErrorId[u32CoreId] = ErrorId;

    return E_OK;
}

/*================================================================================================*/
/**
* @brief   This function provides the service for reporting of transient errors.
* @details This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
*
* @param[in]     ModuleId    Module ID of Calling Module
* @param[in]     InstanceId  Index of Module starting at 0
* @param[in]     ApiId       ID of API with Error
* @param[in]     FaultId     ID of Fault
*
* @requirement SWS_Det_01001
*/
Std_ReturnType Det_ReportTransientFault(uint16 ModuleId,
                                        uint8 InstanceId,
                                        uint8 ApiId,
                                        uint8 FaultId)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    Det_TransientModuleId[u32CoreId] = ModuleId;
    Det_TransientInstanceId[u32CoreId] = InstanceId;
    Det_TransientApiId[u32CoreId] = ApiId;
    Det_TransientFaultId[u32CoreId] = FaultId;

    return E_OK;
}

/*================================================================================================*/
/**
* @brief   This function provides the starting after the Det_Init has been called.
* @details This is a function stub only.  Det_Init and Det_Start shall always be available.
*          Functionality is void in this implementation
*
* @requirement DET010
*/
void Det_Start(void)
{
    /* Do nothing */
}

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
