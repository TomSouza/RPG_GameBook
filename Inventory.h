#pragma once
#include "Item.h"

class Inventory
{
private:
    Item *backpack;
    Item equipped[5];

    int slots;

    void backpackClick(int pos);
    void equipClick(int pos);

public:
    Inventory(int);
    ~Inventory();

    Item showItens();
    bool pickUp(Item);
    void discart(int);
};