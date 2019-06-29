/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_COMMAND_H_
#define PATTERNS_COMMAND_H_
#include <iostream>
#include <memory>
namespace cmd {
class Receiver {
 public:
   void Action(){ std::cout << "action !" << std::endl;}
};

class Command
{
public:
 virtual void Execute() = 0;
};

class ConcreteCommand : public Command
{
private:
  std::shared_ptr<Receiver> rev_;
  /* data */
public:
  ConcreteCommand(std::shared_ptr<Receiver> rev);
  ~ConcreteCommand();
  void Execute();
};

class Invoker {
public:
  void SetCommand(std::shared_ptr<Command> cmd);
  void RunCommand();
private:
  std::shared_ptr<Command> cmd_;
};

}  // namespace cmd

#endif  //  PATTERNS_COMMAND_H_
