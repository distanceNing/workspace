//
// Created by yangning on 18-1-13.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//
#include "headers/MySqlConnPool.h"
using namespace config;
bool MySqlConnPool::connect()
{
    for (auto& i:mysqlConnList_) {
        if ( !i.mysql_conn.connectMySQL(gServerConfig.sql_host.c_str(), gServerConfig.sql_user.c_str(),
                gServerConfig.sql_pass.c_str(), gServerConfig.sql_name.c_str(), 0, NULL, 0));
        return false;
    }
    return true;
}
MySQL* MySqlConnPool::repeatConnection()
{
    if ( curFreeConnNum_ > 0 ) {
        for (auto& i :mysqlConnList_) {
            if ( i.conn_ref_num == 0 ) {
                return &i.mysql_conn;
            }
        }
        curFreeConnNum_--;
    }
    else if ( mysqlConnList_.size() < gServerConfig.max_mysql_connections ) {
        MysqlConn conn;
        mysqlConnList_.push_back(std::move(conn));
        MySQL* mysql = &mysqlConnList_.back().mysql_conn;
        if ( mysql->connectMySQL(gServerConfig.sql_host.c_str(), gServerConfig.sql_user.c_str(),
                gServerConfig.sql_pass.c_str(), gServerConfig.sql_name.c_str(), 0, NULL, 0))
            return mysql;
        else
            return nullptr;
    }
    else if ( mysqlConnList_.size() == gServerConfig.max_mysql_connections ) {
        //add a timer wait a free connection
    }
    return NULL;
}
