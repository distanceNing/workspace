#ifndef _LOGIN_DEMO_BLL_H_
#define _LOGIN_DEMO_BLL_H_

#include "../module/module.h"
#include "../dal/dal.h"
#include "../net_helper/tcp_socket.h"
#include "../net_helper/common.h"

class LoginDemoBll
{
public:
    LoginDemoBll(LOGIN_INFO* loginInfo);
    
    bool initDatabase();

    LOGIN_RESULT checkUserInfo();

    ~LoginDemoBll(){}

private:
    LoginDemoDal loginDemoDal_;
    LOGIN_INFO* loginInfo_;
};

#endif//!_LOGIN_DEMO_BLL_H_

