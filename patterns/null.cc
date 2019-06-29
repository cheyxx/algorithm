/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/null.h"
#include <iostream>
#include <memory>

Customer::Customer(std::string name) {
  name_ = name; 
}

std::string
Customer::GetName() {
  return name_;
}

bool
Customer::isNull() {
  return false;
}

std::string
NullCustomer::GetName() {
  return "Not An Available Name !";
}

bool
NullCustomer::isNull() {
  return true;
}


std::shared_ptr<AbstractCustomer>
CustomerFactory::GetCustomer(std::string name) {
  for(size_t i=0;i<data_base_.size();i++) {
    if (data_base_[i] == name) {
      return std::shared_ptr<Customer>(new Customer(name));
    }
  }
  return std::shared_ptr<NullCustomer>(new NullCustomer);
}