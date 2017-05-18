#include "Narrative.h"

Narrative::Narrative()
{
    model.load();
    setStage(1);

    gRecursos.carregarSpriteSheet("pause", "assets/buttons/pause.png");
    pauseButton.setSpriteSheet("pause");

    pauseButton.setPos(
        gJanela.getLargura() / 2 - 350,
        gJanela.getAltura() / 2 - 80
    );

	gRecursos.carregarSpriteSheet("options", "assets/buttons/option.png", 3, 1);    

	gRecursos.carregarSpriteSheet("div", "assets/bg/narrativeDivision.png");
    gRecursos.carregarSpriteSheet("enemyLabel", "assets/bg/enemyLabel.png");

    gRecursos.carregarSpriteSheet("bgStage1", "assets/bg/dungon.png");
    background.setSpriteSheet("bgStage1");

    gRecursos.carregarFonte("buttonFont", "assets/fonts/SCHLBKI.ttf", 14);
    gRecursos.carregarFonte("descriptionFont", "assets/fonts/SCHLBKI.ttf", 20);

    stageText.setFonte("gameFont");
    stageText.setString("");
    stageText.setCor(0, 0, 0, 255, true);

    playerHealth.setFonte("gameFont");
    playerHealth.setCor(0, 0, 0, 255, true);
    playerHealth.setLarguraMaxima(150);

    enemyHealth.setFonte("gameFont");
    enemyHealth.setCor(0, 0, 0, 255, true);

    enemyLabel.setSpriteSheet("enemyLabel");
    enemyLabel.setEscala(0.8, 0.8);

    stageLabel.setSpriteSheet("enemyLabel");
    stageLabel.setEscala(0.4, 0.4);

	for (int i = 0; i < 4; i++)
	{
		battleOptions[i].button.setSpriteSheet("options");
        battleOptions[i].label.setFonte("buttonFont");
        battleOptions[i].label.setCor(0, 0, 0, 255, true);

		if (i < 3) {
			options[i].button.setSpriteSheet("options");
            options[i].label.setFonte("buttonFont");
            options[i].label.setCor(0, 0, 0, 255, true);
		}
	}

    setButtonPosition();

	narrativeDiv.setSpriteSheet("div");
    narrativeDiv.setEscala(1, 1.4);

	narration.setFonte("descriptionFont");
	narration.setString("");
	narration.setCor(0, 0, 0, 255, true);
    narration.setLarguraMaxima(600);
}

Narrative::~Narrative()
{
}

void Narrative::start()
{
    sceneChange = KEEP;
    started = true;
    setStage(AppModel::scene[0], AppModel::scene[1]);
}

void Narrative::finish()
{
    started = false;
    pause->setNewGame(false);
    pause->setInGame(false);
    paused = false;
}

Scenes Narrative::update()
{
    draw();

    if (gTeclado.pressionou[TECLA_TAB]) {
        paused = !paused;
    }

    if (paused) {
        sceneChange = pause->update();
        return sceneChange;
    }

    narrativeDiv.desenhar(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2 + 150
    );

    switch (actualState)
    {
    case HISTORY:
        history();
        break;
    case BATTLE:
        battle();
        break;
    default:
        break;
    }

	return sceneChange;
}

void Narrative::setPauseScene(PauseMenu* scene)
{
    pause = scene;
}

void Narrative::setStage(int stage, int storyLine)
{
    for (int i = 0; i < AppModel::stageVectorSize; i++)
    {
        if (
            AppModel::stages[i].nivel == stage &&
            AppModel::stages[i].ident == storyLine
        ) {
            stageInfo = &AppModel::stages[i];

            this->stage = stage;
            this->storyLine = storyLine;

            AppModel::scene[0] = stage;
            AppModel::scene[1] = storyLine;
            break;
        }
    }

    if (stageInfo->type == 'm') {
        actualState = BATTLE;
    }
    else if (stageInfo->type == 'h') {
        actualState = HISTORY;
    }
}

void Narrative::draw()
{
	background.desenhar(
		gJanela.getLargura() / 2,
		gJanela.getAltura() / 2
	);

    stageLabel.desenhar(
        gJanela.getLargura() / 2 - 350,
        gJanela.getAltura() / 2 -250
    );

    stageText.setString(to_string(stage));

    stageText.desenhar(
        gJanela.getLargura() / 2 - 350,
        gJanela.getAltura() / 2 - 250
    );

    pauseButton.atualizar();
    if (pauseButton.estaClicado() == true) {
        paused = !paused;
    }
    pauseButton.desenhar();
}

void Narrative::history()
{
    narration.setString(stageInfo->description);

    narration.desenhar(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2 + 120
    );

    if (stageInfo->item != NULL) {
        AppModel::player->inventory->pickUp(*stageInfo->item);
        stageInfo->item = NULL;
    }

    for (int i = 0; i < 3; i++)
    {
        if (options[i].optValue) {
            options[i].button.atualizar();

            verifyButtons(i);

            options[i].button.desenhar();
            options[i].label.desenhar(
                options[i].button.getX(),
                options[i].button.getY()
            );
        }
    }
}

void Narrative::battle()
{
    if (stageInfo->enemy->getHp() <= 0) {
        setStage(stage + 1, stageInfo->options[0].value);
        return;
    }

    if (playerTurn) {
        for (int i = 0; i < 4; i++)
        {
            if (!battleOptions[i].action) {
                battleOptions[i].button.atualizar();

                verifyButtons(i);

                battleOptions[i].button.desenhar();
                battleOptions[i].label.desenhar(
                    battleOptions[i].button.getX(),
                    battleOptions[i].button.getY()
                );
            }
        }
    }
    else {
        battleManager.fight(*stageInfo->enemy, *AppModel::player);
        playerTurn = true;
    }

    enemyLabel.desenhar(
        gJanela.getLargura() / 2 + 280,
        gJanela.getAltura() / 2 - 200
    );

    enemyHealth.setString(
        stageInfo->enemy->getName() +
        "\nHP: " + to_string(stageInfo->enemy->getHp())
    );

    enemyHealth.desenhar(
        gJanela.getLargura() / 2 + 280,
        gJanela.getAltura() / 2 - 200
    );

    playerHealth.setString(
        AppModel::player->getName() +
        "\nHP: " + to_string(AppModel::player->getHp())
    );
    playerHealth.desenhar(
        gJanela.getLargura() / 2 + 250,
        gJanela.getAltura() / 2 + 150
    );
}

void Narrative::setButtonPosition()
{
    if (stageInfo->type == 'm') {

        int marginX = -150;
        int marginY = 120;

        for (int i = 0; i < 4; i++)
        {
            if (!battleOptions[i].action) {

                if (i == 2) {
                    marginX = -150;
                    marginY += 80;
                }

                battleOptions[i].button.setPos(
                    gJanela.getLargura() / 2 + marginX,
                    gJanela.getAltura() / 2 + marginY
                );
            }
            marginX += 200;
        }

        battleOptions[0].label.setString("Atacar");
        battleOptions[1].label.setString("Defender");
        battleOptions[2].label.setString("Pocao");
        battleOptions[3].label.setString("Fujir");
    }
    else 
    {
        int margin = -200;

        for (int i = 0; i < 3; i++)
        {
            if (!options[i].optValue) {
                options[i].button.setPos(
                    gJanela.getLargura() / 2 + margin,
                    gJanela.getAltura() / 2 + 240
                );
            }
            margin += 150;

            options[i].optValue = stageInfo->options[i].value;

            options[i].label.setString(
                stageInfo->options[i].description
            );
        }
    }
}

void Narrative::verifyButtons(int option)
{
    if (stageInfo->type == 'm') {
        if (battleOptions[option].button.estaClicado()) {

            switch (option)
            {
            case 0:
                battleManager.fight(*AppModel::player, *stageInfo->enemy);
                break;
            case 1:
                AppModel::player->setTempDefence(
                    AppModel::player->getDP() / 2
                );
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;
            }

            playerTurn = false;
        }
    }
    else {
        if (options[option].button.estaClicado() == true) {
            setStage(stage + 1, options[option].optValue);
            setButtonPosition();
        }
    }
}
