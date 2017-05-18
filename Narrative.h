#pragma once
#include "Scene.h"
#include "BattleManager.h"
#include "PauseMenu.h"

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

    void setPauseScene(PauseMenu* scene);

private:
	void draw();

    bool paused = false;
    PauseMenu* pause = NULL;
    BotaoSprite pauseButton;

    void history();
    void battle();

    void setButtonPosition();
    void verifyButtons(int option);

    int stage;
    int storyLine;
    void setStage(int stage, int storyLine = 1);

    Texto stageText;
    Sprite stageLabel;
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

