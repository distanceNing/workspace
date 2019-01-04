//
// Created by yangning on 19-1-2.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#ifndef THEAPP_MSG_H
#define THEAPP_MSG_H
#include <string>
#include <iostream>
//消息传输类型
class MsgProto {
public:
    MsgProto(const std::string& type)
    {
    }

    const std::string& getMsgProto() const
    {
        return msg_type_;
    }

    virtual void encode() = 0;

    virtual void decode() = 0;

protected:
    std::string msg_type_;
};
class XML : public MsgProto {
public:
    XML() :MsgProto("Xml")
    {
    }

    void encode(){
        std::cout<<"Xml 编码\n";
    }

    void decode(){
        std::cout<<"Xml 解码\n";
    }


};
class BinProto : public MsgProto {
public:
    BinProto() :MsgProto("Html")
    {
    }
    void encode(){
        std::cout<<"BinProto 编码\n";
    }

    void decode(){
        std::cout<<"BinProto 解码\n";
    }
};
class JSON : public MsgProto {
public:
    JSON()
            :MsgProto("Json")
    {
    }

    void encode(){
        std::cout<<"Json 编码\n";
    }

    void decode(){
        std::cout<<"Json 解码\n";
    }
};
//消息 MSG
class Msg {
public:
    Msg(const std::string& content):content_(content){
    }
    void msgEncode()
    {
        msg_type_->encode();
    }
    const std::string& getContent()const{
        return content_;
    }

    virtual  void process()=0;

    void setMsgProto(int msg_type);

    std::string packMsg(const std::string& content);


protected:
    MsgProto* msg_type_;
    std::string content_;
};
//通告
class AnnounceMsg : public Msg {
public:
    AnnounceMsg(const std::string& content):Msg(content)
    {}
    void process(){
        std::cout<<"AnnounceMsg \n";
    }


};
//提醒
class RemindMsg : public Msg {
public:
    RemindMsg(const std::string& content):Msg(content)
    {}
    void process(){
        std::cout<<"RemindMsg \n";
    }

};
//信息
class InfoMsg : public Msg {
public:
    InfoMsg(const std::string& content):Msg(content)
    {}
    void process(){
        std::cout<<"InfoMsg \n";
    }
};
#endif //THEAPP_MSG_H
