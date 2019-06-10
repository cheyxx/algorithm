/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef ALGORITHMS_MULTIPLE_H_
#define ALGORITHMS_MULTIPLE_H_
#include <string>
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

#endif  //  ALGORITHMS_MULTIPLE_H_
