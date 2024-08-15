/**
 * @file CanIf_Cdd.h
 * @brief This header contains the declaration of the notifications for the CanIf driver related to the transmision
 * and reception of PDUs of each CanIf controller registered.
 * 
 */

#ifndef CANIF_CDD_H
#define CANIF_CDD_H

//Headers.
#include "CanIf.h"

//Global data.
extern boolean CanIf_Can2_bTxFlag;   ///< Flag for transmision of PDU of FlexCan2 controller.
extern boolean CanIf_Can2_bRxFlag;   ///< Flag for reception of PDU of FlexCan2 controller.

//Functions.
//Can 2 controller.
void CDD_UserTxConfirmation_Can_2( PduIdType TxPduId, Std_ReturnType result );
void CDD_UserRxIndication_Can_2( PduIdType RxPduId, const PduInfoType* PduInfoPtr );

#endif