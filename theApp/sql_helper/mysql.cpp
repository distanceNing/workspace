
#include "mysql.h"
#include "mysql_data.h"
MySQL::MySQL()
{
	conn_ptr=NULL;
}

bool MySQL::InitMySQL()
{
	conn_ptr=mysql_init(NULL);
	if(!conn_ptr)
	{
		std::cout<<"MySQL init failed\n";
		return false;
	}
	return true;
}

bool MySQL::ConnectMySQL(const char* host,const char* user,const char* passwd,const char* database,unsigned int port,const char* unix_socket,unsigned long client_flag)
{
	if(!mysql_real_connect(conn_ptr,host,user,passwd,database,port,unix_socket,client_flag))
	{
		std::cout<<"MySQL connect failed\n";
		return false;
	}
	return true;
}

bool MySQL::QueryNoResultSet(const char* const sql_sentence)
{
	int flag=mysql_query(conn_ptr,sql_sentence);
	size_t result;
	if(flag!=0)
	{
		std::cout<<"Query error:"<<mysql_error(conn_ptr)<<std::endl;
		return false;
	}
	result=mysql_affected_rows(conn_ptr);
	std::cout<<"affercted "<<result<<"rows\n";
	return true;

}

DataSet* MySQL::QueryResultSet(const char* sql_sentence,size_t &row,size_t& fetch)
{
	int flag=mysql_query(conn_ptr,sql_sentence);
	if(flag!=0)
	{
		std::cout<<"Query error:\n"<<mysql_error(conn_ptr)<<std::endl;
		return NULL;
	}
	MYSQL_RES* result_data=mysql_store_result(conn_ptr);
	if(result_data==NULL)
	{
		std::cout<<"No result set\n";
		return NULL;
	}
	MYSQL_ROW data_row;
	fetch=mysql_num_fields(result_data); 
	unsigned long* length;
	row=mysql_num_rows(result_data);
	int count=0;
	DataSet* res=new DataSet;
	while((data_row=mysql_fetch_row(result_data)))
	{
		
		length=mysql_fetch_lengths(result_data);
		for(int i=0;i<fetch;i++)
		{
			res->push_back(data_row[i]);
			count++;
		}
	}

	mysql_free_result(result_data);
	return res;
}



