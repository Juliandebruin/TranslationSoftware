#pragma once

#include <Arduino.h>

/**
 * @brief Class creates a JSON string.
 */
class CreateJson
{
public:
    /**
     * @brief Construct a new CreateJson instance.
     */
	CreateJson();
    /**
     * @brief Destroy the CreateJson instance.
     */
	virtual ~CreateJson();

    /**
     * @brief Append a key and value to the JSON string.
     * 
     * @param key The key which is used to identify the value.
     * @param value The value which is associated with the key.
     */
    void append(String key, String value);

    /**
     * @brief Get the JSON string.
     * 
     * @return Returns the JSON string surrounded with {}.
     */
    String get_json_string();

private:
    String _json_string; // The JSON string where all keys and values are saved without the surrounding {}.
};