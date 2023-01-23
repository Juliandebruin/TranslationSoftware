#pragma once

#include <Arduino.h>

/**
 * @brief Class to send and recieve CAN messages over the CAN bus.
 */
class CanComs
{
public:
	/**
	 * @brief Construct a new CanComs instance.
	 */
	CanComs();
	/**
	 * @brief Destroy the CanComs instance.
	 */
	virtual ~CanComs();

	/**
	 * @brief Send a message to the CAN bus.
	 * 
	 * @param id Id used to as address by can bus.
	 * @param message Message to send.
	 */
	void send_message(uint16_t id, String message);

	/**
	 * @brief Recieve a message from the CAN bus.
	 * 
	 * @return std::pair<long, std::string> Id and Message which is recieved.
	 */
	String receive_message(int *id);
};