#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

int Enemy::attack()
{
    int damage = 0;

    srand(time(NULL));

    int dice = rand() % 6 + 1;

    if (dice == 6) {
        AP += strength;
    }

    damage = AP + dice;

    return damage;
}

void Enemy::defend(int damage)
{
    damage = (damage - DP) < 0 ? 0 : damage - DP;

    hp -= damage;
}

void Enemy::create()
{
    hp = endurance * 5;
    AP = strength + ability;
    DP = ability + armor;
}
