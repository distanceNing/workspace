#include <headers/Protocol.h>
#include <iostream>
#include "consumer.h"
#include "msg.h"

static const char* begin = "BEGIN";
static const char* end = "END";
void Consumer::init(const char* ip, uint16_t port)
{
    if ( !socket_.CreateSocket()) {
        printErrorMsg("socket");
    }
    if ( net::TcpSocket::noblockingConnect(socket_.getFd(), ip, port, 5) < 0 ) {
        printErrorMsg("connect");
    }
    //if ( !setFdNonBlocking(fd_))
    //   printErrorMsg("setFdNonBlocking");

    net::TcpSocket::setTcpNoDelay(socket_.getFd());
}

bool Consumer::register_node(int type)
{
    std::map<std::string, std::string> map;
    map["cmd"] = std::to_string(Protocol::kCmdRegister);
    map["msg_type"] = std::to_string(type);

    auto str_msg = map2jsonstr(map);
    if ( socket_.Send(str_msg.c_str(), str_msg.length()) < 0 ) {
        printErrorMsg("send");
    }

    char buffer[1024];
    memset(buffer, 0, 1024);
    socket_.Receive(buffer, 1024);
    return !strncmp(buffer, Protocol::kSuccess, strlen(Protocol::kSuccess));
}
void Consumer::process()
{
    char buffer[1024];
    memset(buffer, 0, 1024);
    ssize_t recv_size = socket_.Receive(buffer, 1024);
    if(recv_size < 0){
        printErrorMsg("recv");
    }
    const char* str =buffer;
    size_t len =(size_t) recv_size;
    if ( strncmp(str, begin, strlen(begin)) != 0 ) {
        //数据块错误没有包含BEGIN
        return ;
    }

    const char* flag = std::search(str + strlen(begin), str + len, end, end + 3);
    if ( flag == str + len ) {
        //接收到的数据中没有END
        return ;
    }

    std::string json_str(str + strlen(begin), flag);
    std::map<std::string, std::string> map;
    jsonstr2map(map, json_str.c_str());
    int proto = atoi(map["msg_proto"].c_str());
    int type = atoi(map["msg_type"].c_str());
    std::string content = map["content"];
    Msg* msg = NULL;
    switch (type) {
    case Protocol::kAnnounceMsg : {
        msg = new AnnounceMsg(content);
        msg->setMsgProto(proto);

        break;
    }
    case Protocol::kInfoMsg: {
        msg = new InfoMsg(content);
        msg->setMsgProto(proto);

        break;
    }
    case Protocol::kRemindMsg: {
        msg = new InfoMsg(content);
        msg->setMsgProto(proto);

        break;
    }
    default:break;
    }
    if ( !msg ) {
        std::cout << "unknow msg\n";
        return;
    }
    msg->msgEncode();

    std::cout<<"msg content is " <<msg->getContent()<<std::endl;


    delete(msg);
}

