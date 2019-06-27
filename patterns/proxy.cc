/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/proxy.h"
#include <iostream>
#include <memory>
void
SubSystemOne::operation() {
  std::cout << "SubSystemOne::operation" << std::endl;
}

void
SubSystemTwo::operation() {
  std::cout << "SubSystemTwo::operation" << std::endl;
}

Facade::Facade() {
    s1 = std::shared_ptr<SubSystemOne>(new SubSystemOne);
    s2 = std::shared_ptr<SubSystemTwo>(new SubSystemTwo);
}

Facade::~Facade() {
}

void
Facade::operation() {
    s1->operation();
    s2->operation();
}
