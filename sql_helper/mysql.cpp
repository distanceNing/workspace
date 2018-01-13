#include "headers/mysql.h"
#include "headers/dataset.h"


bool
MySQL::connectMySQL(const char* host, const char* user, const char* passwd, const char* database, unsigned int port,
        const char* unix_socket, unsigned long client_flag)
{
    if ( !mysql_real_connect(conn_ptr_, host, user, passwd, database, port, unix_socket, client_flag)) {
        std::cout << "MySQL connect failed\n";
        return false;
    }
    return true;
}

bool MySQL::queryNoResultSet(const char* const sql_sentence)
{
    int flag = mysql_query(conn_ptr_, sql_sentence);
    size_t result;
    if ( flag != 0 ) {
        std::cout << "Query error:" << mysql_error(conn_ptr_) << std::endl;
        return false;
    }
    result = mysql_affected_rows(conn_ptr_);
    std::cout << "affercted " << result << "rows\n";
    return true;

}

DataSet* MySQL::queryResultSet(const char* sql_sentence, size_t& row, size_t& fetch)
{
    int flag = mysql_query(conn_ptr_, sql_sentence);
    if ( flag != 0 ) {
        std::cout << "Query error:\n" << mysql_error(conn_ptr_) << std::endl;
        return nullptr;
    }
    MYSQL_RES* result_data = mysql_store_result(conn_ptr_);
    if ( result_data == NULL ) {
        std::cout << "No result set\n";
        return nullptr;
    }
    MYSQL_ROW data_row;
    fetch = mysql_num_fields(result_data);
    unsigned long* length;
    row = mysql_num_rows(result_data);
    int count = 0;
    DataSet* res = new DataSet;
    while ((data_row = mysql_fetch_row(result_data))) {
        length = mysql_fetch_lengths(result_data);
        for (int i = 0; i < fetch; i++) {
            res->push_back(data_row[i]);
            count++;
        }
    }

    mysql_free_result(result_data);
    return res;
}



