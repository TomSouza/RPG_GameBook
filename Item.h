#pragma once
#include "libUnicornio.h"
#include <string>

using namespace std;

struct itemButton {
    BotaoSprite button;
    Texto label;
};

enum Type {
    EMPTY, EQUIPPABLE, CONSUMABLE
};

enum Position {
    UNSETABLE, HEAD, CHEST, LEGS, LEFT_HAND, RIGHT_HAND
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
    Type type = EMPTY;
    Position position = UNSETABLE;
    bonusAttribute bonus = NONE;
    itemButton action;

    void initiate(string name, bool useInFight, Type type, Position position, int base);
    Item* copy();
};

