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

    void setNewGame(bool);
    void setInGame(bool);
    void setState(Screens state);

private:
    void draw();

    void initStatusResources();

    void inventory();
    void status();
    void dataManager();
    void checkSaves();

    void createNewGame();
    void drawTabs();

    /* Status */
    void inputUpdate();
    void inputDraw();

    void showAttributes();
    void setAttributesLabel(int);
    void checkAttributesButtons(int);    

    bool newGame;
    bool inGame = false;
    BotaoSprite saveLoad[3];
    Texto loadName[3];

    BotaoSprite plus[5];
    BotaoSprite minus[5];
    Texto attributesLabel[5];
    Texto remainingPoints;

    Texto playerName;
    Texto playerHealth;
    Texto nameLabel;
    Sprite nameinput;

    BotaoSprite warrior;
    BotaoSprite mage;
    BotaoSprite rogue;

    BotaoSprite confirm;

    Sprite inventorySlots;
    Sprite equipableSlots;

    Player** player = &AppModel::player;
    Screens actualScreen;
    BotaoSprite tabs[3];
    Texto tabsLabel[3];

    actionButton saveActual;
    actionButton mainMenu;
};

