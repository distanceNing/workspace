#include "headers/epoll_mod.h"


SocketEvent::SocketEvent(){
    if((epollfd_ = epoll_create1(0)) < 0){
        std::cout << "create epoll handle error!" << std::endl;
        return;
    }
    bzero(event, sizeof(struct epoll_event)*MAX_EVENTS);
}

SocketEvent::~SocketEvent(){
    if(epollfd_ > 0){
        close(epollfd_);
        epollfd_ = -1;
    }
}

bool SocketEvent::eventAdd(int fd, bool readable, bool writeable){
    struct epoll_event ev;

    bzero(&ev, sizeof(epoll_event));
    ev.events |= EPOLLET;//设置事件为ET触发模式

    if(readable){
        ev.events |= EPOLLIN;
    }
    if(writeable){
        ev.events |= EPOLLOUT;
    }
    ev.data.fd = fd;

    if(epoll_ctl(epollfd_, EPOLL_CTL_ADD, fd, &ev) == -1)
        ERR_EXIT("epoll_ctl");
    return true;
}


int SocketEvent::getEvents(int timeout){
    int nfds;
    if((nfds = epoll_wait(epollfd_, event, MAX_EVENTS, timeout)) < 0)
        ERR_EXIT("epoll_wait");
    return nfds;
}


//设置非阻塞
bool setSocketNonBlock(int sockFd){
    int opt = fcntl(sockFd, F_GETFL);
    if(opt < 0){
        std::cout << "set nonblock failed!!!" << std::endl;
        return false;		
    }
    opt = opt | O_NONBLOCK;
    if(fcntl(sockFd, F_SETFL, opt) < 0){
        std::cout << "set nonblock failed!!!" << std::endl;
        return false;
    }
    return true;
}


//建立socket
int Socket(int domain, int type, int protocol){
    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(listenfd < 0)
        ERR_EXIT("socket");
    return listenfd;
}


//绑定地址信息
int Bind(int listenfd, const struct sockaddr* addr, socklen_t addrlen){
    if(bind(listenfd, addr, addrlen) < 0)
        ERR_EXIT("bind");
    return 1;
}


//监听
int Listen(int listenfd, int backlog){
    if(listen(listenfd, backlog) < 0)
        ERR_EXIT("listen");
    return 1;
}


//接收连接请求
int Accept(int listenfd, struct sockaddr* addr, socklen_t* addrlen){
    int connfd;
    if((connfd = accept(listenfd, addr, addrlen)) < 0){
        if(errno != EAGAIN && errno != ECONNRESET && errno != EPROTO && errno != EINTR)
            ERR_EXIT("accept");
    }
    return connfd;
}


int readV(int sockfd){
    ssize_t read_size;
    ssize_t total_read_size = 0;
    char buffer[MAX_BUFFER_SIZE] = {'\0'};
    char extera[MAX_EXTERA_SIZE] = {'\0'};

    int fd;
    if((fd = open("NEWfile", O_RDWR | O_CREAT | O_APPEND)) < 0)
        ERR_EXIT("open fd");
    struct iovec vec[2];
    vec[0].iov_base = buffer;
    vec[0].iov_len = MAX_BUFFER_SIZE;

    vec[1].iov_base = extera;
    vec[1].iov_len = MAX_BUFFER_SIZE;

    while((read_size = readv(sockfd, vec, 2)) > 0){
        if(read_size <= MAX_BUFFER_SIZE)
            write(fd, buffer, (size_t)read_size);
        else if(read_size > MAX_BUFFER_SIZE){
            write(fd, buffer, MAX_BUFFER_SIZE);
            write(fd, extera, (size_t)read_size - MAX_BUFFER_SIZE);
        }
        total_read_size += read_size;
    }
    return total_read_size;
}


int main(){
    int reuseport, connfd, i, yes = 1;
    bool setblockres;

    struct sockaddr_in servaddr, localaddr;
    bzero(&servaddr, sizeof(servaddr));
    bzero(&localaddr, sizeof(localaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6066);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int listenfd = Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //设置端口复用
    if((reuseport = setsockopt(listenfd, SOL_SOCKET, SO_REUSEPORT, &yes, sizeof(yes))) == -1)
        ERR_EXIT("setsockopt port");
    //设置地址复用
    if((setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes))) == -1)
        ERR_EXIT("setsockpot ip");

    if(!(setblockres = setSocketNonBlock(listenfd)))
        ERR_EXIT("setSocketNonblock");
    
    //bind
    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    //listen
    Listen(listenfd, BACKLOG_SIZE);


    //epoll
    SocketEvent sockevent;
    sockevent.event[MAX_EVENTS];

    //将listenfd加入事件EPOLLIN列表
    sockevent.eventAdd(listenfd, true, false);

    socklen_t addrlen = sizeof(localaddr);
    for(;;){
        //等待事件
        int nfds = sockevent.getEvents(EPOLL_TIMEOUT);

        for(i=0; i<nfds; ++i){
            int sockfd = sockevent.event[i].data.fd;
            if(sockfd < 0) continue;
            //处理新连接
            if(sockevent.event[i].data.fd == listenfd){
                while((connfd = Accept(listenfd, (struct sockaddr*)&localaddr, &addrlen)) > 0){
                    setSocketNonBlock(connfd);

                    std::cout << "远程连入地址>> " << inet_ntoa(localaddr.sin_addr)
                            << "  远程连入端口>> " << ntohs(localaddr.sin_port) << std::endl;
                    sockevent.eventAdd(connfd, true, false);
                }
            }

            else if(sockevent.event[i].events & EPOLLIN) {
                int total_read_size = readV(sockfd);
                if(total_read_size == 0){
                    close(sockfd);
                    std::cout << "远程地址主机>> " << inet_ntoa(localaddr.sin_addr)
                            << "  远程主机端口>> " << ntohs(localaddr.sin_port)
                            << " 的主机关闭"  << std::endl;
                    continue;
                }
                std::cout << "read size is " << total_read_size << std::endl;
            }
        }
    }
    close(listenfd);
    return 0;
}
