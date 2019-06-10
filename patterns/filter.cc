/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "patterns/filter.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
void rule_impl::action(std::string a) { _s = a; }

std::string rule_impl::get_rule() { return _s; }

void Consumer::add(Consumer::rule_ptr impl) { _impl.push_back(impl); }

void Consumer::remove(Consumer::rule_ptr impl, std::string target) {
  for (std::vector<rule_ptr>::iterator it = _impl.begin(); it != _impl.end();
       it++) {
    if (target == (**it).get_rule()) {
      _impl.erase(it++);
    }
  }
}
std::vector<Consumer::rule_ptr>::iterator Consumer::begin() {
  return _impl.begin();
}
std::vector<Consumer::rule_ptr>::iterator Consumer::end() {
  return _impl.end();
}

std::vector<Consumer::rule_ptr> Consumer::get() { return _impl; }

void Andfilter::rule(std::shared_ptr<rule_impl> rule) { _rule.push_back(rule); }
std::size_t Andfilter::count() { return _Consumers.size(); }

void Andfilter::regulation(std::shared_ptr<Consumer> cs_ptr) {
  std::size_t count = 0;
  for (std::vector<Consumer::rule_ptr>::iterator it = cs_ptr->begin();
       it != cs_ptr->end(); it++) {
    for (std::vector<Consumer::rule_ptr>::iterator rule_it = _rule.begin();
         rule_it != _rule.end(); rule_it++) {
      if ((**rule_it).get_rule() == (**it).get_rule()) {
        count++;
        std::cout << count << std::endl;
      }
    }
  }

  if (_rule.size() == count) _Consumers.push_back(cs_ptr);
}

void Orfilter::rule(std::shared_ptr<rule_impl> rule) { _rule.push_back(rule); }

std::size_t Orfilter::count() { return _Consumers.size(); }

void Orfilter::regulation(std::shared_ptr<Consumer> cs_ptr) {
  bool belong_to = false;
  for (std::vector<Consumer::rule_ptr>::iterator it = cs_ptr->begin();
       it != cs_ptr->end(); it++) {
    for (std::vector<Consumer::rule_ptr>::iterator rule_it = _rule.begin();
         rule_it != _rule.end(); rule_it++) {
      if ((**rule_it).get_rule() == (**it).get_rule()) {
        belong_to = true;
      }
    }
  }
  if (belong_to) _Consumers.push_back(cs_ptr);
}
