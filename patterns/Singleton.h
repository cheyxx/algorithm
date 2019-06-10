/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_SINGLETON_H_
#define PATTERNS_SINGLETON_H_

class Singleton {
 public:
  static Singleton &GetInstance();
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;
  void asString();

 private:
  Singleton() = default;
  ~Singleton() = default;
  // Singleton(const Singleton &assign);
  // Singleton &operator=(Singleton const &copyConstructor);
};

#endif  //  PATTERNS_SINGLETON_H_
