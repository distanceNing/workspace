//
// Created by yangning on 18-1-15.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#include "headers/Server.h"
#include "tcp_server.h"
void Server::run()
{
    tcpServer_.serverStart();
}
