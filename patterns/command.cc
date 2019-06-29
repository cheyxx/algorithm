/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/command.h"
#include <iostream>
#include <memory>
namespace cmd {
void 
Invoker::SetCommand(std::shared_ptr<Command> cmd)
{
  cmd_ = cmd;
}

void
Invoker::RunCommand() {
  cmd_->Execute();
}

ConcreteCommand::ConcreteCommand(std::shared_ptr<Receiver> rev)
{
  rev = rev_;
}

ConcreteCommand::~ConcreteCommand()
{
}

void 
ConcreteCommand::Execute() {
  rev_->Action();
}


}  // namespace Command

