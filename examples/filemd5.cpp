#include <vector>
#include <iostream>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>
#include "File.h"
#include "common.h"
using namespace std;
const size_t kMb=1024*1024;

const size_t kNum = 4;

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
    size_t total_read_size=0;
    //static int calc_count=1;
    int64_t start=nowTime();
    while ((read_size = fread(file_buffer, 1, MAX_BUF_SIZE, fp)) > 0) {
        MD5_Update(&ctx, file_buffer, read_size);
        total_read_size+=read_size;

        if(total_read_size ==kMb*kNum )
        {
            total_read_size=0;
            int64_t end=nowTime();
            std::cout<<"pass time : "<<(end-start)/1000<<"  total read size : "<<kNum<<"MB"<<std::endl;
            start=nowTime();
            break;
        }
    }
    unsigned char digest[MD5_DIGEST_LENGTH] = {};
    MD5_Final(digest, &ctx);
    std::ostringstream oss;
    for (unsigned i = 0; i < MD5_DIGEST_LENGTH; i++) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    std::cout<< oss.str().size();
    return oss.str();
}



int main(int argc, char* argv[])
{
    std::string fpath = "/home/roux/下载/";
    std::string fname = "CLion-2017.1.3.tar.gz";  //282MB

    std::cout<<utility::File::calcMd5Value(fpath, fname);

    return 0;
}