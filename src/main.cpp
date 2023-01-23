#include <Arduino.h>

#include "Map.h"

#include "CanComs.h"
#include "UartComs.h"
#include "CreateJson.h"

#define TIMEOUT 500

#define RECEIVE_KEY_ADDRESS   0x30
#define RECEIVE_VALUE_ADDRESS 0x40

Map data;

CanComs canComs;
UartComs uartComs;

void setup() {
	Serial.begin(9600);
}

void waitForData(String key) {
	int startTime = millis();
	bool dataReceived = false;

	while (dataReceived) {
		int id = 0;
		int enlapsedDime = (millis() - startTime);
		String value = canComs.receive_message(&id);

		if (id == RECEIVE_VALUE_ADDRESS) {
			if (data.contains(key)) {
				data.update(key, value);
			} else {
				data.add(key, value);				
			}
		} else if (enlapsedDime > TIMEOUT) {
			Serial.println("No data received after recieving a key!");
			break;
		}
	}
}

String createJsonOfMap() {
	CreateJson createJson;
	
	for (int i = 0; i < data.get_size(); i++) {
		String key = data.get_key(i);
		String value = data.get(key);
		createJson.append(key, value);
	}

	return createJson.get_json_string();
}

void loop() {
	int id = 0;
	String key = canComs.receive_message(&id);

	if (id == RECEIVE_KEY_ADDRESS) {
		waitForData(key);
		String json = createJsonOfMap();
		uartComs.send_message(json);
	}
}
