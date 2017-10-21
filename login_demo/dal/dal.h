#ifndef _LOGIN_DEMO_DAL_
#define _LOGIN_DEMO_DAL_

#include "../sql_helper/mysql_cpp.h"
#include "../module/module.h"
const int SQL_BUF_SZIE = 512;

class LoginDemoDal
{
public:
    LoginDemoDal(){}
    bool loadingDataBase();
    bool  queryUserLoginInfo(const char * user_id,LOGIN_INFO & login_info); 
    bool  isLogin(const char* user_id);
    ~LoginDemoDal();

private:
    MySQL mysqlConn_;
};


#endif//! _LOGIN_DEMO_DAL_
