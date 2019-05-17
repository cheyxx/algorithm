#ifndef SINGLETON_HH_
#define SINGLETON_HH_
#include <iostream>
class singleton {
 public:
  static singleton& getinstance();
  singleton(const singleton& s) = delete;
  singleton& operator=(const singleton& s) = delete;

 private:
  singleton() = default;
  ~singleton() = default;
};
#endif
