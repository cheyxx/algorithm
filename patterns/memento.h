/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_MEMENTO_H_
#define PATTERNS_MEMENTO_H_
#include <iostream>
#include <memory>
#include <vector>

/* 备忘录模式用于保存和恢复对象的状态，相信大家看过我前面的拙作就会想到原型模式也能保存一个对象在某一个时刻的状态，
*  那么两者有何不同的呢？原型模式保存的是当前对象的所有状态信息，恢复的时候会生成与保存的对象完全相同的另外一个实例；
*  而备忘录模式保存的是我们关心的在恢复时需要的对象的部分状态信息，相当于快照。备忘录模式大家肯定都见过，
*  比如在玩游戏的时候有一个保存当前闯关的状态的功能，会对当前用户所处的状态进行保存，当用户闯关失败或者需要从
*  快照的地方开始的时候，就能读取当时保存的状态完整地恢复到当时的环境.
*/
#include <iostream>
#include <string>
#include <vector>

class Memento
{
private:
        int Vitality_;
public:
        Memento(){}
        Memento(int Vitality) { this->Vitality_ = Vitality;}
        int GetVitality() const { return this->Vitality_;}
};

class Originator
{
private:
        int Vitality_;
        std::string name_;
public:
        Originator(std::string strName, int iVit): Vitality_(iVit), name_(strName){}
        Memento* SaveState() { return new Memento(Vitality_);}
        void RecoverState(const Memento* Memento){this->Vitality_ = Memento->GetVitality();}
        void SetVitality(int Vit) { this->Vitality_ = Vit;}
        void Show();
};

class CareTaker
{
private:
  std::vector<Memento*> vecStMemento_;
public:
  void AddMemento(Memento* Memento);
  Memento* GetMemento(unsigned int index);
};
#endif  //  PATTERNS_MEMENTO_H_