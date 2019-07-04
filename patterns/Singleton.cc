/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/Singleton.h"
#include <iostream>
Singleton &Singleton::GetInstance() {
  static Singleton instance;
  return instance;
}

/*
template <class T>
class Singleton
{
public:
    static T* Instance()
    {
        return instance;
    }
    static T* getInstance()
    {
        return instance;
    }

protected:
    Singleton() // 构造函数声明为 protected， 只有子类才能构造。 
    {
        if( 0 != instance )
            throw std::exception;

        instance = static_cast<T *>(this);
    }
    virtual ~Singleton()
    {
        instance = 0;
    }

private:
    static T   *instance;
};

template <class T>
T* Singleton<T>::instance = 0;
#endif
*/
