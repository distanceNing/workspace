//
// Created by yangning on 17-12-11.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#ifndef THEAPP_FILEMD5_H
#define THEAPP_FILEMD5_H

#include <string>

class FileMd5 {
public:
    FileMd5(const char* file_name):fileName_(file_name)
    {
    }

    FileMd5(const std::string &file_name):fileName_(file_name)
    {

    }
    /*
     * @descriprion: calc file md5 value
     * @param:       file name
     * @return:      return "" open file error  return !="" is file md5 value
     */
    static std::string calcMd5Value(std::string file_name);

    bool calcMd5Value();

    std::string getFileMd5() const
    {
        return fileMd5_;
    }

    ~FileMd5()
    {
    }

private:
    std::string fileName_;
    std::string fileMd5_;
};

#endif //THEAPP_FILEMD5_H
