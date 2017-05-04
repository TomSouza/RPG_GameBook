#include "Intro.h"

Intro::Intro()
{
    gRecursos.carregarSpriteSheet("libIntro", "assets/logo/libLogo.png");
    gRecursos.carregarSpriteSheet("beeIntro", "assets/logo/beeLogo.png");

    lib.setSpriteSheet("libIntro");
    bee.setSpriteSheet("beeIntro");    
}

Intro::~Intro()
{
}

void Intro::start()
{
    gJanela.fading.setDuracao(2.0f);
    gJanela.fading.iniciarFadeIn();

    introTime = 0.0;
    logoPos = 0;

    sceneChange = KEEP;
    started = true;
}

void Intro::finish()
{
    started = false;
}

Scenes Intro::update()
{
    draw();
    return sceneChange;
}

void Intro::draw()
{
    showIntro();
}

void Intro::showIntro()
{
    if (logoPos == 0) {
        lib.desenhar(
            gJanela.getLargura() / 2,
            gJanela.getAltura() / 2
        );
    }
    else if (logoPos == 1) {
        bee.desenhar(
            gJanela.getLargura() / 2,
            gJanela.getAltura() / 2
        );
    }
    else {
        sceneChange = MAIN_MENU;
    }

    introTime += gTempo.getDeltaTempo();

    if (introTime > 3) {
        gJanela.fading.iniciarFadeIn();
        logoPos++;
        introTime = 0.0;
    }
}
