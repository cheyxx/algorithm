#ifndef SINGLE_FACTORY_HH_
#define SINGLE_FACTORY_HH_
#include <iostream>

class Car {
 public:
  virtual void product() = 0;
};

class BenzCar : public Car {
 public:
  void product();
};

class BMWCar : public Car {
  {
   public:
    void product();
  };

  class SingleFactory {
   private:
    /* data */
   public:
    SingleFactory(/* args */);
    Car* CreateCar();
    ~SingleFactory();
  };
#endif
