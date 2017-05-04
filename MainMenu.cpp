#include "MainMenu.h"

MainMenu::MainMenu()
{
    gRecursos.carregarSpriteSheet("bg", "assets/bg/main_menu.jpg");
    background.setSpriteSheet("bg");

    gRecursos.carregarSpriteSheet("new_game", "assets/buttons/newGame.png", 3, 1);
    newGame.setSpriteSheet("new_game");

    gRecursos.carregarSpriteSheet("load_game", "assets/buttons/loadGame.png", 3, 1);
    loadGame.setSpriteSheet("load_game");

    gRecursos.carregarSpriteSheet("exit_game", "assets/buttons/exitGame.png", 3, 1);
    exitGame.setSpriteSheet("exit_game");

    newGame.setPos(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2 - 100
    );

    loadGame.setPos(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2
    );

    exitGame.setPos(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2 + 100
    );
}

MainMenu::~MainMenu()
{
}

void MainMenu::start()
{
    sceneChange = KEEP;
    started = true;
}

void MainMenu::finish()
{
    started = false;
}

Scenes MainMenu::update()
{
    newGame.atualizar();
    loadGame.atualizar();
    exitGame.atualizar();

    buttomEvents();

    draw();

    return sceneChange;
}

void MainMenu::draw()
{
    background.desenhar(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2
    );

    newGame.desenhar();
    loadGame.desenhar();
    exitGame.desenhar();
}

void MainMenu::buttomEvents()
{
    if (exitGame.estaClicado()) {
        gEventos.sair = true;
    }

    if (loadGame.estaClicado()) {
        sceneChange = INTRO;
    }
}
