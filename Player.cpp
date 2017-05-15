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

    srand(time(NULL));

    int dice = rand() % 6 + 1;

    if (dice == 6) {
        damage += strength;
    }

    damage += AP + dice;

    return damage;
}

void Player::defend(int damage)
{
    int dice = rand() % 6 + 1;

    if (dice == 6) {
        tempDefence += armor;
    }

    tempDefence += dice;

    damage = (damage - (DP + tempDefence)) < 0 
        ? 0
        : damage - (DP + tempDefence);

    hp -= damage;

    if (tempDefence > 0) {
        tempDefence = 0;
    }
}

int Player::getUsablePoints()
{
    return pointsToUse;
}

void Player::create()
{
    if (hp == 0) {
        int multiplier = 5;

        if (playerClass == WARRIOR) {
            multiplier = 6;
        }

        hp = endurance * multiplier;
    }

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

void Player::setTempDefence(int value)
{
    tempDefence = value;
}

int Player::getPointsToUse()
{
    return pointsToUse - (
        strength + ability + endurance + armor + fire_power
    );
}
