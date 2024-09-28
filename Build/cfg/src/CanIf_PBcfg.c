/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : generic
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/**
*   @file    CanIf_PBcfg.c
*   @version 2.0.0
*
*   @brief   AUTOSAR CanIf - module interface
*   @details Configuration Structures for PostBuild
*
*   @addtogroup CANIF_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanIf.h"

#include "CanIf_Cdd.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_VENDOR_ID_PBCFG_C                      43
#define CANIF_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
#define CANIF_AR_RELEASE_MINOR_VERSION_PBCFG_C       7
#define CANIF_AR_RELEASE_REVISION_VERSION_PBCFG_C    0
#define CANIF_SW_MAJOR_VERSION_PBCFG_C               2
#define CANIF_SW_MINOR_VERSION_PBCFG_C               0
#define CANIF_SW_PATCH_VERSION_PBCFG_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"


/* Here is the TxPdu configuration */
static const CanIf_TxPduType CanIf_TxPdu[5U] =
{
    {
        /* .PduIdType */
        (uint8)0U,
        /* .CanId */
        (Can_IdType)256U,
        /* .CanFrameType */
        CANIF_STANDARD_FD_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)5U,
        /* .CanIfCtrlId */
        (uint8)1U,
        /* .UserTxConfirmation */
        CDD_UserTxConfirmation_Can_0
    },
    {
        /* .PduIdType */
        (uint8)1U,
        /* .CanId */
        (Can_IdType)257U,
        /* .CanFrameType */
        CANIF_STANDARD_FD_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)5U,
        /* .CanIfCtrlId */
        (uint8)1U,
        /* .UserTxConfirmation */
        CDD_UserTxConfirmation_Can_0
    },
    {
        /* .PduIdType */
        (uint8)2U,
        /* .CanId */
        (Can_IdType)258U,
        /* .CanFrameType */
        CANIF_STANDARD_FD_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)5U,
        /* .CanIfCtrlId */
        (uint8)1U,
        /* .UserTxConfirmation */
        CDD_UserTxConfirmation_Can_0
    },
    {
        /* .PduIdType */
        (uint8)3U,
        /* .CanId */
        (Can_IdType)259U,
        /* .CanFrameType */
        CANIF_STANDARD_FD_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)5U,
        /* .CanIfCtrlId */
        (uint8)1U,
        /* .UserTxConfirmation */
        CDD_UserTxConfirmation_Can_0
    },
    {
        /* .PduIdType */
        (uint8)4U,
        /* .CanId */
        (Can_IdType)768U,
        /* .CanFrameType */
        CANIF_STANDARD_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)6U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        CDD_UserTxConfirmation_Can_2
    }
};

/* Here is the RxPdu configuration */
static const CanIf_RxPduType CanIf_RxPdu[5U] =
{
    {
        /* .PduId */
        (uint8)0U,
        /* .PduLengthCheck */
        (boolean)TRUE,
        /* .PduLength */
        (uint16)3U,
        /* .CanIfCtrlId */
        (uint8)1U,
        /* .UserRxIndication */
        CDD_UserRxIndication_Can_0
    },
    {
        /* .PduId */
        (uint8)1U,
        /* .PduLengthCheck */
        (boolean)TRUE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)1U,
        /* .UserRxIndication */
        CDD_UserRxIndication_Can_0
    },
    {
        /* .PduId */
        (uint8)2U,
        /* .PduLengthCheck */
        (boolean)TRUE,
        /* .PduLength */
        (uint16)12U,
        /* .CanIfCtrlId */
        (uint8)1U,
        /* .UserRxIndication */
        CDD_UserRxIndication_Can_0
    },
    {
        /* .PduId */
        (uint8)3U,
        /* .PduLengthCheck */
        (boolean)TRUE,
        /* .PduLength */
        (uint16)9U,
        /* .CanIfCtrlId */
        (uint8)1U,
        /* .UserRxIndication */
        CDD_UserRxIndication_Can_0
    },
    {
        /* .PduId */
        (uint8)4U,
        /* .PduLengthCheck */
        (boolean)TRUE,
        /* .PduLength */
        (uint16)3U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        CDD_UserRxIndication_Can_2
    }
};


/* Here is the configuration related to Can_43_FLEXCAN Driver */
static const CanIf_RxPduType * const CanIf_Can_43_FLEXCAN_HohToRxPduMapping[7U] = 
{
    &CanIf_RxPdu[0U],
    &CanIf_RxPdu[1U],
    &CanIf_RxPdu[2U],
    &CanIf_RxPdu[3U],
    &CanIf_RxPdu[4U],
    NULL_PTR,
    NULL_PTR
};

static const CanIf_CanDrvConfigType CanIf_Can_43_FLEXCAN_DrvConfig = 
{
    /* .HohToRxPduMappingPtr */
    CanIf_Can_43_FLEXCAN_HohToRxPduMapping
};

static const CanIf_CanDrvConfigType * const CanIf_CanDrvConfig[1U] =
{
    &CanIf_Can_43_FLEXCAN_DrvConfig
};


const CanIf_ConfigType CanIf_Config =
{
    /* .NumRxPdu */
    (uint8)5U,
    /* .NumTxPdu */
    (uint8)5U,
    CanIf_CanDrvConfig,
    /* .CanIf_RxPduConfigPtr */
    CanIf_RxPdu,
    /* .CanIf_TxPduConfigPtr */
    CanIf_TxPdu
};

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
