#include "Map.h"

Map::Map() :
    _size(0),
    _keys({}),
    _values({})
{

}

Map::~Map() 
{

}

void Map::add(String key, String value) {
    if (_size < MAP_SIZE) {
        _keys[_size] = key;
        _values[_size] = value;
        _size++;
    }
}

void Map::update(String key, String value) {
    for (int i = 0; i < MAP_SIZE; i++) {
        if (key == _keys[i]) {
            _values[i] = value;
        }
    }
}

String Map::get(String key) {
    for (int i = 0; i < MAP_SIZE; i++) {
        if (key == _keys[i]) {
            return _values[i];
        }
    }

    return "";
}

String Map::get_key(int index) {
    if (index < MAP_SIZE) {
        return _keys[index];
    } else {
        return "";
    }
}

bool Map::contains(String key) {
   for (int i = 0; i < MAP_SIZE; i++) {
        if (key == _keys[i]) {
            return true;
        }
    }

    return false;
}

int Map::get_size() {
    return _size;
}