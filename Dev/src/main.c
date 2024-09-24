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
 * Test, communication Canable with FlexCAN0 in both directions.
 * This example transmits a 3 byte data PDU every 5s using CAN 0 at a bitrate of 100Kbps. It also receives
 * a 3 byte data PDU from CANABLE every determined time.
 * 
 * In this case only one HTH is used for transmission with one message buffer. For reception only one HRH is utilized.
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

    EcuM_Init();    //MCU configuration.

    //SBC by default is in force normal mode so the CAN transceiver is already active.

    CanIf_SetControllerMode( CanIfFlexCan0 , CAN_CS_STARTED );   //Can 0 controller active in Can Bus.

    while( 1u ) {
        //Transmit messages every 5s.
        CanIf_Transmit( CanIfTxPDU_0, &Message0 );   //Writing in Can 0 message buffer 1.

        while( CanIf_Can0_bTxFlag == FALSE ); //Waiting until messages are transmitted.
        CanIf_Can0_bTxFlag = FALSE;  //Clearing transmit flag.

        Delay( 5000 );  //Waiting 5s for next transmission.
    }

    return 0u;
}

