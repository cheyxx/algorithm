/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "observer.h"
void object::addObserver(abstractObserver &o) {
  std::lock_guard<std::mutex> lck(_mt);
  observers.push_back(std::shared_ptr<abstractObserver>(o.clone()));
}

void object::removeObserver(abstractObserver &o) {
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
