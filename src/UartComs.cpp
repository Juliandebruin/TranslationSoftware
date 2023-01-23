#include "UartComs.h"

#define TX_PIN 6
#define RX_PIN 7

#define BAUD_RATE 115200

UartComs::UartComs() : 
    _uart(SoftwareSerial(RX_PIN, TX_PIN)) 
{
    _uart.begin(BAUD_RATE);
}

UartComs::~UartComs() {

}

void UartComs::send_message(String message) {
    _uart.print(message.c_str());
}