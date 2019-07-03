/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/state.h"
#include <iostream>
#include <memory>
#include <vector>

SoldOutState::SoldOutState(Context *context) {
  context_ = context;
}

void 
SoldOutState::InsertQuarter() {
  std::cout << "You can't insert a quarter, the machine is sold out" << std::endl;
}

void
SoldOutState::EjectQuarter() {
  std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl;

}

void
SoldOutState::TurnCrank() {
  std::cout << "You turned, but there are no gumballs" << std::endl;
}

void
SoldOutState::Dispense() {
   std::cout << "No gumball dispense" << std::endl;
}


NoQuarterState::NoQuarterState(Context *context) {
  context_ = context;
}

void
NoQuarterState::InsertQuarter() {
  std::cout << "You inserted a quarter" << std::endl;
  context_->SetState(context_->GetHasQuarterState());
}

void
NoQuarterState::EjectQuarter() {
  std::cout << "You haven't inserted a quarter" << std::endl;
}

void
NoQuarterState::TurnCrank() {
  std::cout << "You turned, but haven't inserted a quarter" << std::endl;
}

void
NoQuarterState::Dispense() {
  std::cout << "You need to play first" << std::endl;
}

HasQuarterState::HasQuarterState(Context *context) {
  context_ = context;
}

void
HasQuarterState::InsertQuarter() {
  std::cout << "You can't insert  another quarter" << std::endl;
}

void
HasQuarterState::EjectQuarter() {
  std::cout << "Quarter return" << std::endl;
  context_->SetState(context_->GetNoQuarterState());
}

void
HasQuarterState::TurnCrank() {
  std::cout << "You turned..." << std::endl;
  context_->SetState(context_->GetSoldState());
}

void
HasQuarterState::Dispense() {
  std::cout << "No quarter dispense" << std::endl;
}


SoldState::SoldState(Context *context) {
  context_ = context;
}

void
SoldState::InsertQuarter() {
  std::cout << "Please wait, we're already giving you a gumball" << std::endl;
}

void
SoldState::EjectQuarter() {
  std::cout << "Sorry , you already turned the crank" << std::endl;

}

void
SoldState::TurnCrank() {
  std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
}

void
SoldState::Dispense() {
  context_->ReleaseBall();
  if (context_->GetCount() > 0) {
    context_->SetState(context_->GetNoQuarterState());
  }
  else {
    std::cout << "No quarter dispense" << std::endl;
    context_->SetState(context_->GetSoldOutState());
  }
}

Context::Context(int num) {
  num_ = num;
  sold_out_state_ = std::shared_ptr<State>(new SoldOutState(this));
  no_quarter_state_ = std::shared_ptr<State>(new NoQuarterState(this));
  sold_state_ = std::shared_ptr<State>(new SoldState(this));
  has_quarter_state_ = std::shared_ptr<State>(new HasQuarterState(this));
  state_ = no_quarter_state_;
  
}

Context::~Context()
{
}

void
Context::SetState(std::shared_ptr<State> state) {
  state_ = state;
}