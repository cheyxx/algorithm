/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_PROXY_H_
#define PATTERNS_PROXY_H_
#include <iostream>
#include <memory>

class AbsObject {
 public:
  virtual void RxTxMessage() = 0;
};

class Object : public AbsObject {
 public:
  void RxTxMessage();
};

class Proxy : public AbsObject {
public:
  Proxy(std::shared_ptr<AbsObject> obj);
  void RxTxMessage();
private:
  std::shared_ptr<AbsObject> obj_;
};

#endif  //  PATTERNS_PROXY_H_
