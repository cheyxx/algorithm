/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_INTERPRETER_H_
#define PATTERNS_INTERPRETER_H_

#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "String.h"
namespace interpreter {
class Context
{
private:
  size_t index_ = -1;
  std::vector<std::string> tokens_;
  std::string currentToken_;
public:
  Context(std::string text);
  std::string NextToken();
  std::string GetCurrentToken() { return currentToken_; }
  void SkipToken(std::string token);
  int GetCurrentNumber();
};

class Node
{
public:
 virtual void Interpret(Context *context) = 0;
 virtual void Execute() = 0;
};


 class LoopCommand :public Node
{
private:
 int number_;
 Node* commandNode_;
public:
    void Interpret(Context *context);
    void Execute() ;
};

class PrimitiveCommand :public Node
{
private:
 std::string name_;
 std::string text_;
public:
  void Interpret(Context *context);
  void Execute();
};

class CommandNode : public  Node
{
private:
  Node* node_ptr;
public:
  void Interpret(Context *context);
  void Execute();
};

class ExpressionNode : public Node
{
private:
  std::vector<Node*> nodeList_;
public:
  void Interpret(Context *context) ;
  void Execute() ;
  ~ExpressionNode();
};
}

#endif  //  PATTERNS_SINGLETON_H_
