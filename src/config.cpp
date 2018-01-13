#include "headers/config.h"
#include "headers/common.h"
#include <assert.h>
#include <cstring>

namespace config {

#define SKIP_SPACE(ptr) do\
{\
for (;*ptr == ' '||*ptr=='\n';++ptr)\
;\
}while (0)

static const char* server_port = "SERVER_PORT";
static const char* sql_name = "SQL_NAME";
static const char* sql_host = "SQL_HOST";
static const char* sql_user = "SQL_USER";
static const char* sql_pass = "SQL_PASS";


Config gServerConfig;

static void fillConfig(char* str)
{
    assert(str != NULL);
    if ( !strncmp(str, server_port, strlen(server_port))) {
        char* temp = str + strlen(server_port);
        SKIP_SPACE(temp);
        gServerConfig.listen_port = static_cast<uint16_t>(atoi(temp));
    }

    else if ( !strncmp(str, sql_host, strlen(sql_host))) {
        char* temp = str + strlen(sql_host);
        SKIP_SPACE(temp);
        gServerConfig.sql_host = temp;
    }
    else if ( !strncmp(str, sql_name, strlen(sql_name))) {
        char* temp = str + strlen(sql_name);
        SKIP_SPACE(temp);
        gServerConfig.sql_name = temp;
    }
    else if ( !strncmp(str, sql_pass, strlen(sql_pass))) {
        char* temp = str + strlen(sql_pass);
        SKIP_SPACE(temp);
        gServerConfig.sql_pass = temp;
    }
    else if ( !strncmp(str, sql_user, strlen(sql_user))) {
        char* temp = str + strlen(sql_user);
        SKIP_SPACE(temp);
        gServerConfig.sql_user = temp;
    }

}

void loadConfig(const char* config_file_name)
{
    assert(config_file_name != NULL);
    FILE* fp = fopen(config_file_name, "r");
    if ( fp == NULL )
        printErrorMsg("fopen");
    char buffer[MAX_BUF_SIZE] = {'\0'};
    size_t read_size = fread(buffer, 1, MAX_BUF_SIZE, fp);
    char config_item[128];
    for (char* temp = buffer; *temp != '\0'; ++temp) {
        SKIP_SPACE(temp);
        char* line_end = std::find(temp, buffer + read_size, '\n');
        if ( *temp != '#' ) {
            memset(config_item, 0, 128);
            strncpy(config_item, temp, line_end - temp - 1);
            fillConfig(config_item);
        }
        temp = line_end;
    }
}

}//namespace config
