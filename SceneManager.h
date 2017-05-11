#pragma once
#include "PauseMenu.h"
#include "MainMenu.h"
#include "Intro.h"

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    void runScene();
    void setScene(Scenes);

private:
    Scene *actualScene = NULL;
    Scenes actual;

    Intro introduction;
    MainMenu menu;
    PauseMenu options;
};