#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
    gRecursos.carregarSpriteSheet("save", "assets/buttons/newData.png", 3, 1);
    gRecursos.carregarSpriteSheet("load", "assets/buttons/loadData.png", 3, 1);

    int pos = -100;

    for (int i = 0; i < 3; i++) {
        saveLoad[i].setSpriteSheet("save");

        saveLoad[i].setPos(
            gJanela.getLargura() / 2,
            gJanela.getAltura() / 2 + pos
        );

        pos += 100;
    }
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::start()
{
}

void PauseMenu::finish()
{
}

Scenes PauseMenu::update()
{
    if (player == NULL) {
        dataManager();
    }

    return sceneChange;
}

void PauseMenu::draw()
{
}

void PauseMenu::inventory()
{
}

void PauseMenu::status()
{
}

void PauseMenu::dataManager()
{
    for (int i = 0; i < 3; i++) {
        saveLoad[i].atualizar();
        saveLoad[i].desenhar();
    }
}
