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

    void setTempDefence(int value);

    int getPointsToUse();

    void setLuck(int value = 0);
    int getLuck();

    int maxNameSize = 20;
    Class playerClass = WARRIOR;
private:
    int pointsToUse = 12;
    int tempDefence = 0;

    int luck = 0;

    string* name;
};