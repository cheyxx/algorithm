/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/memento.h"
#include <iostream>
#include <memory>

void 
Originator::Show() {
  std::cout<< "Name: "<< name_ << std::endl;
  std::cout<< "Live: "<< Vitality_ << std::endl;
}

void 
CareTaker::AddMemento(Memento* Memento) {
  vecStMemento_.push_back(Memento);
}

Memento*
CareTaker::GetMemento(unsigned int index) {
  if (index >= vecStMemento_.size()) {
      return nullptr;
  }
 else {
      return vecStMemento_[index];
 }
}
