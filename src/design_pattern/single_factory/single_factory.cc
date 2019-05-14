#include "single_factory.hh"
#include<iostream>
SingleFactory::SingleFactory(/* args */)
{
}

Car *SingleFactory::CreateCar(string car)
{
    //Car *car = nullptr;
    if (car == "Benz")
        return new BenzCar();
    else if (car == "BMW")
        return new BMWCar();
    else
        std::cout << "invalid car type" << std::endl;
    return nullptr;
}

SingleFactory::~SingleFactory()
{
}