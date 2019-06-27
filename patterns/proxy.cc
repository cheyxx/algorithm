/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/proxy.h"
#include <iostream>
#include <memory>

void
Object::RxTxMessage() {
  std::cout << "tx msg!" << std::endl;
  std::cout << "rx msg!" << std::endl;
}

Proxy::Proxy(std::shared_ptr<AbsObject> obj) {
  obj_ = obj;
}

void
Proxy::RxTxMessage() {
  std::cout << "encode msg!" << std::endl;
  obj_->RxTxMessage();
  std::cout << "decode msg!" << std::endl;
}