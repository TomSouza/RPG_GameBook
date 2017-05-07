#pragma once
#include "Character.h"

enum Class {
    WARRIOR, MAGE, ROGUE
};

class Player : public Character
{
public:
    Player();
    ~Player();

    int attack();
    void defend(int damage);
    int getUsablePoints();
    void create();

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

    int getPointsToUse();

    int maxNameSize = 20;
    Class playerClass = WARRIOR;
private:
    int pointsToUse = 12;
    string* name;
};