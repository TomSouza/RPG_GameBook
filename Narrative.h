#pragma once
#include "Scene.h"

struct optionButton
{
    BotaoSprite button;
    int optValue = 0;
    Texto label;
};

struct battleButton
{
    BotaoSprite button;
    int action = 0;
    Texto label;
};

enum GameState {
    HISTORY, BATTLE
};

class Narrative :
	public Scene
{
public:
	Narrative();
	~Narrative();

	void start();
	void finish();
    Scenes update();

private:
	void draw();

    void history();
    void battle();

    void setButtonPosition();

    int stage;
    int storyLine;

    GameState actualState = HISTORY;

	Sprite narrativeDiv;
	Texto narration;

    optionButton options[3];
    battleButton battleOptions[4];
};

