#include <headers/common.h>
#include <net/socket/tcp_socket.h>
#include <rapidjson/document.h>
#include <map>
#include "producer.h"
#include "headers/Protocol.h"

void Producer::init(const char* ip, uint16_t port)
{
    if(!socket_.CreateSocket()){
        printErrorMsg("socket");
    }
    if ( net::TcpSocket::noblockingConnect(socket_.getFd(), ip, port, 5) < 0 ) {
        printErrorMsg("connect");
    }
    //if ( !setFdNonBlocking(fd_))
    //   printErrorMsg("setFdNonBlocking");

    net::TcpSocket::setTcpNoDelay(socket_.getFd());
}
bool Producer::push_msg(int topic, int proto,const std::string& content)
{
    std::map<std::string,std::string> map;
    map["cmd"] = std::to_string(Protocol::kCmdPush);
    map["msg_type"] = std::to_string(topic);
    map["msg_proto"] = std::to_string(proto);
    map["content"] = content;



    auto str_msg = map2jsonstr(map);
    if(socket_.Send(str_msg.c_str(),str_msg.length()) < 0){
        printErrorMsg("send");
    }

    char buffer[1024];
    memset(buffer,0,1024);
    socket_.Receive(buffer,1024);

    return !strncmp(buffer,Protocol::kSuccess,strlen(Protocol::kSuccess));

}
