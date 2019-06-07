/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "multiple.h"
#include <iostream>
#include <iterator>
#include <vector>

multiple::multiple() {}

void multiple::cin() {
  std::cout << "Please, insert two strings: ";

  std::istream_iterator<std::string> eos;            // end-of-stream iterator
  std::istream_iterator<std::string> iit(std::cin);  // stdin iterator

  if (iit != eos) _multiplier = *iit;

  ++iit;
  if (iit != eos) _multiplicand = *iit;
}

void multiple::algorithm() {
  std::vector<unsigned int> v_multiplier;
  std::vector<unsigned int> v_multiplicand;
  unsigned int i, j;
  std::vector<unsigned int> tmp;

  for (i = 0; i < _multiplier.length(); i++) {
    v_multiplier.push_back(_multiplier[_multiplier.length() - i - 1] - '0');
  }
  for (j = 0; j < _multiplicand.length(); j++) {
    v_multiplicand.push_back(_multiplicand[_multiplicand.length() - j - 1] -
                             '0');
  }

  for (i = 0; i < v_multiplier.size(); i++) {
    tmp.clear();
    unsigned int h = 0;
    int self, carry;
    self = carry = 0;
    for (h = 0; h < i; h++) tmp.push_back(0);
    for (j = 0; j < v_multiplicand.size(); j++) {
      self = (v_multiplier[i] * v_multiplicand[j] + carry) % 10;
      carry = (v_multiplier[i] * v_multiplicand[j] + carry) / 10;
      tmp.push_back(self);
      if (j == (v_multiplicand.size() - 1) && (carry > 0)) tmp.push_back(carry);
    }
    if (0 == i) {
      _result = tmp;
    } else {
      if (tmp.size() > _result.size()) {
        unsigned int i;
        for (i = 0; i < tmp.size() - _result.size(); i++) _result.push_back(0);
      }
      unsigned int carry = 0;
      unsigned int self;
      for (unsigned int j = 0; j < tmp.size(); j++) {
        self = (tmp[j] + _result[j] + carry) % 10;
        carry = (tmp[j] + _result[j] + carry) / 10;
        _result[j] = self;
      }
      if (carry > 0) {
        _result.push_back(0);
      }
    }
  }
}

void multiple::display() {
  std::vector<unsigned int>::reverse_iterator rit = _result.rbegin();
  for (; rit != _result.rend(); ++rit) std::cout << *rit;
  std::cout << std::endl;
}

void multiple::execute() {
  this->cin();
  this->algorithm();
  this->display();
}
