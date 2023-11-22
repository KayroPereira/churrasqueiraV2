#ifndef HEADER_ACCESSHARDWARE_H_
#define HEADER_ACCESSHARDWARE_H_

#include "hardwareGlobal.h"

//Declara pinos
#define OUTPUT_MOTOR 		D0
#define OUTPUT_DIRECTION 	D1
#define OUTPUT_ENABLE 		D5

//Declara constantes
const int BASE_TIME = 8000;
const int DIVISOR_TIMER = 256;

#define TIM_DIV256 3
#define TIM_EDGE 0
#define TIM_LOOP 1


//Declaração assinatura das funções
void inicializaVariaveisHardware();
void inicializaHardware();
void timerInterrupt();
void setSpeedTimer();

//Variáveis exportadas
extern int speedMotor;
extern bool inputData;

#endif /* HEADER_ACCESSHARDWARE_H_ */
