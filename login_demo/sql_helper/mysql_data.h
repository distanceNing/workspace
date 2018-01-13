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
#include <boost/shared_ptr.hpp>
#include <iostream>
class mysql_data
{
public:
	typedef std::vector<boost::shared_ptr<std::string> > DataStructer;
	mysql_data(){}
	void push_back( char* str);
	const char* operator[](int i) const
	{
		if(i<element.size())
			return (element[i])->c_str();
		else
			std::cerr<<"accross of range!\n";
	}
	bool isEmpty()
	{
		if(element.size()==0)
			return true;
		return false;
	}
	int size() const
	{
		return element.size();
	}
private:
	DataStructer element;
};
#endif //!_MYSQL_DATA_H_

