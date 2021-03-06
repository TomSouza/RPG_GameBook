#include "Inventory.h"

Inventory::Inventory(int slots)
{
    backpack = new Item[slots];
    this->slots = slots;
    
    initPositions();

}

Inventory::~Inventory()
{
    delete [] backpack;
    delete [] equipped;
}

void Inventory::backpackClick(int pos)
{
    if (backpack[pos].action.button.estaClicado() == true) {
        if (backpack[pos].type == EQUIPPABLE) {
            if (equipped[RIGHT_HAND -1].type == EMPTY) {
                itemButton foo = equipped[RIGHT_HAND - 1].action;

                equipped[RIGHT_HAND -1] = backpack[pos];
                backpack[pos].type = EMPTY;
                equipped[RIGHT_HAND - 1].type = EQUIPPABLE;

                equipped[RIGHT_HAND - 1].action = foo;
                equipped[RIGHT_HAND - 1].action.button.setSpriteSheet(backpack[pos].name);
            }
        }
    }
}

void Inventory::equipClick(int pos)
{
    if (equipped[pos].action.button.estaClicado() == true) {
        for (int i = 0; i < 6; i++)
        {
            if (backpack[i].type == EMPTY) {
                itemButton foo = backpack[i].action;

                backpack[i] = equipped[pos];
                equipped[pos].type = EMPTY;

                backpack[i].action = foo;
                backpack[i].action.button.setSpriteSheet(backpack[i].name);

                return;
            }
        }
    }
}

void Inventory::setEquipped(Item * equips)
{
    for (int i = 0; i < 5; i++)
    {
        equipped[i] = equips[i];
    }
}

void Inventory::initPositions()
{
    int posX = gJanela.getLargura() / 2 + 32;
    int posY = gJanela.getAltura() / 2 - 42;

    for (int i = 0; i < 6; i++)
    {
        if (i == 3) {
            posY += 88;
            posX = gJanela.getLargura() / 2 + 32;
        }

        backpack[i].action.button.setPos(posX, posY);
        backpack[i].action.label.setFonte("buttonFont");
        backpack[i].action.button.setSpriteSheet(backpack[i].name);

        posX += 88;
    }

    for (int i = 0; i < 5; i++)
    {
        switch (i + 1)
        {
        case HEAD:
            equipped[i].action.button.setPos(
                gJanela.getLargura() / 2 - 150,
                gJanela.getAltura() / 2 - 60
            );
            break;
        case CHEST:
            equipped[i].action.button.setPos(
                gJanela.getLargura() / 2 - 150,
                gJanela.getAltura() / 2
            );
            break;
        case LEGS:
            equipped[i].action.button.setPos(
                gJanela.getLargura() / 2 - 150,
                gJanela.getAltura() / 2 + 60
            );
            break;
        case LEFT_HAND:
            equipped[i].action.button.setPos(
                gJanela.getLargura() / 2 - 85,
                gJanela.getAltura() / 2 - 15
            );
            break;
        case RIGHT_HAND:
            equipped[i].action.button.setPos(
                gJanela.getLargura() / 2 - 215,
                gJanela.getAltura() / 2 - 15
            );
            break;
        default:
            break;
        }

        equipped[i].action.label.setFonte("buttonFont");
        equipped[i].action.button.setSpriteSheet(equipped[i].name);
    }
}

void Inventory::showItens()
{

    for (int i = 0; i < 6; i++)
    {
        if (backpack[i].type != EMPTY) {
            backpack[i].action.button.atualizar();

            backpackClick(i);

            backpack[i].action.button.desenhar();
            backpack[i].action.label.desenhar(
                backpack[i].action.button.getX(),
                backpack[i].action.button.getY()
            );
        }

        if (equipped[i].type != EMPTY && i < 5) {
            equipped[i].action.button.atualizar();

            equipClick(i);

            equipped[i].action.button.desenhar();
            equipped[i].action.label.desenhar(
                equipped[i].action.button.getX(),
                equipped[i].action.button.getY()
            );
        }
    }
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

    itemButton foo = backpack[empty].action;
    foo.button.setSpriteSheet(newItem.name);
    backpack[empty] = newItem;
    backpack[empty].action = foo;

}

void Inventory::discart(int discart)
{
    backpack[discart].~Item();
}

Item* Inventory::getBackpack()
{
    return backpack;
}

Item* Inventory::getEquipped()
{
    return equipped;
}
