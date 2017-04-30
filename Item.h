#pragma once
#include <string>

using namespace std;

enum Type {
    EMPTY, WEAPON, DEFENSE, CONSUMABLE
};

enum Position {
    UNSETABLE, HEAD, CHEAST, LEGS, LEFT_HAND, RIGHT_HAND
};

enum bonusAttribute {
    NONE, STRENGTH, ABILITY, ENDURANCE, ARMOR, FIRE_POWER
};

class Item
{
public:
    Item();
    ~Item();

    int skill = -1;
    int base = 0;
    int modifier = 0;
    bool useInFight = false;

    string name;
    string description;
    Type type;
    Position position;
    bonusAttribute bonus;
};

