#include "Jogo.h"

Jogo::Jogo()
{
    uniInicializar(800, 600, false, "Tales of Rhagni");
    sceneManager = new SceneManager;
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{    
    sceneManager->setScene(INTRO);
}

void Jogo::finalizar()
{
    gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
        sceneManager->runScene();
		uniTerminarFrame();
	}
}
