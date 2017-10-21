#include "../net_helper/common.h"
#include "../net_helper/tcp_socket.h"
#include "../module/module.h"

#include <iostream>

int main()
{
    TcpSocket sock;
    sock.CreateSocket();
    char connIP[]="127.0.0.1";
    if(!sock.Connect(connIP,kPort))
    {
        std::cout<<"Create Socket Error"<<strerror(errno)<<std::endl;
        return -1;
    }
    LOGIN_INFO login_info;
    memset(&login_info,0,sizeof(LOGIN_INFO));
    std::cout<<"input your id \n";
    std::cin>>login_info.user_id;
    std::cout<<"input your  password\n";
    std::cin>>login_info.user_passwd;

    sock.Send(&login_info,sizeof(LOGIN_INFO));
    int ret =0;
    sock.Receive(&ret,sizeof(int));
    switch (ret)
    {
        case LOGIN_SUCCESS:
            std::cout<<"LOGIN SUCCESS\n";
            break;
        case ALREADY_ONLINE:
            std::cout<<"ALREADY ONLINE\n";
            break;
        case ERROR_PASSWD:
            std::cout<<"ERROR PASSWD\n";
            break;
        case NO_THIS_USER:
            std::cout<<"NO_THIS_USER\n";
            break;
        default:
            std::cout<<"UNKNOWN RETURN\n";
            break;
    }
    sock.CloseSocket();    

    return 0;
}

