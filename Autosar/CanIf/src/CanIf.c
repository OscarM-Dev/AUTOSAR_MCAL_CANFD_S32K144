/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : generic
* Dependencies : 
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 2.0.0
* Build Version : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
/**
*   @file       CanIf.c
*
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
#include "CanIf_Can.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_VENDOR_ID_C                         43
#define CANIF_MODULE_ID_C                         60
#define CANIF_AR_RELEASE_MAJOR_VERSION_C          4
#define CANIF_AR_RELEASE_MINOR_VERSION_C          7
#define CANIF_AR_RELEASE_REVISION_VERSION_C       0
#define CANIF_SW_MAJOR_VERSION_C                  2
#define CANIF_SW_MINOR_VERSION_C                  0
#define CANIF_SW_PATCH_VERSION_C                  0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

extern const CanIf_PCConfigType CanIf_PCConfig; 
#if (STD_ON == CANIF_PRECOMPILE_SUPPORT)
extern const CanIf_ConfigType CanIf_Config;
#endif

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"

static const CanIf_ConfigType * CanIf_ConfigPtr;

#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

/**
 * @brief This function initialices the CanIf Driver.
 * 
 * @param ConfigPtr Pointer to driver control structure. 
 */
void CanIf_Init(const CanIf_ConfigType * ConfigPtr)
{
    #if (STD_ON == CANIF_PRECOMPILE_SUPPORT)
    CanIf_ConfigPtr = &CanIf_Config;
    (void)ConfigPtr;
    #else
    CanIf_ConfigPtr = ConfigPtr;
    #endif
}

/**
 * @brief This function transmits a given PDU.
 * 
 * @param CanTxPduId Id of the PDU (container) to transmit.
 * @param PduInfoPtr Pointer to PDU (message) to transmit.
 * @return RetVal Status of the operation. 
 */
Std_ReturnType CanIf_Transmit
(
    PduIdType CanTxPduId,
    const PduInfoType * PduInfoPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    Can_HwHandleType CanHth = 0U;
    Can_PduType PduInfo;
    const CanIf_TxPduType * TxPduInfo = NULL_PTR;
    uint8 CanIfControllerId = 0U;
    const CanIf_CtrlPCConfigType * CanIfController = NULL_PTR;

    if (NULL_PTR != CanIf_ConfigPtr)
    {
        if (CanTxPduId < (CanIf_ConfigPtr->NumTxPdu))
        {
            TxPduInfo = &CanIf_ConfigPtr->CanIf_TxPduConfigPtr[CanTxPduId];
            CanIfControllerId = TxPduInfo->CanIfCtrlId;
            CanIfController = &CanIf_PCConfig.CanIfCtrlConfigPtr[CanIfControllerId];

            CanHth = TxPduInfo->CanHth;

            PduInfo.id = TxPduInfo->CanId;
            /* Convert Id by adding two most significant bits specify the frame type */
            switch (TxPduInfo->CanFrameType)
            {
                case CANIF_EXTENDED_CAN:
                {
                    PduInfo.id |= 0x80000000U;
                    break;
                }
                case CANIF_EXTENDED_FD_CAN:
                {
                    PduInfo.id |= 0xC0000000U;
                    break;
                }
                case CANIF_STANDARD_FD_CAN:
                {
                    PduInfo.id |= 0x40000000U;
                    break;
                }
                default:
                {
                    break;
                }
            }
            
            PduInfo.length = (uint8)(PduInfoPtr->SduLength);
            PduInfo.sdu = PduInfoPtr->SduDataPtr;
            PduInfo.swPduHandle = CanTxPduId;

            RetVal = CanIfController->CanDrvConfigPtr->CanApi->CanWrite(CanHth, &PduInfo); 
        }
    }
    return RetVal;
}

void CanIf_TxConfirmation
(
    PduIdType CanTxPduId
)
{
    PduIdType UserPduId;
    const CanIf_TxPduType * TxPduInfo = NULL_PTR;

    if (NULL_PTR != CanIf_ConfigPtr)
    {
        if (CanTxPduId < (CanIf_ConfigPtr->NumTxPdu))
        {
            TxPduInfo = &CanIf_ConfigPtr->CanIf_TxPduConfigPtr[CanTxPduId];

            if (NULL_PTR != TxPduInfo->UserTxConfirmation)
            {
                UserPduId = TxPduInfo->PduId;
                TxPduInfo->UserTxConfirmation(UserPduId, E_OK);
            }
        }
    }
}


void CanIf_RxIndication
(
    const Can_HwType * Mailbox,
    const PduInfoType * PduInfoPtr
)
{
    PduIdType UserPduId = 0U;
    PduInfoType PduInfo;
    const CanIf_RxPduType * RxPduInfo = NULL_PTR;
    uint8 CanDrvId = 0U;

    if (NULL_PTR != CanIf_ConfigPtr)
    {
        if ((Mailbox->ControllerId) < (CanIf_PCConfig.NumOfCtrl))
        {
            if ((Mailbox->Hoh) < (CanIf_PCConfig.CanIfCtrlConfigPtr[Mailbox->ControllerId].CanDrvConfigPtr->NumCanHoh))
            {
                CanDrvId = CanIf_PCConfig.CanIfCtrlConfigPtr[Mailbox->ControllerId].CanDrvConfigPtr->CanDrvId;
                RxPduInfo = CanIf_ConfigPtr->CanDrvConfigPtr[CanDrvId]->HohToRxPduMappingPtr[Mailbox->Hoh];
                
                /* Will discard the Can HOH if it was not referred by any CanIf RxPDU */
                if (NULL_PTR != RxPduInfo)
                {
                    if (NULL_PTR != RxPduInfo->UserRxIndication)
                    {
                        UserPduId = RxPduInfo->PduId;
                        if ((TRUE == RxPduInfo->PduLengthCheck) && (PduInfoPtr->SduLength > (RxPduInfo->PduLength)))
                        {
                            PduInfo.SduLength = RxPduInfo->PduLength; /* Truncates exceeded data as configured on GUI */
                        }
                        else
                        {
                            PduInfo.SduLength = PduInfoPtr->SduLength;
                        }
                        PduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;
                        RxPduInfo->UserRxIndication(UserPduId, &PduInfo);
                    }
                }
            }
        }
    }
}

void CanIf_ControllerModeIndication
( 
    uint8 ControllerId, 
    Can_ControllerStateType ControllerMode 
)
{
    (void)ControllerId; 
    (void)ControllerMode;
}

void CanIf_ControllerBusOff ( uint8 ControllerId ) {
    switch ( ControllerId ) { //Identifying which CAN controller is in bus off state.
        case 0: //FlexCan2
            CanIf_Can2_BusOff_Count++;
        break;
                
        case 1: //FlexCan0
            //Restarting controller
            CanIf_SetControllerMode( CanIfFlexCan0 , CAN_CS_STOPPED );
            CanIf_SetControllerMode( CanIfFlexCan0 , CAN_CS_STARTED );
            
            CanIf_Can0_bTxFlag = TRUE;  //For restarting transmission routine.
            CanIf_Can0_BusOff_Count++;
        break;
        
        default:
        break;
    }
}

/**
 * @brief This function sets a given CanIf controller to a given state.
 * 
 * @param Controller CanIf controller ID.
 * @param Transition Desired state.
 * @return RetVal Status of the operation.
 */
Std_ReturnType CanIf_SetControllerMode( uint8 Controller, Can_ControllerStateType Transition ) {
    //Local data.
    Std_ReturnType RetVal = E_NOT_OK;
    const CanIf_CtrlPCConfigType * CanIfControllerConf = NULL_PTR;    //Pointer to CanIf controller configuration.
    uint8 CanController_ID = 0; //Can controller ID.


    if ( CanIf_ConfigPtr != NULL_PTR ) { 
        if ( Controller < CanIf_PCConfig.NumOfCtrl ) { //Operation can be done as normal.
            CanIfControllerConf = &CanIf_PCConfig.CanIfCtrlConfigPtr[ Controller ];
            CanController_ID = CanIfControllerConf->CanCtrlId;
            RetVal = CanIfControllerConf->CanDrvConfigPtr->CanApi->CanSetMode( CanController_ID, Transition );   //Calling Can Driver Api.
        }
    }

    return RetVal;
}

/**
 * @brief This function enables the interrupts of a given CanIf controller.
 * 
 * @param Controller CanIf controller ID.
 */
void CanIf_EnableControllerInterrupts( uint8 Controller ) {
    //local data.
    const CanIf_CtrlPCConfigType * CanIfControllerConf = NULL_PTR;    //Pointer to CanIf controller configuration.
    uint8 CanController_ID = 0; //Can controller ID.

    if ( CanIf_ConfigPtr != NULL_PTR ) { 
        if ( Controller < CanIf_PCConfig.NumOfCtrl ) { //Operation can be done as normal.
            CanIfControllerConf = &CanIf_PCConfig.CanIfCtrlConfigPtr[ Controller ];
            CanController_ID = CanIfControllerConf->CanCtrlId;
            CanIfControllerConf->CanDrvConfigPtr->CanApi->CanEnableInterrupts( CanController_ID );   //Calling Can Driver Api.
        }
    }
}

/**
 * @brief This function disables the interrupts of a given CanIf controller.
 * 
 * @param Controller CanIf controller ID.
 */
void CanIf_DisableControllerInterrupts( uint8 Controller ) {
    //local data.
    const CanIf_CtrlPCConfigType * CanIfControllerConf = NULL_PTR;    //Pointer to CanIf controller configuration.
    uint8 CanController_ID = 0; //Can controller ID.

    if ( CanIf_ConfigPtr != NULL_PTR ) { 
        if ( Controller < CanIf_PCConfig.NumOfCtrl ) { //Operation can be done as normal.
            CanIfControllerConf = &CanIf_PCConfig.CanIfCtrlConfigPtr[ Controller ];
            CanController_ID = CanIfControllerConf->CanCtrlId;
            CanIfControllerConf->CanDrvConfigPtr->CanApi->CanDisableInterrupts( CanController_ID );   //Calling Can Driver Api.
        }
    }
}

/**
 * @brief This function obtains the actual error state of a given CanIf controller.
 * 
 * @param ControllerId CanIf controller ID.
 * @param ErrorStatePtr Pointer to variable to store the actual error state of the controller.
 * @return RetVal Status of the operation. 
 */
Std_ReturnType CanIf_GetControllerErrorState( uint8 ControllerId, Can_ErrorStateType *ErrorStatePtr) {
    //Local data.
    Std_ReturnType RetVal = E_NOT_OK;
    const CanIf_CtrlPCConfigType * CanIfControllerConf = NULL_PTR;    //Pointer to CanIf controller configuration.
    uint8 CanController_ID = 0; //Can controller ID.

    if ( CanIf_ConfigPtr != NULL_PTR ) { 
        if ( ControllerId < CanIf_PCConfig.NumOfCtrl ) { //Operation can be done as normal.
            CanIfControllerConf = &CanIf_PCConfig.CanIfCtrlConfigPtr[ ControllerId ];
            CanController_ID = CanIfControllerConf->CanCtrlId;
            RetVal = CanIfControllerConf->CanDrvConfigPtr->CanApi->CanGetErrorState( CanController_ID, ErrorStatePtr );   //Calling Can Driver Api.
        }
    }

    return RetVal;
}
 
/**
 * @brief This function obtains the actual state of a given CanIf controller.
 * 
 * @param Controller CanIf controller ID.
 * @param ControllerModePtr Pointer to variable to store the actual state of the controller.
 * @return RetVal Status of the operation.
 */
Std_ReturnType CanIf_GetControllerMode( uint8 Controller, Can_ControllerStateType *ControllerModePtr ) {
    //Local data.
    Std_ReturnType RetVal = E_NOT_OK;
    const CanIf_CtrlPCConfigType * CanIfControllerConf = NULL_PTR;    //Pointer to CanIf controller configuration.
    uint8 CanController_ID = 0; //Can controller ID.

    if ( CanIf_ConfigPtr != NULL_PTR ) { 
        if ( Controller < CanIf_PCConfig.NumOfCtrl ) { //Operation can be done as normal.
            CanIfControllerConf = &CanIf_PCConfig.CanIfCtrlConfigPtr[ Controller ];
            CanController_ID = CanIfControllerConf->CanCtrlId;
            RetVal = CanIfControllerConf->CanDrvConfigPtr->CanApi->CanGetMode( CanController_ID, ControllerModePtr );   //Calling Can Driver Api.
        }
    }

    return RetVal;
}

/**
 * @brief This function obtains the actual Rx error count of a given CanIf controller.
 * 
 * @param ControllerId CanIf controller ID.
 * @param RxErrorCounterPtr Pointer to variable to store the actual value of the rx error counter of the controller.
 * @return RetVal Status of the operation.
 */
Std_ReturnType CanIf_GetControllerRxErrorCounter( uint8 ControllerId, uint8 *RxErrorCounterPtr ) {
    //Local data.
    Std_ReturnType RetVal = E_NOT_OK;
    const CanIf_CtrlPCConfigType * CanIfControllerConf = NULL_PTR;    //Pointer to CanIf controller configuration.
    uint8 CanController_ID = 0; //Can controller ID.

    if ( CanIf_ConfigPtr != NULL_PTR ) { 
        if ( ControllerId < CanIf_PCConfig.NumOfCtrl ) { //Operation can be done as normal.
            CanIfControllerConf = &CanIf_PCConfig.CanIfCtrlConfigPtr[ ControllerId ];
            CanController_ID = CanIfControllerConf->CanCtrlId;
            RetVal = CanIfControllerConf->CanDrvConfigPtr->CanApi->CanGetRxErrorCounter( CanController_ID, RxErrorCounterPtr );   //Calling Can Driver Api.
        }
    }

    return RetVal;
}

/**
 * @brief This function obtains the actual Tx error count of a given CanIf controller.
 * 
 * @param ControllerId CanIf controller ID.
 * @param TxErrorCounterPtr Pointer to variable to store the actual value of the tx error counter of the controller.
 * @return RetVal Status of the operation. 
 */
Std_ReturnType CanIf_GetControllerTxErrorCounter( uint8 ControllerId, uint8 *TxErrorCounterPtr ) {
    //Local data.
    Std_ReturnType RetVal = E_NOT_OK;
    const CanIf_CtrlPCConfigType * CanIfControllerConf = NULL_PTR;    //Pointer to CanIf controller configuration.
    uint8 CanController_ID = 0; //Can controller ID.

    if ( CanIf_ConfigPtr != NULL_PTR ) { 
        if ( ControllerId < CanIf_PCConfig.NumOfCtrl ) { //Operation can be done as normal.
            CanIfControllerConf = &CanIf_PCConfig.CanIfCtrlConfigPtr[ ControllerId ];
            CanController_ID = CanIfControllerConf->CanCtrlId;
            RetVal = CanIfControllerConf->CanDrvConfigPtr->CanApi->CanGetTxErrorCounter( CanController_ID, TxErrorCounterPtr );   //Calling Can Driver Api.
        }
    }

    return RetVal;
}


/**
 * @note Initialization for the pointers to APIs of CAN driver.
 *      &Can_43_FLEXCAN_Write,
        &Can_43_FLEXCAN_SetControllerMode,
        &Can_43_FLEXCAN_EnableControllerInterrupts,
        &Can_43_FLEXCAN_DisableControllerInterrupts,
        &Can_43_FLEXCAN_GetControllerErrorState,
        &Can_43_FLEXCAN_GetControllerMode,
        &Can_43_FLEXCAN_GetControllerRxErrorCounter,
        &Can_43_FLEXCAN_GetControllerTxErrorCounter
*/


#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#ifdef __cplusplus
}
#endif /* CANIF_C */

/** @} */
