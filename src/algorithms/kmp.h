/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef KMP_H_
#define KMP_H_
#include <iostream>
#include <memory>
#include <string>
class KMP {
 public:
  KMP(std::string match, std::string original);
  int algorithm();
  void calculate_next();

 private:
  std::string match_;
  std::string original_;
  std::shared_ptr<int> next_;
};
#endif  // KMP_H_
