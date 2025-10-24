/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

//#include "additionalFonts.h"

#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "init.h"
#include "timer.h"
#include "delay.h"
#include "LCD_GUI.h"
#include "LCD_Demos.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "LCD_Touch.h"
#include "error.h"
#include "input.h"
#include "fsm.h"
#include "output.h"
#include "calculate.h"


int main(void) {
	
    initITSboard();                 // Initialisierung des ITS Boards
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch
	if (!checkVersionFlashFonts()) {
	    // Ueberpruefe Version der Fonts im Flash passt nicht zur Software Version
		Error_Handler();
	}
	
	TPhase phase; 
	TPhase oldPhase=INIT;
	int reset=0;
	initTimer();
	printInit();
	
	int oldWinkel=0;
	int winkel;
	int ausgabe=0;
	
	double geschw=0;
	
	unsigned int takt = 0;
	unsigned int told = getTimer();
	unsigned int timerDiff = 0;
	
	TDirection direction;
	
	int test=0;
	while(1){
		//Eingabe
		phase = getPhase();
		reset = getReset();
		takt  = getTimer(); //Zeit in us
		
		//Verarbeitung
		if( reset ) {
			resetCount();
			phase = INIT;
		}	
		
		if ( getState() != FEHLER || (getState() == FEHLER && phase == INIT) ){
			direction = fsm(phase);
			
			timerDiff = (takt - told)/90000;  //Zeit in ms
			if ( (timerDiff > 250 && oldPhase != phase) || timerDiff > 1000){
				 winkel = getWinkel( getCount() );
				 geschw = getGeschwindigkeit( timerDiff, winkel - oldWinkel );
				 oldWinkel = winkel;
				 told = takt;
				 ausgabe = 1;
				
				 GPIOD->ODR = test&0xFF;
				 test++;
				
			}
		}

		
		//Ausgabe
		if( ausgabe==1 ){
		   printWinkel( winkel );
			 printGeschwindigkeit(geschw);
			 ausgabe = 0;
		}
		setRichtung(direction);
		
		if(getState() == FEHLER ){
       setError();
		} else {	
       clearError();
		}
    
		setLEDCount(getCount());
		
		oldPhase = phase;
	}
		
	



}

// EOF
