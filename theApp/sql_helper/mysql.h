/* ************************************************************************
 *       Filename:  mysql_cpp.h
 *    Description:  
 *        Version:  1.0
 *        Created:  04/23/2017 11:56:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 * ************************************************************************/

#ifndef _MYSQL_CPP_H_
#define _MYSQL_CPP_H_

#include <mysql/mysql.h>
#include <iostream>
#include <string.h>
#include "uncopyable.h"

class  DataSet;

class MySQL:private uncopyable
{

public:
	MySQL();

	bool InitMySQL();

    bool ConnectMySQL(const char* host,const char* user,const char* passwd,const char*database,unsigned int port,const char* unix_socket,unsigned long client_flag);



    bool QueryNoResultSet(const char*  sql_sentence);

    /*
     * @param : 数据库查询语句, row和fetch都是输出型参数,返回查询到的行数和列数
     * @return: 建议用只能指针来管理dataset,正确释放资源
     */
	DataSet* QueryResultSet(const char* sql_sentence,size_t& row,size_t& fetch);

    void close()
    {
        mysql_close(conn_ptr);
    }

	virtual ~MySQL()
	{
		mysql_close(conn_ptr);
	}
private:
    MYSQL *conn_ptr;


};
#endif //!_MYSQL_CPP_H_

