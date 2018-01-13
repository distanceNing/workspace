//
// Created by yangning on 17-10-18.
//

#ifndef EPOLL_COMMON_H
#define EPOLL_COMMON_H
enum LOGIN_RESULT
{
    LOGIN_SUCCESS = 1000,
    ALREADY_ONLINE,
    ERROR_PASSWD,
    NO_THIS_USER,
};
const int kPort=9000;

void printErrorMsg(const char* msg);

bool setFdNonBlocking(int fd);

#endif //EPOLL_COMMON_H
