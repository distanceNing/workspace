
#include "msg.h"

//#include "net/socket/tcp_socket.h"

#include "rapidjson/document.h"
#include "headers/Protocol.h"

#include <iostream>
using namespace std;

void Msg::setMsgProto(int msg_type)
{
    switch (msg_type)
    {
    case Protocol::kBinProto:
        msg_type_ = new BinProto();
        break;
    case Protocol::kJson:
        msg_type_ = new JSON();
        break;
    case Protocol::kXml:
        msg_type_ = new XML();
        break;;
    default:
        break;
    }
}

std::string Msg::packMsg(const std::string& content)
{


    return std::string();
}
