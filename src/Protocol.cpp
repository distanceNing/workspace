//
// Created by yangning on 18-1-11.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#include "headers/Protocol.h"
#include "rapidjson/prettywriter.h" // for stringify JSON


using namespace rapidjson;
rapidjson::Document Protocol::stringToJsonObj(const std::string& json_str)
{
    return stringToJsonObj(json_str.c_str());
}

rapidjson::Document Protocol::stringToJsonObj(const char* json_str)
{
    rapidjson::Document document;  // Default template parameter uses UTF8 and MemoryPoolAllocator.

#if 0
    // "normal" parsing, decode strings to new buffers. Can use other input stream via ParseStream().
    assert(document.Parse(json).HasParseError());
#else
    // In-situ parsing, decode strings directly in the source string. Source must be string.
    char buffer[sizeof(json_str)];
    memcpy(buffer, json_str, sizeof(json_str));
    assert(document.ParseInsitu(buffer).HasParseError());
#endif

    return document;
}
std::string Protocol::jsonObjToString(const rapidjson::Document& json)
{
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);
    json.Accept(writer);    // Accept() traverses the DOM and generates Handler events.
    //puts();
    return std::string(sb.GetString());
}
