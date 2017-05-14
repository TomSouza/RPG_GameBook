#pragma once
#include "libUnicornio.h"
#include "Character.h"

class BattleManager
{
public:
    BattleManager();
    ~BattleManager();

    void fight(Character& attacker, Character& defender);
};