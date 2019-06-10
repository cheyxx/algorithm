/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "patterns/strategy.h"
#include <iostream>
#include <memory>

void
Character::fight() {
std::cout << "fight" << std::endl;
}

void Queen::fight() {
  std::shared_ptr<WeaponBehavior> w;
  w = getWeapon();
  w->useWeapon();
}

void King::fight() {
  std::shared_ptr<WeaponBehavior> w;
  w = getWeapon();
  w->useWeapon();
}

void Troll::fight() {
  std::shared_ptr<WeaponBehavior> w;
  w = getWeapon();
  w->useWeapon();
}

void Knight::fight() {
  std::shared_ptr<WeaponBehavior> w;
  w = getWeapon();
  w->useWeapon();
}

Character::Character() {}

Character::~Character() {}
void Character::setWeapon(std::shared_ptr<WeaponBehavior> w) { weapon = w; }

std::shared_ptr<WeaponBehavior> Character::getWeapon() { return weapon; }

void KnifeBehavior::useWeapon() {
  std::cout << "use KnifeBehavior" << std::endl;
}
void BowAndArrowBehavior::useWeapon() {
  std::cout << "use BowAndArrowBehavior" << std::endl;
}
void AxeBehavior::useWeapon() { std::cout << "use AxeBehavior" << std::endl; }

