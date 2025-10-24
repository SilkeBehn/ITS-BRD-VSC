#include "output.h"

char winkel[15];
char oldWinkel[15];

char gesch[15];
char oldGesch[15];

void printInit(){
	 lcdGotoXY(10, 10);
	 lcdPrintS( "Winkel:  ");
	 lcdGotoXY(10, 15);
	 lcdPrintS( "Geschw:  ");
	 
	 
}

void printWinkel(int winkelInt){
	 int index = 0;
	 int nachkomma = winkelInt % 100;
	 if ( nachkomma < 0 ){
		  nachkomma = nachkomma * (-1);
	 }
	 
	 sprintf(winkel, "%d.%02d     " , winkelInt/100 , nachkomma );
	 while( winkel[index] != '\0' ){ 
		   if ( winkel[index] != oldWinkel[index] ){
	        lcdGotoXY(index+17, 10);
	        lcdPrintC( winkel[index] );
				  oldWinkel[index] = winkel[index];
			 }
			 index++;
		}    
	 
}
	 
void printGeschwindigkeit(double geschDouble){
	 int index = 0;
	 
	 sprintf(gesch, "%.2lf     " , geschDouble );
	 while( gesch[index] != '\0' ){ 
		   if ( gesch[index] != oldGesch[index] ){
	        lcdGotoXY(index+17, 15);
	        lcdPrintC( gesch[index] );
				  oldGesch[index] = gesch[index];
			 }
			 index++;
		}    
	 
}

void setRichtung(TDirection direction){
	 if( direction == FOR ){
		  GPIOE->BSRR = 0xC0 << 16;
		  GPIOE->BSRR = 0x80;
	 } else if (direction == BACK){
		  GPIOE->BSRR = 0xC0 << 16;
		  GPIOE->BSRR = 0x40;
	 }
}

void setError(){
	GPIOE->BSRR = 0x20;
}

void clearError(){
	GPIOE->BSRR = 0x20 << 16;
}

void setLEDCount(int count){
	GPIOD->ODR = count & 0xFF;
}
	
	