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

void Player::setStrength(int value)
{
    if (value >= 0) {
        strength = value;
    }
}

int Player::getStrength()
{
    return strength;
}

void Player::setAbility(int value)
{
    if (value >= 0) {
        ability = value;
    }
}

int Player::getAbility()
{
    return ability;
}

void Player::setEndurance(int value)
{
    if (value >= 0) {
        endurance = value;
    }
}

int Player::getEndurance()
{
    return endurance;
}

void Player::setArmor(int value)
{
    if (value >= 0) {
        armor = value;
    }
}

int Player::getArmor()
{
    return armor;
}

void Player::setFirePower(int value)
{
    if (value >= 0) {
        fire_power = value;
    }
}

int Player::getFirePower()
{
    return fire_power;
}

int Player::getPointsToUse()
{
    return pointsToUse - (
        strength + ability + endurance + armor + fire_power
    );
}
