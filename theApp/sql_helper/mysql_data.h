/* ************************************************************************
 *       Filename:  mysql_data.h
 *    Description:  
 *        Version:  1.0
 *        Created:  04/25/2017 09:28:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/
#ifndef _MYSQL_DATA_H_
#define _MYSQL_DATA_H_
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <assert.h>

class DataSet
{
public:
	typedef std::vector<std::string> DataStructer;
	DataSet(){}
	void push_back( const char* str);

	const char* operator[](size_t i) const
    {
        assert ( i < element.size());
        return element[i].c_str();
	}

	bool empty()
	{
        return element.size()==0;
    }

	size_t size() const
	{
		return element.size();
	}
private:
	DataStructer element;
};
#endif //!_MYSQL_DATA_H_

