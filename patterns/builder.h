/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef PATTERNS_BUILDER_H_
#define PATTERNS_BUILDER_H_
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Builder {
 public:
  virtual void BuildWheel(std::string wheel) = 0;
  virtual void BuildBody(std::string body) = 0;
};

class Product {
 public:
  void Add(std::string s);
  void Display();

 private:
  std::vector<std::string> items_;
};

class ConcreteBuilder : public Builder {
 public:
  explicit ConcreteBuilder(std::shared_ptr<Product> instance);
  void BuildWheel(std::string wheel) { product_->Add(wheel); }
  void BuildBody(std::string body) { product_->Add(body); }
  std::shared_ptr<Product> GetProduct() { return product_; }

 private:
  std::shared_ptr<Product> product_;
};

class Direct {
 public:
  void Construct(std::shared_ptr<Builder> builderInstance);

 private:
  std::shared_ptr<Builder> builder_;
};
#endif  //  PATTERNS_BUILDER_H_
