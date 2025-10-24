#ifndef OUTPUT_H
#define OUTPUT_H

#include "lcd.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "fsm.h"

void printInit();
void printWinkel(int winkel);
void printGeschwindigkeit(double geschDouble);
void setRichtung(TDirection direction);
void setError();
void clearError();
void setLEDCount(int count);


#endif
