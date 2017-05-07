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

    Class playerClass;
};