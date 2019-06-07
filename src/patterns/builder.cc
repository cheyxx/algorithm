/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "builder.h"
#include <iostream>
#include <memory>
#include <string>

void product::add(std::string s) { items.push_back(s); }

void product::display() {
  for (auto &v : items) std::cout << v << std::endl;
}

concrete_builder::concrete_builder(std::shared_ptr<product> instance) {
  m_product = instance;
}

void direct::construct(std::shared_ptr<builder> builderInstance) {
  m_builder = builderInstance;
  m_builder->build_wheel("wheel");
  m_builder->build_body("body");
}
