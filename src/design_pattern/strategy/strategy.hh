#ifndef STRATEGY_HH_
#define STRATEGY_HH_
#include <iostream>
#include <memory>
using namespace std;

class WeaponBehavior
{
public:
    virtual void useWeapon() = 0;
};

class KnifeBehavior : public WeaponBehavior
{
public:
    void useWeapon();
};

class Character
{
private:
    std::shared_ptr<WeaponBehavior> weapon;

public:
    Character();
    ~Character();
    void setWeapon(std::shared_ptr<WeaponBehavior> w);
    std::shared_ptr<WeaponBehavior> getWeapon();
    virtual void fight() { cout << "fight" << endl; };
};

class Queen : public Character
{
public:
    void fight();
};

class King : public Character
{
public:
    void fight();
};

class Troll : public Character
{
public:
    void fight();
};

class Knight : public Character
{
public:
    void fight();
};

class BowAndArrowBehavior : public WeaponBehavior
{
public:
    void useWeapon();
};class AxeBehavior : public WeaponBehavior
{
public:
    void useWeapon();
};

#endif