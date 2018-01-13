/* ************************************************************************
 *       Filename:  dataset.h
 *    Description:  用来保存数据库查询的结果集
 *        Version:  1.0
 *        Created:  04/25/2017 09:28:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  yang ning
 * ************************************************************************/
#ifndef _MYSQL_DATA_H_
#define _MYSQL_DATA_H_
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <assert.h>

class DataSet {
public:
    typedef std::vector<std::string> DataStructer;
    DataSet()
    {
    }
    void push_back(const char* str);

    const char* operator[](size_t i) const
    {
        assert (i < data_.size());
        return data_[i].c_str();
    }

    bool empty()
    {
        return data_.size() == 0;
    }

    size_t size() const
    {
        return data_.size();
    }
private:
    DataStructer data_;
};
#endif //!_MYSQL_DATA_H_

