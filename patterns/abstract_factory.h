/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef PATTERNS_ABSTRACT_FACTORY_H_
#define PATTERNS_ABSTRACT_FACTORY_H_
#include <iostream>
#include <memory>
#include <string>
namespace virtualfactory {
class Car {
 public:
  virtual void Product() = 0;
};

class BenzCar : public Car {
 public:
  void Product();
};

class BMWCar : public Car {
 public:
  void Product();
};

class Motor {
 public:
  virtual void Product() = 0;
};

class BenzMotor : public Motor {
 public:
  void Product();
};

class BMWMotor : public Motor {
 public:
  void Product();
};

class Factory {
 private:
  /* data */
 public:
  virtual std::shared_ptr<Car> CreateCar() = 0;
  virtual std::shared_ptr<Motor> CreateMotor() = 0;
};

class BMWFactory : public Factory {
 private:
  /* data */
 public:
  BMWFactory(/* args */);
  std::shared_ptr<Car> CreateCar();
  std::shared_ptr<Motor> CreateMotor();
  ~BMWFactory();
  std::string s;
};

class BenzFactory : public Factory {
 private:
  /* data */
 public:
  BenzFactory(/* args */);
  std::shared_ptr<Car> CreateCar();
  std::shared_ptr<Motor> CreateMotor();
  ~BenzFactory();
};
}  // namespace virtualfactory
#endif  //  PATTERNS_ABSTRACT_FACTORY_H_
