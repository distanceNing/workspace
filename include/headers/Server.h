//
// Created by yangning on 18-1-15.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#ifndef THEAPP_SERVER_H
#define THEAPP_SERVER_H

#include "tcp_server.h"
#include "tcp_connection.h"
#include "config.h"
#include "Session.h"

class Server {
public:

    using SessionMap=std::map<net::TcpServer::TcpConnectionPtr,Session>;

    Server(net::EventLoop* loop):tcpServer_(config::gServerConfig.listen_port,loop)
    {
    }


    void run();

    ~Server()
    {
    }

private:
    void newConnCallBack(int fd, const IpAddress& address){
        //
    }

    SessionMap sessionMap_;
    net::TcpServer tcpServer_;
};

#endif //THEAPP_SERVER_H
