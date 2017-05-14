#pragma once
#include "Character.h"

class Enemy : public Character
{
private:

public:
    Enemy();
    ~Enemy();

    int attack();
    void defend(int damage);

    void create();
};

