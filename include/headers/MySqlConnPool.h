//
// Created by yangning on 18-1-13.
//
// Descriprion : 数据库连接池,数据库连接的分配和释放.
//
// Copyright (c) yangning All rights reserved.
//

#ifndef THEAPP_MYSQLCONNPOOL_H
#define THEAPP_MYSQLCONNPOOL_H
#include <vector>
#include <memory>
#include "config.h"
#include "headers/mysql.h"


class MySqlConnPool {
public:

    using MysqlConnPtr =std::shared_ptr<MySQL>;
    using MysqlConnList=std::vector<MySQL*>;
    MySqlConnPool()
            :mysqlConnList_(config::gServerConfig.min_mysql_connections,new MySQL()),curUsingNum_(0)
    {
    }
    /*
     * @brief:连接数据库服务器
     *
     **/
    bool connect();

    /*
     * @brief:分配一个可用的数据库连接
     *
     **/
    MysqlConnPtr repeatConnection();

    /*
     * @brief:归还一个数据库连接
     *
     **/
    void returnConnection(MySQL* conn)
    {
        curUsingNum_--;
        mysqlConnList_.emplace_back(conn);
    }

    size_t getActiveSize() const
    {
        return mysqlConnList_.size();
    }

    void destory()
    {
        for(auto& i :mysqlConnList_)
            delete(i);
        mysqlConnList_.clear();
    }


    ~MySqlConnPool()
    {
    }

private:
    MysqlConnList mysqlConnList_;
    uint32_t curUsingNum_;
};

#endif //THEAPP_MYSQLCONNPOOL_H
