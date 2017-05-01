#pragma once
#include "Inventory.h"

class Character
{
protected:
    //Attributes
    int strength, ability, endurance, armor, fire_power;
    // Combat
    int AP, DP;
    int hp, mp;

    int experience;

    Inventory *inventory = NULL;

public:
    Character();
    ~Character();

    virtual int attack() = 0;
    virtual void defend(int dano) = 0;
};

