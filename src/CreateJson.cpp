#include "CreateJson.h"

CreateJson::CreateJson() : 
    _json_string("") 
{

}

CreateJson::~CreateJson() {

}

void CreateJson::append(String key, String value) {
    _json_string += "\"" + key + "\":\"" + value + "\",";
}

String CreateJson::get_json_string() {
    return "{" + _json_string + "}";
}