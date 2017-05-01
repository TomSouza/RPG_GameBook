#include "MainMenu.h"

MainMenu::MainMenu()
{
    gRecursos.carregarSpriteSheet("bg", "assets/bg/main_menu.jpg");
    background.setSpriteSheet("bg");
}

MainMenu::~MainMenu()
{
}

void MainMenu::start()
{
    update();
}

void MainMenu::finish()
{
}

void MainMenu::update()
{
    draw();
}

void MainMenu::draw()
{
    background.desenhar(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2
    );
}
