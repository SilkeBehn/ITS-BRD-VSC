

int getWinkel( int count ){
	 
	  //360Grad == 1200 count
	  // x Grad == count
	int grad = count * 360 / 12;
	return grad;
	
}

double getGeschwindigkeit(int deltaTime, int deltaWinkel){
	
	 return ((double)deltaWinkel)*10 / deltaTime;
}