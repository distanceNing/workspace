#ifndef INCLUDE_ZLIB_WRAPPER_H_
#define INCLUDE_ZLIB_WRAPPER_H_
#include <vector>
#include "zlib.h"
#define _DEF_STRING(x) #x
#define DEF_TO_STRING(x) _DEF_STRING(x)
#define SOURCE_AT __FILE__ ":" DEF_TO_STRING(__LINE__)
#define ERROR_STR(msg) std::string(SOURCE_AT ":").append(msg)
#define throw_except_if_msg(except,expression,msg) \
    if(expression)\
        throw except(ERROR_STR(msg));
#define _CAS_ERROR_MSG_(ERR) case ERR:return #ERR;
/*
 * ��sting��ʽ���ش�����Ϣ
 */
inline std::string zlib_error_message(int err){
    switch(err){
    _CAS_ERROR_MSG_(Z_OK)
    _CAS_ERROR_MSG_(Z_MEM_ERROR)
    _CAS_ERROR_MSG_(Z_BUF_ERROR)
    _CAS_ERROR_MSG_(Z_STREAM_ERROR)
    };
    return "unknow error";
}
#undef _CAS_ERROR_MSG_
/* zlib�쳣�� */
class zlib_exception:public std::logic_error{
    // �̳л��๹�캯��
    using std::logic_error::logic_error;
};
/*
 * ����zlibѹ������
 */
inline std::vector<uint8_t> zlib_mem_compress (const void *source, size_t sourceLen){
    throw_if(nullptr==source||0==sourceLen)
    std::vector<uint8_t> buffer(compressBound(sourceLen));
    auto destLen=uLongf(buffer.size());
    auto err=compress(buffer.data(),&destLen,reinterpret_cast<const Bytef *>(source),uLong(sourceLen));
    throw_except_if_msg(zlib_exception,err!=Z_OK,zlib_error_message(err))
    return std::vector<uint8_t>(buffer.data(),buffer.data()+destLen);
}
/*
 * ����zlibѹ����������
 */
inline std::vector<uint8_t> zlib_mem_compress (const std::string &source){
    return zlib_mem_compress(source.data(),source.size());
}
/*
 * ����zlibѹ������
 */
template<typename T>
inline std::vector<uint8_t> zlib_mem_compress (const std::vector<T> &source){
    return zlib_mem_compress(source.data(),source.size()*sizeof(T));
}
/*
 * ����zlibѹ����������
 */
template<typename T>
inline  typename std::enable_if<std::is_class<T>::value,std::vector<uint8_t>>::type
compress_obj (const T &source){
    return zlib_mem_compress(std::addressof(source),sizeof(T));
}

/*
 * ����zlib��ѹ������
 * uncompress_boundΪѹ��ǰ�����ݳ���,�����֪������Դ��������Ϊ0
 * */
inline std::vector<uint8_t> zlib_mem_uncompress (const void *source, size_t sourceLen,size_t uncompress_bound=0){
    throw_if(nullptr==source||0==sourceLen)
    //uncompress_boundΪ0ʱ������������ΪsourceLen��8������
    if (!uncompress_bound)
        uncompress_bound = sourceLen << 3;  
    for(;;){        
        std::vector<uint8_t> buffer(uncompress_bound);
        auto destLen=uLongf(buffer.size());
        auto err=uncompress(buffer.data(),&destLen,reinterpret_cast<const Bytef *>(source),uLong(sourceLen));
        if(Z_OK==err)
            return std::vector<uint8_t>(buffer.data(),buffer.data()+destLen);
        else if(Z_BUF_ERROR==err){
            // ����������
            uncompress_bound<<=2;// �������Ŵ�4���ٳ���
            continue;
        }
        // ���������׳��쳣
        throw zlib_exception(zlib_error_message(err));
    }
}
/*
 * ����zlib��ѹ������
 * */
inline std::string zlib_mem_uncompress (const std::string &source,size_t uncompress_bound=0){
    auto un_data=zlib_mem_uncompress(source.data(),source.size(),uncompress_bound);
    return std::string((char*)un_data.data(),un_data.size());
}
/*
 * ����zlib��ѹ������
 * */
inline void zlib_mem_uncompress (void *dest,size_t *destLen,const void *source, size_t sourceLen){
    throw_if(nullptr==source||0==sourceLen||nullptr==dest||nullptr==destLen||0==*destLen)
    auto len=uLongf(*destLen);
    auto err=uncompress(reinterpret_cast<Bytef *>(dest),&len,reinterpret_cast<const Bytef *>(source),uLong(sourceLen));
    *destLen=size_t(len);
    throw_except_if_msg(zlib_exception,err!=Z_OK,zlib_error_message(err))
}
/*
 * ��ѹ�����ݵ�����
 */
template<typename T>
inline typename std::enable_if<std::is_class<T>::value>::type
uncompress_obj (T &dest,const void *source, size_t sourceLen){
    auto destLen=sizeof(T);
    zlib_mem_uncompress(std::addressof(dest),&destLen,source,sourceLen);
}
#endif /* INCLUDE_ZLIB_WRAPPER_H_ */