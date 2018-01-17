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

#define FALSE 0
#define  TRUE 1

#define MAX_BUF_SIZE_QUICK 1024

typedef struct chunk
{
    /*存放每个文件块的信息*/
    std::string chunkmd5;
    unsigned long chunknum;
}CHUNK;

namespace utility {
class File {
public:
    File(const char* file_path, const char* file_name)
            :filePath_(file_path),fileName_(file_name)
    {
    }

    /*
     * @brief : calc file md5 value
     * @param : file name and path
     * @return: return "" open file error  return !="" is file md5 value
     */
    static std::string calcMd5Value(const std::string &file_path, const std::string &file_name);

    static int chunkSplit(const std::string &file_path, const std::string &file_name);

    static std::string calcMd5ValueQuick(const std::string &file_path, const std::string &file_name);

    static size_t getFileSize(const std::string &file_path, const std::string &file_name);

    bool calcMd5Value();

    std::string getFileMd5() const
    {
        return fileMd5_;
    }

    ~File()
    {
    }

private:
    std::string filePath_;
    std::string fileName_;
    std::string fileMd5_;
};
}//namespace utility

#endif //THEAPP_FILE_H
