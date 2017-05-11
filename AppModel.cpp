#include "appModel.h"

Player* AppModel::player = NULL;
saveSlots AppModel::slots[3];
int AppModel::saveSlot = NULL;

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

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

    loadPlayer(load);

    load.close();
}

void AppModel::checkSlots()
{
    ifstream load("saveData.bee", ios::binary);
    int verify;
    string* name;

    for (int i = 0; i < 3; i++)
    {
        slots[i].slot = i;

        load.seekg(i * slotBites);
        load.read(reinterpret_cast<char*>(&verify), sizeof(int));

        if (verify) {
            char *nameBuffer = new char[verify];
            load.read(nameBuffer, verify);

            slots[i].empty = false;
            name = new string(nameBuffer, verify);
            slots[i].name = *name;
        }
        else {
            slots[i].empty = true;
            name = new string("");
            slots[i].name = *name;
        }

        slots[i].name = trim(slots[i].name);

        verify = 0;
    }

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

void AppModel::loadPlayer(ifstream & load)
{
    player = new Player;

    int strength, ability, endurance, armor, fire_power, hp, mp;
    Class playerClass;

    load.read(reinterpret_cast<char*>(&player->maxNameSize), sizeof(int));
    char *name = new char[player->maxNameSize];
    load.read(name, player->maxNameSize);

    load.read(reinterpret_cast<char*> (&strength), sizeof(int));
    load.read(reinterpret_cast<char*> (&ability), sizeof(int));
    load.read(reinterpret_cast<char*> (&endurance), sizeof(int));
    load.read(reinterpret_cast<char*> (&armor), sizeof(int));
    load.read(reinterpret_cast<char*> (&fire_power), sizeof(int));

    load.read(reinterpret_cast<char*> (&hp), sizeof(int));
    load.read(reinterpret_cast<char*> (&mp), sizeof(int));

    load.read(reinterpret_cast<char*> (&playerClass), sizeof(Class));

    player->setName(string(name, player->maxNameSize));
    player->setName(trim(player->getName()));

    player->setStrength(strength);
    player->setAbility(ability);
    player->setEndurance(endurance);
    player->setArmor(armor);
    player->setFirePower(fire_power);

    player->setHp(hp);
    player->setMp(mp);

    player->playerClass = playerClass;
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