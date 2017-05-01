#pragma once
#include "Item.h"

class Inventory
{
private:
    Item *backpack;
    Item equipped[5];

    int slots;
public:
    Inventory(int);
    ~Inventory();

    Item showItens();
    bool pickUp(Item);
    void discart(int);
};