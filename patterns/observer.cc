/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "patterns/observer.h"
void object::addObserver(const AbstractObserver &o) {
  std::lock_guard<std::mutex> lck(_mt);
  observers.push_back(std::shared_ptr<AbstractObserver>(o.clone()));
}

void object::removeObserver(const AbstractObserver &o) {
  std::lock_guard<std::mutex> lck(_mt);
  for (observer_list::iterator it = observers.begin(); it != observers.end();
       ++it) {
    if (o.equals(**it)) {
      observers.erase(it);
    }
  }
}

void object::notify(Notification::Ptr pNf) {
  for (observer_list::iterator it = observers.begin(); it != observers.end();
       ++it) {
    (*it)->notify(pNf);
  }
}

void ServiceHander::method(Notification::Ptr pNf) {
  pNf = pNf;
  std::cout << "methed" << std::endl;
}
void ServiceHander::method1(Notification::Ptr pNf) {
  pNf = pNf;
  std::cout << "methed1" << std::endl;
}
