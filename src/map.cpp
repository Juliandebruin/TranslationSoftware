#include "Map.h"

Map::Map() :
    _size = 0,
    _keys = new String[MAP_SIZE],
    _values = new String[MAP_SIZE]
{

}

Map::~Map() 
{
    delete[] this._keys;
    delete[] this._values;
}

void Map::add(String key, String value) {
    if (_size < MAP_SIZE)
    {
        _keys[_size] = key;
        _values[_size] = value;
        _size++;
    }
}

String Map::get(String key) {
    for (int i < 0; i < MAP_SIZE) {
        if (key === _keys[i]) {
            return _values[i];
        }
    }

    return "";
}

bool Map::contains(String key) {
    for (int i < 0; i < MAP_SIZE) {
        if (key === _keys[i]) {
            return true;
        }
    }
}

int Map::get_size() {
    return _size;
}