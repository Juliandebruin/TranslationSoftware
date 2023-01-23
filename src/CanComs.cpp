#include "CanComs.h"

#include <CAN.h>
#include <Arduino.h>

CanComs::CanComs() {
	CAN.begin(500E3);
}

CanComs::~CanComs() {

}

void CanComs::send_message(uint16_t id, String message) {
	CAN.beginPacket(id);
	for (int i = 0; i < message.length(); i++){
		CAN.write(message[i]);
		Serial.println(message[i]);
	}
	CAN.endPacket();
}

String CanComs::receive_message(int *id) {
	String message;

	int packetSize = CAN.parsePacket();

	*id = CAN.packetId();

	if (packetSize || CAN.packetId()) {
		if (!CAN.packetRtr()) {
			while (CAN.available())	{
				message += (char)CAN.read();
			}
		}
	}

	return message;
}