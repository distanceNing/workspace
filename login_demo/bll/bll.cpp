#include "bll.h"

const int MAX_BUF_SIZE = 1024;

LoginDemoBll::LoginDemoBll(LOGIN_INFO* loginInfo):loginInfo_(loginInfo)
{
}

bool LoginDemoBll::initDatabase()
{
   return  loginDemoDal_.loadingDataBase();
}

LOGIN_RESULT LoginDemoBll::checkUserInfo()
{
    LOGIN_INFO real_info;
    memset(&real_info,0,sizeof(LOGIN_INFO));
    
    if(!loginDemoDal_.queryUserLoginInfo(loginInfo_->user_id,real_info))
    {
        return NO_THIS_USER;
    }

    if(loginDemoDal_.isLogin(loginInfo_->user_id))
        return ALREADY_ONLINE;
    
    if(!strcmp(loginInfo_->user_passwd,real_info.user_passwd))
    {
        return LOGIN_SUCCESS;
    }
    else
    {
        return ERROR_PASSWD;
    }
}

