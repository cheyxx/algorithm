/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "reverse_polish_notation.h"
#include <iostream>
#include <stack>


std::string reverse_polish_notation::stack_to_string(std::stack<char> str) {
  std::string result;
  while (!str.empty()) {
    result = str.top() + result;
    str.pop();
  }
  return result;
}
//  逆波兰表达式
std::string reverse_polish_notation::reverse(std::string str) {
  std::stack<char> _stack;
  //临时栈
  std::stack<char> tmp;
  unsigned int i;
  for (i = 0; i < str.length(); i++) {
    char curChar = str[i];

    //  如果遇到的是数字，将数字压入_stack中
    if ((curChar >= '0') &&
        (curChar <= '9')) {
      _stack.push(curChar);
    } else if (curChar == '(') {
      tmp.push(curChar);  //  如果遇到的是左括号，将左括号压入tmp中
    } else if (
        !tmp.empty() &&
        curChar ==
            ')') {
            //  如果遇到的是右括号，将tmp中的运算符一直出栈压入_Stack中，
            //  直到遇到左括号，但是该左括号出tmp却不入_stack；
      while (tmp.top() != '(') {
        _stack.push(tmp.top());
        tmp.pop();
      }
      tmp.pop();
    } else   {  //  如果遇到的是运算符，按照如下规则操作
      if (!tmp.empty()) {   //  如果tmp不为空
        if ((priority(curChar) >=
             priority(
                 tmp.top()))) {
          //  当前遍历到的运算符优先级大于等于tmp栈顶运算符
          tmp.push(curChar);  //  将当前遍历到的运算符压入tmp
        } else {  //  如果tmp不为空，当前遍历到的运算符优先级小于tmp栈顶运算符
        // 将栈顶运算符一直出栈压入_stack中，
        //  直到栈为空或遇到一个运算符优先级小于当前遍历到的运算符，此时将当前遍历到的运算符压入tmp；
          while (!tmp.empty()) {
            if ((priority(curChar) <= priority(tmp.top()))) {
              tmp.push(tmp.top());
              tmp.pop();
            } else {
              break;
            }
          }
          tmp.push(curChar);
        }
      } else {
        tmp.push(curChar);  //  如果tmp为空，将运算符压入tmp中
      }
    }
  }
  while (!tmp.empty()) {
    //  直到遍历完整个中序表达式后，若S2中仍然存在运算符，将这些运算符依次出栈压入_stack，直到tmp为空
    _stack.push(tmp.top());
    tmp.pop();
  }
  return stack_to_string(_stack);
}

//  计算值
int reverse_polish_notation::calculate(std::string S1) {
  std::stack<int> S3;
  unsigned int i;
  for (i = 0; i < S1.length(); i++) {
    char curChar = S1[i];
    int a, b, res;
    if (curChar == '+' || curChar == '-' || curChar == '*' || curChar == '/') {
      b = S3.top();
      S3.pop();
      a = S3.top();
      S3.pop();
      if (curChar == '+')
        res = a + b;
      else if (curChar == '-')
        res = a - b;
      else if (curChar == '*')
        res = a * b;
      else
        res = a / b;

      S3.push(res);
    } else {
      int temp;
      if (!S3.empty()) {
        temp = S3.top();
        temp = static_cast<int>(curChar - '0');
        S3.push(temp);
      } else {
        S3.push(curChar - '0');
      }
    }
  }
  return S3.top();
}

//优先级
int reverse_polish_notation::priority(char c) {
  switch (c) {
    case '+':
      return 1;
      break;
    case '-':
      return 1;
      break;
    case '*':
      return 2;
      break;
    case '/':
      return 2;
      break;
    default:
      return 0;
  }
}

