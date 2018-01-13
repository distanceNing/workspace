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
#include "headers/common.h"
 namespace utility {
 bool File::calcMd5Value()
 {
     fileMd5_ = calcMd5Value(fileName_);
     return fileMd5_ != "";
 }
 std::string File::calcMd5Value(std::string file_name)
 {
     MD5_CTX ctx;
     MD5_Init(&ctx);

     FILE* fp = fopen(file_name.c_str(), "rb");
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
 }//namespace utility