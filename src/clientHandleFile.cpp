#include "headers/epoll_mod.h"

using namespace std;

int Socket(int domain, int type, int protocol){
    int sockfd;

    sockfd = socket(domain, type, protocol);
    if(sockfd < 0){
        ERR_EXIT("socket");
    }
    return sockfd;
}


int Connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen){
    int nsec;

    for(nsec = 1; nsec <= MAXSLEEP; nsec <<= 1){
        if((connect(sockfd, addr, addrlen)) == 0){
            return 0;//connection accepted
        }

        //sleep nsec then connect retry
        if(nsec <= MAXSLEEP/2)
            sleep(nsec);
    }
    return -1;
}


int main(){
    char buffer[MAX_BUFFER_SIZE];
    ssize_t readn;
    struct sockaddr_in servaddr, localaddr;
    socklen_t addrlen = sizeof(localaddr);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6066);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");


    //build socket
    int sockfd = Socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    //connect
    int conn;
    if((conn = Connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) < 0)
        ERR_EXIT("connect");


    if(getsockname(sockfd, (struct sockaddr*)&localaddr, &addrlen) < 0)
        ERR_EXIT("getsockname");
    cout << "本机IP>> "   << inet_ntoa(localaddr.sin_addr)
         << "本机端口>> " << ntohs(localaddr.sin_port) << endl;


    printf("send begin\n");
    int fd = open("testdata", O_RDWR);
    while(readn = read(fd, buffer, MAX_BUFFER_SIZE)){
        send(sockfd, buffer, readn, 0);
    }
    printf("send close\n");
    while(::read(sockfd,buffer,MAX_BUFFER_SIZE) > 0){}

    close(sockfd);
    return 0;
}
