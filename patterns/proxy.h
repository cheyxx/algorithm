/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_PROXY_H_
#define PATTERNS_PROXY_H_
#include <iostream>
#include <memory>

class SubSystem {
 public:
  virtual void operation() = 0;
};

class SubSystemOne : public SubSystem {
 public:
  void operation();
};

class SubSystemTwo : public SubSystem {
 public:
  void operation();
};



class Facade : public SubSystem {
 private:
  /* data */
  std::shared_ptr<SubSystem> s1;
  std::shared_ptr<SubSystem> s2;
 public:
 void operation();
  Facade();
  ~Facade();
};

#endif  //  PATTERNS_PROXY_H_
