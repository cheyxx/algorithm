#include "factory.hh"
#include <iostream>
#include <memory>
namespace factory {
void BenzCar::product() { std::cout << "BenzCar" << std::endl; }
void BMWCar::product() { std::cout << "BMWCar" << std::endl; }
BenzFactory::BenzFactory() {}
BenzFactory::~BenzFactory() {}
BMWFactory::BMWFactory() {}
BMWFactory::~BMWFactory() {}
std::shared_ptr<Car> BenzFactory::CreateCar() {
  return std::shared_ptr<BenzCar>(new BenzCar());
}

std::shared_ptr<Car> BMWFactory::CreateCar() {
  return std::shared_ptr<BMWCar>(new BMWCar());
}
}
