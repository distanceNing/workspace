#include <headers/File.h>
#include <headers/Server.h>
#include "gtest/gtest.h"
//#define _TESTING
#include "event_loop.h"



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

    std::string fpath = "/home/roux/下载/";
    std::string fname = "CLion-2017.1.3.tar.gz";

    //std::cout<<utility::File::calcMd5Value(fpath, fname);

    //std::cout<<utility::File::chunkSplit(fpath, fname);

    std::cout<<utility::File::getFileSize(fpath, fname);

    return 0;
#endif
}