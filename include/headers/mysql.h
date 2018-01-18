/* ************************************************************************
 *       Filename:  mysql_cpp.h
 *    Description:  数据库的连接和查询操作
 *        Version:  1.0
 *        Created:  04/23/2017 11:56:34 AM
 *       Compiler:  gcc
 *         Author:  yang ning
 * ************************************************************************/

#ifndef _MYSQL_CPP_H_
#define _MYSQL_CPP_H_

#include <mysql/mysql.h>
#include <iostream>
#include <cstring>
#include <cassert>
#include <memory>
#include "uncopyable.h"

class DataSet;

class MySQL : private uncopyable {

public:
    MySQL():conn_ptr_ (mysql_init(NULL)){
        assert(conn_ptr_ != NULL);
    }

    bool connectMySQL(const char* host, const char* user, const char* passwd, const char* database, unsigned int port,
            const char* unix_socket, unsigned long client_flag);
    /*
     * @brief : 用来做无结果集返回的查询操作,例如 delete .
     * @param : 数据库查询语句
     * @return: 执行是否成功
     */
    bool queryNoResultSet(const char* sql_sentence);

    /*
     * @brief : 用来做有结果集返回的查询操作
     * @param : 数据库查询语句, row和fetch都是输出型参数,返回查询到的行数和列数
     * @return: 建议用只能指针来管理dataset,正确释放资源
     */
    DataSet* queryResultSet(const char* sql_sentence, size_t& row, size_t& fetch);

    void close()
    {
        mysql_close(conn_ptr_);
    }

    virtual ~MySQL()
    {
        mysql_close(conn_ptr_);
    }
private:
    MYSQL* conn_ptr_;

};
#endif //!_MYSQL_CPP_H_

