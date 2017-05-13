#pragma once
#include "Intro.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "Narrative.h"

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
    Narrative game;
};