#include "gtest/gtest.h"
//#define _TESTING
#include <headers/Protocol.h>
#include "producer.h"

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "rapidjson/error/en.h"
#include <map>
#include <string>

#include "consumer.h"
//#define  _CONSUMTER
void printMsgType()
{

    std::cout << "\nAnnounce  Msg : " << Protocol::kAnnounceMsg << "\n";
    std::cout << "\nRemindMsg Msg : " << Protocol::kRemindMsg << "\n";
    std::cout << "\nInfo      Msg : " << Protocol::kInfoMsg << "\n";
}

void printMsgProto()
{
    std::cout << "\nJson : " << Protocol::kJson << "\n";
    std::cout << "\nXml  : " << Protocol::kXml << "\n";
    std::cout << "\nBinProto : " << Protocol::kBinProto << "\n";
}
int main(int argc, char* argv[])
{
#ifdef _TESTING
    //::testing::FLAGS_gtest_color = "yes";
    //::testing::InitGoogleTest(&argc, argv);

#else

    const char* ip = "127.0.0.1";
    uint16_t port = 9000;
#ifdef _CONSUMTER
    //printMsgType();
    Consumer consumer;
    consumer.init(ip,port);

    std::cout<<"Please select the subscription message type :\n ";
    printMsgType();
    int type;
    std::cin>>type;

    if(!consumer.register_node(type)){
        std::cout<<"register_node fail \n";
        return EXIT_FAILURE;
    }else{
        std::cout<<"register_node successful \n";
    }
    while(true){
        consumer.process();
    }

#else

    Producer producer;
    producer.init(ip, port);
    bool is_loop = true;
    while (is_loop) {

        std::cout << "Please select the  message type :\n ";
        printMsgType();
        int type;
        std::cin >> type;
        std::cout << "Please select the  message trans proto :\n ";
        printMsgProto();
        int proto;
        std::cin >>proto;

        std::string content;
        std::cout << "Please select the  message content :\n ";
        std::cin >>content;

        if ( !producer.push_msg(type, proto, content)) {
            std::cout << "push msg fail \n";
            is_loop = false;
        }
    }

#endif
#endif
    return 0;
}
