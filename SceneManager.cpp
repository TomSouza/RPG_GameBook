#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::runScene()
{
    if (actualScene != NULL) {
        actual = actualScene->update();
    }

    setScene(actual);
}

void SceneManager::setScene(Scenes scene)
{
    if (scene != KEEP && actualScene != NULL) {
        actualScene->finish();
    }

    switch (scene)
    {
    case INTRO:
        actualScene = &introduction;
        break;
    case MAIN_MENU:
        actualScene = &menu;
        break;
    case NEW_GAME:
        options.setNewGame(true);
        actualScene = &options;
        break;
    case LOAD_GAME:
        options.setNewGame(false);
        actualScene = &options;
        break;
    case PAUSE_MENU:
        actualScene = &options;
        break;
    case NARRATIVE:
        options.setNewGame(false);
        options.setInGame(true);
        options.setState(STATUS);

        game.setPauseScene(&options);

        actualScene = &game;
        break;
    case KEEP:
    default:
        break;
    }

    if (!actualScene->started) {
        actualScene->start();
    }
}