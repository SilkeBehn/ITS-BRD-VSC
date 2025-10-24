
#include "fsm.h"

int state = INIT;
TDirection direction = NONE;
int count = 0;

TDirection fsm(TPhase aktPhase){

		switch ( state ){
			case PHASEA: 
					 switch (aktPhase) {
						 case PHASEA: direction = NONE; break;
						 case PHASEB: direction = FOR; count++;  break;
						 case PHASEC: direction = ERR; break;
						 case PHASED: direction = BACK; count--; break;
						 case INIT:  direction = NONE; break;
						 default: break;
					 } 
					 break;
			case PHASEB: 
					 switch (aktPhase) {
						 case PHASEA: direction = BACK; count--;break;
						 case PHASEB: direction = NONE; break;
						 case PHASEC: direction = FOR; count++; break;
						 case PHASED: direction = ERR; break;
						 case INIT:  direction = NONE; break;
						 default: break;
					 } 
					 break;
			case PHASEC: 
					 switch (aktPhase) {
						 case PHASEA: direction = ERR; break;
						 case PHASEB: direction = BACK; count--; break;
						 case PHASEC: direction = NONE; break;
						 case PHASED: direction = FOR; count++; break;
						 case INIT:  direction = NONE; break;
						 default: break;
					 } 
					 break;
			case PHASED: 
					 switch (aktPhase) {
						 case PHASEA: direction = FOR; count++;break;
						 case PHASEB: direction = ERR; break;
						 case PHASEC: direction = BACK; count--; break;
						 case PHASED: direction = NONE; break;
						 case INIT:  direction = NONE; break;
						 default: break;
					 } 
					 break;
			case INIT: 
					 switch (aktPhase) {
						 case PHASEA: direction = NONE; break;
						 case PHASEB: direction = NONE; break;
						 case PHASEC: direction = NONE; break;
						 case PHASED: direction = NONE; break;
						 case INIT:  direction = NONE; break;
						 default: break;
					 } 
					 break;
			case FEHLER: 
					 switch (aktPhase) {
						 case PHASEA: direction = NONE; break;
						 case PHASEB: direction = NONE; break;
						 case PHASEC: direction = NONE; break;
						 case PHASED: direction = NONE; break;
						 case INIT:  direction = NONE; break;
						 default: break;
					 } 
					 break;		 
		}
		if (direction == ERR){
			state = FEHLER;
		} else {	
		  state = aktPhase;
		}
    return direction;		
}

int getCount(){
	return count;
}

void resetCount(){
	count = 0;
}

int getState(){
	 return state;
}

