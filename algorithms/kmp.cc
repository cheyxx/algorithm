/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "algorithms/kmp.h"
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
KMP::KMP(std::string match, std::string original) {
  unsigned int length = match.length();
  original_ = original;
  match_ = match;
  std::shared_ptr<int> p(new int[length], std::default_delete<int[]>());
  next_ = p;
}

void KMP::calculate_next() {
  unsigned int length = match_.length();
  unsigned int cursor = 0;

  int *next = next_.get();
  next[0] = -1;
  int position = -1;
  while (cursor < length - 1) {
    if ((position == -1) || (match_[cursor] == match_[position])) {
      ++cursor;
      ++position;
      next[cursor] = position;
    } else {
      position = next[position];
    }
  }
}

int KMP::algorithm() {
  calculate_next();
  int i = 0;
  std::ostringstream o;
  o.clear();
  int *next = next_.get();
  int length_ = match_.length();
  for (i = 0; i < length_; i++) {
    o << std::to_string(next[i]) + " ";
  }

  std::cout << o.str() << std::endl;
  int o_length = original_.length();
  int m_i = 0;
  int o_i = 0;

  while ((m_i < length_) && (o_i < o_length)) {
    if ((m_i == -1) || (original_[o_i] == match_[m_i])) {
      ++m_i;
      ++o_i;
    } else {
      m_i = next[m_i];
    }
  }
  if (m_i == length_) {
    std::cout << o_i << " " << o_length << " match" << std::endl;
    return o_length - o_i;
  } else {
    std::cout << "don't match" << std::endl;
    return -1;
  }
}
