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

#define MAX_BUFFER_SIZE 4096
#define MAX_FILENAME_SIZE 256

class Session {
public:
    enum kProcessState {
        kSuccess = 1, kFailed, kUpload, kDownload, kSendFileBlock, kRecvFileBlock
    };

    enum cmd {
	    kCmdRegister = 1, kCmdLogin, kCmdAck, kCmdError, kCmdDownload, kCmdUpload,
	    kCmdUpdatePath, kCmdReTrans, kCmdContinue, kCmdStop, kCmdLogout, kCmdVip
    };

    Session():json(nullptr)
    {
    }

    bool parse(net::SocketBuf* buf);

    void process();

    int kCmdAckErrorFunc (int cmd_type);

	int kCmdRegisterFuc ();

	int kCmdLoginFunc ();

	int kCmdDownloadFunc ();

	int kCmdUploadFunc ();

	int kCmdReTransFunc ();

	int kCmdContinueFunc ();

	int kCmdStopFunc ();

	int kCmdLogoutFunc ();

	int kCmdVipFunc ();

    ~Session()
    {
    }

private:
    void handleRequest(net::TcpConnection& connection, net::SocketBuf* buf);
    //kProcessState processState_;
    std::shared_ptr<rapidjson::Document> json;
    rapidjson::Document replyJson_;
	int handleState_;
};

#endif //THEAPP_SESSION_H
