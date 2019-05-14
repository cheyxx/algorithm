#ifndef FACTORY_HH_
#define FACTORY_HH_
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



class Factory
{
private:
    /* data */
public:
    virtual std::shared_ptr<Car> CreateCar() = 0;
};

class BMWFactory :public Factory
{
private:
    /* data */
public:
    BMWFactory(/* args */);
    std::shared_ptr<Car> CreateCar();
    ~BMWFactory();
};

class BenzFactory : public Factory
{
private:
    /* data */
public:
    BenzFactory(/* args */) ;
    std::shared_ptr<Car> CreateCar();
    ~BenzFactory();
};
}
#endif
