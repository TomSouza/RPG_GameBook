#include "Player.h"

Player::Player()
{
    inventory = new Inventory(6);
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
