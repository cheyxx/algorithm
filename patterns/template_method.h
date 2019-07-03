/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_TEMPLATE_METHOD_H_
#define PATTERNS_TEMPLATE_METHOD_H_
#include <iostream>
#include <memory>
#include <vector>
namespace temp {
class Person {
 public:
  void Activity() {
      CombHair();
      Drink();
      Sleep();
  }   
  void Sleep() {std::cout << "Going to sleep " << std::endl;}
  void Drink() {std::cout << "Drinking " << std::endl;}
  virtual void CombHair() = 0;
};

class Man : public Person {
public:
  void CombHair();
};


class Woman : public Person {
public:
  void CombHair();
};
}
#endif  //  #define PATTERNS_TEMPLATE_METHOD_H_


