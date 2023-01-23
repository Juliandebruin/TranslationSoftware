#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>

/**
 * @brief Class to send UART messages.
 */
class UartComs
{
public:
	/**
	 * @brief Construct a new UartComs instance.
	 */
	UartComs();
	/**
	 * @brief Destroy the UartComs instance.
	 */
	virtual ~UartComs();

	/**
	 * @brief Send a message over UART.
	 * 
	 * @param message Message to send.
	 */
	void send_message(String message);

private:
    SoftwareSerial _uart; /*< UART Instance used for communcation */
};