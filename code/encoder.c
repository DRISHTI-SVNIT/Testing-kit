#include <avr/io.h>
#include "encoder.h"



void  interruptInit ()
{
	EICRA |= (1<<ISC10)|(1<<ISC11);
	EIMSK = (1<<INT1);
}
/*void countFunc(int count1,int count2){
	if(bit_is_clear(PINE,5)){
		count1++;
	}else{
		count2++;
	}
}*/
