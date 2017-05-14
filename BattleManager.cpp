#include "BattleManager.h"

BattleManager::BattleManager()
{
}

BattleManager::~BattleManager()
{
}

void BattleManager::fight(Character & attacker, Character & defender)
{
    defender.defend(
        attacker.attack()
    );
}
