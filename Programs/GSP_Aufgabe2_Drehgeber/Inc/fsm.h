#ifndef FSM_H
#define FSM_H

#include "input.h"

typedef enum {FOR, BACK, NONE, ERR} TDirection;

TDirection fsm(TPhase aktPhase);
int getCount();
void resetCount();
int getState();
	
#endif
