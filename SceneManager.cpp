#include "SceneManager.h"

SceneManager::SceneManager()
{
    gRecursos.carregarSpriteSheet("libIntro", "assets/logo/libLogo.png");
    gRecursos.carregarSpriteSheet("beeIntro", "assets/logo/beeLogo.png");

    lib.setSpriteSheet("libIntro");
    bee.setSpriteSheet("beeIntro");    

    gJanela.fading.setDuracao(2.0f);
    gJanela.fading.iniciarFadeIn();
}

SceneManager::~SceneManager()
{
}

void SceneManager::runScene()
{
    if (actualScene != NULL) {
        actualScene->start();
    }
    else {
        showIntro();
    }

}

void SceneManager::setScene(Scenes scene)
{
    switch (scene)
    {
    case INTRO:        
        showIntro();
        break;
    case MAIN_MENU:
        if (actualScene != NULL) {
            actualScene->finish();
        }
        actualScene = &menu;

        break;
    default:
        break;
    }
}

void SceneManager::showIntro()
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
        setScene(MAIN_MENU);
    }
    
    introTime += gTempo.getDeltaTempo();

    if (introTime > 3) {
        gJanela.fading.iniciarFadeIn();
        logoPos++;
        introTime = 0.0;
    }
}
