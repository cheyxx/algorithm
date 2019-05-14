#include "virtual_factory.hh"
#include <iostream>
#include <memory>
namespace virtualfactory
{
void BenzCar::product()
{
    std::cout << "BenzCar" << std::endl;
}
void BMWCar::product()
{
    std::cout << "BMWCar" << std::endl;
}

void BenzMotor::product()
{
    std::cout << "BenzMotor" << std::endl;
}
void BMWMotor::product()
{
    std::cout << "BMWMotor" << std::endl;
}

BenzFactory::BenzFactory()
{
}
BenzFactory::~BenzFactory()
{
}
BMWFactory::BMWFactory()
{
}
BMWFactory::~BMWFactory()
{
}
std::shared_ptr<Car> BenzFactory::CreateCar()
{
    return std::shared_ptr<BenzCar>(new BenzCar());
}

std::shared_ptr<Car> BMWFactory::CreateCar()
{
    return std::shared_ptr<BMWCar>(new BMWCar());
}

std::shared_ptr<Motor> BenzFactory::CreateMotor()
{
    return std::shared_ptr<BenzMotor>(new BenzMotor());
}

std::shared_ptr<Motor> BMWFactory::CreateMotor()
{
    return std::shared_ptr<BMWMotor>(new BMWMotor());
}
} // namespace virtualfactory
