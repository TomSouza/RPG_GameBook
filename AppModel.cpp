#include "appModel.h"

Player* AppModel::player = NULL;
int AppModel::saveSlot = NULL;

AppModel::AppModel()
{
}

AppModel::~AppModel()
{
}

void AppModel::save(const char* file)
{
}

void AppModel::saveBinary(const char* file)
{
    ofstream save(file, ios::binary);

    save.write(reinterpret_cast<const char*> (&player), sizeof(Player));

    save.close();
}

void AppModel::load(const char* file)
{
}

void AppModel::loadBinary(const char* file)
{
    ifstream load(file, ios::binary);

    while (load && !load.eof()) {
        load.read(reinterpret_cast<char*>(&player), sizeof(Player));
    }

    load.close();
}
