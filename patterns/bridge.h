/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef PATTERNS_BRIDGE_H_
#define PATTERNS_BRIDGE_H_
#include <iostream>
#include <memory>

// pimpl 模式（Private Implementation） 类似于桥接模式，力图把类的具体实现细节对用户隐藏起来，以达到类之间的最小耦合关系

class TV {
 public:
  virtual void On() = 0;
  virtual void Off() = 0;
  virtual void TuneChannel() = 0;
};

class Sony : public TV {
 public:
  void On();
  void Off();
  void TuneChannel();
};

class RCA : public TV {
 public:
  void On();
  void Off();
  void TuneChannel();
};

class RemoteControl {
 public:
  virtual void On() = 0;
  virtual void Off() = 0;
  virtual void SetChannel() = 0;
};

class ConcreteRemoteLaser : public RemoteControl {
 public:
  ConcreteRemoteLaser();
  void SetImpl(std::shared_ptr<TV> impl);
  void On();
  void Off();
  void SetChannel();

 private:
  std::shared_ptr<TV> impl_;
};

class ConcreteRemoteInfrareRay : public RemoteControl {
 public:
  ConcreteRemoteInfrareRay();
  void SetImpl(std::shared_ptr<TV> impl);
  void On();
  void Off();
  void SetChannel();

 private:
  std::shared_ptr<TV> impl_;
};
#endif  //  PATTERNS_BRIDGE_H_
