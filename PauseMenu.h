#pragma once
#include "Scene.h"

enum Screens {
    DATA_MANAGER, STATUS, INVENTORY
};

class PauseMenu : public Scene
{
public:
    PauseMenu();
    ~PauseMenu();

    void start();
    void finish();
    Scenes update();

private:
    void draw();

    void inventory();
    void status();
    void dataManager();

    void createNewGame();

    /* Status */
    void inputUpdate();
    void inputDraw();

    void showAttributes();
    void setAttributesLabel(int);
    void checkAttributesButtons(int);

    bool newGame;
    BotaoSprite saveLoad[3];

    BotaoSprite plus[5];
    BotaoSprite minus[5];
    Texto attributesLabel[5];
    Texto remainingPoints;

    Texto playerName;
    Texto nameLabel;
    Sprite nameinput;

    BotaoSprite warrior;
    BotaoSprite mage;
    BotaoSprite rogue;

    BotaoSprite confirm;

    Player** player = &AppModel::player;
    Screens actualScreen;
};

