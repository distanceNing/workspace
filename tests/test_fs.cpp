//
// Created by yangning on 18-1-15.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#include "gtest/gtest.h"

#include "headers/File.h"


class TestFileSystem : public ::testing::Test {
protected:
    //第一个case执行前执行
    static void SetUpTestCase()
    {

    }
    //SetUp()方法在每个TestCase之前执行
    virtual void SetUp()
    {

    }
    // TearDown()方法在每个TestCase之后执行
    virtual void TearDown()
    {
    }
    static void TearDownTestCase()
    {
        // std::cout << "after test case\n";
    }

};
TEST_F(TestFileSystem,calcmd5)
{
    EXPECT_STREQ(utility::File::calcMd5Value("/home/yangning/mem").c_str(),"a2aa98a268bbbbc9850f712969a8a795");
}