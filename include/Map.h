#pragma once

#include <Arduino.h>

#define MAP_SIZE 30

/**
 * @brief This class is a simple map implementation with a fixed size.
 */
class Map 
{
public:
    /**
     * @brief Construct a new Map instance.
     */
    Map();
    /**
     * @brief Destroy the Map instance.
     */
    virtual ~Map();

    /**
     * @brief Add a key value pair to the map.
     * 
     * @param key Key to add.
     * @param value Value to add.
     */
    void add(String key, String value);
    /**
     * @brief Update the value of a key.
     * 
     * @param key Key to update.
     * @param value New value of the key.
     */
    void update(String key, String value);
    /**
     * @brief Get the value of a key by using the key.
     * 
     * @param key Key to get the value of.
     * @return String Value of the key.
     */
    String get(String key);
     /**
     * @brief Get a key by using the index.
     * 
     * @param index Index to get the key.
     * @return String Key name.
     */
    String get_key(int index);
    /**
     * @brief Check if the map contains a key.
     * 
     * @param key Key to check.
     * @return true If the map contains the key.
     * @return false If the map does not contain the key.
     */
    bool contains(String key);
    /**
     * @brief Get the size of the map.
     * 
     * @return int Size of the map.
     */
    int get_size();

private:
    int    _size;             /*< Size of the map. */
    String _keys[MAP_SIZE];   /*< Array with keys used to locate values in the values array. */
    String _values[MAP_SIZE]; /*< Array with values with help of the keys the values can be located. */
};