#pragma once
#include "libUnicornio.h"
#include "AppModel.h"

enum Scenes {
    KEEP,
    INTRO,
    MAIN_MENU,
    NEW_GAME,
    LOAD_GAME,
    PAUSE_MENU,
    NARRATIVE
};

class Scene
{
public:
    Scene();
    ~Scene();

    bool started = false;

    virtual void start() = 0;
    virtual void finish() = 0;
    virtual Scenes update() = 0;

protected:
    virtual void draw() = 0;

    Sprite background;
    Scenes sceneChange;
    AppModel model;
};

