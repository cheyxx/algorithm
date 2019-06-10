/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/single_factory.h"
#include <iostream>
#include <memory>

void BenzCar::product() { std::cout << "BenzCar" << std::endl; }
void BMWCar::product() { std::cout << "BMWCar" << std::endl; }

SingleFactory::SingleFactory(/* args */) {}

SingleFactory::~SingleFactory() {}

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
