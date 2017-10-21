#include "../net_helper/tcp_socket.h"
#include "../net_helper/common.h"
#include "bll.h"
#include <boost/scoped_ptr.hpp>
#include <iostream>

int main()
{
    TcpSocket listen_sock;
    listen_sock.CreateSocket(AF_INET,SOCK_STREAM,kPort);
    listen_sock.Listen();
    char fromIP[32];
    UINT fromPort;
    
    while(true)
    {
        TcpSocket client_sock;
        memset(fromIP,'\0',32);
        std::cout<<"Wait for Connection ----- \n";
        listen_sock.Accept(client_sock, fromIP, fromPort);
        std::cout << "From IP: " << fromIP << "-- From Port: " << fromPort << "---Login" << std::endl;
        LOGIN_INFO login_info;
        memset(&login_info,0,sizeof(LOGIN_INFO));
        client_sock.Receive(&login_info,sizeof(LOGIN_INFO));
        LoginDemoBll bll(&login_info);
        int login_result=bll.checkUserInfo();
        client_sock.Send(&login_result,sizeof(int));
        std::cout<< login_info.user_id<<"----login"<<"result is "<<login_result<<std::endl;
//        client_sock.CloseSocket();
    }

    return 0;
}
