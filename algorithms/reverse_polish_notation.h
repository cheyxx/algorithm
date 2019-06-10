/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef ALGORITHMS_REVERSE_POLISH_NOTATION_H_
#define ALGORITHMS_REVERSE_POLISH_NOTATION_H_
#include <iostream>
#include <stack>
#include <string>

#if 0
  std::string original_expression = "9+(1+9*6)*2";
  std::string processed_xpression = r.reverse(original_expression);
  int results = r.calculate(processed_xpression);
  std::cout << results << std::endl;
#endif
class reverse_polish_notation {
 public:
  std::string stack_to_string(std::stack<char> str);
  std::string reverse(std::string str);
  int calculate(std::string S1);
  int priority(char c);

 private:
  std::stack<char> _stack;
};
#endif  //  ALGORITHMS_REVERSE_POLISH_NOTATION_H_

