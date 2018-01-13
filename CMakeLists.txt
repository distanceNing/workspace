cmake_minimum_required(VERSION 3.7)

project(theApp)

INCLUDE_DIRECTORIES(
        include/openssl/include
        ${PROJECT_SOURCE_DIR}/include
        include/googletest/include
)

set(CMAKE_CXX_STANDARD 14)

LINK_DIRECTORIES(include/openssl/lib
       )

set(SOURCE_FILES
        sql/sql_helper/mysql.cpp include/headers/mysql.h
        sql/sql_helper/dataset.cpp include/headers/dataset.h

        tests/test_config.cpp
        tests/test_mysql.cpp



        src/config.cpp include/headers/config.h
        src/Protocol.cpp include/headers/Protocol.h
        src/File.cpp include/headers/File.h
        include/headers/common.h
        src/main.cpp src/Dao.cpp include/headers/Dao.h src/MySqlConnPool.cpp include/headers/MySqlConnPool.h)

add_executable(theApp ${SOURCE_FILES})

target_link_libraries(
        theApp
        libssl.a
        ${PROJECT_SOURCE_DIR}/include/googletest/make/gtest_main.a
        libcrypto.a
        pthread
        mysqlclient
        )
