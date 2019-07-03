/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_FILTER_H_
#define PATTERNS_FILTER_H_
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class rule {
 public:
  virtual void action(std::string a) = 0;
};

class rule_impl : public rule {
 public:
  void action(std::string a);
  std::string get_rule();

 private:
  std::string _s;
};

class Consumer {
 public:
  typedef std::shared_ptr<rule_impl> rule_ptr;
  void add(std::shared_ptr<rule_impl> impl);
  void remove(std::shared_ptr<rule_impl> impl, std::string target);
  std::vector<Consumer::rule_ptr>::iterator begin();
  std::vector<Consumer::rule_ptr>::iterator end();
  std::vector<Consumer::rule_ptr> get();

 private:
  std::vector<rule_ptr> _impl;
};

class filter {
 public:
  virtual void regulation(std::shared_ptr<Consumer> cs_ptr) = 0;
};

class Andfilter : public filter {
 public:
  void regulation(std::shared_ptr<Consumer> cs_ptr);
  void rule(Consumer::rule_ptr rule);
  std::size_t count();

 private:
  typedef std::shared_ptr<Consumer> Consumer_ptr;
  std::vector<Consumer_ptr> _Consumers;
  std::vector<Consumer::rule_ptr> _rule;
};

class Orfilter : public filter {
 public:
  void regulation(std::shared_ptr<Consumer> cs_ptr);
  void rule(std::shared_ptr<rule_impl> rule);
  std::size_t count();

 private:
  typedef std::shared_ptr<Consumer> Consumer_ptr;
  std::vector<Consumer_ptr> _Consumers;
  std::vector<Consumer::rule_ptr> _rule;
};

#endif  //  PATTERNS_FILTER_H_
