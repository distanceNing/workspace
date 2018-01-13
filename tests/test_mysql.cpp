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
#include "headers/mysql.h"
using namespace config;
class TestMysql : public ::testing::Test {
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
    MySQL mysql_;
};
TEST_F(TestMysql,connect)
{
    EXPECT_TRUE(mysql_.connectMySQL(gServerConfig.sql_host.c_str(),
            gServerConfig.sql_user.c_str(),
            gServerConfig.sql_pass.c_str(),
            gServerConfig.sql_name.c_str(),
            0,NULL,0));
}