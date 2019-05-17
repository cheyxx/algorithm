#include "singleton.hh"
static singleton &singleton::getinstance() {
  static singleton single;
  return single;
}