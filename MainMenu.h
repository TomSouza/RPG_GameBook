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
};

