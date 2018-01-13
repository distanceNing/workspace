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

enum DaoType {
  Login, Upload, DownLoad
};

class DataSet;
class Dao {
public:
    Dao()
    {
    }

    virtual void query()=0;
    virtual ~Dao()
    {
    }
protected:
    /*
     * @brief:从数据库连接池中拿出一个可用的连接
     */
    void getAFreeConn()
    {
        //mysqlConn_=
    }

    MySQL* mysqlConn_;
};

class DaoFactory {
public:
    std::shared_ptr<Dao> createDao(DaoType type)
    {
        switch (type) {
        case Login:return std::make_shared<LoginDao>();
        case Upload:return std::make_shared<UploadDao>();
        case DownLoad: return std::make_shared<DownloadDao>();
        }
        return std::shared_ptr<Dao>();
    }

};

class LoginDao : public Dao {
public:
    LoginDao(const char* sql)
    {
    }

    void query()
    {
        //this->getAFreeConn();
    }

    virtual ~LoginDao()
    {

    }
};

class UploadDao : public Dao {
};
class DownloadDao : public Dao {
};
#endif //THEAPP_DAO_H
