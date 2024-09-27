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
boolean CanIf_Can0_bTxFlag;   ///< Flag for transmision of PDU of FlexCan0 controller.
boolean CanIf_Can0_bRxFlag;   ///< Flag for reception of PDU of FlexCan0 controller.
boolean CanIf_Can2_bTxFlag;   ///< Flag for transmision of PDU of FlexCan2 controller.
boolean CanIf_Can2_bRxFlag;   ///< Flag for reception of PDU of FlexCan2 controller.

/**
 * @brief This is the main function of the project
 * 
 * Test, communication FLEXCAN0 to CANABLE with CANFD using nominal bit rate of 1Mbps and data bit rate of 2Mbps.
 * 
 * -Transmission of 4 messages every 3s.
 *      -3 data byte PDU. -->0x100
 *      -8 data byte PDU. -->0x101
 *      -12 data byte PDU.  -->0x102
 *      -9 data byte PDU. -->0x103
 * 
 * In this case only one HTH is used for transmission with four message buffer. For reception only one HRH is utilized.
 * 
 * 
 * @return Always zero
*/
int main( void ) {
    //local data.
    //Transmit message (PDU) 0 (Message ID 0x100) for Can 0 controller.
    uint8 Message0_SDU[3] = { 0xDE, 0xF4, 0xC9 }; //Data payload for message.
    PduInfoType Message0 = {
        .SduLength = 3,
        .SduDataPtr = Message0_SDU,
        .MetaDataPtr = NULL_PTR
    };

    //Transmit message (PDU) 1 (Message ID 0x101) for Can 0 controller.
    uint8 Message1_SDU[8] = { 0xAA, 0xDE, 0xF4, 0xC5, 0xB6, 0xFE, 0xCC, 0x07 }; //Data payload for message.
    PduInfoType Message1 = {
        .SduLength = 8,
        .SduDataPtr = Message1_SDU,
        .MetaDataPtr = NULL_PTR
    };

    //Transmit message (PDU) 2 (Message ID 0x102) for Can 0 controller.
    uint8 Message2_SDU[12] = { 0xBB, 0xDE, 0xCC, 0xAA, 0x22, 0x33, 0xDD, 0x05, 0x09, 0x45, 0xFF, 0x33 }; //Data payload for message.
    PduInfoType Message2 = {
        .SduLength = 12,
        .SduDataPtr = Message2_SDU,
        .MetaDataPtr = NULL_PTR
    };

    //Transmit message (PDU) 3 (Message ID 0x103) for Can 0 controller.
    uint8 Message3_SDU[9] = { 0xFF, 0xDD, 0x22, 0x44, 0x53, 0x11, 0x46, 0x59, 0xBB }; //Data payload for message.
    PduInfoType Message3 = {
        .SduLength = 9,
        .SduDataPtr = Message3_SDU,
        .MetaDataPtr = NULL_PTR
    };

    EcuM_Init();    //MCU configuration.

    //SBC by default is in force normal mode so the CAN transceiver is already active.

    CanIf_SetControllerMode( CanIfFlexCan0 , CAN_CS_STARTED );   //Can 0 controller active in Can Bus.

    while( 1u ) {
        //Transmit messages every 3s.
        CanIf_Transmit( CanIfTxPDU_0, &Message0 );   //Writing in Can 0 message buffer 1
        CanIf_Transmit( CanIfTxPDU_1, &Message1 );   //Writing in Can 0 message buffer 2
        CanIf_Transmit( CanIfTxPDU_2, &Message2 );   //Writing in Can 0 message buffer 3
        CanIf_Transmit( CanIfTxPDU_3, &Message3 );   //Writing in Can 0 message buffer 4

        while( CanIf_Can0_bTxFlag == FALSE ); //Waiting until messages are transmitted.
        CanIf_Can0_bTxFlag = FALSE;  //Clearing transmit flag.

        Delay( 3000 );  //Waiting 3s for next transmission.
    }

    return 0u;
}

