//
// Created by yangning on 18-1-14.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#ifndef THEAPP_SESSION_H
#define THEAPP_SESSION_H
#include "Protocol.h"
#include <string>
#include <memory>
#include "net/tcp_connection.h"

class Session {
public:
    enum kProcessState {
      kUpload, kDownload, kSendFileBlock, kRecvFileBlock
    };

    enum cmd {
      kCmdLogin, kCmdRegister, kCmdAck, kCmdUpload, kCmdDownload, kCmdReTrans, kCmdLogout, kCmdUpdatePath, kCmdContinue

    };

    Session():json(nullptr)
    {
    }

    bool parse(net::SocketBuf* buf);

    void process();

    ~Session()
    {
    }

private:
    void handleRequest(net::TcpConnection& connection, net::SocketBuf* buf);
    kProcessState processState_;
    std::shared_ptr<rapidjson::Document> json;
    rapidjson::Document replyJson_;
};

#endif //THEAPP_SESSION_H
