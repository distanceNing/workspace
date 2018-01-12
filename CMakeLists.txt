cmake_minimum_required(VERSION 3.7)

project(theApp)

INCLUDE_DIRECTORIES(
        include/openssl/include
        ${PROJECT_SOURCE_DIR}/include
        include/googletest/include
)

set(CMAKE_CXX_STANDARD 14)

LINK_DIRECTORIES(include/openssl/lib)

set(SOURCE_FILES
        sql_helper/mysql.cpp sql_helper/mysql.h
        sql_helper/mysql_data.cpp sql_helper/mysql_data.h


        src/Protocol.cpp include/headers/Protocol.h
        src/FileMd5.cpp include/headers/FileMd5.h
        include/headers/common.h
        src/main.cpp)

add_executable(theApp ${SOURCE_FILES})

target_link_libraries(
        theApp
        libssl.a
        include/googletest/make/gtest_main.a
        libcrypto.a
        pthread
        mysqlclient
        )
