#include "dal.h"
#include "../sql_helper/mysql_data.h"
#include "boost/scoped_ptr.hpp"
#include <cstdio>

bool LoginDemoDal::loadingDataBase()
{
    if(!mysqlConn_.InitMySQL())
    {
        perror("Init Mysql error");
        return false;
    }
    if(!mysqlConn_.ConnectMySQL("127.0.0.1","root","nopasswd","LoginDemo",0,NULL,0))
    {
        perror("Connect Mysql error");
        return false;
    }
    return true;
}

bool LoginDemoDal::queryUserLoginInfo(const char* user_id,LOGIN_INFO& login_info)
{
    char sql[SQL_BUF_SZIE]={'\0'};
    snprintf(sql,SQL_BUF_SZIE,"select * from LoginInfo where user_id =\"%s\"",user_id);
    int row=0;
    int fetch=0;
    boost::scoped_ptr<mysql_data> result(mysqlConn_.QueryResultSet(sql,row,fetch));
    if(result->isEmpty())
        return false;
    strncpy(login_info.user_id,(*result)[0],16);
    strncpy(login_info.user_passwd,(*result)[1],16);
    return true;
}

bool LoginDemoDal::isLogin(const char* user_id)
{
    char sql[SQL_BUF_SZIE]={'\0'};
    snprintf(sql,SQL_BUF_SZIE,"select * from LoginStatus where user_id =\"%s\"",user_id);
    int row=0;
    int fetch=0;
    boost::scoped_ptr<mysql_data> result(mysqlConn_.QueryResultSet(sql,row,fetch));
    return result->isEmpty() ? false : true ;
}

LoginDemoDal::~LoginDemoDal()
{
    mysqlConn_.close();
}
