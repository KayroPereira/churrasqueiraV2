#include "churrasqueira.h"

void setup(){
	inicializaVariaveisHardware();
	inicializaHardware();
}

void loop(){
	if(bufferSerialLength() > 0){
		controllerSerial();
	}
}
