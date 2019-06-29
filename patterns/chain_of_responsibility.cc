/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/chain_of_responsibility.h"
#include <iostream>
#include <memory>

namespace Chain {

void
Car::SetNext(std::shared_ptr<AbstractChain> abstract) {
  abstract_ = abstract;
}

std::shared_ptr<AbstractChain>
Car::GetNext(){
  return abstract_;
}

void
Car::Product(Consumer c) {
  if(c.wanted() == self_) {
    std::cout << "product " << c.wanted() << std::endl;
  }
  else {
    std::shared_ptr<AbstractChain> next;
    next = GetNext();
    if (next != nullptr) {
      next->Product(c);
    }
  }
}

void
Van::SetNext(std::shared_ptr<AbstractChain> abstract) {
  abstract_ = abstract;
}

std::shared_ptr<AbstractChain>
Van::GetNext(){
  return abstract_;
}

void
Van::Product(Consumer c) {
  if(c.wanted() == self_) {
    std::cout << "product " << c.wanted() << std::endl;
  }
  else {
    std::shared_ptr<AbstractChain> next;
    next = GetNext();
    if (next != nullptr) {
      next->Product(c);
    }
  }
}
}

