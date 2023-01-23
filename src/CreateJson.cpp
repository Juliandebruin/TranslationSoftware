#include "CreateJson.h"

CreateJson::CreateJson() : 
    _json_string("") 
{

}

CreateJson::~CreateJson() {

}

void CreateJson::append(String key, String value) {
    String jsonString = "\"" + key + "\":\"" + value + "\",";
    _json_string += json_string;
}

String CreateJson::get_json_string() {
    return "{" + _json_string + "}";
}