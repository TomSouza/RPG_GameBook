#pragma once
#include "Scene.h"

class MainMenu : public Scene
{
public:
    MainMenu();
    ~MainMenu();

    void start();
    void finish();
    Scenes update();

private:
    void draw();
    void buttomEvents();

    BotaoSprite newGame;
    BotaoSprite loadGame;
    BotaoSprite exitGame;
};

