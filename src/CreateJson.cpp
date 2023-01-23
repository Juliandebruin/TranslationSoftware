#include "CreateJson.h"

CreateJson::CreateJson() : 
    _json_string("") 
{

}

CreateJson::~CreateJson() {

}

void CreateJson::append(String key, String value) {
    _json_string += "\"" + key + "\":\"" + value + "\", ";
}

String CreateJson::get_json_string() {
    int lastIndex = _json_string.length() - 1;
	_json_string.remove(lastIndex);
    _json_string.remove(lastIndex - 1);
    return "{" + _json_string + "}\n";
}