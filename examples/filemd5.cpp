#include <vector>
#include <iostream>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>
#include "FileMd5.h"
#include "common.h"
using namespace std;
const size_t kMb=1024*1024;

const size_t kNum = 4;


void calcMd5Value(std::string file_name)
{
    static int calc_count=1;
    MD5_CTX ctx;
    MD5_Init(&ctx);

    FILE* fp = fopen(file_name.c_str(), "rb");
    if ( fp == NULL ) {
        perror("fopen");
        //return std::string("");
    }
    char file_buffer[MAX_BUF_SIZE];
    size_t read_size;
    size_t total_read_size=0;
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
}


int main(int argc, char *argv[]) {

    vector<string> const args{"/mnt/hgfs/big_file/en_windows_7_professional_x64_dvd.iso",
                              "/mnt/hgfs/big_file/windows.xp_Service.Pack(SP3).iso",
                              "/mnt/hgfs/big_file/浪潮_bd.mp4"};

    for (auto& fname : args) {
        calcMd5Value(fname);
    }

    /*for (auto& fname : args) {
        FileMd5 file_md5(fname);
        int64_t start=nowTime();
        if ( file_md5.calcMd5Value()) {
            string md5(file_md5.getFileMd5());
            std::cout << fname << " : " << md5 << std::endl;
            std::cout << " md5 hash : " << hashFun(md5) << std::endl;
        }
        else
            std::cout<<"calc md5 fail \n";
        std::cout<<"pass time : "<<(nowTime()-start)/1000<<std::endl;
    }
*/
    return 0;
}
