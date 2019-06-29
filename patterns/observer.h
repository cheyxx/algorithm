/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef PATTERNS_OBSERVER_H_
#define PATTERNS_OBSERVER_H_
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

class Notification {
 public:
  typedef std::shared_ptr<Notification> Ptr;
  void notify();
};

class AbstractObserver {
 public:
  virtual bool equals(const AbstractObserver &observer) const = 0;
  virtual AbstractObserver *clone() const = 0;
  virtual void notify(Notification::Ptr pNf) const = 0;
};

class obserable {
 private:
 public:
  virtual void addObserver(const AbstractObserver &o) = 0;
  virtual void removeObserver(const AbstractObserver &o) = 0;
  virtual void notify(Notification::Ptr pNf) = 0;
};

class object : public obserable {
 public:
  void addObserver(const AbstractObserver &o);
  void removeObserver(const AbstractObserver &o);
  void notify(Notification::Ptr pNf);

 private:
  typedef std::shared_ptr<AbstractObserver> AbstractObserverPtr;
  typedef std::vector<AbstractObserverPtr> observer_list;
  observer_list observers;
  std::mutex _mt;
};

template <class C, class N>
class Observer : public AbstractObserver {
 public:
  typedef std::shared_ptr<N> NotificationPtr;
  bool equals(const AbstractObserver &observer) const {
    const Observer *pObs = dynamic_cast<const Observer *>(&observer);
    return pObs && pObs->_pObject == _pObject && pObs->_method == _method;
  }
  typedef void (C::*Callback)(NotificationPtr);
  Observer(C &object, Callback method) : _pObject(&object), _method(method) {}
  AbstractObserver *clone() const { return new Observer(*this); }

  void notify(Notification::Ptr pNf) const {
    if (_pObject) {
      NotificationPtr pCastNf = std::dynamic_pointer_cast<N>(pNf);
      if (pCastNf != nullptr) {
        (_pObject->*_method)(pCastNf);
      }
    }
  }

 private:
  C *_pObject;
  Callback _method;
};

class ServiceHander {
 public:
  void method(Notification::Ptr pNf);
  void method1(Notification::Ptr pNf);
};

#endif  //  PATTERNS_OBSERVER_H_

