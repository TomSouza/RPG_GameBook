#pragma once
#include "MainMenu.h"

enum Scenes {
    INTRO, MAIN_MENU
};

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    void runScene();
    void setScene(Scenes);

private:
    Scene *actualScene = NULL;
    MainMenu menu;

    Sprite lib, bee;
    double introTime = 0.0;
    int logoPos = 0;

    void showIntro();
};