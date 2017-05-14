#pragma once
#include "Scene.h"
#include "BattleManager.h"

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
    void verifyButtons(int option);

    int stage;
    int storyLine;
    void setStage(int stage, int storyLine = 1);

    stageInfo* stageInfo = NULL;

    GameState actualState = HISTORY;

	Sprite narrativeDiv;
	Texto narration;

    optionButton options[3];
    battleButton battleOptions[4];

    Texto playerHealth;
    Texto enemyHealth;
    Sprite enemyLabel;

    bool playerTurn;

    BattleManager battleManager;
};

