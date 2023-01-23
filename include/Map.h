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
     * @brief Get the value of a key.
     * 
     * @param key Key to get the value of.
     * @return String Value of the key.
     */
    String get(int key);
    /**
     * @brief Check if the map contains a key.
     * 
     * @param key Key to check.
     * @return true If the map contains the key.
     * @return false If the map does not contain the key.
     */
    bool contains(int key);
    /**
     * @brief Get the size of the map.
     * 
     * @return int Size of the map.
     */
    int get_size();

private:
    int size_;               /*< Size of the map. */
    String keys[MAP_SIZE];   /*< Array with keys used to locate values in the values array. */
    String values[MAP_SIZE]; /*< Array with values with help of the keys the values can be located. */
};