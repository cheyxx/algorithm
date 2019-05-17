#ifndef KMP_HH_
#define KMP_HH_
#include <iostream>
#include <memory>
using namespace std;
class KMP {
 public:
  KMP(string match, string original);
  int algorithm();
  void calculate_next();

 private:
  string m_match;
  string m_original;
  std::shared_ptr<int> m_next;
};
#endif
