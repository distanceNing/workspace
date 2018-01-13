//
// Created by yangning on 17-12-11.
//
// Descriprion :文件基本操作工具类
//
// Copyright (c) yangning All rights reserved.
//

#ifndef THEAPP_FILE_H
#define THEAPP_FILE_H

#include <string>
namespace utility {
class File {
public:
    File(const char* file_name)
            :fileName_(file_name)
    {
    }

    File(const std::string& file_name)
            :fileName_(file_name)
    {

    }
    /*
     * @brief : calc file md5 value
     * @param : file name
     * @return: return "" open file error  return !="" is file md5 value
     */
    static std::string calcMd5Value(std::string file_name);

    bool calcMd5Value();

    std::string getFileMd5() const
    {
        return fileMd5_;
    }

    ~File()
    {
    }

private:
    std::string fileName_;
    std::string fileMd5_;
};
}//namespace utility
#endif //THEAPP_FILE_H
