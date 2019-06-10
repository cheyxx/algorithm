/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_FACTORY_H_
#define PATTERNS_FACTORY_H_
#include <iostream>
#include <memory>
namespace factory {
class Car {
 public:
  virtual void product() = 0;
};

class BenzCar : public Car {
 public:
  void product();
};

class BMWCar : public Car {
 public:
  void product();
};

class Factory {
 private:
  /* data */
 public:
  virtual std::shared_ptr<Car> CreateCar() = 0;
};

class BMWFactory : public Factory {
 private:
  /* data */
 public:
  BMWFactory(/* args */);
  std::shared_ptr<Car> CreateCar();
  ~BMWFactory();
};

class BenzFactory : public Factory {
 private:
  /* data */
 public:
  BenzFactory(/* args */);
  std::shared_ptr<Car> CreateCar();
  ~BenzFactory();
};
}  // namespace factory

#endif  //  PATTERNS_FACTORY_H_
