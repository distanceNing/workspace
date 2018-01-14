//
// Created by yangning on 18-1-13.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#include "headers/Dao.h"
#include "headers/MySqlConnPool.h"
const size_t kSQLBufSize = 512;

static MySqlConnPool gMySqlConnManage;
std::shared_ptr<MySQL> Dao::getAFreeConn()
{
    return gMySqlConnManage.repeatConnection();
}


bool Dao::loaginDao(std::string user_no)
{
    char sql[kSQLBufSize]={'0'};
    std::shared_ptr<MySQL> conn;
    if(conn == nullptr)
        return false;
    else
    {
        conn->queryNoResultSet(sql);
    }
    return true ;
}
