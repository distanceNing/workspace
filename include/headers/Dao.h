//
// Created by yangning on 18-1-13.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#ifndef THEAPP_DAO_H
#define THEAPP_DAO_H
#include <memory>
#include <assert.h>
#include "mysql.h"


class DataSet;

class Dao {


    static bool loaginDao(std::string user_no);
    static std::shared_ptr<MySQL> getAFreeConn();
};







#endif //THEAPP_DAO_H
