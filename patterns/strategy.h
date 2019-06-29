/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_STRATEGY_H_
#define PATTERNS_STRATEGY_H_
#include <iostream>
#include <memory>

class WeaponBehavior {
 public:
  virtual void UseWeapon() = 0;
};

class KnifeBehavior : public WeaponBehavior {
 public:
  void UseWeapon();
};

class Character {
 private:
  std::shared_ptr<WeaponBehavior> weapon;

 public:
  Character();
  ~Character();
  void setWeapon(std::shared_ptr<WeaponBehavior> w);
  std::shared_ptr<WeaponBehavior> getWeapon();
  virtual void Fight();
};

class Queen : public Character {
 public:
  void Fight();
};

class King : public Character {
 public:
  void Fight();
};

class Troll : public Character {
 public:
  void Fight();
};

class Knight : public Character {
 public:
  void Fight();
};

class BowAndArrowBehavior : public WeaponBehavior {
 public:
  void UseWeapon();
};
class AxeBehavior : public WeaponBehavior {
 public:
  void UseWeapon();
};

#endif  //  PATTERNS_STRATEGY_H_
