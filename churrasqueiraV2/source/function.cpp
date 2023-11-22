#include "function.h"

//Comandos Serial
const String SET_VALUE = "s";
const String CLEAR_VALUE = "c";
const String DISABLE_PULSE = "d";
const String ENABLE_PULSE = "a";
const String ENABLE_MOTOR = "em";
const String DISABLE_MOTOR = "dm";
const String FRONT_DIRECTION = "f";
const String END_DIRECTION = "e";

void controllerSerial(){

	if(inputData){

		speedMotor = getIntSerial();

		print("speedMotor: ");
		println(speedMotor);

		inputData = false;
		setSpeedTimer();
	}else{
		String comandosSerial = readString();
		println(comandosSerial);

		if(comandosSerial == SET_VALUE){
			inputData = true;
		}
		if(comandosSerial == CLEAR_VALUE){
			inputData = false;
		}
		if(comandosSerial == DISABLE_PULSE){
			removeCallbackTimer1();
			changePin(OUTPUT_MOTOR, HIGH);
			changePin(LED_BUILTIN, HIGH);
			disableMotor();
		}
		if(comandosSerial == ENABLE_PULSE){
			callBackTimer1(timerInterrupt);
			setSpeedTimer();
			enableMotor();
		}
		if(comandosSerial == ENABLE_MOTOR){
			enableMotor();
		}
		if(comandosSerial == DISABLE_MOTOR){
			disableMotor();
		}
		if(comandosSerial == FRONT_DIRECTION){
			changePin(OUTPUT_DIRECTION, LOW);
		}
		if(comandosSerial == END_DIRECTION){
			changePin(OUTPUT_DIRECTION, HIGH);
		}
	}
}

void enableMotor(){
	changePin(OUTPUT_ENABLE, LOW);
}

void disableMotor(){
	changePin(OUTPUT_ENABLE, HIGH);
}

