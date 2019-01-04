#ifndef _CONSUMER_H_
#define _CONSUMER_H_

#include "net/socket/tcp_socket.h"
#include <string>
#include <net/headers/common.h>
#include "ProcessMethod.h"
class Consumer{
public:
    Consumer(){}
    void init(const char* ip, uint16_t port);

    void setMsgHandle(const MsgHandleFunc::MsgHandleFun& msgHandle){
        msgHandle_ = msgHandle;
    }

    bool register_node(int type);

    void process();

    ~Consumer(){}

private:
    net::TcpSocket socket_;
    MsgHandleFunc::MsgHandleFun msgHandle_;
};
#endif // _CONSUMER_H_
