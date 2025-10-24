#ifndef INPUT_H
#define INPUT_H

#include "stm32f4xx_hal.h"

typedef enum {PHASEA, PHASEB, PHASEC, PHASED, INIT, FEHLER} TPhase;

TPhase getPhase();
int getReset();
int getTimer();



#endif