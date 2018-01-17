#include "gtest/gtest.h"
//#define _TESTING
#include "event_loop.h"
#include "headers/Server.h"

int main(int argc, char* argv[])
{
#ifdef _TESTING
    ::testing::FLAGS_gtest_color="yes";
    ::testing::InitGoogleTest(&argc, argv);
    return  RUN_ALL_TESTS();
#else

    net::EventLoop main_loop(net::POLL);

    Server server(&main_loop);


    //theapp.run();
    return 0;
#endif
}