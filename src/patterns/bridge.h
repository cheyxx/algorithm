/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef BRIDE_H_
#define BRIDE_H_
#include <iostream>
#include <memory>

class TV {
 public:
  virtual void on() = 0;
  virtual void off() = 0;
  virtual void tuneChannel() = 0;
};

class Sony : public TV {
 public:
  void on();
  void off();
  void tuneChannel();
};

class RCA : public TV {
 public:
  void on();
  void off();
  void tuneChannel();
};

class RemoteControl {
 public:
  virtual void on() = 0;
  virtual void off() = 0;
  virtual void setChannel() = 0;
};

class ConcreteRemoteLaser : public RemoteControl {
 public:
  ConcreteRemoteLaser(std::shared_ptr<TV> impl);
  void on();
  void off();
  void setChannel();

 private:
  std::shared_ptr<TV> _impl;
};

class ConcreteRemoteInfrareRay : public RemoteControl {
 public:
  ConcreteRemoteInfrareRay(std::shared_ptr<TV> impl);
  void on();
  void off();
  void setChannel();

 private:
  std::shared_ptr<TV> _impl;
};
#endif // BRIDGE_H_