//
// Created by yangning on 19-1-3.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#ifndef THEAPP_PROCESSMETHOD_H
#define THEAPP_PROCESSMETHOD_H
#include "msg.h"
#include <iostream>
#include <functional>
class  MsgHandleFunc{
public:
    using MsgHandleFun = std::function<bool(Msg* msg)>;

    static MsgHandleFun DiscardHandle;

    static MsgHandleFun DelayHandle ;

    static MsgHandleFun ImmediatelyHandle;
};
class MsgHandle {
public:
    MsgHandle()
    {
    }

    virtual bool process(Msg* msg) = 0;

    ~MsgHandle()
    {
    }

private:
};

class DiscardHandle : public MsgHandle {
public:
    bool process(Msg* msg)
    {
        std::cout << "discard msg\n";
        return true;
    }
};

class DelayHandle : public MsgHandle {
public:
    bool process(Msg* msg)
    {
        std::cout << "Delay Process\n";
        return true;
    }
};

class ImmediatelyHandle : public MsgHandle {
public:
    bool process(Msg* msg)
    {
        std::cout << "Immediately Process\n";
        return true;
    }
};

#endif //THEAPP_PROCESSMETHOD_H
