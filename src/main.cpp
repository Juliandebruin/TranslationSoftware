#include <Arduino.h>
#include <SoftwareSerial.h>

#include "CanComs.h"

#define TX_PIN 6
#define RX_PIN 7

CanComs coms;
SoftwareSerial UART(RX_PIN, TX_PIN);

int global_rpm     = 4000;
int global_speed   =   40;
int global_battery =   50;

void print(String str) {
	UART.print(str);
	Serial.print(str);
}

void send_dashboard_data(int rpm, int speed, int battery, String pin, String pout) {
	Serial.print("Sending data...\n");

	print("{");
	String rpmStr = "\"rpm\":\"" + String(rpm, DEC) + "\",";
	print(rpmStr);
	String speedStr = "\"speed\":\"" + String(speed, DEC) + "\",";
	print(speedStr);
	String batteryStr = "\"battery\":\"" + String(battery, DEC) + "\",";
	print(batteryStr);
	String pinStr = "\"pin\":\"" + pin + "\",";
	print(pinStr);
	String poutStr = "\"pout\":\"" + pout + "\"";
	print(poutStr);
	print("}\n");
}

void setup() {
	UART.begin(9600);
	Serial.begin(9600);
}

int id = 0x00;

String Pin  = "0";
String Pout = "0";

void loop() {
	String msg = coms.receive_message(&id);

	if (id == 0x21) {
		Pin = msg;
	} else if (id == 0x22) {
		Pout = msg;
	}

	send_dashboard_data(3500, 35, 85, Pin, Pout);
}
