#include "accessHardware.h"

int speedMotor;
bool inputData;

void inicializaVariaveisHardware(){
	speedMotor = 10;
	inputData = false;
}

void inicializaHardware(){

	//Define pinagem
	configPin(GPIO_ID_PIN(OUTPUT_MOTOR), OUTPUT);
	configPin(GPIO_ID_PIN(OUTPUT_DIRECTION), OUTPUT);
	configPin(GPIO_ID_PIN(OUTPUT_ENABLE), OUTPUT);
	configPin(LED_BUILTIN, OUTPUT);

	//Configuração Serial
	configSerial(9600);

	//Configurações timer
	callBackTimer1(timerInterrupt);
	configTimer1(TIM_DIV256, TIM_EDGE, TIM_LOOP);

	//Inicialização padrão hardware
	changePin(OUTPUT_DIRECTION, LOW);
	changePin(OUTPUT_ENABLE, HIGH);
}

void setSpeedTimer(){
	setSpeedTimer1((speedMotor * BASE_TIME) / DIVISOR_TIMER); // 1 segundo (80 MHz / 256)
}

void timerInterrupt(){
	changePin(OUTPUT_MOTOR, !readPin(OUTPUT_MOTOR));
	changePin(LED_BUILTIN, !readPin(LED_BUILTIN));
}
