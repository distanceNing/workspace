#ifndef _HTTP_SERVER_CONFIG_H_
#define _HTTP_SERVER_CONFIG_H_
#include <string>

#include <algorithm>

namespace config {
typedef struct {
  std::string sql_name;
  std::string sql_host;
  std::string sql_pass;
  std::string sql_user;
  uint16_t listen_port;
} Config;

extern Config gServerConfig;

void loadConfig(const char* config_file_name);

}//namespace config
#endif // !_HTTP_SERVER_CONFIG_H_
