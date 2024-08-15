/**
 * @file HwIoAb_2_Pots_Cfg.c
 * @brief This file contains the declaration and definition of the instances of the control and config
 * structures related to the IO hardware abstraction for the Pots on board.
 * 
 */

//Headers
#include "HwIoAb_2_Pots.h"

//Global data.
HwIoAb_Pots_Ctrl PotsCtrl;  //Control structure instance.
HwIoAb_Pots_Ctrl *PotsControl_Ptr = &PotsCtrl;  //Pointer to control structure instance.