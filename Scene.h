#pragma once
#include "libUnicornio.h"

enum Scenes {
    KEEP, INTRO, MAIN_MENU
};

class Scene
{
public:
    Scene();
    ~Scene();

    virtual void start() = 0;
    virtual void finish() = 0;
    virtual Scenes update() = 0;

    bool started = false;
protected:
    virtual void draw() = 0;

    Sprite background;
    Scenes sceneChange;
};

