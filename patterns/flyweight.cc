/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/flyweight.h"
#include <iostream>
#include <memory>
#include <string>

UnsharedConcreteFlyWeight::UnsharedConcreteFlyWeight(std::string info) {
  info_ = info;
}
UnsharedConcreteFlyWeight::UnsharedConcreteFlyWeight(
    UnsharedConcreteFlyWeight& w) {
  info_ = w.GetInfo();
}
std::string UnsharedConcreteFlyWeight::GetInfo() { return info_; }
void UnsharedConcreteFlyWeight::SetInfo(std::string info) { info_ = info; }

ConcreteFlyWeight::ConcreteFlyWeight(UnsharedConcreteFlyWeight state) {
  state_ = state;
}

void ConcreteFlyWeight::operation() {
  std::cout << "in state flyweight: FIXED"
            << "\n"
            << "out state flyweight: " << state_.GetInfo() << std::endl;
}

std::shared_ptr<AbstractFlyWeight> FlyWeightFactory::GetFlyWeight(
    UnsharedConcreteFlyWeight OutSideState) {
  std::string key = OutSideState.GetInfo();
  std::map<std::string, flyweightptr>::iterator iter;
  iter = maps_.find(key);
  if (iter != maps_.end()) {
    std::cout << "Find " << key << std::endl;
    return std::shared_ptr<AbstractFlyWeight>(iter->second);
  } else {
    UnsharedConcreteFlyWeight w;
    w.SetInfo(key);
    std::shared_ptr<AbstractFlyWeight> abs =
        std::shared_ptr<ConcreteFlyWeight>(new ConcreteFlyWeight(w));
    maps_.insert(std::map<std::string, flyweightptr>::value_type(key, abs));
    return abs;
  }
}
