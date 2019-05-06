#include <iostream>
#include <memory>
#include "strategy.hh"
using namespace std;
void Queen::fight()
{
    std::shared_ptr<WeaponBehavior> w;
    w = getWeapon();
    w->useWeapon();
}

void King::fight()
{
    std::shared_ptr<WeaponBehavior> w;
    w = getWeapon();
    w->useWeapon();
}

void Troll::fight()
{
    std::shared_ptr<WeaponBehavior> w;
    w = getWeapon();
    w->useWeapon();
}

void Knight::fight()
{
    std::shared_ptr<WeaponBehavior> w;
    w = getWeapon();
    w->useWeapon();
}

Character::Character()
{
}

Character::~Character()
{
}
void Character::setWeapon(std::shared_ptr<WeaponBehavior> w)
{
    weapon = w;
}

std::shared_ptr<WeaponBehavior> Character::getWeapon()
{
    return weapon;
}

void KnifeBehavior::useWeapon()
{
    cout << "use KnifeBehavior" << endl;
}
void BowAndArrowBehavior::useWeapon()
{
    cout << "use BowAndArrowBehavior" << endl;
}
void AxeBehavior::useWeapon()
{
    cout << "use AxeBehavior" << endl;
}