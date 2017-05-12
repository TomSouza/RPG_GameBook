#include "Narrative.h"

Narrative::Narrative()
{
	gRecursos.carregarSpriteSheet("options", "assets/buttons/option.png", 3, 1);
	gRecursos.carregarSpriteSheet("div", "assets/bg/narrativeDivision.png");

	for (int i = 0; i < 4; i++)
	{
		battleOptions[i].button.setSpriteSheet("options");

		if (i < 3) {
			options[i].button.setSpriteSheet("options");
		}
	}

    setButtonPosition();

	narrativeDiv.setSpriteSheet("div");

	narration.setFonte("gameFont");
	narration.setString("");
	narration.setCor(0, 0, 0, 255, true);
}


Narrative::~Narrative()
{
}

void Narrative::start()
{
}

void Narrative::finish()
{
}

Scenes Narrative::update()
{
	draw();

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

void Narrative::draw()
{
	narrativeDiv.desenhar(
		gJanela.getLargura() / 2,
		gJanela.getAltura() / 2 + 150 
	);
}

void Narrative::history()
{
    narration.desenhar(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2 + 150
    );

    for (int i = 0; i < 3; i++)
    {
        if (!options[i].optValue) {

            options[i].button.atualizar();

            options[i].button.desenhar();
        }
    }
}

void Narrative::battle()
{
    for (int i = 0; i < 4; i++)
    {
        if (!battleOptions[i].action) {

            battleOptions[i].button.atualizar();

            battleOptions[i].button.desenhar();
        }
    }
}

void Narrative::setButtonPosition()
{
    int marginX = -200;
    int marginY = 100;

    for (int i = 0; i < 4; i++)
    {
        if (!battleOptions[i].action) {

            if (i == 2) {
                marginX = -200;
                marginY += 80;
            }

            battleOptions[i].button.setPos(
                gJanela.getLargura() / 2 + marginX,
                gJanela.getAltura() / 2 + marginY
            );

            marginX += 100;
        }
    }

    int margin = -200;

    for (int i = 0; i < 3; i++)
    {
        if (!options[i].optValue) {
            options[i].button.setPos(
                gJanela.getLargura() / 2 + margin,
                gJanela.getAltura() / 2 + 200
            );

            margin += 150;
        }
    }
}
