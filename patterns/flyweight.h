/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_FLYWEIGHT_H_
#define PATTERNS_FLYWEIGHT_H_
#include <iostream>
#include <map>
#include <memory>

class UnsharedConcreteFlyWeight {
 public:
  UnsharedConcreteFlyWeight(){};
  explicit UnsharedConcreteFlyWeight(std::string info);
  UnsharedConcreteFlyWeight(UnsharedConcreteFlyWeight& w);
  std::string GetInfo();
  void SetInfo(std::string info);

 private:
  std::string info_;
};

class AbstractFlyWeight {
 public:
  virtual void operation() = 0;
};

class ConcreteFlyWeight : public AbstractFlyWeight {
 public:
  ConcreteFlyWeight(){};
  explicit ConcreteFlyWeight(UnsharedConcreteFlyWeight state);
  void operation();
  ~ConcreteFlyWeight(){};

 private:
  UnsharedConcreteFlyWeight state_;
};

class FlyWeightFactory {
 public:
  std::shared_ptr<AbstractFlyWeight> GetFlyWeight(
      UnsharedConcreteFlyWeight OutSideState);

 private:
  typedef std::shared_ptr<AbstractFlyWeight> flyweightptr;
  std::map<std::string, flyweightptr> maps_;
};

#endif  //  PATTERNS_FLYWEIGHT_H_
