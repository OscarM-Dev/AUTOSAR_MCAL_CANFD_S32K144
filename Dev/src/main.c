/**
 * @file main.c
 * @brief This file contains the main function of the project
 * 
 * This file executes the double click state machine using the scheduler.
*/

//Header.
#include "Mcu_init.h"
#include "Scheduler.h"

//Global data.
QueueMessage Queue1[ SCHEDULER_QUEUE1_ELEMENTS ];
boolean CanIf_Can2_bTxFlag;   ///< Flag for transmision of PDU of FlexCan2 controller.
boolean CanIf_Can2_bRxFlag;   ///< Flag for reception of PDU of FlexCan2 controller.

/**
 * @brief This is the main function of the project
 * 
 * This example transmits 2 8 byte data PDUs every 5s using CAN 2 at a bitrate of 100Kbps.
 * In this case only one HTH is used with two message buffers.
 * 
 * @return Always zero
*/
int main( void ) {
    //local data.
    //Transmit message (PDU) 0 (Message ID 0x123) for Can 2 controller.
    uint8 Message0_SDU[8] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 }; //Data payload for message.
    PduInfoType Message0 = {
        .SduLength = 8,
        .SduDataPtr = Message0_SDU,
        .MetaDataPtr = NULL_PTR
    };

    //Transmit message (PDU) 1 (Message ID 0x124) for Can 2 controller.
    uint8 Message1_SDU[8] = { 0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70 }; //Data payload for message.
    PduInfoType Message1 = {
        .SduLength = 8,
        .SduDataPtr = Message1_SDU,
        .MetaDataPtr = NULL_PTR
    };

    EcuM_Init();    //MCU configuration.
    CanIf_SetControllerMode( CanIfFlexCan2 , CAN_CS_STARTED );   //Can 2 controller active in Can Bus.

    while( 1u ) {
        //Transmit messages every 5s.
        CanIf_Transmit( CanIfTxPDU_0, &Message0 );   //Writing in Can 2 message buffer 0.
        CanIf_Transmit( CanIfTxPDU_1, &Message1 );  //Writing in Can 2 message buffer 1.

        while( CanIf_Can2_bTxFlag == FALSE ); //Waiting until messages are transmitted.
        CanIf_Can2_bTxFlag = FALSE;  //Clearing transmit flag.

        //Changing SDUs.
        Message0_SDU[0]++;
        Message0_SDU[7]++;
        Message1_SDU[0]++;
        Message1_SDU[7]++;

        Delay( 5000 );  //Waiting 5s for next transmission.
    }

    return 0u;
}

