//
// Created by yangning on 19-1-3.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#include "ProcessMethod.h"
MsgHandleFunc::DiscardHandle = [](Msg* msg) {
  std::cout << "discard msg\n";
  return true;
};


MsgHandleFunc::DelayHandle = [](Msg* msg) {
  std::cout << "Delay Handle\n";
  return true;
};


MsgHandleFunc::ImmediatelyHandle = [](Msg* msg) {
  std::cout << "Immediately Handle\n";
  return true;
};