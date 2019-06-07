/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef BUILDER_H_
#define BUILDER_H_
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class builder {
 public:
  virtual void build_wheel(std::string a_wheel) = 0;
  virtual void build_body(std::string a_body) = 0;
};

class product {
 public:
  void add(std::string s);
  void display();

 private:
  std::vector<std::string> items;
};

class concrete_builder : public builder {
 public:
  concrete_builder(std::shared_ptr<product> instance);
  void build_wheel(std::string a_wheel) { m_product->add(a_wheel); }
  void build_body(std::string a_body) { m_product->add(a_body); }
  std::shared_ptr<product> get_product() { return m_product; }

 private:
  std::shared_ptr<product> m_product;
};

class direct {
 public:
  void construct(std::shared_ptr<builder> builderInstance);

 private:
  std::shared_ptr<builder> m_builder;
};
#endif  // BUILDER_H_
