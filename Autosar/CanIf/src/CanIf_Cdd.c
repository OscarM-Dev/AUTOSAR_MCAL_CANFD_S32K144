/**
 * @file CanIf_Cdd.c
 * @brief This file contains the definition of the notifications for the CanIf driver related to the transmision
 * and reception of PDUs of each CanIf controller registered.
 * 
 */

//Headers.
#include "CanIf_Cdd.h"

//Functions.
//Can 0 controller.
/**
 * @brief Callback function for the complete transmit of a PDU (registered) from Can0 controller.
 * 
 * @param TxPduId ID (container) of the PDU transmitted.
 * @param result Status of the transmision operation.
 */
void CDD_UserTxConfirmation_Can_0( PduIdType TxPduId, Std_ReturnType result ) {
    //local data.
    static uint8 Transmit_count = 0;    //Count of transmitted PDUs.
    (void)TxPduId;

    if ( result == E_OK ) { //Message was transmitted successfully.
        Transmit_count++;
        CanIf_Can0_bTxFlag = TRUE;
    }
    
}

/**
 * @brief Callback function for the reception of a PDU (registered) of interest for the Can0 controller.
 * 
 * @param RxPduId ID (container) of the PDU received.
 * @param PduInfoPtr Pointer to PDU received (message)
 */
void CDD_UserRxIndication_Can_0( PduIdType RxPduId, const PduInfoType* PduInfoPtr ) {
    (void) RxPduId;
    (void) PduInfoPtr;
    
    CanIf_Can0_bRxFlag = TRUE;   //Message received.
}

//Can 2 controller.
/**
 * @brief Callback function for the complete transmit of a PDU (registered) from Can2 controller.
 * 
 * @param TxPduId ID (container) of the PDU transmitted.
 * @param result Status of the transmision operation.
 */
void CDD_UserTxConfirmation_Can_2( PduIdType TxPduId, Std_ReturnType result ) {
    //local data.
    static uint8 Transmit_count = 0;    //Count of transmitted PDUs.
    (void)TxPduId;

    if ( result == E_OK ) { //Message was transmitted successfully.
        Transmit_count++;
        CanIf_Can2_bTxFlag = TRUE;
    }

    /*if ( Transmit_count == 2 ) {    //All PDUs were transmitted successfully.
        CanIf_Can2_bTxFlag = TRUE;
        Transmit_count = 0;
    }*/
}

/**
 * @brief Callback function for the reception of a PDU (registered) of interest for the Can2 controller.
 * 
 * @param RxPduId ID (container) of the PDU received.
 * @param PduInfoPtr Pointer to PDU received (message)
 */
void CDD_UserRxIndication_Can_2( PduIdType RxPduId, const PduInfoType* PduInfoPtr ) {
    (void) RxPduId;
    (void) PduInfoPtr;
    
    CanIf_Can2_bRxFlag = TRUE;   //Message received.
}
