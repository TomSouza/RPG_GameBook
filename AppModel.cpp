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

    savePlayer(save);

    save.close();
}

void AppModel::load(const char* file)
{
}

void AppModel::loadBinary(const char* file)
{
    ifstream load(file, ios::binary);

    player = new Player;

    int f, h, r, a, pdf, ap, dp, hp, mp;
    Class playerClass;

    load.read(reinterpret_cast<char*>(&player->maxNameSize), sizeof(int));
    char *name = new char[player->maxNameSize];
    load.read(name, player->maxNameSize);

    load.read(reinterpret_cast<char*> (&f), sizeof(int));
    load.read(reinterpret_cast<char*> (&h), sizeof(int));
    load.read(reinterpret_cast<char*> (&r), sizeof(int));
    load.read(reinterpret_cast<char*> (&a), sizeof(int));
    load.read(reinterpret_cast<char*> (&pdf), sizeof(int));

    load.read(reinterpret_cast<char*> (&ap), sizeof(int));
    load.read(reinterpret_cast<char*> (&dp), sizeof(int));
    load.read(reinterpret_cast<char*> (&hp), sizeof(int));
    load.read(reinterpret_cast<char*> (&mp), sizeof(int));

    load.read(reinterpret_cast<char*> (&playerClass), sizeof(Class));

    player->setName(string(name,player->maxNameSize));
    player->setStrength(f);
    player->setAbility(h);
    player->setEndurance(r);
    player->setArmor(a);
    player->setFirePower(pdf);

    player->setHp(hp);
    player->setMp(mp);

    player->playerClass = playerClass;

    load.close();
}

void AppModel::savePlayer(ofstream& save)
{
    save.write(reinterpret_cast<const char*> (&player->maxNameSize), sizeof(int));
    insertString(save, player->getName(), player->maxNameSize);

    insertInteger(save, player->getStrength());
    insertInteger(save, player->getAbility());
    insertInteger(save, player->getEndurance());
    insertInteger(save, player->getArmor());
    insertInteger(save, player->getFirePower());

    insertInteger(save, player->getHp());
    insertInteger(save, player->getMp());

    insertClass(save, player->playerClass);
}

void AppModel::insertString(ofstream& streamer, string value, int size)
{
    value = fillBlankSpaces(value, size);
    streamer.write(value.c_str(), size);
}

void AppModel::insertInteger(ofstream& streamer, int value)
{
    streamer.write(reinterpret_cast<const char*> (&value), sizeof(int));
}

void AppModel::insertClass(ofstream & streamer, Class value)
{
    streamer.write(reinterpret_cast<const char*> (&value), sizeof(Class));
}

string AppModel::fillBlankSpaces(string string, int size)
{
    char *filled = new char[size];
    int stringSize = string.size();

    if (stringSize < size) {
        for (int i = 0; i < size; i++)
        {
            if (i < stringSize) {
                filled[i] = string[i];
            }
            else {
                filled[i] = ' ';
            }
        }
    }

    return filled;
}
