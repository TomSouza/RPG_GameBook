#pragma once
#include "libUnicornio.h"

class Scene
{
public:
    Scene();
    ~Scene();

    virtual void start() = 0;
    virtual void finish() = 0;

protected:
    virtual void update() = 0;
    virtual void draw() = 0;

    Sprite background;
};

