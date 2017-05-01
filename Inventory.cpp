#include "Inventory.h"

Inventory::Inventory(int slots)
{
    backpack = new Item[slots];
}

Inventory::~Inventory()
{
    delete [] backpack;
    delete [] equipped;
}

Item Inventory::showItens()
{
    return *backpack;
}

bool Inventory::pickUp(Item newItem)
{
    int empty = -1;
    for (int i = 0; i < slots; i++)
    {
        if (backpack[i].type == EMPTY) {
            empty = i;
            break;
        }
    }

    if (empty < 0) {
        return false;
    }

    backpack[empty] = newItem;

}

void Inventory::discart(int discart)
{
    backpack[discart].~Item();
}
