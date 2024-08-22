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
 * This example transmits 2 8 byte data PDUs every 5s using CAN 2 at a bitrate of 100Kbps.
 * In this case only one HTH is used with two message buffers.
 * 
 * @return Always zero
*/
int main( void ) {
    //local data.
    //Transmision and reception buffers for Spi1Cs3 channels.
    uint8 Control = 0;  //Transmit buffer for control channel.
    uint8 RxDataBuffer = 50; //Receive buffer for data channel.

    //Transmit message (PDU) 2 (Message ID 0x100) for Can 0 controller.
    uint8 Message2_SDU = 0x01; //Data payload for message.
    PduInfoType Message2 = {
        .SduLength = 1,
        .SduDataPtr = &Message2_SDU,
        .MetaDataPtr = NULL_PTR
    };

    EcuM_Init();    //MCU configuration.
    CanIf_SetControllerMode( CanIfFlexCan0 , CAN_CS_STARTED );   //Can 0 controller active in Can Bus.
    
    
    //Sending a single register read instruction to SBC.
    //Defining control channel.
    Control = 0x74; //Register ID.
    Control <<= 1;
    Control += 1;
    
    //Setup of external buffers.
    Spi_SetupEB( SpiConf_SpiChannel_Spi1Cs3_Control, &Control, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_Spi1Cs3_Data, NULL , &RxDataBuffer , 1 );

    Spi_SyncTransmit( SpiConf_SpiSequence_Spi1Cs3_Sequence_W_R );   //Transmiting instruction.
    

    while( 1u ) {
        //Transmit messages every 5s.
        CanIf_Transmit( CanIfTxPDU_2, &Message2 );   //Writing in Can 0 message buffer 1.

        while( CanIf_Can0_bTxFlag == FALSE ); //Waiting until messages are transmitted.
        CanIf_Can0_bTxFlag = FALSE;  //Clearing transmit flag.

        //Changing SDUs.
        Message2_SDU++;

        Delay( 5000 );  //Waiting 5s for next transmission.
    }

    return 0u;
}

