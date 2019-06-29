/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_CHAIN_OF_RESPONSIBILITY_H_
#define PATTERNS_CHAIN_OF_RESPONSIBILITY_H_
#include <iostream>
#include <memory>

namespace Chain {

class Consumer {
public:
    Consumer(std::string wanted) {wanted_ = wanted;}
    std::string wanted() {return wanted_;}
private:
std::string wanted_;
};

class AbstractChain {
 public:
  virtual void SetNext(std::shared_ptr<AbstractChain> abstract) = 0;
  virtual std::shared_ptr<AbstractChain> GetNext() = 0;
  virtual void Product(Consumer c) = 0;
};

class Car : public AbstractChain {
 public:
  Car(): self_("Car"){};
  void SetNext(std::shared_ptr<AbstractChain> abstract);
  std::shared_ptr<AbstractChain> GetNext();
  void Product(Consumer c);
private:
  std::string self_;
  std::shared_ptr<AbstractChain> abstract_;
};

class Van : public AbstractChain {
 public:
 Van(): self_("Van"){};
  void SetNext(std::shared_ptr<AbstractChain> abstract);
  std::shared_ptr<AbstractChain> GetNext();
  void Product(Consumer c);
private:
  std::string self_;
  std::shared_ptr<AbstractChain> abstract_;
};
}
#endif  //  PATTERNS_CHAIN_OF_RESPONSIBILITY_H_
