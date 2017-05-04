#pragma once
#include "Scene.h"
class Intro : public Scene
{
public:
    Intro();
    ~Intro();

    void start();
    void finish();
    Scenes update();

private:
    void draw();

    Sprite lib, bee;
    double introTime;
    int logoPos;

    void showIntro();;
};

