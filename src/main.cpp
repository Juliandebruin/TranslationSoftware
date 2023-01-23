#include <Arduino.h>

#include "Map.h"

#include "CanComs.h"
#include "UartComs.h"
#include "CreateJson.h"

#define RECEIVE_KEY_ADDRESS   0x30
#define RECEIVE_VALUE_ADDRESS 0x40

Map data;

CanComs canComs;
UartComs uartComs;

void setup() {
	Serial.begin(9600);
}

void loop() {
	Serial.println("Loop");
}
