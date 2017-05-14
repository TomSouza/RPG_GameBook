#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::setName(string value)
{
    name = value;
}

string Character::getName()
{
    return name;
}

void Character::setStrength(int value)
{
    if (value >= 0) {
        strength = value;
    }
}

int Character::getStrength()
{
    return strength;
}

void Character::setAbility(int value)
{
    if (value >= 0) {
        ability = value;
    }
}

int Character::getAbility()
{
    return ability;
}

void Character::setEndurance(int value)
{
    if (value >= 0) {
        endurance = value;
    }
}

int Character::getEndurance()
{
    return endurance;
}

void Character::setArmor(int value)
{
    if (value >= 0) {
        armor = value;
    }
}

int Character::getArmor()
{
    return armor;
}

void Character::setFirePower(int value)
{
    if (value >= 0) {
        fire_power = value;
    }
}

int Character::getFirePower()
{
    return fire_power;
}

void Character::setExperience(int value)
{
    experience += value;
}

int Character::getExperience()
{
    return experience;
}

void Character::setHp(int hp)
{
    this->hp = hp;
}

int Character::getHp()
{
    return hp;
}

void Character::setMp(int mp)
{
    this->mp = mp;
}

int Character::getMp()
{
    return mp;
}


int Character::getAP()
{
    return AP;
}

int Character::getDP()
{
    return DP;
}
