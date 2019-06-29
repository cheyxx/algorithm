/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "patterns/strategy.h"
#include <iostream>
#include <memory>

void
Character::Fight() {
std::cout << "Fight" << std::endl;
}

void Queen::Fight() {
  std::shared_ptr<WeaponBehavior> w;
  w = getWeapon();
  w->UseWeapon();
}

void King::Fight() {
  std::shared_ptr<WeaponBehavior> w;
  w = getWeapon();
  w->UseWeapon();
}

void Troll::Fight() {
  std::shared_ptr<WeaponBehavior> w;
  w = getWeapon();
  w->UseWeapon();
}

void Knight::Fight() {
  std::shared_ptr<WeaponBehavior> w;
  w = getWeapon();
  w->UseWeapon();
}

Character::Character() {}

Character::~Character() {}
void Character::setWeapon(std::shared_ptr<WeaponBehavior> w) { weapon = w; }

std::shared_ptr<WeaponBehavior> Character::getWeapon() { return weapon; }

void KnifeBehavior::UseWeapon() {
  std::cout << "use KnifeBehavior" << std::endl;
}
void BowAndArrowBehavior::UseWeapon() {
  std::cout << "use BowAndArrowBehavior" << std::endl;
}
void AxeBehavior::UseWeapon() { std::cout << "use AxeBehavior" << std::endl; }

