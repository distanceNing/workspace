#ifndef _PRODUCER_H_
#define _PRODUCER_H_


#include "net/socket/tcp_socket.h"
#include <string>
class Producer{
public:
    Producer(){}

    void init(const char* ip,uint16_t port);

    bool push_msg(int topic,int proto,const std::string& content);

    ~Producer()
    {}
private:
    net::TcpSocket socket_;


};
#endif //! _PRODUCER_H_