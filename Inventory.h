#pragma once
#include "Item.h"

class Inventory
{
private:
    friend class AppModel;

    Item *backpack;
    Item equipped[5];

    int slots;

    void backpackClick(int pos);
    void equipClick(int pos);

    void setEquipped(Item* equips);
    void initPositions();

public:
    Inventory(int);
    ~Inventory();

    void showItens();
    bool pickUp(Item);
    void discart(int);

    Item* getBackpack();
    Item* getEquipped();
};