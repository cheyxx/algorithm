/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_STATE_H_
#define PATTERNS_STATE_H_
#include <iostream>
#include <memory>
#include <vector>

class State {
 public:
  virtual void  InsertQuarter() = 0;
  virtual void  EjectQuarter() = 0;
  virtual void  TurnCrank() = 0;
  virtual void  Dispense() = 0;
};

class Context
{
private:
  std::shared_ptr<State> sold_out_state_;
  std::shared_ptr<State> no_quarter_state_;
  std::shared_ptr<State> has_quarter_state_;
  std::shared_ptr<State> sold_state_;
  std::shared_ptr<State> state_;
  int num_;
public:
  Context(int num);
  ~Context();
  void SetState(std::shared_ptr<State> state);
  std::shared_ptr<State> GetSoldOutState() {return sold_out_state_;}
  std::shared_ptr<State> GetNoQuarterState() {return no_quarter_state_;}
  std::shared_ptr<State> GetHasQuarterState() {return has_quarter_state_;}
  std::shared_ptr<State> GetSoldState() {return sold_state_;}
  void ReleaseBall() {
    std::cout << "A gumball comes rolling out the slot ..." << std::endl;
    if (0 != num_) {
    num_ = num_ - 1;
    }
  }
  int GetCount() {return num_;}
  void  InsertQuarter() {
    state_->InsertQuarter();
  }
  void  EjectQuarter(){
    state_->EjectQuarter();
  }
  void  TurnCrank(){
    state_->TurnCrank();
  }
  void  Dispense(){
    state_->Dispense();
  }
};

class NoQuarterState : public State {
 public:
  NoQuarterState( Context *context);
  void  InsertQuarter();
  void  EjectQuarter();
  void  TurnCrank();
  void  Dispense();
private:
  Context* context_;
};

class HasQuarterState : public State {
 public:
  HasQuarterState(Context *context);
  void  InsertQuarter() ;
  void  EjectQuarter() ;
  void  TurnCrank() ;
  void  Dispense() ;
private:
  Context* context_;
};

class SoldState : public State {
 public:
  SoldState( Context *context);
  void  InsertQuarter() ;
  void  EjectQuarter() ;
  void  TurnCrank() ;
  void  Dispense() ;
private:
  Context* context_;
};

class SoldOutState :public State {
 public:
  SoldOutState( Context *context);
  void  InsertQuarter() ;
  void  EjectQuarter() ;
  void  TurnCrank() ;
  void  Dispense() ;
private:
  Context* context_;
};



#endif  //  PATTERNS_STATE_H_
