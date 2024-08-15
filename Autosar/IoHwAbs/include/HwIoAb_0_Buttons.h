/**
 * @file HwIoAb_0_Buttons.h
 * @brief This header contains the declaration of the control structures, functions and global data related to 
 * the IO hardware abstraction for the buttons on board.
 * 
 */

#ifndef HWIOAB_0_BUTTONS_H
#define HWIOAB_0_BUTTONS_H

//Headers
#include "StandardTypes.h"
#include "Det.h"
#include "Dio.h"

//General information.
#define HWIOAB_BUTTONS_MODULE_ID 301    ///< Module id.
#define HWIOAB_BUTTONS_INSTANCE_ID 0   ///< Instance id.

//Api ids.
#define HWIOAB_BUTTONS_INIT_ID 0x00 ///< HwIoAb_Buttons_Init() id.

#define HWIOAB_BUTTONS_GETEVENT_ID 0x01 ///< HwIoAb_Buttons_GetEvent() id.

#define HWIOAB_BUTTONS_MAINFUNCTION_ID 0x02 ///< HwIoAb_Buttons_MainFunction() id.

//Error ids.
#define HWIOAB_BUTTONS_E_CONFIG 0x00 ///<"Invalid config pointer" --> Buttons_Init

#define HWIOAB_BUTTONS_E_BUTTON_ID 0x01 ///<"Invalid button id" --> Buttons_GetEvent

#define HWIOAB_BUTTONS_E_STATE 0x02 ///<"Invalid button state" -->Buttons_MainFunction

#define HWIOAB_BUTTONS_E_UNINIT 0x03    ///< "Module uninitialized" --> All apis except init.

//Enums.
typedef enum {
    HWIOAB_BTN_STATE_IDLE,         ///< Not a press has happened yet.
    HWIOAB_BTN_STATE_SINGLE_PRESS, ///< Single press in button.
    HWIOAB_BTN_STATE_DOUBLE_PRESS, ///< Double press in button.
    HWIOAB_BTN_STATE_HOLD_PRESS,   ///< Hold press in button.
    HWIOAB_BTN_STATE_RELEASE       ///< Release in button.
} ButtonStates; //Button states.

typedef enum {
    HWIOAB_BTN_EVENT_IDLE,         ///< Not a click has happened yet.
    HWIOAB_BTN_EVENT_SINGLE_CLICK, ///< Single click.
    HWIOAB_BTN_EVENT_DOUBLE_CLICK, ///< Double click.
    HWIOAB_BTN_EVENT_HOLD_CLICK,   ///< Hold click.
    HWIOAB_BTN_EVENT_RELEASE,    ///< Release event.
    HWIOAB_BTN_EVENT_NULL = 50  ///< Null event.
} ButtonEvents; //Button events.

typedef enum {
    HWIOAB_BTN_ACTIVE_LOW,         ///< Button is active low.
    HWIOAB_BTN_ACTIVE_HIGH         ///< Button is active high.
} ButtonActive; //Button active status.

typedef enum { BTN_1, BTN_2, BTN_3 } buttons;

/**
 * @brief Configuration structure for each button.
 * 
 * @note Usually the instance of this struct is constant.
 * 
 */
typedef struct _HwIoAb_Buttons_Config
{
    Dio_ChannelType Button;     ///< Dio channel where the button is connected.
    uint8 Active;               ///< Button active status.
    uint32 Timeout;             ///< Timeout for the button press in ms.
} HwIoAb_Buttons_Config;

#include "HwIoAb_0_Buttons_Cfg.h"

/**
 * @brief Control/Config structure for the double click state machine for the buttons on board.
 * 
 * @note Usually the instance of this struct is variable.
 * 
 */
typedef struct _HwIoAb_Buttons_Ctrl
{
    uint8 Buttons;  ///< Number of buttons to handle.
    const HwIoAb_Buttons_Config *ButtonsConfig_Ptr; ///< Ptr to configuration array.
    uint8 States[ HWIOAB_BUTTONS_MAX ]; ///< Actual state of each button.
    uint8 Events[ HWIOAB_BUTTONS_MAX ]; ///< Actual event of each button.
    boolean Buttons_init;   ///< Boolean flag that indicates if the control structure was initialized.
} HwIoAb_Buttons_Ctrl;


//Reference to global data.
extern const HwIoAb_Buttons_Config ButtonsCfg[ HWIOAB_BUTTONS_MAX ];   //Configuration array.
extern HwIoAb_Buttons_Ctrl ButtonsCtrl; //Control structure instance.
extern HwIoAb_Buttons_Ctrl *ButtonsControl_Ptr;  //Pointer to control structure instance. 

//Functions.
void HwIoAb_Buttons_Init( const HwIoAb_Buttons_Config *Buttons_Config );
uint8 HwIoAb_Buttons_GetEvent( uint8 Button );
void HwIoAb_Buttons_MainFunction( void );

#endif