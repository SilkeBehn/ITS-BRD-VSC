/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "additionalFonts.h"
#include "error.h"
#include "adc.h"
#include "delay.h"
#include <stdio.h>


int main(void) {
	int value = 0;
	double volt = 0;
	char txt[30];

	initITSboard();    // Initialisierung des ITS Boards
	
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch

  // Begruessungstext	
	lcdPrintlnS("ISSP Aufgabe1");
	
    initADC(3);
	ADC_RegChannelConfig(3,7);

    while(1){
        value = readADCValue(3);
		volt = 3.3 * value / 8096;
		sprintf(txt, "%.2lf Volt", volt);
		lcdGotoXY(5, 3);
		lcdPrintS(txt);
		delay(1000);
	}



	// Test in Endlosschleife
	while(1) {
		HAL_Delay(10000);
	}
}

// EOF
