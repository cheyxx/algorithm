/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "algorithms/pid.h"
#include <iostream>

pid::pid(double kp, double ki, double kd, double currError, double deviation) {
  _prevError = 0;
  _kp = kp;
  _ki = ki;
  _kd = kd;
  _currError = currError;
  _deviation = deviation;
  _integral = 0;
  _differential = 0;
  _total = 0.2;
  _u = 0;
}

void pid::iterater() {
  _prevError = _currError;
  _integral = _integral + _currError;
  std::cout << _integral << std::endl;
  _u = _kp * _currError + _ki * _integral + _kd * _differential;
  std::cout << _kp << " " << _ki << " " << _kd << " " << _u << std::endl;
  _total = _total + _u;
  _total = _total - _deviation;  //稳态误差
  std::cout << _total << " " << _integral << " " << std::endl;
  _currError = (1 - _total);
  _differential = _currError - _prevError;
  std::cout << "error " << _currError << " total " << _total + _deviation
            << std::endl;
}
void pid::loop(int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    iterater();
  }
}
