/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_NULL_H_
#define PATTERNS_NULL_H_
#include <iostream>
#include <memory>
#include <vector>

class AbstractCustomer {
 public:
  virtual std::string GetName() = 0;
  virtual bool isNull() = 0;
};

class Customer : public AbstractCustomer {
public:
    Customer(std::string name);
    std::string GetName();
    bool isNull();
private:
    std::string name_;
};

class NullCustomer : public AbstractCustomer{
public:
    std::string GetName();
    bool isNull();

};

class CustomerFactory {
private:
  std::vector<std::string> data_base_ = {"bob", "tom"};
public:
  std::shared_ptr<AbstractCustomer> GetCustomer(std::string name);
};

#endif  //  PATTERNS_NULL_H_
