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
        if ( !i->connectMySQL(gServerConfig.sql_host.c_str(), gServerConfig.sql_user.c_str(),
                gServerConfig.sql_pass.c_str(), gServerConfig.sql_name.c_str(), 0, NULL, 0));
        return false;
    }
    return true;
}
MySqlConnPool::MysqlConnPtr MySqlConnPool::repeatConnection()
{

    if ( !mysqlConnList_.empty()) {
        curUsingNum_++;
        MySQL* conn = mysqlConnList_.back();
        mysqlConnList_.pop_back();
        return std::shared_ptr<MySQL>(conn,[this](MySQL* p){
          //deletor
          this->returnConnection(p);
        });
    }
    else if ( mysqlConnList_.size() < gServerConfig.max_mysql_connections ) {
        mysqlConnList_.emplace_back();
        MySQL* mysql = mysqlConnList_.back();
        if ( mysql->connectMySQL(gServerConfig.sql_host.c_str(), gServerConfig.sql_user.c_str(),
                gServerConfig.sql_pass.c_str(), gServerConfig.sql_name.c_str(), 0, NULL, 0))
        {
            curUsingNum_++;
            return std::shared_ptr<MySQL>(mysql, [this](MySQL* conn) {
              //deletor
              this->returnConnection(conn);
            });
        }
        else
            return nullptr;
    }
    else if ( mysqlConnList_.size() == gServerConfig.max_mysql_connections ) {
        //add a timer wait a free connection
    }

    return nullptr;
}
