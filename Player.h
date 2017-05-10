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

    void setName(string value);
    string getName();

    int getPointsToUse();

    int maxNameSize = 20;
    Class playerClass = WARRIOR;
private:
    int pointsToUse = 12;
    string* name;
};