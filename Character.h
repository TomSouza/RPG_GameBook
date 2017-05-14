#pragma once
#include "Inventory.h"
#include <time.h>

class Character
{
protected:
    //Attributes
    int strength = 0, ability = 0, endurance = 0, armor = 0, fire_power = 0;
    // Combat
    int AP = 0, DP = 0;
    int hp = 0, mp = 0;

    int experience = 0;

    string name;

    Inventory *inventory = NULL;

public:
    Character();
    ~Character();

    virtual int attack() = 0;
    virtual void defend(int damage) = 0;

    void setName(string value);
    string getName();

    void setStrength(int);
    int getStrength();

    void setAbility(int);
    int getAbility();

    void setEndurance(int);
    int getEndurance();

    void setArmor(int);
    int getArmor();

    void setFirePower(int);
    int getFirePower();

    void setExperience(int);
    int getExperience();

    void setHp(int);
    int getHp();

    void setMp(int);
    int getMp();

    int getAP();
    int getDP();
};

