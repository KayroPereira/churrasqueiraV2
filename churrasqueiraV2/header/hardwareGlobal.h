#include "Arduino.h"
#include "ESP8266WiFi.h"

#ifndef HEADER_HARDWAREGLOBAL_H_
#define HEADER_HARDWAREGLOBAL_H_

//Declaração assinatura das funções
void configPin(uint8_t pin, uint8_t mode);
void changePin(uint8_t pin, uint8_t status);
int readPin(uint8_t pin);
void configSerial(unsigned long baud);
int bufferSerialLength();
long getIntSerial();
void print(const String &s);
void println(const String &s);
void println(int value);
String readString();
void callBackTimer1(timercallback userFunc);
void configTimer1(uint8_t divider, uint8_t int_type, uint8_t reload);
void removeCallbackTimer1();
void setSpeedTimer1(uint32_t ticks);


#endif /* HEADER_HARDWAREGLOBAL_H_ */
