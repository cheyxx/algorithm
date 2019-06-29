/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/single_factory.h"
#include <iostream>
#include <memory>

void BenzCar::Product() { std::cout << "BenzCar" << std::endl; }
void BMWCar::Product() { std::cout << "BMWCar" << std::endl; }

SingleFactory::SingleFactory(/* args */) {}

SingleFactory::~SingleFactory() {}


// 开闭原则（Open Close Principle）: 简单工厂模式不符合开闭原则
// 定义 : 一个软件实体如类,模块和函数应该对扩展开放,对修改关闭,开闭原则也是其他五个原则的基石
std::shared_ptr<Car> SingleFactory::CreateCar(std::string car) {
  // Car *car = nullptr;
  if (car == "Benz")
    return std::shared_ptr<BenzCar>(new BenzCar());
  else if (car == "BMW")
    return std::shared_ptr<BMWCar>(new BMWCar());
  else
    std::cout << "invalid car type" << std::endl;
  return nullptr;
}
