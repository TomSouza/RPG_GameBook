#pragma once
#include "Scene.h"

class MainMenu : public Scene
{
public:
    MainMenu();
    ~MainMenu();

    void start();
    void finish();

private:
    void update();
    void draw();
    void buttomEvents();

    int teste = 0;

    BotaoSprite newGame;
    BotaoSprite loadGame;
    BotaoSprite exitGame;
};

