#ifndef _EPOLL_MOD_H
#define _EPOLL_MOD_H
#include<iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <cstring>

#define MAXSLEEP 64
#define MAX_BUFFER_SIZE 4096

#define BACKLOG_SIZE 1024

#define MAX_EXTERA_SIZE 65536
#define MAX_EVENTS 256
#define EPOLL_TIMEOUT -1

#define ERR_EXIT(msg) \
    do{ \
        perror(msg); \
        exit(EXIT_FAILURE); \
    } while(0)

int Socket(int, int, int);
int Connect(int, const struct sockaddr*, socklen_t);

bool setSocketNonBlock(int);
int Bind(int, const struct sockaddr, socklen_t);
int Listen(int, int);

int readV(int);

class SocketEvent{
public:
    SocketEvent();//构造函数
    virtual ~SocketEvent();//析构函数
    int getEvents(int timeout);//epoll_wait
    bool eventAdd(int epollfd, bool readable, bool writeable);//EPOLL_CTL_ADD操作
    struct epoll_event event[MAX_EVENTS];
private:
    int epollfd_;
};


#endif
