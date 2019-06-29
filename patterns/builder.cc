/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "patterns/builder.h"
#include <iostream>
#include <memory>
#include <string>

void Product::Add(std::string s) { items_.push_back(s); }

void Product::Display() {
  for (auto &v : items_) std::cout << v << std::endl;
}

ConcreteBuilder::ConcreteBuilder(std::shared_ptr<Product> instance) {
  product_ = instance;
}

void Direct::Construct(std::shared_ptr<Builder> builderInstance) {
  builder_ = builderInstance;
  builder_->BuildWheel("wheel");
  builder_->BuildBody("body");
}
