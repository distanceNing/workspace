/* ************************************************************************
 *       Filename:  DataSet.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  04/25/2017 10:01:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include "mysql_data.h"

void DataSet::push_back(const char* str)
{

	element.push_back(std::string(str)) ;
}



