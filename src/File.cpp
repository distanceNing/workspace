//
// Created by yangning on 17-12-11.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#include "headers/File.h"
#include "openssl/md5.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "headers/common.h"
 namespace utility {
     bool File::calcMd5Value()
     {
         fileMd5_ = calcMd5Value(filePath_, fileName_);
         return fileMd5_ != "";
     }

     size_t File::getFileSize(const std::string &file_path, const std::string &file_name)
     {
         /*获取文件的大小*/

         std::string file;
         file += file_path;
         file += file_name;
         struct stat filesize;
         const char* pfile = file.c_str();

         if (stat(pfile, &filesize) < 0) {
             return 0;
         }

         return (size_t)filesize.st_size;
     }

     std::string File::calcMd5Value(const std::string &file_path, const std::string &file_name)
     {
         /*计算文件的md5*/
         std::string file;
         file += file_path;
         file += file_name;

         MD5_CTX ctx;
         MD5_Init(&ctx);

         FILE* fp = fopen(file.c_str(), "rb");
         if ( fp == NULL ) {
             perror("fopen");
             return std::string("");
         }
         char file_buffer[MAX_BUF_SIZE];
         size_t read_size;
         while ((read_size = fread(file_buffer, 1, MAX_BUF_SIZE, fp)) > 0) {
             MD5_Update(&ctx, file_buffer, read_size);
         }
         unsigned char digest[MD5_DIGEST_LENGTH] = {};
         MD5_Final(digest, &ctx);
         std::ostringstream oss;
         for (unsigned i = 0; i < MD5_DIGEST_LENGTH; i++) {
             oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
         }
         return oss.str();
     }

     std::string File::calcMd5ValueQuick(const std::string &file_path, const std::string &file_name)
     {
         /*快速计算文件md5(假md5)，用来分块使用*/
         std::string file;
         file += file_path;
         file += file_name;

         MD5_CTX ctx;
         MD5_Init(&ctx);

         FILE* fp = fopen(file.c_str(), "rb");
         if ( fp == NULL ) {
             perror("fopen");
             return std::string("");
         }
         char file_buffer[MAX_BUF_SIZE_QUICK];
         size_t read_size;
         int i = 1;
         while ((read_size = fread(file_buffer, 1, MAX_BUF_SIZE_QUICK, fp)) > 0) {
             if (i == 1 || i == 5 || i == 10 || i == 15) {
                 MD5_Update(&ctx, file_buffer, read_size);
                 if (i == 15) {
                    break;
                 }
             }
             i++;
         }
         unsigned char digest[MD5_DIGEST_LENGTH] = {};
         MD5_Final(digest, &ctx);

         std::ostringstream oss;
         for (unsigned i = 0; i < MD5_DIGEST_LENGTH; i++) {
             oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
         }

         return oss.str();
     }

     int File::chunkSplit(const std::string &file_path, const std::string &file_name)
     {
         /*文件分块并命名*/
         std::string filefakemd5 = File::calcMd5ValueQuick(file_path, file_name);

         std::string file;
         file += file_path;
         file += file_name;

         std::string chunk_name;

         MD5_CTX ctx;
         MD5_Init(&ctx);

         FILE* fp = fopen(file.c_str(), "rb");
         if ( fp == NULL ) {
             perror("fopen");
             return FALSE;
         }

         char file_buffer[MAX_BUF_SIZE];
         size_t read_size;
         unsigned long count = 1;
         std::string number;
         CHUNK filechunk;

         while ((read_size = fread(file_buffer, 1, MAX_BUF_SIZE, fp)) > 0) {
             MD5_Update(&ctx, file_buffer, read_size);
             unsigned char digest[MD5_DIGEST_LENGTH] = {};
             MD5_Final(digest, &ctx);

             std::ostringstream oss;
             for (unsigned i = 0; i < MD5_DIGEST_LENGTH; i++) {
                 oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
             }

             /*文件块的信息，再发送的时候提取使用*/
             filechunk.chunkmd5 = oss.str();
             filechunk.chunknum = count;

             std::ostringstream str;
             str<<count;
             number = str.str();
             chunk_name += filefakemd5;
             chunk_name += number;
             std::cout<<chunk_name<<std::endl;

             //std::cout<<oss.str()<<"                 "<<count<<std::endl;
             count++;
             chunk_name = "";
         }
         return TRUE;
     }
 }//namespace utility