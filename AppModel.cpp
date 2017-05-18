#include "appModel.h"

Player* AppModel::player = NULL;
Item* AppModel::itens = NULL;
saveSlots AppModel::slots[3];
stageInfo* AppModel::stages = NULL;
int AppModel::saveSlot = NULL;
int AppModel::stageVectorSize;
int AppModel::scene[2];

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

vector<string> explode(string const & text, char delimiter) {
    vector<string> result;
    istringstream iss(text);

    for (string token; getline(iss, token, delimiter); )
    {
        result.push_back(move(token));
    }

    return result;
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

void AppModel::saveBinary()
{
    ofstream *save;

    if (slots[0].empty && slots[1].empty && slots[2].empty) {
        save = new ofstream(gameData, ios::binary);
    }
    else {
        save = new ofstream(gameData, ios::in | ios::out | ios::binary);
    }

    save->seekp(saveSlot * slotBites);

    insertInteger(*save, scene[0]);
    insertInteger(*save, scene[1]);

    savePlayer(*save);

    save->close();
}

void AppModel::load()
{
    ifstream itensFile(itemData);

    if (itensFile.is_open()) {
        int itensVectorSize;
        char breakPoint;
        string read;

        itensFile >> itensVectorSize;
        itens = new Item[itensVectorSize];

        for (int i = 0; i < itensVectorSize; i++)
        {
            vector<string> itemInfo;

            itensFile >> read;
            itemInfo = explode(read, ';');

            bool combat;
            combat = itemInfo[1].at(0) == '1' ? true : false;

            Type auxType;
            auxType = static_cast<Type>(stoi(itemInfo[2]));

            Position auxPosition;
            auxPosition = static_cast<Position>(stoi(itemInfo[3]));

            itens[i].initiate(
                itemInfo[0],
                combat,
                auxType,
                auxPosition,
                stoi(itemInfo[4])
            );

            itensFile >> breakPoint;

            if (breakPoint ==  '#') {
                continue;
            }
            else if (breakPoint == '&') {
                break;
            }
        }
    }

    ifstream load(stageData);

    if (load.is_open()) {
        int actualStage = 0;
        int nivel, ident, value;
        char type;
        string read;

        load >> stageVectorSize;
        stages = new stageInfo[stageVectorSize];

        do {
            string description;

            load >> read;

            if (read == "#") {
                load >> nivel >> ident >> type;

                if (nivel == -10) {
                    break;
                }

                stages[actualStage].nivel = nivel;
                stages[actualStage].ident = ident;
                stages[actualStage].type = type;
            }

            do {
                load >> read;
                if (read != "#") {
                    description += " " + read;
                }
            } while (read != "#");

            stages[actualStage].description = description;

            load >> read;

            vector<string> monsterInfo;

            if (read == "M:") {
                load >> read;
                monsterInfo = explode(read, ';');

                stages[actualStage].enemy = new Enemy();
                stages[actualStage].enemy->setName(monsterInfo[0]);
                stages[actualStage].enemy->setStrength(stoi(monsterInfo[1]));
                stages[actualStage].enemy->setAbility(stoi(monsterInfo[2]));
                stages[actualStage].enemy->setEndurance(stoi(monsterInfo[3]));
                stages[actualStage].enemy->setArmor(stoi(monsterInfo[4]));
                stages[actualStage].enemy->setFirePower(stoi(monsterInfo[5]));

                stages[actualStage].enemy->create();

                load >> read;
            }

            if (read == "I:") {
                int idItem;
                load >> idItem;

                if (idItem >= 0) {
                    stages[actualStage].item = itens[idItem].copy();
                }

            }

            load >> read;

            if (read == "$") {
                int optCount = 0;

                do {
                    description = "";
                    load >> value;

                    do {
                        load >> read;

                        if (read == "---") {
                            break;
                        }

                        if (read[0] != '$' && read[0] != '#') {
                            description += " " + read;
                        }

                    } while (read[0] != '$');

                    stages[actualStage].options[optCount].value = value;
                    stages[actualStage].options[optCount].description = trim(description);

                    optCount++;
                } while (optCount < 3);
            }

            actualStage++;
        } while (true);
    }

    load.close();
}

void AppModel::loadBinary()
{
    ifstream load(gameData, ios::binary);

    load.seekg(saveSlot * slotBites);

    load.read(reinterpret_cast<char*> (&scene[0]), sizeof(int));
    load.read(reinterpret_cast<char*> (&scene[1]), sizeof(int));

    loadPlayer(load);

    load.close();
}

void AppModel::checkSlots()
{
    ifstream load(gameData, ios::binary);

    int verify = 0;
    string* name;

    for (int i = 0; i < 3; i++)
    {
        slots[i].slot = i;

        if (load) {
            load.seekg(i * slotBites);
            // Le duas vezes para pular posição
            load.read(reinterpret_cast<char*>(&verify), sizeof(int));
            load.read(reinterpret_cast<char*>(&verify), sizeof(int));

            load.read(reinterpret_cast<char*>(&verify), sizeof(int));
        }

        if (verify) {
            char *nameBuffer = new char[verify];

            if (load) {
                load.read(nameBuffer, verify);
            }

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

    if (load) {
        load.close();
    }
}

void AppModel::savePlayer(ofstream& save)
{
    save.write(reinterpret_cast<const char*> (&player->maxNameSize), sizeof(int));
    insertString(save, player->getName(), player->maxNameSize);

    insertInteger(save, player->getStrength());
    insertInteger(save, player->getAbility());
    insertInteger(save, player->getEndurance());
    insertInteger(save, player->getArmor());
    insertInteger(save, player->getLuck());

    insertInteger(save, player->getHp());
    insertInteger(save, player->getMp());

    insertClass(save, player->playerClass);
}

void AppModel::loadPlayer(ifstream & load)
{
    player = new Player;

    int strength, ability, endurance, armor, luck, hp, mp;
    Class playerClass;

    load.read(reinterpret_cast<char*>(&player->maxNameSize), sizeof(int));
    char *name = new char[player->maxNameSize];
    load.read(name, player->maxNameSize);

    load.read(reinterpret_cast<char*> (&strength), sizeof(int));
    load.read(reinterpret_cast<char*> (&ability), sizeof(int));
    load.read(reinterpret_cast<char*> (&endurance), sizeof(int));
    load.read(reinterpret_cast<char*> (&armor), sizeof(int));
    load.read(reinterpret_cast<char*> (&luck), sizeof(int));

    load.read(reinterpret_cast<char*> (&hp), sizeof(int));
    load.read(reinterpret_cast<char*> (&mp), sizeof(int));

    load.read(reinterpret_cast<char*> (&playerClass), sizeof(Class));

    player->setName(string(name, player->maxNameSize));
    player->setName(trim(player->getName()));

    player->setStrength(strength);
    player->setAbility(ability);
    player->setEndurance(endurance);
    player->setArmor(armor);
    player->setLuck(luck);

    player->setHp(hp);
    player->setMp(mp);

    player->playerClass = playerClass;

    player->create();
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