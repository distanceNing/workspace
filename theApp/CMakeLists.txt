cmake_minimum_required(VERSION 3.7)

project(theApp)

INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/openssl/include
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/googletest/include
)

set(CMAKE_CXX_STANDARD 14)

LINK_DIRECTORIES(openssl/lib)

set(SOURCE_FILES
        sql_helper/mysql.cpp sql_helper/mysql.h
        sql_helper/mysql_data.cpp sql_helper/mysql_data.h


        Protocol.cpp Protocol.h
        FileMd5.cpp FileMd5.h
        common.h
        main.cpp)
add_executable(theApp ${SOURCE_FILES})

target_link_libraries(theApp
        libssl.a
        ${PROJECT_SOURCE_DIR}/googletest/make/gtest_main.a
        libcrypto.a
        pthread
        /usr/lib/mysql
        mysqlclient
        )
