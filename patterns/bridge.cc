
/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "patterns/bridge.h"
#include <iostream>
#include <memory>

void Sony::On() { std::cout << "sony tv on" << std::endl; }

void Sony::Off() { std::cout << "sony tv off" << std::endl; }

void Sony::TuneChannel() { std::cout << "sony tv tuneChannel" << std::endl; }

void RCA::On() { std::cout << "RCA tv on" << std::endl; }

void RCA::Off() { std::cout << "RCA tv off" << std::endl; }

void RCA::TuneChannel() { std::cout << "RCA tv tuneChannel" << std::endl; }

ConcreteRemoteLaser::ConcreteRemoteLaser() {

}

void 
ConcreteRemoteLaser::SetImpl(std::shared_ptr<TV> impl) {
  impl_ = impl;
}

void ConcreteRemoteLaser::On() {
  std::cout << "ConcreteRemoteLaser on" << std::endl;
  impl_->On();
}

void ConcreteRemoteLaser::Off() {
  std::cout << "ConcreteRemoteLaser off" << std::endl;
  impl_->Off();
}

void ConcreteRemoteLaser::SetChannel() {
  std::cout << "ConcreteRemoteLaser setChannel" << std::endl;
  impl_->TuneChannel();
}

ConcreteRemoteInfrareRay::ConcreteRemoteInfrareRay() {

}

void 
ConcreteRemoteInfrareRay::SetImpl(std::shared_ptr<TV> impl) {
  impl_ = impl;
}

void ConcreteRemoteInfrareRay::On() {
  std::cout << "ConcreteRemoteInfrareRay on" << std::endl;
  impl_->On();
}

void ConcreteRemoteInfrareRay::Off() {
  std::cout << "ConcreteRemoteInfrareRay off" << std::endl;
  impl_->On();
}

void ConcreteRemoteInfrareRay::SetChannel() {
  std::cout << "ConcreteRemoteInfrareRay setChannel" << std::endl;
  impl_->TuneChannel();
}
