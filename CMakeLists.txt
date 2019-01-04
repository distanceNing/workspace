cmake_minimum_required(VERSION 3.7)

project(theApp)

INCLUDE_DIRECTORIES(
        include/openssl/include
        ${PROJECT_SOURCE_DIR}/include
        include/googletest/include
        include/net
)

set(CMAKE_CXX_STANDARD 14)

LINK_DIRECTORIES(include/openssl/lib
       )

set(SOURCE_FILES

        include/net/socket/tcp_socket.h include/net/socket/tcp_socket.cpp






        #tests/test_config.cpp
        #tests/test_mysql.cpp
        #tests/test_parse.cpp


        src/config.cpp include/headers/config.h
        src/Protocol.cpp include/headers/Protocol.h
        include/headers/common.h
        src/producer.cpp src/producer.h
        src/msg.cpp src/msg.h
        src/consumer.cpp src/consumer.h



        src/main.cpp )


add_executable(theApp ${SOURCE_FILES})

target_link_libraries(
        theApp
        libssl.a
        #${PROJECT_SOURCE_DIR}/include/googletest/make/gtest_main.a
        libcrypto.a
        pthread
 #       mysqlclient
        )
