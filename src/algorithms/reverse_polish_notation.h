/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef REVERSE_POLISH_NOTATION_H_
#define REVERSE_POLISH_NOTATION_H_
#include <iostream>
#include <stack>
/*
* std::string original_expression = "9+(1+9*6)*2";
* std::string processed_xpression = r.reverse(original_expression);
* int results = r.calculate(processed_xpression);
* std::cout << results << std::endl;
*/
class reverse_polish_notation {
 public:
  reverse_polish_notation(){};
  ~reverse_polish_notation(){};
  std::string stack_to_string(std::stack<char> str);
  std::string reverse(std::string str);
  int calculate(std::string S1);
  int priority(char c);

 private:
  std::stack<char> _stack;
};
#endif // REVERSE_POLISH_NOTATION_H_
