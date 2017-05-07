#pragma once
#include "Scene.h"

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

    BotaoSprite saveLoad[3];
};

