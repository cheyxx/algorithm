
/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "bridge.h"
#include <iostream>
#include <memory>

void Sony::on() { std::cout << "sony tv on" << std::endl; }

void Sony::off() { std::cout << "sony tv off" << std::endl; }

void Sony::tuneChannel() { std::cout << "sony tv tuneChannel" << std::endl; }

void RCA::on() { std::cout << "RCA tv on" << std::endl; }

void RCA::off() { std::cout << "RCA tv off" << std::endl; }

void RCA::tuneChannel() { std::cout << "RCA tv tuneChannel" << std::endl; }

ConcreteRemoteLaser::ConcreteRemoteLaser(std::shared_ptr<TV> impl) {
  _impl = impl;
}

void ConcreteRemoteLaser::on() {
  std::cout << "ConcreteRemoteLaser on" << std::endl;
  _impl->on();
}

void ConcreteRemoteLaser::off() {
  std::cout << "ConcreteRemoteLaser off" << std::endl;
  _impl->on();
}

void ConcreteRemoteLaser::setChannel() {
  std::cout << "ConcreteRemoteLaser setChannel" << std::endl;
  _impl->tuneChannel();
}

ConcreteRemoteInfrareRay::ConcreteRemoteInfrareRay(std::shared_ptr<TV> impl) {
  _impl = impl;
}

void ConcreteRemoteInfrareRay::on() {
  std::cout << "ConcreteRemoteInfrareRay on" << std::endl;
  _impl->on();
}

void ConcreteRemoteInfrareRay::off() {
  std::cout << "ConcreteRemoteInfrareRay off" << std::endl;
  _impl->on();
}

void ConcreteRemoteInfrareRay::setChannel() {
  std::cout << "ConcreteRemoteInfrareRay setChannel" << std::endl;
  _impl->tuneChannel();
}
