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
#include "config.h"
#include "headers/mysql.h"

class MySqlConnPool {
public:
    typedef struct {
      MySQL mysql_conn;
      uint32_t conn_ref_num;
    } MysqlConn;
    using MysqlConnList=std::vector<MysqlConn>;
    MySqlConnPool()
            :mysqlConnList_(config::gServerConfig.min_mysql_connections),
             curFreeConnNum_((uint32_t) mysqlConnList_.size())
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
    MySQL* repeatConnection();

    /*
     * @brief:归还一个数据库连接
     *
     **/
    void returnConnection(MysqlConn* conn)
    {
        conn->conn_ref_num--;
        curFreeConnNum_++;
    }

    size_t getActiveSize() const
    {
        return mysqlConnList_.size() - curFreeConnNum_;
    }

    ~MySqlConnPool()
    {
    }

private:
    MysqlConnList mysqlConnList_;
    uint32_t curFreeConnNum_;
};

#endif //THEAPP_MYSQLCONNPOOL_H
