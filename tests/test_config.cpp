//
// Created by yangning on 18-1-13.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//
#include <headers/config.h>
#include "gtest/gtest.h"
#include "headers/config.h"
using namespace config;
class TestParseConfig : public ::testing::Test {
protected:
    //第一个case执行前执行
    static void SetUpTestCase()
    {
       loadConfig("/mnt/hgfs/shared/workspace/config.txt");
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
TEST_F(TestParseConfig,config)
{
    EXPECT_EQ(gServerConfig.listen_port,8000);
    EXPECT_STREQ(gServerConfig.sql_user.c_str(),"root");
    EXPECT_STREQ(gServerConfig.sql_name.c_str(),"workspace");
    EXPECT_STREQ(gServerConfig.sql_pass.c_str(),"guochen");
    EXPECT_STREQ(gServerConfig.sql_host.c_str(),"120.79.16.72");
}