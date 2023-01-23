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

String Map::get(String key) {
    for (int i = 0; i < MAP_SIZE; i++) {
        if (key == _keys[i]) {
            return _values[i];
        }
    }

    return "";
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