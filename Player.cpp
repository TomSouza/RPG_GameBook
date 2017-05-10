#include "Player.h"

Player::Player()
{
    inventory = new Inventory(6);
    name = new string[maxNameSize];
}


Player::~Player()
{
}

int Player::attack()
{
    int damage = 0;

    damage = AP;

    return damage;
}

void Player::defend(int damage)
{
    hp -= damage - DP;
}

int Player::getUsablePoints()
{
    return pointsToUse;
}

void Player::create()
{
    hp = endurance * 5;
    AP = strength + ability;
    DP = ability + armor;
}

void Player::setName(string value)
{
    *name = value;
}

string Player::getName()
{
    return *name;
}

int Player::getPointsToUse()
{
    return pointsToUse - (
        strength + ability + endurance + armor + fire_power
    );
}
