#include "hardwareGlobal.h"

//IN_OUT

void configPin(uint8_t pin, uint8_t mode){
	pinMode(pin, mode);
}

void changePin(uint8_t pin, uint8_t status){
	digitalWrite(pin, status);
}

int readPin(uint8_t pin){
	return digitalRead(pin);
}


//Serial

void configSerial(unsigned long baud){
	Serial.begin(baud);
}

int bufferSerialLength(){
	return Serial.available();
}

long getIntSerial(){
	return Serial.parseInt();
}

void print(const String &s){
	Serial.print(s);
}

void println(const String &s){
	Serial.println(s);
}

void println(int value){
	Serial.println(value);
}

String readString(){
	return Serial.readString();
}


//Timer1

void setSpeedTimer1(uint32_t ticks){
	timer1_write(ticks);
}

void callBackTimer1(timercallback userFunc){
	timer1_attachInterrupt(userFunc);
}

void configTimer1(uint8_t divider, uint8_t int_type, uint8_t reload){
	timer1_enable(divider, int_type, reload);
}

void removeCallbackTimer1(){
	timer1_detachInterrupt();
}
