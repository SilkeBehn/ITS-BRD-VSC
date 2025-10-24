#include "input.h"

TPhase getPhase(){
	 int in = GPIOF->IDR & 0x3;
	 TPhase phase = 0;
	 switch (in) {
		 case 0: phase = PHASEA; break;
		 case 2: phase = PHASEB; break;
		 case 3: phase = PHASEC; break;
		 case 1: phase = PHASED; break;
   }		 
	 return phase;
}

int getReset(){
	 int in = GPIOF->IDR & 0x80;
	 if ( in == 0 ){
		 return 1;
	 } else {
		 return 0;
	 }
}

int getTimer(){
	return TIM2->CNT;
}