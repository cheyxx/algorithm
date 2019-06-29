/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef PATTERNS_BRIDGE_H_
#define PATTERNS_BRIDGE_H_
#include <iostream>
#include <memory>

// pimpl 模式（Private Implementation） 类似于桥接模式，力图把类的具体实现细节对用户隐藏起来，以达到类之间的最小耦合关系

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
  ConcreteRemoteLaser();
  void SetImpl(std::shared_ptr<TV> impl);
  void on();
  void off();
  void setChannel();

 private:
  std::shared_ptr<TV> _impl;
};

class ConcreteRemoteInfrareRay : public RemoteControl {
 public:
  ConcreteRemoteInfrareRay();
  void SetImpl(std::shared_ptr<TV> impl);
  void on();
  void off();
  void setChannel();

 private:
  std::shared_ptr<TV> _impl;
};
#endif  //  PATTERNS_BRIDGE_H_
