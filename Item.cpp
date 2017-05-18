#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
    type = EMPTY;
}

void Item::initiate(string name, bool useInFight, Type type, Position position, int base)
{
    this->name = name;
    this->useInFight = useInFight;
    this->type = type;
    this->position = position;
    this->base = base;

    action.button.setSpriteSheet(name);
}

Item * Item::copy()
{
    return this;
}
