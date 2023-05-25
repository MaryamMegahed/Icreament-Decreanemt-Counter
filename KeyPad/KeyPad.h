/*
 * main.c
 *
 *      Created on: May 6, 2023
 *      Author:Maryam Megahed
 *      BN:32
 */
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Gpio.h"
#include "Std_Types.h"
//__________________config columns______________________________
#define COL_PORT GPIO_B
#define COL_START_INDEX 0
#define COL_END_INDEX 2
//__________________config Rows_________________________________
#define ROW_PORT GPIO_B
#define ROW_START_INDEX 7
#define ROW_END_INDEX 10
//__________________button state________________________________
#define BUTTON_PRESSED 0
#define BUTTON_RELEASED 1

//provided api functions
void Keypad_Init(void);
void Keypad_Manage(void);
uint8 Keypad_Getkey(void);

//required function implemented by application
void KeypadCallout_KeyPressNotification();

#endif
