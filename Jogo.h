#pragma once
#include "libUnicornio.h"
#include "SceneManager.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();
private:
    SceneManager *sceneManager;
};

