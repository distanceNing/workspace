#include "gtest/gtest.h"
#define _TESTING



int main(int argc, char* argv[])
{
#ifdef _TESTING
    ::testing::FLAGS_gtest_color="yes";
    ::testing::InitGoogleTest(&argc, argv);
    return  RUN_ALL_TESTS();
#else
    //theapp.run();
    return 0;
#endif
}