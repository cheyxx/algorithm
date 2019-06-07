/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef MULTIPLE_H_
#define MULTIPLE_H_
#include <iostream>
#include <vector>
class multiple {
 public:
  multiple();
  void cin();
  void algorithm();
  void display();
  void execute();

 private:
  std::string _multiplier;
  std::string _multiplicand;
  std::vector<unsigned int> _result;
};

#endif // MULTIPLE_H_