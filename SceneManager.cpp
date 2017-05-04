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
    switch (scene)
    {
    case INTRO:
        if (actualScene != NULL) {
            actualScene->finish();
        }
        actualScene = &introduction;
        break;
    case MAIN_MENU:
        if (actualScene != NULL) {
            actualScene->finish();
        }
        actualScene = &menu;
        break;
    case KEEP:
    default:
        break;
    }

    if (!actualScene->started) {
        actualScene->start();
    }
}
